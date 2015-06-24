{koder: A^2P}{6 - 5 - 2007}
{PSN 2002 #86 "Dominoes"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 41;
var
  fin,fout        : text;
  N,i,j,r,t       : longint;
  A,B             : array[0..MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
    readln(fin,A[i],B[i]);

  {sort}
  for i:=1 to N do
    for j:=i + 1 to N do
      if A[j] + B[j] < A[i] + B[i] then
      begin
        t := A[i]; A[i] := A[j]; A[j] := t;
        t := B[i]; B[i] := B[j]; B[j] := t;
      end;{then}

  {solve}
  for i:=1 to N do
  begin
    t := A[i] + B[i] + r;
    A[i] := t mod 10;
    r := t div 10;
  end;{for}

  {dprint}
  if r > 0 then write(fout,r);
  for i:=N downto 1 do write(fout,A[i]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
86ş Dominoes                                                Korea 2002
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Los estudiantes de la Preselecci¢n Nacional est n jugando domin¢ con N
(1<=N<=40)  fichas de domin¢. Cada ficha tiene dos n£meros en el rango
0..9 ubicadas una en el tope del otro similar a este.

               ÚÄÄÄ¿
               ³ 5 ³
               ÃÄÄÄ´
               ³ 2 ³
               ÀÄÄÄÙ

La  figura  de  abajo representa tres fichas de domin¢ ubicadas cara a
cara  a  lo  largo  con  dos  enteros  en  base  10 que representan la
distribuci¢n:

         ÚÄÄÄ¿  ÚÄÄÄ¿  ÚÄÄÄ¿
         ³ 5 ³  ³ 3 ³  ³ 4 ³   5 * 100 + 3 * 10 + 4 * 1 = 534
         ÃÄÄÄ´  ÃÄÄÄ´  ÃÄÄÄ´
         ³ 2 ³  ³ 4 ³  ³ 1 ³   2 * 100 + 4 * 10 + 1 * 1 = 241
         ÀÄÄÄÙ  ÀÄÄÄÙ  ÀÄÄÄÙ

Por    supuesto,   algunas  fichas  pueden  ser  rotadas  180  grados,
intercambiando los n£meros de arriba y de abajo.

               ÚÄÄÄ¿      ÚÄÄÄ¿
               ³ 5 ³      ³ 2 ³
               ÃÄÄÄ´ ÄÄÄ> ÃÄÄÄ´
               ³ 2 ³      ³ 5 ³
               ÀÄÄÄÙ      ÀÄÄÄÙ

El  juego  particular  que  los  estudiantes  de la Preselecci¢n est n
jugando  requiere  acostar  las  N  fichas  (elegiendo  el  orden y la
rotaci¢n)  tal  que  la  suma de las dos representaciones bases 10 sea
maximizada. Para el ejemplo de arriba, la suma m xima es 775. Su tarea
es calcular esa suma m xima.

Entrada

El fichero de entrada PSNDOM.IN contendr :
- l¡nea 1 : Una l¡nea con un entero simple: N
- l¡nea 2..N+1: cada l¡nea contiene dos enteros describiendo una
  ficha.

Salida

El  fichero  de  salida  PSNDOM.OUT  contendr  una l¡nea con un entero
simple  que  es la suma m xima posible de la representaci¢n base 10 de
la ficha dispuesta cara a cara.

ÚÄÄÄÄÄÄÄÄÄÄÄ¿  ÚÄÄÄÄÄÄÄÄÄÄÄÄ¿
³ PSNDOM.IN ³  ³ PSNDOM.OUT ³
ÃÄÄÄÄÄÄÄÄÄÄÄ´  ÃÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 3         ³  ³ 775        ³
³ 1 4       ³  ÀÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 2 5       ³
³ 3 4       ³
ÀÄÄÄÄÄÄÄÄÄÄÄÙ
}