/*
Alfonso Alfonso Peterssen
21 - 9 - 2007
USACO 2006 OCT Open "Construyendo el Foso"
*/
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;

#define problem "d"
#define MAXN 5000
#define sqr( x ) ( ( x ) * ( x ) )

int N, i, len;
int cvxhull[MAXN];
struct point { int X, Y; } ls[MAXN];
double sol;

  double dist( const point &p1,
               const point &p2 ) {
    return sqrt( sqr( p1.X - p2.X ) +
                 sqr( p1.Y - p2.Y ) );
  }

  int cross( const point &o,
             const point &c,
             const point &m ) {
    return ( c.X - o.X ) * ( m.Y - o.Y ) -
           ( m.X - o.X ) * ( c.Y - o.Y );
  }

  bool cw_cmp( const point &p1,
               const point &p2 ) {

    int cp = cross( ls[0], p1, p2 );

    if ( cp == 0 )
         return dist( ls[0], p1 ) < dist( ls[0], p2 );
    else return cp > 0;
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ )
    fin >> ls[i].X >> ls[i].Y;

  /* Graham Scan */
  for ( i = 1; i < N; i++ )
    if ( ls[i].Y < ls[0].Y ||
       ( ls[i].Y == ls[0].Y && ls[i].X < ls[0].X ) )
         swap( ls[0], ls[i] );

  sort( ls + 1, ls + N, cw_cmp );

  cvxhull[len++] = 0;
  cvxhull[len++] = 1;

  for ( i = 2; i < N; i++ ) {
    while ( ( len > 2 ) &&
            cross( ls[ cvxhull[len - 2] ],
                   ls[ cvxhull[len - 1] ],
                   ls[i] ) < 0 )
                   len--;

    cvxhull[len++] = i;
  }

  cvxhull[len] = 0;
  for ( i = 0; i < len; i++ )
    sol += dist( ls[ cvxhull[i] ],
                 ls[ cvxhull[i + 1] ] );

  fout.precision( 2 );
  fout << fixed << sol << endl;

  return 0;
}

/*
Problema 6: Construyendo el Foso [Eric Price, 2006]


Para repeler la invasión de zarigüeyas sedientas, el Granjero Juan (GJ)
quiere construir un foso alrededor de su granja. El posee N
(8 <= N <= 5,000) pozos de agua, y excavará el foso como líneas rectas
entre pares de ellos. Su foso debe proteger (rodear) todos los pozos;
cada pozo deberá estar dentro del foso, y el foso debe ser cerrado.

Excavar el foso es un trabajo costoso, y GJ quiere que su foso tenga la
mínimalongitud posible. Encuentre la longitud del foso más pequeño que él
pueda construir.

Los pozos están ubicados en coordenadas enteras en el rango (1..45,000,
1..45,000). GJ se ha dado cuenta que no hay tres pozos en la misma línea
recta.

Considere esta cuadrilla con a lo más dos docenas de '*'s representando
pozos:

...*-----------------*......
../..........*........\.....
./.....................\....
*......................*\...
|..........*........*....\..
|*........................\.
|..........................*
*..........................|
.\*........................|
..\.....................*..|
...\........*............*.|
....\..................*...*
.....\..*..........*....../.
......\................../..
.......*----------------*...

Las líneas envolventes forman el camino más corto posible que encierra este
conjunto de pozos.

Los desplazamientos lineales, comenzando en la línea superior son : (18,0),
(6,-6), (0,-5), (-3,-3), (-17,0), (-7,7), (0,4), y (3,3).  Esto da una
distancia de 70.8700576850888(...).. Nuestra salida imprimirá solo dos
decimales, por lo tanto la distancia será reportada como 70.87.



NOMBRE DEL PROBLEMA: moat

FORMATO DE ENTRADA:

* Línea  1: Un solo entero, N

* Líneas 2..N+1: Dos enteros separados por espacio, X_i y Y_i que especifican
      la ubicación de un pozo

ENTRADA EJEMPLO (archivo moat.in):

20
2 10
3 7
22 15
12 11
20 3
28 9
1 12
9 3
14 14
25 6
8 1
25 1
28 4
24 12
4 15
13 5
26 5
21 11
24 4
1 8

FORMATO DE SALIDA:

* Línea 1: Un solo entero D, la longitud más pequeña posible de un foso.
       Imprima este número con dos números decimales.

SALIDA EJEMPLO (archivo moat.out):

70.87
*/
