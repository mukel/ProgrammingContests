{koder: A^2P}{26 - 2 - 2007}
{PSN 2007 #24 "Competencia de Baile"}
{$B-,I-,Q-,R-,S-}
const
  filein = 'd.in';
  fileout = 'd.out';
  MaxN = 60;
  mov : array[0..1,1..8] of shortint =
  ((-1,-1,-1,0,0,1,1,1),(-1,0,1,-1,1,-1,0,1));
var
  fin,fout        : text;
  N,M,i,j,k       : longint;
  mat             : array[0..1,0..MaxN,0..MaxN] of byte;

begin
  {fload}
  assign(fin,filein); reset(fin);
  assign(fout,fileout); rewrite(fout);

  {dread}
  readln(fin,N,M);
  for k:=0 to 1 do
    for i:=1 to N do
      for j:=1 to M do read(fin,mat[k,i,j]);

  {solve}
  for i:=2 to N - 1 do
    for j:=2 to M - 1 do
      if mat[0,i - 1,j - 1] xor mat[1,i - 1,j - 1] = 1 then
      begin
        writeln(fout,i,' ',j);
        for k:=1 to 8 do
          mat[1,i + mov[0,k],j + mov[1,k]] :=
            mat[1,i + mov[0,k],j + mov[1,k]] xor 1;
      end;{then}

  {fclose}
  close(fin); close(fout);
end.{main}

{
24ş Competencia de Baile.                                 Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

La FEEM de la LENIN ha decidido realizar una Competencia de Baile para
celebrar la Copa. Para ello  se ha construido una plataforma de  baile
£ltimo modelo,  que posee  un sistema  de luces.  La plataforma  puede
poseer dimensiones  variables de  n filas  y m  columnas de  secciones
como se muestra. n=10, m=10.

Esta plataforma tiene la peculiaridad que al pisar una secci¢n  cambia
el estado de  las 8 secciones  adyacentes, encendi‚ndose o  apag ndose
sus luces en dependencia de su estado anterior. Por ejemplo:


Si se pisara la secci¢n marcada con la X entonces las 8 adyacentes  se
apagaran. Como las secciones perif‚ricas no poseen 8 adyacentes, sobre
estas  no  se  puedes  parar  el  bailador.  Observe  que  pasa  si  a
continuaci¢n se pisara otra secci¢n.

Problema

El problema consiste en determinar la secuencia m¡nima de pasos que se
debe dar para obtener un determinado estado de las luces, a partir  de
un estado inicial dado.

Entrada

Ejemplo (BAILE.IN)

10 10
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1

0 0 0 1 1 1 1 1 1 1
0 0 1 0 1 1 1 1 1 1
0 1 0 0 1 1 1 1 1 1
1 0 0 0 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1

Descripci¢n

L¡nea1: Dos enteros n y m separados por un espacio que representan las
dimensiones de la plataforma.
Siguientes n L¡neas: m estados iniciales de las secciones, 1
encendido, 0 apagado.
L¡nea n+2: Vac¡a.
Siguientes n L¡neas: m estados finales de las secciones, 1 encendido,
0 apagado.

Salida

Ejemplo (BAILE.OUT)
2 2
3 3

Descripci¢n

Coordenadas (separadas por un espacio)  de los pasos que se  deben dar
para llegar del estado inicial al final, un par por cada l¡nea.

Consideraciones

-	1<N<=60   1<M<=60
- Se garantiza que todos los casos de prueba tienen al menos una
  soluci¢n.
- Para el 50% de los casos de prueba 1<N<=10 y 1<M<=10.



25ş El Juego del Dado.                                    Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un  tablero de NxM casillas se ha enumerado  consecutivamente con  los
n£meros  del  1  al  NxM  comenzando  por  la £ltima fila llenando las
casillas  de izquierda a derecha, luego la pen£ltima fila de derecha a
izquierda y asi alternadamente hasta la primera fila (figura 1).
Algunas  casillas tienen pase directo a otras casillas, bien en avance
o  en  retroceso  (se  indica  con una flecha). Estos pases  solo  son
validos cuando se termina de contar en una casilla que contenga enlace
directo con otra casilla.

Un  jugador con su ficha se va moviendo por las casillas (en el  orden
en  que fueron enumeradas) a medida que lanza un dado y avanza  tantas
casillas  como puntos salen. Las caras del dado est n enumeradas del 1
al  6. El objetivo del juego es  llegar  a la casilla  de mayor n£mero
(meta)  con la menor cantidad posible de tiros del dado. Se comienza a
contar la primera vez a partir de la casilla n£mero 1.

Determine  la puntuaci¢n que debe sacar un jugador en cada uno  de sus
turnos para ganar el juego lo m s pronto posible.

Figura 1 (Hoja).

Entrada

El  archivo de Entrada contiene en la primera l¡nea el n£mero de filas
del   tablero  N y el  n£mero  de  columnas  separados por un  espacio
(4  ¢  N,  M ¢ 1000). Las  pr¢ximas l¡neas  tienen los  enlaces de las
casillas  que tienen pase directo a otra, uno por l¡nea, primero  esta
el n£mero de la casilla y luego, separado por espacio, el n£mero de la
casilla a donde se dirigir  la flecha.

Salida

El  archivo de  Salida  deber   contener en  una l¡nea la cantidad  de
veces  que  habra  que  lanzar  el  dado,  la  segunda l¡nea tendra la
puntuaci¢n que alcanzar  en cada tirada.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³  Ejemplo de Entrada  ³ ³ Ejemplo de Salida ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5 5                  ³ ³ 4                 ³
³ 3 12                 ³ ³ 3 6 1 1           ³
³ 13 1                 ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 17 7                 ³
³ 19 24                ³  Nota: S¢lo se dar  una soluci¢n.
³ 22 11                ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

Descripci¢n  del ejemplo de salida:

En el primer  lanzamiento sali¢ la cara 3, entonces movemos la ficha
por las casillas 1, 2 y 3. Al llegar a  la casilla 3 esta tiene un
enlace directo  hasta la  casilla 12 por lo  que autom ticamente la
ficha se  mueve hasta dicha  casilla. En el segundo tiro sali¢ un 6,
por tanto nos movemos por las casillas  desde la  13 hasta la 18. En
el tercer lance sali¢ un 1 y nos movemos  hasta la  casilla 19, esta
tiene un pase directo hasta la casilla 24. En  el £ltimo lance sali¢
un 1 y con esto llegamos a la casilla final, la 25.
}
