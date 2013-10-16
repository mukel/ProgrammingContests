/*
Alfonso Alfonso Peterssen
8 - 9 - 2007
USACO 2006 JAN Bronze "Removiendo Montículos"
*/
#include <cstdio>

#define problem "d"
#define MAXN 50001

int N, i;
int stump[MAXN];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d", &N );
  for ( i = 0; i < N; i++ )
    scanf( "%d", &stump[i] );

  stump[N] = stump[N - 1];
  for ( i = 0; i < N; i++ ) {
    while ( stump[i] < stump[i + 1] ) i++;
    printf( "%d\n", i + 1 );
    while ( stump[i] > stump[i + 1] ) i++;
  }

  return 0;
}

/*
Problema 11: Removiendo Montículos [Graham Poulter/SACO, 2005]

Siempre pensando en la experiencia de pasteo de las vacas, el Granjero
Juan (GJ) ha encontrado que él debe remover N (1 <= N <= 50,000)
montículos invisibles del pastizal. Los montículos están convenientemente
arreglados en una línea recta y numerados 1..N con cada montículo
teniendo alguna altura H_i (1 <= H_i <= 10,000).
GJ usará los explosivos tradicionales para destruir los montículos. Estos
explosivos están formulados para destruir montículos adyacentes en tanto
estos montículos adyacentes sean estrictamente más cortos que el
montículo más cercano que esté siendo destruido. La explosión puede
continuar pasando al montículo más cercano adyacente al montículo
adyacente siguiente si es aún más corto que el montículo más cercano
recién destruido. Tan pronto como un montículo encontrado por la
explosión no es más corto, no más destrucción ocurre en ese lado del
montículo objeto (el otro lado sigue las mismas reglas con cualesquiera
montículos que aparezcan ahí).
Considere una línea de nueve montículos con estas alturas:

               1 2 5 4 3 3 6 6 2
Si GJ vuela el tercer montículo (con altura 5), entonces el segundo
montículo también será destruido (altura 2) y el primer montículo (altura
1) también será destruido. De manera similar, el cuarto montículo (altura
4) y el quinto montículo (altura 3) serán destruidos desde que ellos son
sucesivamente más cortos, dejando la línea como esto:

              * * * * * 3 6 6 2
Dos explosiones más (en los montículos 7 y 8) destruirán el resto.
Ayude a GJ a determinar el número mínimo de cargas de explosivos que él
necesita para destruir los montículos.

NOMBRE DEL PROBLEMA: stumps

FORMATO DE ENTRADA:

* Lìnea 1: Un solo entero, N

* Lìneas 2..N+1: La línea i+1 contiene H_i

ENTRADA EJEMPLO (archivo stumps.in):

9
1
2
5
4
3
3
6
6
2


FORMATO DE SALIDA:

* Líneas 1..?: Cada línea contiene un entero el cual es el índice de un
       montículo a ser volado. Los índices deben ser mostrados en orden
       ascendente.

SALIDA EJEMPLO (archivo stumps.out):

3
7
8
*/
