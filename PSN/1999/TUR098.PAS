{koder: A^2P}{31 - 3 - 2007}
{PSN 1999 #98 "Esperando por una papeleta"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 200;
  oo = 1 shl 29;
var
  fin,fout        : text;
  N,i,j           : longint;
  A,B             : array[0..MaxN] of longint;
  C,last          : array[0..MaxN,0..1] of longint;

    function min(a,b: longint): longint;
    begin
      if a <= b then min := a
        else min := b;
    end;{min}

    procedure print(i,j: longint);
    begin
      if i <= 0 then exit;
      if j = 0
        then print(i - 1,last[i,j])
        else print(i - 2,last[i,j]);
      if j = 1 then write(fout,i - 1,'+');
      writeln(fout,i);
    end;{print}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do read(fin,A[i]);
  readln(fin);
  for i:=2 to N do read(fin,B[i]);

  {solve}
  C[1,0] := A[1]; C[1,1] := oo;
  for i:=2 to N do
  begin
    C[i,0] := min(C[i - 1,0],C[i - 1,1]) + A[i];
    if C[i - 1,1] < C[i - 1,0] then last[i,0] := 1;
    C[i,1] := min(C[i - 2,0],C[i - 2,1]) + B[i] ;
    if C[i - 2,1] < C[i - 2,0] then last[i,1] := 1;
  end;{for}

  {dprint}
  if C[N,1] < C[N,0] then j := 1;
  writeln(fout,C[N,j]);
  print(N,j);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 98þ Esperando por una papeleta                           Turqu¡a 1999
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

 El grupo de rock U2 dar  un concierto en Nicosia la capital de Chipre
 durante noviembre del 96. Se ha formado una cola de n (n<=200)
 fan ticos del grupo que esperan para comprar una papeleta a un £nico
 cajero. Cada persona quiere comprar solamente una papeleta ya que el
 cajero puede vender como m ximo dos papeletas a una persona.

 Suponga que el cajero gasta Ti unidades de tiempo para atender al
 i-‚simo fan tico (donde 1 <= i <= N). No obstante, dos fan ticos
 consecutivos en la cola (por ejemplo, el j-‚simo y el (j+1)-‚simo con
 1 <= j <= n-1 ) pueden ponerse de acuerdo de manera que uno de ellos
 permanezca en la cola y el otro la deje, si el tiempo Rj requerido
 por el cajero para servir al j-‚simo y el (j+1)-‚simo es m s peque¤o
 que Tj + T(j+1). As¡ para minimizar el tiempo del cajero y estrechar
 la cola, cada persona de la cola trata de negociar con su predecesor
 y su sucesor, y finalmente acelerar el proceso.

 Dado un valor entero positivo para N, Ti y Rj se desea minimizar el
 tiempo total del cajero. Esto se logra haciendo pares de personas
 consecutivas en una forma ¢ptima. Note, sin embargo, que no es
 necesario para un fan tico en espec¡fico estar unido con un
 predecesor o un sucesor.

 Entrada:

 El fichero de entrada consiste de tres l¡neas: la primera contiene el
 entero N. La segunda l¡nea contiene N enteros: los Ti valores
 separado cada uno entre si por un espacio en blanco. La tercera l¡nea
 contiene N-1 valores establecidos para los Rj valores separados por
 un espacio en blanco cada uno.

 Salida:

 El fichero de salida contiene en la primera l¡nea el tiempo total
 consumido por el cajero. Cada una de las pr¢ximas l¡neas contiene un
 n£mero o dos n£meros separados por el caracter +; m s
 espec¡ficamente, cada l¡nea contiene el n£mero i, si el i-‚simo
 fan tico es atendido solo, o i+(i+1)  si estos dos fan ticos son
 atendidos por un par.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³Ejemplo de Entrada³³Ejemplo de Salida³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 7								³³ 14 						 ³
 ³ 5 4 3 2 1 4 4		³³ 1							 ³
 ³ 7 3 4 2 2 4			³³ 2+3						 ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ³ 4+5						 ³
										 ³ 6+7						 ³
                     ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
