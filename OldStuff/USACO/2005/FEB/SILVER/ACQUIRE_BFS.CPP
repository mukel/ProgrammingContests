/*
Alfonso Alfonso Peterssen
28 - 8 - 2007
USACO 2005 FEB Silver "Adquisición de Partes"
*/
#include <cstdio>
#include <queue>
using namespace std;

#define problem "d"
#define MAXV 1001

int V, E, i, j, k;
int len[MAXV], ls[MAXV][MAXV];
int last[MAXV], dist[MAXV];
queue< int > Q;

  void print_path( int x ) {
    if ( x == -1 ) return ;
    print_path( last[x] );
    printf( "%d\n", x );
  }

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &E, &V );
  for ( i = 0; i < E; i++ ) {
    scanf( "%d %d", &j, &k );
    ls[j][ len[j]++ ] = k;
  }

  Q.push( 1 );
  last[1] = -1;

  while ( !Q.empty() && !last[V] ) {

    i = Q.front(); Q.pop();
    for ( j = 0; j < len[i]; j++ ) {

      int x = ls[i][j];

      if ( !last[x] ) {
        dist[x] = dist[i] + 1;
        last[x] = i;
        Q.push( x );
      }
    }
  }

  if ( !last[V] )
    printf( "-1\n" );
  else {
    printf( "%d\n", dist[V] + 1 );
    print_path( V );
  }

  return 0;
}

/*
Problema 6: Adquisición de Partes [Entrenadores, 2004]

Las vacas han sido enviadas en una misión a través del espacio para
adquirir una nueva máquina ordeñadora para su establo. Ellas están
viajando a través de un conglomerado de estrellas conteniendo N (1 <= N
<= 50,000) planetas, cada uno con una tienda.

Las vacas han determinado cuáles de K (1 <= K <= 1,000) tipos de objetos
(numerados 1..K) de cada planeta en el conglomerado desean, y cuáles
productos deben comerciar. Ningún planeta ha desarrollado dinero, por lo
tanto ellos trabajan con el sistema de trueque: todo los intercambios
consisten de que cada parte da exactamente un objeto (presumiblemente de
tipos diferentes).

Las vacas parten de la Tierra con un paquete de heno de alta calidad
(ítem 1), y ellas desean una nueva máquina ordeñadora (ítem K). Ayúdelas
a encontrar la mejor manera de hacer una serie de intercambios en los
planetas del conglomerado para obtener el ítem K. Si esta tarea es
imposible, dé como salida -1.

NOMBRE DEL PROBLEMA: acquire

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por espacios, N y K.

* Líneas 2..N+1: La Línea i+1 contiene dos enteros separados por
    espacio, a_i y b_i respectivamente, que son los productos de
    intercambio del planeta i. El planeta dará el ítem b_i con el
    propósito de recibir el ítem a_i.

ENTRADA EJEMPLO (archivo acquire.in):

6 5
1 3
3 2
2 3
3 1
2 5
5 4

FORMATO DE SALIDA:

* Línea 1: El mínimo número de intercambios T requeridos para obtener la
    máquina ordeñadora, la cual es el ítem K (o -1 si las vacas no pueden
    obtener el ítem K).

* Líneas 2..T+1: La lista ordenada de objetos que las vacas poseen
    durante la secuencia de intercambios.

SALIDA EJEMPLO (archivo acquiere.out):

4
1
3
2
5

DETALLES DE LA SALIDA

Las vacas poseen 4 objetos en total: primero ellas intercambian el objeto
1 por el objeto 3, luego el objeto 3 por el objeto 2, y luego el objeto 2
por el objeto 5.
*/
