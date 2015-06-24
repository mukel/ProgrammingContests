{koder: A^2P}
{PSN 2002 #13 "Cadena m s larga"}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 100000;
var
  fin,fout        : text;
  N,i,j,k,p,q     : longint;
  s,t,sol         : string;
  len             : array[1..MaxN] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);

  {solve}
  for i:=1 to N do
  begin
    readln(fin,s); len[i] := length(s);
    for j:=1 to length(s) do
    begin
      k := pos(s[j],t); delete(t,1,k); t := t + s[j];
      inc(p,k);
      if length(t) > length(sol) then
      begin
        sol := t; q := p;
      end;{then}
    end;{for}
  end;{for}
  i := 1; p := 0;
  repeat
    inc(p,len[i]); inc(i);
  until (i > N) or (p > q);

  {dprint}
  writeln(fout,length(sol),' ',i-1);
  write(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
13ş Cadena m s larga                                        Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Cierta  investigaci¢n  biol¢gica  est  tratando de encontrar la cadena
m s  larga  de  c‚lulas  diferentes  a  partir  de  ciertos organismos
ubicados consecutivamente o sea uno al lado del otro.

Cada c‚lula est  representada  por un car cter alfanum‚rico  (entre la
'A'  y  la  'Z',  entre  la 'a' y la 'z' y del  0 al  9) por lo que un
organismo es un conjunto de a lo sumo 10 caracteres.

La  cadena  m s  larga  se  forma  cuando al concatenar los organismos
(palabras)  en  el  mismo  orden en que aparecen podemos encontrar una
cadena  de  caracteres  consecutivos  en  los  que no se repita ning£n
car cter.

Tarea

Dado  un  conjunto  de  palabras encuentre la cadena de caracteres m s
larga  sin  que  se  repita  alguno  de  ellos  en  el  momento que se
concatenen todas esas palabras.

Entrada

El fichero de Entrada CADENA.IN contiene:
L¡nea 1: N (1 <= N <= 100000),  cantidad de organismos.
L¡nea  2 .. N+1 es cada una de ellas aparecer   una palabra de  cuando
m s 80 caracteres.

Salida

El fichero de salida CADENA.OUT contiene:
L¡nea  1:   dos enteros separados por un espacio en blanco. El primero
es  la longitud de la cadena m s larga y el segundo el n£mero de orden
de  la  palabra  en el fichero de Entrada donde se encuentra el primer
car cter de la cadena encontrada.
L¡nea 2: caracteres que forman la cadena m s larga.

Ejemplo de Entrada y Salida:

ÚÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ CADENA.IN ³ ³ CADENA.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5         ³ ³ 10 2       ³
³ asa       ³ ³ vialsegunr ³
³ avial     ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ segun     ³
³ rally     ³
³ point     ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}
