/*
Alfonso Alfonso Peterssen
12 - 8 - 2007
USACO 2005 MAR Bronze "Potencias Negativas de Dos"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXLEN 251

int N, len, i, j, r, t;
int pot[MAXLEN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;

  pot[++len] = 1;
  for ( i = 0; i < N; i++ ) {
    for ( j = 1; j <= len; j++ ) {
      t = 5 * pot[j] + r;
      pot[j] = t % 10;
      r = t / 10;
    }
    if ( r ) {
      pot[++len] = r;
      r = 0;
    }
  }

  fout << "0.";
  for ( i = N; i; i-- )
    fout << pot[i];

  fout << endl;

  return 0;
}

/*
Problema 13: Potencias Negativas de Dos [Tradicional, 2005]

Dado un entero N (1 <= N <= 250), imprima el inverso exacto de 2 a la
eNésima potencia. Imprímalo en la forma  "0.x..."  sin ceros
sobrantes.

NOMBRE DEL PROBLEMA: nptwo

FORMATO DE ENTRADA:

* Línea 1: Un solo entero N.

ENTRADA EJEMPLO (archivo nptwo.in):

67

FORMATO DE SALIDA:

* Línea 1: La representación decimal de  1 / (2^N).

SALIDA EJEMPLO (archivo nptwo.out):

0.0000000000000000000067762635780344027125465800054371356964111328125
*/
