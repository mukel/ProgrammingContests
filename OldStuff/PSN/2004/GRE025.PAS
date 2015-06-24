{koder: A^2P}{16 - 3 - 2007}
{PSN 2004 #25 "Viaje"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 80;
  MaxL = 1000;
var
  fin,fout        : text;
  A,B,S           : string;
  N,M,D,i,j       : longint;
  size            : array[0..MaxN] of byte;
  list            : array[0..MaxL] of string;
  c,l1,l2         : array[0..MaxN,0..MaxN] of byte;

    function max(a,b: byte): byte;
    begin
      if a >= b then max := a
        else max := b;
    end;{max}

    procedure find(i,j,len: byte);
    var k : integer;
    begin
      if len = 0 then
      begin
        for k:=1 to D do
          if S = list[k] then exit;
        inc(D); list[D] := S;
        exit;
      end;{then}
      for k:=1 to size[c[i,j] - 1] do
        if (l1[c[i,j] - 1,k] < i) and (l2[c[i,j] - 1,k] < j) then
        begin
          S[len] := A[l1[c[i,j] - 1,k]];
          find(l1[c[i,j] - 1,k],l2[c[i,j] - 1,k],len - 1);
        end;{then}
    end;{find}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,A); N := byte(A[0]);
  readln(fin,B); M := byte(B[0]);

  {solve}{lcs}
  for i:=1 to N do
    for j:=1 to M do
      if A[i] = B[j] then
      begin
        c[i,j] := c[i - 1,j - 1] + 1;
        inc(size[c[i,j]]);
        l1[c[i,j],size[c[i,j]]] := i;
        l2[c[i,j],size[c[i,j]]] := j;
      end{then ->}
      else c[i,j] := max(c[i - 1,j],c[i,j - 1]);

  {find the ways}
  byte(S[0]) := c[N,M];
  c[N + 1,M + 1] := c[N,M] + 1;
  find(N + 1,M + 1,c[N,M]);

  {dprint}
  for i:=1 to D do
    writeln(fout,list[i]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
25ş Viaje.                                                 Grecia 2004
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Alice y Bob desean ir de vacaciones. Cada uno de ellos tiene planeada
una ruta, la cual es una lista de ciudades para ser visitadas en un
orden dado. Una ruta puede contener una ciudad m s de una vez.

Como ellos desean viajar juntos, tienen que acordar una ruta com£n.
Ninguno desea cambiar el orden de las ciudades en su ruta o agregar
otras ciudades. Por lo tanto, ellos no tienen ninguna selecci¢n para
quitar algunas ciudades de la ruta. Por supuesto, la ruta com£n debe
ser tan larga como sea posible.

Hay exactamente 26 ciudades en la regi¢n. Por lo que ellos codificaron
las listas con letras min£sculas desde 'a' hasta 'z'.

Entrada

El fichero de entrada trip.in consiste de dos lineas; la primera l¡nea
es la ruta de Alice, la segunda l¡nea es la lista de Bob. Cada una de
estas listas consiste de 1 a 80 letras min£sculas sin espacios entre
ellas.

Salida

El fichero de salida trip.out debe contener todas las rutas que reunan
las condiciones descritas arriba. Pero ninguna ruta debe ser listada
mas de una vez. Cada ruta debe imprimirse en una l¡nea separada. Al
menos hay una ruta que no es vac¡a, pero nunca m s de 1000 diferentes.
El orden de las rutas en el fichero de salida no importa.

Ejemplo

ÚÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄ¿
³trip.in  ³     ³trip.out³
ÃÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄ´
³abcabcaa ³     ³ababa   ³
³acbacba  ³     ³abaca   ³
ÀÄÄÄÄÄÄÄÄÄÙ     ³abcba   ³
                ³acbca   ³
                ³acaba   ³
                ³acaca   ³
                ³acbaa   ³
                ÀÄÄÄÄÄÄÄÄÙ
}
