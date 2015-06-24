/*
Alfonso Alfonso Peterssen
21 - 9 - 2007
USACO 2006 OCT Open "Tesoros de Tartas Vacunas"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXC 102
#define oo 1000000000

int F, C, i, j;
int dp[MAXC][MAXC];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &F, &C );

  for ( i = 1; i <= F; i++ )
    for ( j = 1; j <= C; j++ ) {
      scanf( "%d", &dp[i][j] );
      if ( j < i ) dp[i][j] = -oo;
    }

  for ( j = 1; j <= C; j++ )
    for ( i = 1; i <= j; i++ )
      dp[i][j] += dp[i][j - 1] >? dp[i - 1][j - 1] >? dp[i + 1][j - 1];

  printf( "%d\n", dp[F][C] );

  return 0;
}

/*
Problema 4: Tesoros de Tartas Vacunas [Kolstad, 2006]

¡Las vacas han estado ocupadas horneando tartas que contienen monedas
de oro! Cada tarta contienen algún número Ni (1 <= Ni <= 25) de monedas
de oro que está pulcramente rotulado en la corteza.

Las vacas han puesto las tartas exactamente en un arreglo de R filas
(1 <= R <= 100) y C columnas (1 <= C <= 100) en el prado. Usted está en
el prado en la posición (R=1, C=1) y ha recogido las monedas de oro de
la tarta que está ahí. Usted debe ir al otro lado del prado, moviéndose
una columna hacia el punto final (el cual está en la ubicación (R,C)) en
cada movimiento que usted haga. Cuando usted avance a una nueva columna,
usted puede permanecer en la misma fila o cambiarse de fila, pero en no
más de 1 (esto es, de (r,c) usted puede moverse a  (r+1,c-1),(r+1, c),
o (r+1,c+1). Por supuesto, usted no quiere dejar el prado sin
conseguir algunas monedas de oro , y usted debe terminar en (R,C).

Dado un mapa del prado, ¿cuál es la cantidad más grande de monedas de oro
que usted puede recoger?

A manera de ejemplo, considere este campo de tartas conteniendo monedas
de oro:

Comienzo -> 6 5 3 7 9 2 7
            2 4 3 5 6 8 6
            4 9 9 9 1 5 8 <-fin

Aquí hay un camino:

Comienzo -> 6 5 3 7 9 2 7
            \
            2 4 3 5 6 8 6
               \   / \
            4 9 9-9 1 5-8 <-fin


El camino mostrado da 6+4+9+9+6+5+8 = 47 monedas de oro. El camino de a
continuación es aún mejor y da 50 monedas, lo cual es lo mejor posible.

comienzo-> 6 5 3 7 9 2 7
           \
           2 4 3 5 6-8 6
              \   /   \
           4 9 9-9 1 5 8 <-fin

 NOMBRE DEL PROBLEMA: pie1

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por espacios, respectivamente R y C

* Líneas 2..R+1: Cada línea contiene C enteros separados por espacio en
       el orden obvio


ENTRADA EJEMPLO (archivo pie1.out):

3 7
6 5 3 7 9 2 7
2 4 3 5 6 8 6
4 9 9 9 1 5 8



FORMATO DE SALIDA:

* Una sola línea que es el máximo número de monedas de oro que se pueden
recoger.

SALIDA EJEMPLO (archivo pie1.out):

50
*/
