{koder: A^2P}{4 - 3 - 2007}
{PSN 2000 #108 "El vuelo de las brujas"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 180000;
  oo = 1 shl 29;
var
  fin,fout        : text;
  N,M,i,j,sol     : longint;
  t               : array[0..MaxN] of longint;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,M); readln(fin,N);
  for i:=1 to N do
  begin
    readln(fin,t[i]);
    inc(t[i],t[i - 1]);
  end;{for}

  {solve}
  sol := oo;
  i := 1; j := 0;
  repeat
    while (j < N) and (t[j + 1] - t[i - 1] <= M)
      do inc(j);
    if j - i + 1 < sol then sol := j - i + 1;
    inc(i);
  until (j = N) or (sol = 0);

  {dprint}
  writeln(fout,sol);

  {fclose}
  close(fin); close(fout);
end.{main}

{
 108þ El vuelo de las brujas                                China 2000
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Una  peque¤a  bruja  de  360 a¤os, se dispone a iniciarse en una orden
que est  de moda en el pa¡s de las brujas, puesto que ya tiene la edad
y  los conocimientos necesarios. Pero antes tiene que pasar una prueba
absurda para ella que consiste en realizar un vuelo de aproximadamente
20 a¤os.

La  prueba  consiste  en hacer un  vuelo con la frente casi rozando el
piso  y  en  completo silencio. Debido al clima del pa¡s de las brujas
por  esa  ‚poca  las  escobas  no  duraban  mucho, por lo que la bruja
necesitaba  llevar  muchas  escobas  para  poder culminar el viaje. El
£nico  problema  de  esto  es  que si el peso de todas las escobas que
carga  la  bruja  es  mayor que el que ella puede soportar entonces la
bruja  empieza  a  roncar,  y  eso est  prohibido, pues el viaje es en
absoluto silencio.

Antes  de  partir  a  la  bruja  se  le pone  delante una secuencia de
escobas.  Ella  con los ojos vendados debe escoger una subsecuencia de
estas  escobas  de  forma tal que el peso de estas no sobrepase el que
ella  puede  soportar.  Las  brujas de tan corta edad solo perciben el
peso  de  las  cosas  con  la  vista.  La  bruja  necesita que dada la
secuencia de escobas con el peso de cada una, halles el mayor valor de
M  de  forma  tal que el peso de todas las subsecuencias de escobas de
longitud M sea soportable por la bruja. Una subsecuencia de longitud M
que empieza en la escoba i y termina en la escoba i+M-1.

Entrada

El  fichero  de  entrada  contiene  en  la  primera  l¡nea un entero P
(1  <=  P  <=  2147483647)  que  representa el peso que la bruja puede
soportar. En la segunda l¡nea aparecer  un entero N (1 <= N <= 180000)
que representa la cantidad de escobas de la secuencia. En las N l¡neas
siguientes  aparecer   un  n£mero  entero  positivo  en cada l¡nea que
representa el peso de la i-‚sima escoba.

Salida

El fichero de salida contendr  en la primera l¡nea el valor de M.

 ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
 ³Ejemplo de Entrada³³Ejemplo de Salida³
 ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
 ³ 300              ³³ 5               ³
 ³ 10               ³ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
 ³ 65               ³
 ³ 63               ³
 ³ 40               ³
 ³ 12               ³
 ³ 98               ³
 ³ 87               ³
 ³ 46               ³
 ³ 15               ³
 ³ 42               ³
 ³ 15               ³
 ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
}
