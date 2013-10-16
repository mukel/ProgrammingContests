/*
Alfonso Alfonso Peterssen
1 - 9 - 2007
USACO 2006 NOV Gold "Bloques de Caminos"
*/
#include <cstdio>
#include <queue>
using namespace std;

#define problem "d"
#define MAXV 5001
#define MAXE 100001
#define oo 1000000000

int V, E, i, j, k, cost;
pair< int, int > dist[MAXV];
int P[MAXV];

struct node {
  int B, len, next;
} ls[ 2 * MAXE ];

queue< int > Q;

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &V, &E );
  for ( i = 1; i <= E; i++ ) {

    scanf( "%d %d %d", &j, &k, &cost );

    ls[i] = ( node ) { k, cost, P[j] };
    P[j] = i;

    ls[E + i] = ( node ) { j, cost, P[k] };
    P[k] = E + i;
  }

  for ( i = V; i; i-- )
    dist[i] = make_pair( oo, oo );

  /* BFS */
  dist[1].first = 0;
  for ( Q.push( 1 ); !Q.empty(); ) {

    j = Q.front(); Q.pop();

    for ( i = P[j]; i; i = ls[i].next ) {

      k = ls[i].B;

      int cost1 = dist[j].first + ls[i].len,
          cost2 = dist[j].second + ls[i].len;

      if ( cost1 < dist[k].first ) {
        dist[k].first = cost1;
        Q.push( k );
      }

      if ( cost1 > dist[k].first &&
           cost1 < dist[k].second ) {
        dist[k].second = cost1;
        Q.push( k );
      }

      if ( cost2 < dist[k].second ) {
        dist[k].second = cost2;
        Q.push( k );
      }

    }
  }

  printf( "%d\n", dist[V].second );

  return 0;
}

/*
Problema 3: Bloques de Caminos [Mirek Michalski, 2004]

Bessie se ha mudado a una granja pequeña y algunas veces disfruta
volver a visitar a una de sus mejores amigas. Ella no quiere regresar
a su viejo hogar muy rápidamente, debido a que a ella le gusta el
paisaje en el camino. Ella ha decidido tomar el segundo camino más
corto en lugar que el camino más corto.

La red de senderos consiste de R (1 <= R <= 100,000) caminos
bidireccionales, cada uno uniendo dos de las N (1 <= N <= 5000)
intersecciones, convenientemente numeradas 1..N. Bessie comienza en la
intersección 1, y su amiga (el destino) está en la intersección N.

El segundo camino más corto puede compartir senderos con cualquiera de
los caminos más cortos, y puede retroceder, esto es usar el mismo
sendero o intersección más de una vez. El segundo camino más corto es
aquel cuya longitud es mayor que la de el(los) camino(s) más corto(s)
(esto es, si existen dos o más caminos mas cortos, el segundo camino
más corto es aquel cuya longitud es mayor que la de estos, pero no
mayor que la de ningún otro camino).

NOMBRE DEL PROBLEMA: block

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por espacio: N y R.

* Líneas 2..R+1: Cada línea contiene tres enteros separados por
     espacio: A, b y D que describen un camino que conecta las
     intersecciones A y B y tiene longitud D (1 <= D <= 5000)

ENTRADA EJEMPLO (archivo block.in)

4 4
1 2 100
2 4 200
2 3 250
3 4 100


FORMATO DE SALIDA:

* Línea 1: La longitud del segundo camino más corto entre el nodo 1 y
     el nodo N.

EJEMPLO DE SALIDA (archivo block.out):

450

DETALLES DE LA SALIDA:

Dos caminos: 1 -> 2 -> 4 (longitud 100+200=300) y 1 -> 2 -> 3 -> 4
(longitud 100+250+100=450)
*/
