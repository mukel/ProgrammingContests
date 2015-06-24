/*
Alfonso Alfonso Peterssen
12 - 8 - 2007
USACO 2005 MAR Silver "Sin Heno"
MST -> Prim O( ( V + E ) lg V )
*/
#include <fstream>
#include <set>
using namespace std;

#define problem "d"
#define MAXV 2001
#define MAXE 10001
#define oo 1000000000

typedef pair< int, int > pii;

int V, E, i, j, sol;
bool mark[MAXV];
int D[MAXV], P[MAXV];
multiset< pii > heap;

struct edge {

  int B, len, next;

  edge ( int x = 0, int y = 0, int z = 0 )
  : B( x ), len( y ), next( z ) {}

} ls[ 2 * MAXE ];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> V >> E;
  for ( i = 1; i <= E; i++ ) {

    int u, v, w;
    fin >> u >> v >> w;

    ls[i] = edge( v, w, P[u] );
    P[u] = i;

    ls[E + i] = edge( u, w, P[v] );
    P[v] = E + i;
  }

  fill_n( D, V + 1, oo );

  /* Prim */
  heap.insert( pii( 0, 1 ) );

  while ( !heap.empty() ) {

    sol >?= ( *heap.begin() ).first;
    j = ( *heap.begin() ).second;
    heap.erase( heap.begin() );
    mark[j] = true;

    for ( i = P[j]; i; i = ls[i].next ) {

      int x = ls[i].B;
      if ( mark[x] ) continue;

      if ( ls[i].len < D[x] ) {
        if ( D[x] != oo )
          heap.erase( heap.find( pii( D[x], x ) ) );
        D[x] = ls[i].len;
        heap.insert( pii( D[x], x ) );
      }
    }

  }

  fout << sol << endl;

  return 0;
}

/*
Problema 8: Sin Heno [Entrenadores, 2004]

Las vacas se han quedado sin heno, un suceso horrible que debe ser
remediado inmediatamente. Bessie quiere recorrer algunas de las N (2
<= N <= 2,000) otras granjas (numeradas 1..N) para investigar su
situación de heno. Ella recorrerá algunos de todos los M (1 <= M <=
10,000) caminos de doble vía cuya longitud no excede 1,000,000,000
que conectan las granjas. Algunas granjas pueden estar conectadas
múltiplemente con caminos de diferentes longitudes.

Bessie está tratando de decidir el tamaño de la cantimplora que ella
necesitará. Ella sabe que necesita una onza de agua por cada unidad de
distancia de un camino. Dado que ella puede obtener más agua en cada
granja, ella únicamente está preocupada por la longitud del camino más
largo. Por supuesto, ella planea su ruta entre granjas de tal manera
que ella minimice la cantidad de agua que ella debe cargar.

Ayude a que Bessie sepa la cantidad más grande de agua que ella tendrá
que cargar: ¿cuál es la longitud del camino más largo que ella tendrá
que recorrer entre cualesquiera dos granjas, presumiendo que ella
elija rutas que minimicen ese número?

NOMBRE DEL PROBLEMA: outofhay

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por espacio, N y M.

* Líneas 2..1+M: La línea i+1 contiene tres enteros separados por
    espacios, A_i, B_i, y L_i, describiendo un camino de A_i a B_i de
    longitud L_i.

ENTRADA EJEMPLO (archivo outofhay.in):

3 3
1 2 23
2 3 1000
1 3 43


FORMATO DE SALIDA:

* Línea 1: Un solo entero que es la longitud del camino más largo que
    necesita ser recorrido.

SALIDA EJEMPLO (archivo outofhay.out):

43

DETALLES DE LA SALIDA:

Con el propósito de llegar a la granja 2, Bessie viaja por un camino
de longitud 23. Para llegar a la granja 3, Bessie viaja por un camino
de longitud 43. Con una capacidad de 43, ella puede viajar a lo largo
de estos caminos dado que ella recarga su cantimplora a capacidad
máxima antes de comenzar un nuevo camino.
*/
