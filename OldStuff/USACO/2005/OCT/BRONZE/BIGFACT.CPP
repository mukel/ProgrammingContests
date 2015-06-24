/*
Alfonso Alfonso Peterssen
30 - 8 - 2007
USACO 2005 OCT Bronze "Max Factor"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXN 20001

int T, N, i, j, sol, bigfact;
int max_factor[MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  for ( i = 1; i < MAXN; i++ )
    if ( max_factor[i] < 2 )
      for ( j = i; j < MAXN; j += i )
        max_factor[j] = i;

  for ( fin >> T; T; T-- ) {
    fin >> N;
    if ( max_factor[N] > bigfact ) {
      bigfact = max_factor[N];
      sol = N;
    }
  }

  fout << sol << endl;

  return 0;
}

/*
Problema 12: Max Factor [Hal Burch, 2005]

Para mejorar la organización de su granja, el Granjero Juan rotula
cada una de sus N (1 <= N <= 5,000) vacas con un número serial
distinto en el rango 1..20,000. Desafortunadamente, él es incapaz de
hacer que las vacas interpreten algunos números seriales tan bien como
otras. En particular, una vaca cuyo número serial tenga el factor
primo más grande disfruta la posición social más alta entre las otras
vacas.

(Recuerde que un número primo es simplemente un número que no tenga
divisores excepto 1 y el mismo. El número 7 es un número primo,
mientras que el número 6, siendo divisible por 2 y 3, no lo es).

Dado un conjunto de N (1 <= N <= 5,000) números eriales en el rango
1..20,000, determien aquel que tenga el factor primo más grande.

NOMBRE DEL PROBLEMA: bigfact

FORMATO DE ENTRADA:

* Lìnea 1: Un solo entero, N

* Lìneas 2..N+1: Los números seriales a ser considerados, uno por
        lìnea.

ENTRADA EJEMPLO (archivo bigfact.in):

4
36
38
40
42

FORMATO DE SALIDA:

Línea 1: El entero con el factor primo más grande. Si hay más de
        uno, de cómo salida el que aparezca más temprano en el
        archivo de entrada.


SALIDA EJEMPLO (archivo bigfact.out):

38

DETALLES DE LA SALIDA:

19 es un factor primo de 38. Ningún otro numero tiene un factor primo
más grande.
*/
