/*
Alfonso Alfonso Peterssen
30 - 9 - 2007
PSN 2007 #3 "Pyramid"
IOI 2007 Day 1 Task 2
*/
#include <cstdio>

#define MAXN 1001
#define oo 1000000000
#define sum( x1, y1, x2, y2 ) \
  ( T[x2][y2] - T[x1 -1][y2] - T[x2][y1 - 1] + T[x1 - 1][y1 - 1] )

int N, M, A, B, C, D, i, j, k, sum, diff;
int bigX, bigY, smallX, smallY;
int T[MAXN][MAXN];

int min_box[MAXN][MAXN];
int min_left[MAXN], min_right[MAXN];

int big[MAXN][MAXN],
    small[MAXN][MAXN];

int main() {

  scanf( "%d %d %d %d %d %d", &M, &N, &B, &A, &D, &C );
  for ( i = 1; i <= N; i++ )
    for ( j = 1; j <= M; j++ ) {
      scanf( "%d", &T[i][j] );
      T[i][j] += T[i - 1][j] + T[i][j - 1] - T[i - 1][j - 1];
    }

  for ( i = 1; i <= N - A + 1; i++ )
    for ( j = 1; j <= M - B + 1; j++ )
      big[i][j] = sum( i, j, i + A - 1, j + B - 1 );

  for ( i = 1; i <= N - C + 1; i++ )
    for ( j = 1; j <= M - D + 1; j++ )
      small[i][j] = sum( i, j, i + C - 1, j + D - 1 );

  diff = B - D - 1;
  for ( i = 2; i < N; i++ )
    for ( j = diff + 1; j <= M; j += diff ) {

      min_left[j] = min_right[j] = small[i][j];

      for ( k = j + 1; k < j + diff && k <= M; k++ )
        min_right[k] = min_right[k - 1] <? small[i][k];

      for ( k = j - 1; k > j - diff; k-- )
        min_left[k] = min_left[k + 1] <? small[i][k];

      for ( k = j - diff + 1; k <= j; k++ )
        min_box[i][k] = min_left[k] <? min_right[k + diff - 1];
    }

  diff = A - C - 1;
  for ( j = 2; j < M; j++ )
    for ( i = diff + 1; i <= N; i += diff ) {

      min_left[i] = min_right[i] = min_box[i][j];

      for ( k = i + 1; k < i + diff && k <= N; k++ )
        min_right[k] = min_right[k - 1] <? min_box[k][j];

      for ( k = i - 1; k > i - diff; k-- )
        min_left[k] = min_left[k + 1] <? min_box[k][j];

      for ( k = i - diff + 1; k <= i; k++ )
        min_box[k][j] = min_left[k] <? min_right[k + diff - 1];
    }

  sum = -oo;
  for ( i = 1; i <= N - A + 1; i++ )
    for ( j = 1; j <= M - B + 1; j++ )
      if ( big[i][j] - min_box[i + 1][j + 1] > sum ) {
        sum = big[i][j] - min_box[i + 1][j + 1];
        bigX = i;
        bigY = j;
      }

  for ( i = 1; i <= A - C - 1; i++ )
    for ( j = 1; j <= B - D - 1; j++ )
      if ( small[bigX + i][bigY + j] == min_box[bigX + 1][bigY + 1] ) {
        smallX = bigX + i;
        smallY = bigY + j;
      }

  printf( "%d %d\n", bigY, bigX );
  printf( "%d %d\n", smallY, smallX );

  return 0;
}

/*
2þ Pyramid.                                               Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Despu‚s   de  ganar   una   gran  batalla,   el   rey  Jaguar   quiere
construir  una  pir mide que   sirva  como monumento  para    recordar
la victoria y   como tumba  para  los  bravos soldados   que  murieron
en el frente.  La  pir mide deber    ser construida  en  el  campo  de
batalla y  tendr  una  base rectangular  de a  columnas por  b  filas.
Dentro  de  ella,  a  nivel de  la  tierra,  hay  una peque¤a   c mara
rectangular de c columnas por d filas  que contendr n los  cuerpos   y
las  armas de los  soldados  fallecidos. La superficie del campo    de
batalla  mide  m  columnas   por  n  filas   con   un   conjunto    de
elevaciones  irregulares   del suelo.   Los arquitectos  del  rey  han
modelado el  campo como  una cuadricula de m columnas por n filas,   y
han medido la elevaci¢n  de cada casilla con  un entero hij para   las
coordenadas (i, j). Ya  que al rey le  gustan los n£meros enteros,  la
pir mide  y la c mara ser n  construidas cubriendo completamente   los
cuadrados de  la cuadricula   y  con  sus  lados   paralelos a     los
del campo   de batalla.

No   se  cambiar   la  elevaci¢n   de los    cuadrados de  la
c mara  interna,  pero   el resto  del  terreno  de la   base  de   la
pir mide ser  nivelado  moviendo arena desde  los cuadrados  altos   a
los bajos.  La elevaci¢n   final de  la base   ser  la  media de    la
elevaci¢n de todos  los  cuadrados de  la base  (excluyendo  a los  de
la c mara). La  elevaci¢n final  puede ser  mayor o  menor que  la  de
los cuadrados de la c mara  interna. Los arquitectos tienen   libertad
para ubicar  a la  c mara interna  en cualquier  lugar del    interior
de  la  pir mide, siempre  y cuando  dejen  por  lo menos un  cuadrado
rodeando  a cada  lado de   la c mara.  Ayuda  a  los arquitectos    a
escoger el   mejor lugar  para ubicar  a la  pir mide y  a la   c mara
interna de manera que la elevaci¢n  final de la  base de la   pir mide
sea  lo  m s grande   posible  para las   medidas  dadas.  La   figura
muestra un  ejemplo del  campo  de batalla; el n£mero dentro  de  cada
cuadro  representa  a  la  elevaci¢n  del  terreno  en   una  posici¢n
particular del  campo. Los  cuadrados grises representan  a la    base
de  la pir mide,  mientras que  los cuadrados blancos bordeados    por
un   trazo  negro   grueso  indipueden  una  manera  de  ubicar   a la
c mara interna. Esta figura ilustra la ubicaci¢n ¢ptima.

TAREA

Escribe un programa que dado el tama¤o del campo, de la pir mide y  de
la  c mara  y  con  las  elevaciones  de  cada  cuadrado  del  campo,
encuentra la  ubicaci¢n de  la pir mide  en el  campo y  de la  c mara
interna de la  pir mide, de forma  que la elevaci¢n  de la base  de la
pir mide sea la m xima posible.

RESTRICCIONES

3 = m = 1 000 3 = n = 1 000 3 = a = m 3 = b = n 1 = c  =
a – 2 1 = d = b – 2 1 = hij = 100 Todas las elevaciones son enteros en
el rango de 1 hasta 100.

ENTRADA

El  programa  debe  leer  los  siguientes  datos  del fichero
pyramid.in

pyramid.in DESCRIPCION 8 5 5 3 2 1 1 5 10 3 7 1 2 5 6 12  4
4 3 3 1 5 2 4 3 1 6 6 19 8 1 1  1 3 4 2 4 5 6 6 3 3 3 2 2 2	LÍNEA   1:
Contiene 6 enteros separados por un espacio, respectivamente: m, n, a,
b, c,  y d.  LAS SIGUIENTES  n LÍNEAS:  Cada l¡nea  contiene m enteros
separados por un espacio que representan las alturas de una fila en la
cuadricula.  La primera de estas l¡neas representa a la fila de arriba
(fila 1) de la cuadricula, y  la £ltima l¡nea representa a la  fila de
abajo (fila n).  Los  m enteros de cada l¡nea representan las  alturas
de cada cuadrado dentro de la fila.

SALIDA

El programa  debe escribir los  siguientes datos en  el fichero
pyramid.out pyramid.out DESCRIPCION 4 1  6 2  LÍNEA 1: Debe   contener
2  enteros  separados  por un   espacio  que  representan la   esquina
superior izquierda de la base de  la pir mide, el primer n£mero es  la
columna   y el  segundo la  fila. LÍNEA  2: Debe  contener 2   enteros
separados  por   un  espacio  que   representan  la   esquina superior
izquierda de  la c mara dentro de la pir mide, el primer n£mero es  la
columna y el segundo  la fila.

NOTA:  Si hay  m£ltiples soluciones  optimas, entonces  cualquiera  de
ellas usted debe considerar correcta.

PUNTUACION Para  un cierto  n£mero de  juegos de  prueba se obtiene un
total  de 30  puntos, cada  juego de  prueba verifica  las  siguientes
restricciones: 3 = m = 10 3 = n = 10
*/