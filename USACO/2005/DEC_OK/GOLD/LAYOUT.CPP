/*
Alfonso Alfonso Peterssen
4 - 8 - 2007
USACO 2005 DEC Gold "Distribución"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXV 1000
#define MAXE 20000
#define oo 1000000000

int V, E, E1, E2, i, j, sol;
int u, v, w;
int C[MAXV];
struct edge {
  int A, B, len;
  edge ( int u = 0, int v = 0, int w = 0 )
  : A ( u ), B( v ), len( w ) {}
} ls[MAXE];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d %d", &V, &E1, &E2 );

  for ( i = 0; i < E1; i++ ) {
    scanf( "%d %d %d", &u, &v, &w );
    ls[E++] = edge( u - 1, v - 1, w );
  }

  for ( i = 0; i < E2; i++ ) {
    scanf( "%d %d %d", &u, &v, &w );
    ls[E++] = edge( v - 1, u - 1, -w );
  }

  fill_n( C, V, oo );
  C[0] = 0;

  /* Bellman-Ford */
  for ( i = 0; i < V - 1; i++ )
    for ( j = 0; j < E; j++ )
      C[ ls[j].B ] <?= C[ ls[j].A ] + ls[j].len;

  sol = C[V - 1];
  if ( sol == oo ) sol = -2;

  for ( j = 0; j < E; j++ )
    if ( C[ ls[j].A ] + ls[j].len < C[ ls[j].B ] )
      sol = -1;

  printf( "%d\n", sol );

  return 0;
}

/*
Problema 3: Distribución [Brian Dean, 2004]

Como todos los demás, a las vacas les gusta estar junto a sus amigas
cuando están haciendo cola por comida. GJ tiene N (1 <= N <= 1,000)
vacas numeradas 1..N que están paradas en una línea recta esperando
comida. Las vacas están paradas en el mismo orden en que están
numeradas, y como ellas son algo insistentes, es posible que dos o más
vacas pueden estar alineadas exactamente en la misma posición (esto
es, si pensamos en que cada vaca está ubicada en alguna coordenada en
una línea numérica, entonces es posible que dos o más vacas compartan
la misma coordenada).

Algunas vacas son amigas entre ellas y quieren estar dentro de cierta
distancia en la alineación. Algunas realmente no se caen bien y
quieren estar separadas al menos cierta distancia. Una lista de ML (1
<= ML <= 10,000) restricciones describen cuales son amigas, una lista
subsecuente de MD restricciones (1 <= MD <= 10,000) describe cuales
vacas no se caen bien.

Su trabajo es calcular, si es posible, la distancia máxima posible
entre la vaca 1 y la vaca N que satisface las restricciones de
distancia.

NOMBRE DEL PROBLEMA: layout

FORMATO DE ENTRADA:

* Línea 1: Tres enteros separados por espacios: N, ML y MD.

* Líneas 2..ML+1: Cada línea contiene tres enteros positivos separados
        por espacios: A, B, y D, con 1 <= A < B <= N. Las vacas A y B
        deben estar a lo más D (1 <= D <= 1,000,000) unidades aparte.

* Líneas ML+2..ML+MD+1: Cada línea contiene tres enteros positivos
        separados por espacios: A, B, y D, con 1 <= A < B <= N. Las
vacas
        A y B deben estar al menos D (1 <= D <= 1,000,000) unidades
        aparte.

ENTRADA EJEMPLO (archivo layout.in)

4 2 1
1 3 10
2 4 20
2 3 3

DETALLES DE LA ENTRADA

Hay 4 vacas. Las vacas #1 y #3 no deben estar alejadas en más de 10
unidades, las vacas #2 y #4 no deben estar más de 20 unidades aparte,
y las vacas #2 y #3 no se caen bien y deben estar alejadas en no menos
de 3 unidades aparte.

FORMATO DE SALIDA:

* Línea 1: Un solo entero. Si no es posible ninguna alineación, dé
         como salida –1. Si las vacas 1 y N pueden estar
         arbitrariamente lejos, dé como salida –2. En otro caso, dé
         como salida la distancia más grande posible entre las vacas
         1 y N.

EJEMPLO DE SALIDA (archivo layout.out):

27

DETALLES DE LA SALIDA:

La mejor distribución, en términos de coordenadas en una línea
numérica, es poner la vaca #1 en 0, la vaca #2 en 7, la vaca #3 en 10,
y la vaca #4 en 27.
*/
