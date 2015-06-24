/*
Alfonso Alfonso Peterssen
13 - 8 - 2007
USACO 2005 MAR Silver "Sin Heno"
MST -> Kruskal O( E lg E )
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXV 2001
#define MAXE 10000

int V, E, i, j, sol;
int P[MAXV];
struct edge {

  int a, b, cost;

  bool operator < ( const edge &e ) const {
    return cost < e.cost;
  }

} ls[MAXE];

  int find( int x ) {
    if ( x != P[x] ) P[x] = find( P[x] );
    return P[x];
  }

  void join( int x, int y ) {
    P[ find( x ) ] = find( y );
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> V >> E;
  for ( i = 0; i < E; i++ )
    fin >> ls[i].a >> ls[i].b >> ls[i].cost;

  sort( ls, ls + E );
  for ( i = 1; i <= V; i++ )
    P[i] = i;

  j = V - 1;
  for ( i = 0; j; i++ )
    if ( find( ls[i].a ) != find( ls[i].b ) ) {
      join( ls[i].a, ls[i].b );
      sol = ls[i].cost;
      j--;
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
