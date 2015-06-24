/*
Alfonso Alfonso Peterssen
16 - 9 - 2007
USACO 2006 JAN Silver "Días de Dólar"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXN 1001
#define MAXLEN 100

int N, M, i, j, k, r, t;
int len[MAXN];
int dp[MAXN][MAXLEN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N >> M;

  dp[0][0] = 1;
  for ( i = 1; i <= M; i++ )
    for ( j = i; j <= N; j++ ) {

      r = 0;
      len[j] >?= len[j - i];
      for ( k = 0; k <= len[j]; k++ ) {
        t = dp[j][k] + dp[j - i][k] + r;
        dp[j][k] = t % 10;
        r = t / 10;
      }

      if ( r )
        dp[j][ ++len[j] ] = r;
    }

  for ( i = len[N]; i >= 0; i-- )
    fout << dp[N][i];

  fout << endl;

  return 0;
}

/*
Problema 7: Días de Dólar [Entrenadores, 2004]

El Granjero Juan (GJ) va a los Días de Dólar en la Tienda Vacuna y
descubre  un número ilimitado de herramientas en promoción. Durante su
primera visita, las herramientas se están vendiendo variadamente por
$1, $2, y $3. El Granjero Juan tiene exactamente $5 para gastar. El
puede comprar 5 herramientas de $1 cada una o 1 herramienta de $3 y
adicionalmente 1 herramienta de $2. Por supuesto, hay otras
combinaciones para un total de 5 maneras diferentes en las cuales GJ
puede gastar todo su dinero en herramientas. Aquí están las maneras:
        1 @ US$3 + 1 @ US$2
        1 @ US$3 + 2 @ US$1
        1 @ US$2 + 3 @ US$1
        2 @ US$2 + 1 @ US$1
        5 @ US$1

Escriba un programa que calculará el número de maneras en que GJ puede
gastar N dólares (1 <= N <= 1000) en la Tienda Vacuna para
herramientas en promoción con un costo de $1..$K (1 <= K <= 100).

NOMBRE DEL PROBLEMA: ddayz


FORMATO DE ENTRADA:

Una sola línea con dos enteros separados por espacio: N y K.


ENTRADA EJEMPLO (archivo ddayz.in):

5 3

FORMATO DE SALIDA:

Una sola línea con un solo entero que es el número de maneras únicas
en que GJ puede gastar su dinero.

SALIDA EJEMPLO (archivo ddayz.out):

5
*/
