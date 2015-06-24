{koder: A^2P}{7 - 5 - 2007}
{PSN 2003 #53 "Torre"}
{$B-,Q-,I-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 10000;
var
  fin,fout        : text;
  N,M,i,j,k       : longint;
  P,len           : array[0..MaxN] of longint;

    function find(A: longint): longint;
    begin
      if P[A] <> A then P[A] := find(P[A]);
      find := P[A];
    end;{find}

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for i:=1 to N do P[i] := i;
  for i:=1 to M do
  begin
    readln(fin,j,k);
    {union}
    P[find(j)] := find(k);
  end;{for}

  {solve}
  for i:=1 to N do inc(len[find(i)]);
  for i:=1 to 2 do
  begin
    for j:=1 to N do
      if len[P[j]] > len[P[k]] then k := j;
    len[P[k]] := 0;
    if i = 1
      then write(fout,k,' ')
      else writeln(fout,k);
  end;{then}

  {fclose}
  close(fin); close(fout);
end.{main}

{
53ş Torre.                                                    USA 2003
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Hay  vasos  pl sticos  vac¡os marcados con n£meros de 1 a N que pueden
ponerse uno dentro del otro, ubicados encima de una mesa.

A usted se le dan los movimientos A -> B que significan que usted debe
mover  la  pila  de  vasos que contiene a A hacia la pila de vasos que
contiene  al  vaso B. Si A es igual a B, o los vasos A y B est n en la
misma pila, entonces no se hace ning£n movimiento.

Por ejemplo, nosotros tenemos 7 vasos y movemos 1->3, 2->6, 3->6, 4->7
y 4->2, entonces la situaci¢n en la mesa cambiar  como sigue:

                                                                   4
                                                                   7
                                                 1        1        1
                                                 3        3        3
                   1            1     2          2        2 4      2
1 2 3 4 5 6 7--> 2 3 4 5 6 7--> 3 4 5 6 7--> 4 5 6 7--> 5 6 7--> 5 6

Los movimientos tienen que hacerse en el orden dado.

Tarea

Escriba  un  programa  que  eligir  el movimiento cero,  el cual es el
movimiento  que  debe  hacerse  antes  del  primer  movimiento  en  el
orden  dado.  Usted debe escoger tal movimiento cero de tal manera que
maximice el n£mero de vasos en la pila m s grande.

Entrada

En la primera l¡nea del fichero de  entrada TOWER.IN hay dos enteros N
y  M, (2 <= N <= 10000, 0 <= M <= 100000). N es el n£mero de vasos que
est n  colocados  en la mesa y M es el n£mero de movimientos que ser n
hecho.  Luego  las  M  siguientes l¡neas contienen los movimientos que
ser n  realizados.  En cada una de estas l¡neas aparecer n dos enteros
A y B que representa un movimiento A -> B.

Salida

En  la  primera  y  £nica  l¡nea del fichero de salida TOWER.OUT  debe
contener  el movimiento cero A -> B representado por dos enteros A y B
separados por un espacio.
Nota: no necesariamente la soluci¢n es £nica.

Ejemplos de Entrada y Salida:

 Ejemplo # 1       Ejemplo # 2      Ejemplo # 3
ÚÄÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄ¿     ÚÄÄÄÄÄÄÄÄÄÄÄ¿
³ TOWER.IN  ³     ³ TOWER.IN  ³     ³ TOWER.IN  ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄ´     ÃÄÄÄÄÄÄÄÄÄÄÄ´
³ 5 3       ³     ³ 6 4       ³     ³ 10 9      ³
³ 1 2       ³     ³ 5 2       ³     ³ 3 7       ³
³ 5 3       ³     ³ 3 3       ³     ³ 5 9       ³
³ 4 1       ³     ³ 1 3       ³     ³ 10 10     ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ     ³ 6 2       ³     ³ 9 5       ³
ÚÄÄÄÄÄÄÄÄÄÄÄ¿     ÀÄÄÄÄÄÄÄÄÄÄÄÙ     ³ 8 7       ³
³ TOWER.OUT ³     ÚÄÄÄÄÄÄÄÄÄÄÄ¿     ³ 3 7       ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´     ³ TOWER.OUT ³     ³ 6 1       ³
³ 4 5       ³     ÃÄÄÄÄÄÄÄÄÄÄÄ´     ³ 4 2       ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ     ³ 3 5       ³     ³ 2 6       ³
                  ÀÄÄÄÄÄÄÄÄÄÄÄÙ     ÀÄÄÄÄÄÄÄÄÄÄÄÙ
                                    ÚÄÄÄÄÄÄÄÄÄÄÄ¿
                                    ³ TOWER.OUT ³
                                    ÃÄÄÄÄÄÄÄÄÄÄÄ´
                                    ³ 7 2       ³
                                    ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}