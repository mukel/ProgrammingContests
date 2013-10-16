/*
Alfonso Alfonso Peterssen
8 - 10 - 2007
PSN 2004 #90 "Mapas Marcianos"
El arbol esta un tin mejor que el habitual.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 10000
#define MAXCOORD 30000

int N, i, lastx, total_area;
int lo, hi, flag;
int marked[ 3 * MAXCOORD ], len[ 3 * MAXCOORD ];

struct event {

  int X, Y1, Y2, flag;

  bool operator < ( const event &e ) const {
    return X < e.X;
  }
} ls[ 2 * MAXN ];

  void mark( int v, int start, int end ) {

    if ( lo <= start && hi >= end )
      len[v] += flag;
    else {
      int mid = ( start + end ) / 2;
      if ( lo <= mid ) mark( v * 2, start, mid );
      if ( hi > mid ) mark( v * 2 + 1, mid + 1, end );
    }

    if ( len[v] > 0 )
      marked[v] = end - start + 1;
    else
      if ( start < end )
           marked[v] = marked[v * 2] + marked[v * 2 + 1];
      else marked[v] = 0;
  }

int main() {

  scanf( "%d", &N );
  for ( i = 0; i < N; i++ ) {
    int x1, x2, y1, y2;
    scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
    ls[i] = ( event ) { x1, y1, y2, 1 };
    ls[N + i] = ( event ) { x2, y1, y2, -1 };
  }

  sort( ls, ls + 2 * N );

  lastx = ls[0].X;
  for ( i = 0; i < 2 * N; i++ ) {

    total_area += ( ls[i].X - lastx ) * marked[1];
    lastx = ls[i].X;

    /* Marks lo..hi -> flag */
    lo = ls[i].Y1 + 1;
    hi = ls[i].Y2;
    flag = ls[i].flag;

    mark( 1, 0, MAXCOORD );
  }

  printf( "%d\n", total_area );

  return 0;
}

/*
90¦ Mapas Marcianos.                                       Grecia 2004
----------------------------------------------------------------------

En el año 2051, varias expediciones a Marte han explorado diferentes
áreas del planeta rojo y producido mapas de estas áreas. La BaSA
(Baltic Space Agency) tiene un plan ambicioso: a ellos les
gustaría producir un mapa del planeta completo. Para calcular el
esfuerzo necesario, ellos necesitan conocer el tamaño total del área
para la cual el mapa ya existe. Su tarea es escribir un programa que
calcule esta área.

Tarea

Escribir un programa que:

. lea la descripción de la forma del mapa del fichero de entrada
  MAR.IN,
. calcule el área total cubierta por el mapa,
. escriba el resultado hacia el fichero de salida MAR.OUT.

Entrada

El fichero de entrada MAR.IN comienza con una línea conteniendo un
entero simple N (1 <= N <= 10000) el número de mapas disponibles. Cada
una de las siguientes N líneas describe un mapa. Cada una de estas
líneas contiene cuatros enteros X1, Y1, X2, Y2 (0 <= X1 <= X2 <=
30000, 0 <= Y1 <= Y2 <= 30000). El valor (X1, Y1) y (X2, Y2) son las
coordenadas de, respectivamente, la esquina inferior izquierda y la
superior derecha del área mapeada. Cada mapa tiene forma rectangular,
y sus lados son paralelos a los ejes X y Y, del sistema de
coordenadas.

Salida

El fichero de salida MAR.OUT debe contener un entero A, el área total
explorada (esta es el área de todos los rectángulos).

Ejemplo de entrada y salida.

+-------------+  +---------+
¦ MAR.IN      ¦  ¦ MAR.OUT ¦
+-------------¦  +---------¦
¦ 2           ¦  ¦  225    ¦
¦ 10 10 20 20 ¦  +---------+
¦ 15 15 25 30 ¦
+-------------+
*/
