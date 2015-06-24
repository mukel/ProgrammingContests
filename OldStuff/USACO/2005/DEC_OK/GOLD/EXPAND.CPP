/*
Alfonso Alfonso Peterssen
5 - 8 - 2007
USACO 2005 DEC Gold "Expansión de Establo"
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXN 25000

int N, P, i;
bool crap[MAXN], mark[MAXN];

struct point {

  int X, Y, id;

  point( int a = 0, int b = 0, int c = 0 )
  : X( a ), Y( b ), id( c ) {}

  bool operator < ( const point &p ) const {
    return X < p.X || ( X ==p.X && Y < p.Y );
  }

} ls[4 * MAXN];

  void sweep_line() {

    sort( ls, ls + P );

    int i, j = 1;
    mark[ ls[0].id ] = true;

    for ( i = 1; i < P; i++ ) {
      int a = ls[i].id,
          b = ls[i - 1].id;

      if ( a != b &&
         ( ls[i].X == ls[i - 1].X && ls[i].Y == ls[i - 1].Y ) ) {
        crap[a] = true;
        crap[b] = true;
      }

      if ( mark[a] ^= true ) j++;
      else if ( --j || a != b ) crap[a] = true;
    }
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ ) {
    int x1, x2, y1, y2;
    fin >> x1 >> y1 >> x2 >> y2;
    ls[P++] = point( x1, y1, i );
    ls[P++] = point( x1, y2, i );
    ls[P++] = point( x2, y1, i );
    ls[P++] = point( x2, y2, i );
  }

  sweep_line();

  for ( i = 0; i < P; i++ )
    swap( ls[i].X, ls[i].Y );

  sweep_line();

  fout << count( crap, crap + N, false ) << endl;

  return 0;
}

/*
Problema 2: Expansión de Establo [Brian Dean, 2005]

El Granjero Juan tiene N (1 <= N <= 25,000) establos rectangulares en
su granja, con todos los lados paralelos a los ejes X y Y y con las
coordenadas de las esquinas enteras en el rango 0..1,000,000,000.
Estos establos no se superponen a pesar que ellos pueden compartir
esquinas y/o paredes con otros establos.

Como él tiene vacas extras para ordeñar este año, a GJ le gustaría
expandir algunos de sus establos. Un establo tiene espacio donde
expandirse si no comparte una esquina o una pared con ningún otro
establo. Esto es, GJ puede expandir un establo si todas las cuatro
paredes pueden ser empujadas hacia fuera al menos alguna cantidad sin
invadir otro establo. Si dos establos se encuentran en una esquina,
ninguno de los dos puede expandirse.

Por favor determine cuántos establos tienen espacio para expandirse.

NOMBRE DEL PROBLEMA: expand

FORMATO DE ENTRADA:

* Línea 1: Un solo entero, N.

* Líneas 2..N+1: Cuatro enteros separados por espacios A; B, C y D,
        describiendo un establo. La esquina inferior izquierda del
        establo está en (A, B), y la esquina superior derecha está
        en (C, D).

ENTRADA EJEMPLO (archivo expand.in)

5
0 2 2 7
3 5 5 8
4 2 6 4
6 1 8 6
0 0 8 1

DETALLES DE LA ENTRADA

Hay 5 establos. El primer establo tiene su esquina inferior izquierda
en (0, 2) y su esquina superior derecha en (2, 7), y así
sucesivamente.

FORMATO DE SALIDA:

* Línea 1: Un solo entero que es el número de establos que pueden
        expandirse

EJEMPLO DE SALIDA (archivo expand.out):

2

DETALLES DE LA SALIDA:

Solo dos establos pueden ser expandidos – los dos primeros listados en
la entrada. Todos los otros establos están en contacto con al menos
uno de los otros establos.
*/
