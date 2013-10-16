/*
Alfonso Alfonso Peterssen
28 - 8 - 2007
USACO 2005 FEB Silver "Contabilidad de Comida"
*/
#include <cstdio>

#define problem "d"
#define MAXD 2001

int C, F1, F2, D, i, j, k;
int cnt[MAXD];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d %d %d", &C, &F1, &F2, &D );

  for ( i = 0; i < C; i++ ) {
    scanf( "%d %d", &j, &k );
    for ( ; j <= k; j++ )
      cnt[j]++;
  }

  j = 0;
  for ( i = D; i; i-- )
    if ( j >= F1 - F2 ) break;
    else j += cnt[i];

  printf( "%d\n", i + 1 );

  return 0;
}

/*
Problema 8: Contabilidad de Comida [Hal Burch, 2004]

El Granjero Juan está tratando de averiguar cuando llegó su último
cargamento de comida. Comenzando con un depósito vacío de comida, él
ordenó y recibió F1 (1 <= F1 <= 1,000,000) kilogramos de comida.
Desafortunadamente, él no está seguro de cuando llegó la comida
exactamente. De los F1 kilogramos, F2 (1 <= F2 <= F1) kilogramos de
comida permanecen en el día D (1 <= D <= 2,000). El debe determinar el
día más reciente en que su cargamento podría haber llegado.

Cada una de sus C (1 <= C <= 100) vacas come exactamente 1 kilogramo de
comida cada día. Por diferentes razones, las vacas llegan un día y se van
en otro, por lo tanto los días podrían tener diferentes consumos de
comida. Los datos de entrada dicen en que días cada vaca estaba presente.
Cada vaca comió comida del depósito del Granjero Juan el día en que ella
llegó y también el día en que ella se fue.

Dado que hoy es el día D, determine el mínimo número de días que deben de
haber pasado desde su último cargamento. Las vacas ya han comido hoy, y
el cargamento llegó antes de que las vacas comenzaran a comer.

NOMBRE DEL PROBLEMA: fcount

FORMATO DE ENTRADA:

* Línea 1: Cuatro enteros seprados por espacios: C, F1, F2 y D.

* Líneas 2..C+1: La línea i+1 contiene dos enteros separados por espacio
    describiendo la presencia de una vaca. El primer entero dice el primer
    día en que la vaca estuvo en la granja; el segundo dice el día final
    de su presencia. Cada día está en el rango 0..2,000.

ENTRADA EJEMPLO (archivo fcount.in):

3 14 4 10
1 9
5 8
8 12

DETALLES DE LA ENTRADA:

El cargamento más reciente fue de 14 kilogramos de comida, y el Granjero
Juan tiene 4 kilogramos sobrantes. El tuvo tres vacas que comieron comida
por alguna cantidad de tiempo durante los últimos 10 días.

FORMATO DE SALIDA:

El último día en que el cargamento podría haber llegado, un entero que
será siempre positivo.

SALIDA EJEMPLO (archivo fcount.out):

6

DETALLES DE LA SALIDA:

Si el Granjero Juan comenzó con 14 kg de comida en el día 6,
entonces en los días 6 y 7, se hubieran comido dos kilogramos cada día.
En el día 8, se hubieran comido tres kilogramos. En el día 9, se hubieran
comido dos kilogramos. En el día 10, se hubiera comido un kilogramo. Por
lo tanto, el total comido hubiera sido 2 + 2 + 3 + 2 + 1 = 10, dejándolo
con 4 kilogramos.
*/
