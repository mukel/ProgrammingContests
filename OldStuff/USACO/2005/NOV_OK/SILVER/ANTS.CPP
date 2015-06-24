/*
Alfonso Alfonso Peterssen
12 - 8 - 2007
USACO 2005 NOV Silver "Conteo de Hormigas"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXF 1000
#define MAXB 100001
#define MODULO 1000000

int F, N, A, B, i, j;
int a, b, ants, tmp, sol;
int dp[2][MAXB], cnt[MAXF];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> F >> N >> A >> B;
  for ( i = 0; i < N; i++ ) {
    fin >> j;
    cnt[j - 1]++;
  }

  dp[a][0] = 1;
  for ( i = 0; i < F; i++ ) {

    a = a ^ 1;
    b = a ^ 1;

    tmp = 0;
    ants = ( ants + cnt[i] ) <? B;

    for ( j = 0; j <= ants; j++ ) {
      if ( j > cnt[i] )
        tmp -= dp[b][ j - cnt[i] - 1 ];

      dp[a][j] = tmp =
        ( tmp + dp[b][j] + MODULO ) % MODULO;;
    }
  }

  for ( i = A; i <= B; i++ )
    sol = ( sol + dp[a][i] ) % MODULO;

  fout << sol << endl;

  return 0;
}

/*
Problema 8: Conteo de Hormigas [Jacob Steinhardt, 2005]

Bessie estaba caminando un día alrededor del hormiguero de hormigas y
mirando marchar a las hormigas de un lado a otro mientras almacenaban
comida. Ella se dio cuenta que muchas de las hormigas eran hermanas,
indistinguibles unas de otras. Ella también se dio cuenta que algunas
veces solamente una hormiga iría por comida, algunas veces unas
cuantas, y algunas veces todas ellas. ¡Esto hace un número grande de
conjuntos diferentes de hormigas!

Siendo un poco matemática, Bessie comenzó a pensar. Bessie notó que la
colonia tiene T (1 <= T <= 1,000) familias de hormigas las cuales
están numeradas 1..T. Cada familia tiene un número Ni (1 <= Ni <= 100)
de hormigas. Hay A hormigas entre todas.

¿Cuántos grupos de tamaños S, S+1, ..., B (1 <= S <= B <= A) pueden
ser formados?

Mientras observaba un grupo, el conjunto de tres familias de hormigas
fue visto como {1, 1, 2, 2, 3}, aunque rara vez en ese orden. Los
conjuntos posibles de hormigas andantes eran:

  3 conjuntos con 1 hormiga:  {1} {2} {3}
  5 conjuntos con 2 hormiga: {1,1} {1,2} {1,3} {2,2} {2,3}
  5 conjuntos con 3 hormiga: {1,1,2} {1,1,3} {1,2,2} {1,2,3} {2,2,3}
  3 conjuntos con 4 hormiga: {1,2,2,3} {1,1,2,2} {1,1,2,3}
  1 conjunto con 5 hormigas: {1,1,2,2,3}

Su tarea es contar el número de posibles conjuntos de hormigas dados
los datos antes mencionados.

NOMBRE DEL PROBLEMA: ants

FORMATO DE ENTRADA:

* Línea 1: 4 enteros separados por espacios: T, A, S, y B.

* Líneas 2..A+1: Cada línea contiene un solo entero que es el tipo de
        hormiga presente en la colonia.

ENTRADA EJEMPLO (archivo ants.in):

3 5 2 3
1
2
2
1
3
3

DETALLES DE LA ENTRADA:

Tres tipos de hormigas (1..3), 5 hormigas en total. ¿Cuántos conjuntos
de tamaño 2 y de tamaño 3 pueden hacerse?

FORMATO DE SALIDA:

*Línea 1: El número de conjuntos de tamaños S..B (inclusive) que
pueden
        ser creados. Un conjunto como {1, 2} es el mismo que el
conjunto
        {2, 1} y no debería ser contado doblemente. Imprima solamente
los
        ULTIMOS SEIS DIGITOS de este número, sin ceros a la izquierda
o
        espacios.


SALIDA EJEMPLO (archivo ants.out):

10

DETALLES DE LA SALIDA:

5 conjuntos de hormigas con dos miembros; 5 conjuntos más de hormigas
con tres miembros.
*/
