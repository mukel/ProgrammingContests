/*
Alfonso Alfonso Peterssen
21 - 9 - 2007
USACO 2006 NOV Bronze "La Toca Vacuna Seria"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXN 1000
#define sqr( x ) ( ( x ) * double( x ) )

int N, i, j, k, start;
struct cow {
  int X, Y, id, next, last;
} ls[MAXN];

  double dist( int i, int j ) {
    return sqr( ls[i].X - ls[j].X ) + sqr( ls[i].Y  - ls[j].Y );
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ ) {
    fin >> ls[i].X >> ls[i].Y;
    ls[i].id = ls[i].next = i + 1;
    ls[i].last = i - 1;
  }

  ls[0].last = N - 1;
  ls[N - 1].next = 0;

  for ( i = 0; i < N - 1; i++ ) {

    int min = ls[start].next;
    for ( j = ls[start].next; j != start; j = ls[j].next )
      if ( dist( start, j ) < dist( start, min ) )
        min = j;

    j = ls[min].last;
    k = ls[min].next;

    ls[j].next = k;
    ls[k].last = j;

    start = ls[start].next;
  }

  fout << ls[start].id << endl;

  return 0;
}

/*
Problema 13: La Toca Vacuna Seria [Johan Wiggins, 2006]

Las N (1 <= N <= 1000) vacas del Granjero Juan (convenientemente
numeradas 1..N) van a jugar el Juego de La Toca Vacuna Seria. En este
juego, cada vaca elige un punto de la cuadrícula de pasteo (-7500 <= X <=
7500, -7500 <= Y <= 7500) de tal manera que las distancias entre todos
los pares de las vacas son únicas.

Las vacas juegan por turnos, comenzando con la vaca  #1 y continuando con
las vacas #2, #3, y así sucesivamente (en tanto las vacas estén aún en el
juego). Cuando es el turno de jugar de una vaca, ella encuentra la vaca
más cercana que aún esté jugando, camina hasta donde está ella, la toca,
y luego vuelve a su posición original. Tan pronto como una vaca es
tocada, ella está fuera del juego.

El juego termina cuando solo queda una vaca, y ella es declarada la
ganadora.

El Granjero Juan está apostando con los granjeros vecinos cuál vaca va a
ganar, por lo tanto a él le gustaría conocer con anterioridad cuál vaca
va a ganar. Escriba un programa que leerá la descripción de las
posiciones de las vacas y determinará la ganadora.

NOMBRE DEL PROBLEMA: cowtag

FORMATO DE ENTRADA:

* Línea 1: Un solo entero N, el número de vacas

* Líneas 2..N+1: La línea i+1 contiene dos enteros separados por espacio
     que describen la ubicación de la vaca i.

Entrada Ejemplo (archivo cowtag.in):

3
0 0
0 3
4 3

DETALLES DE LA ENTRADA:

Tres vacas en (0, 0), (0, 3) y (4, 3).

FORMATO DE SALIDA:

* Línea 1: El número de la vaca ganadora.

ARCHIVO EJEMPLO (archivo cowtag.out):

3

DETALLES DE LA SALIDA:

La vaca 1 va primero y toca la vaca más cercana, la vaca 2. La vaca 2
queda eliminada y por lo tanto no obtiene un turno. La vaca 3 entonces
toca la única vaca restante, la vaca 1. Ella es la última que queda, por
lo tanto ella gana.
*/
