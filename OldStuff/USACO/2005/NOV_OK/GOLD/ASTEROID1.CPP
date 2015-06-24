/*
Alfonso Alfonso Peterssen
12 - 8 - 2007
USACO 2005 NOV Gold "Asteroides"
La implementacion de siempre
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXV 1010

int V, E, i, j, k, sol;
int src, snk;
int prev[MAXV];
int cap[MAXV][MAXV];
int S, Q[MAXV]; /* Simple Queue */

  bool augment() {

    int v, x;
    memset( prev, 0, sizeof( prev ) );

    Q[ S = 1 ] = src;
    while ( S && !prev[snk] ) {

      v = Q[S--];

      for ( x = 1; x <= V; x++ )
        if ( !prev[x] && cap[v][x] > 0 ) {
          prev[x] = v;
          if ( x == snk ) break;
          Q[++S] = x;
        }
    }

    if ( !prev[snk] ) return false;

    for ( x = snk; x != src; x = prev[x] )
      cap[ prev[x] ][x]--, cap[x][ prev[x] ]++;

    return true;
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> V >> E;

  src = 2 * V + 1, snk = src + 1;

  for ( i = 0; i < E; i++ ) {
    fin >> j >> k;
    cap[src][j] = 1;
    cap[j][V + k] = 1;
    cap[V + k][snk] = 1;
  }

  V = 2 * V + 2;

  while ( augment() ) sol++;

  fout << sol << endl;

  return 0;
}

/*
Problema 1: Asteroides [Gary Sivak, 2004]


Bessie quiere navegar en su nave espacial a través de un campo
peligroso de asteroides que tiene la forma de una retícula N x N (1 <=
N <= 500). La retícula contiene K asteroides (1 <= K <= 10,000), los
cuales están convenientemente ubicados en los puntos de intersección
de la retícula.

Afortunadamente, Bessie tiene un arma poderosa que puede vaporizar
todos los asteroides en cualquier fila o columna dada de la retícula
con un solo disparo. Esta arma es algo cara, por lo tanto ella desea
usarla esporádicamente. Dada la ubicación de todos los asteroides en
el campo, encuentre el mínimo número de disparos que Bessie debe hacer
para eliminar todos los asteroides

NOMBRE DEL PROBLEMA: asteroid

FORMATO DE ENTRADA:

* Línea 1: Dos enteros N y K, separados por un solo espacio

* Líneas 2..K+1: Cada línea contiene dos enteros separados por un
espacio
        R y C (1 <= R, C <= N) denotando las coordenadas fila y
columna
        de un asteroide.

ENTRADA EJEMPLO (archivo asteroid.in):

3 4
1 1
1 3
2 2
3 2

DETALLES DE LA ENTRADA:

El siguiente diagrama representa los datos, donde "X" es un asteroide
y "." es un espacio vacío:
X.X
.X.
.X.


FORMATO DE SALIDA:


* Línea 1: El entero que representa el número mínimo de veces que
Bessie
        debe disparar.

SALIDA EJEMPLO (archivo asteroid.out):

2

DETALLES DE LA SALIDA:

Bessie debe disparar a través de la fila 1 para destruir los
asteroides en (1, 1) y (1, 3), y luego ella puede disparar en la
columna 2 para destruir los asteroides en (2, 2) y (3, 2).
*/
