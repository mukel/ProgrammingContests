/*
Alfonso Alfonso Peterssen
12 - 8 - 2007
USACO 2005 NOV "Pasteando a la Carrera"
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXN 1000
#define dist( i, j ) ( dist[j] - dist[i] )

int N, S, i, j, k;
int dist[MAXN];
int L[MAXN][MAXN], R[MAXN][MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> S;
  for ( i = 0; i < N; i++ )
    fin >> dist[i];

  sort( dist, dist + N );

  for ( i = 0; i < N; i++ )
    L[i][i] = R[i][i] = abs( S - dist[i] ) * N;

  for ( k = 1; k < N; k++ )
    for ( i = 0; i < N - k; i++ ) {

      j = i + k;

      L[i][j] = min( L[i + 1][j] + dist( i, i +  1 ) * ( N - k ),
                     R[i + 1][j] + dist( i, j ) * ( N - k ) );

      R[i][j] = min( R[i][j - 1] + dist( j - 1, j ) * ( N - k ),
                     L[i][j - 1] + dist( i, j ) * ( N - k ) );
    }

  fout << min( L[0][N - 1], R[0][N - 1] ) << endl;

  return 0;
}

/*
Problema 2: Pasteando a la Carrera [Brian Dean, 2005]

Un campo grande, lineal, tiene N (1 <= N <= 1,000) montículos de pasto
en ubicaciones enteras que serán tratadas como posiciones enteras en
una línea numérica.

Bessie comienza en alguna ubicación entera L en la línea numérica (1
<= L <= 1,000,000) y recorre la línea numérica en las dos direcciones
posibles (algunas veces cambiado su dirección) con el propósito de
alcanzar y comer todos los montículos. Ella se mueve con una velocidad
constante (una unidad de distancia en una unidad de tiempo), y come un
montículo de manera instantánea cuando lo encuentra.

Los montículos que no son comidos durante un tiempo se rancian.
Decimos que la ``ranciedad'' de un montículo es la cantidad de tiempo
que pasa desde que Bessie comienza a moverse hasta que ella se come el
montículo. Bessie quiere minimizar la ranciedad total de todos los
montículos que ella come.

Encuentre la cantidad mínima de ranciedad que Bessie puede conseguir
comiendo todos los montículos.

NOMBRE DEL PROBLEMA: ontherun

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por un espacio: N y L.

* Líneas 2..N+1: Cada línea contiene un solo entero dando la posición
P
        de un montículo (1 <= P <= 1,000,000).


ENTRADA EJEMPLO (archivo ontherun.in)

4 10
1
9
11
19

DETALLES DE LA ENTRADA

Cuatro montículos: en 1, 9, 11, y 19. Bessie comienza en la posición
10.

FORMATO DE SALIDA:

* Línea 1: Un solo entero: la ranciedad total mínima que Bessie puede
        conseguir comiendo todos los montículos.

EJEMPLO DE SALIDA (archivo ontherun.out):

44

DETALLES DE LA SALIDA:

Bessie puede seguir esta ruta:

* comenzar en la posición 10 en el tiempo 0
* moverse a la posición  9, llegando en el tiempo 1
* moverse a la posición  11, llegando en el tiempo 3
* moverse a la posición 19, llegando en el tiempo 11
* moverse a la posición 1, llegando en el tiempo 29


que le da una ranciedad total de 1+3+11+29 = 44. Hay otras rutas con
la misma ranciedad total, pero ninguna ruta con una menor.
*/
