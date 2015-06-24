{koder: A^2P}
{PSN 2006 #66 "Moo"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 50001;
  oo = MaxLongint;
var
  fin,fout        : text;
  N,i,j           : longint;
  left,right,c    : array[0..MaxN] of word;
  h,sol           : array[0..MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N);
  for i:=1 to N do
    readln(fin,h[i],c[i]);

  {solve}
  h[0] := oo; h[N + 1] := oo;
  left[1] := 0; right[N] := N + 1;

  for i:=N-1 downto 1 do
  begin
    j := i + 1;
    while h[i] >= h[j] do j := right[j];
    inc(sol[j],c[i]);
    right[i] := j;
  end;{for}

  h[0] := oo;
  for i:=2 to N do
  begin
    j := i - 1;
    while h[i] >= h[j] do j := left[j];
    inc(sol[j],c[i]);
    left[i] := j;
  end;{for}

  {dprint}
  j := 1;
  for i:=1 to N do
    if sol[i] > sol[j] then j := i;
  writeln(fout,sol[j]);

  {fclose}
  close(fin); close(fout);
end.{main}

{
66ş Moo.                                                   M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las N (1 <= N <= 50,000) vacas del Granjero Juan est n en una fila muy
larga  mugiendo.  Cada vaca  tiene  una altura  £nica  h en  el  rango
1..2,000,000,000 nan¢metros (GJ  realmente es muy quisquilloso con  la
precisi¢n). Cada vaca muge en  alg£n volumen v en el  rango 1..10,000.
Este mugido viaja a  trav‚s de la fila  de vacas en ambas  direcciones
(excepto obviamente para las vacas en los extremos). Curiosamente,  es
oido por las vacas m s  cercanas en cada direcci¢n cuyas  alturas sean
estrictamente mayores que la vaca  mugidora (por lo tanto cada  mugido
ser  oido  por 0,  1 ¢  2 vacas,  dependiendo si  o no vacas mas altas
existan a la derecha o izquierda de la vaca mugidora).

El volumen total de mugido o¡do por una vaca dada es la suma de  todos
los vol£menes de mugido que llegan a la vaca. Desde que algunas  vacas
(presumiblemente m s altas) podr¡an estar sometidas a una cantidad muy
grande de volumen  de mugido, GJ  quiere comprar tapones  para la vaca
cuya audici¢n sea la m s  amenazada. Por favor, calcule el  volumen de
mugido mas alto o¡do por cualquier vaca.

Entrada

El fichero de entrada MOO.IN contiene:
- L¡nea 1: Un solo entero, N.
- L¡neas 2..N+1: La l¡nea i+1 contiene dos enteros, h y v, para la
  vaca que est  en la ubicaci¢n i.

Salida

El fichero de salida MOO.OUT contiene:
- L¡nea 1: El volumen de mugido m s grande o¡do por cualquier vaca en
  particular.

Ejemplo de Entrada y Salida

ÚÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄ¿
³ MOO.IN  ³ ³ MOO.OUT ³
ÃÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄ´
³ 3       ³ ³ 7       ³
³ 4 2     ³ ÀÄÄÄÄÄÄÄÄÄÙ
³ 3 5     ³
³ 6 10    ³
ÀÄÄÄÄÄÄÄÄÄÙ

Detalles de la Entrada:
Tres vacas: la primera tiene altura 4 y muge con volumen 2, etc.

Detalles de la Salida:

La tercera vaca oye  tanto los mugidos de  la primera y segunda  vacas
2+5=7. A pesar  que la tercera  vaca muge con  volumen 10, ninguna  la
oye.
}









































