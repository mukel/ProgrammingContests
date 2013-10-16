/*
Alfonso Alfonso Peterssen
22 - 9 - 2007
USACO 2006 NOV Gold "Campos de Maíz"
O( N * fib( M + 1 )^2 )
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXF 13
#define MAXLEN 4096
#define MODULO 100000000

int F, C, i, j, k, len, sol;
int land[MAXF], valid[MAXLEN];
int dp[MAXF][MAXLEN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> F >> C;
  for ( i = 1; i <= F; i++ )
    for ( j = 0; j < C; j++ ) {
      fin >> k;
      land[i] |= k << j;
    }

  for ( i = 0; i < ( 1 << C ); i++ )
    if ( !( i & ( i << 1 ) ) )
      valid[len++] = i;

  dp[0][0] = 1;
  for ( i = 1; i <= F; i++ )
    for ( j = 0; j < len; j++ )
      if ( ( valid[j] | land[i] ) == land[i] )
        for ( k = 0; k < len; k++ )
          if ( !( valid[j] & valid[k] ) )
            dp[i][j] = ( dp[i][j] + dp[i - 1][k] ) % MODULO;

  for ( i = 0; i < len; i++ )
    sol = ( sol + dp[F][i] ) % MODULO;

  fout << sol << endl;

  return 0;
}

/*
Problema 2: Campos de Maíz [Richard Ho, 2004]

El Granjero Juan ha comprado un exuberante nuevo campo de pasteo
compuesto de M por N (1 <= M <= 12; 1 <= N <= 12) parcelas cuadradas.
El quiere sembrar algún maíz dulce para las vacas en un número de
cuadrados. Desafortunadamente algunos de los cuadrados son infértiles
y no pueden ser sembrados. El astuto GJ sabe que a las vacas les
disgusta comer cerca de las otras, por lo tanto cuando elige que
cuadrados plantar, él evita elegir cuadrados que sean adyacentes;
ningún par de cuadrados elegidos comparten un lado. El aún no ha hecho
la elección final en qué cuadrados plantar.

Siendo un hombre de mente muy abierta, el Granjero Juan quiere
considerar todas las opciones posibles para elegir los cuadrados para
plantar. ¿El es tan de mente abierta que él considera elegir ningún
cuadrado como una opción válida! Por favor ayude al Granjero Juan a
determinar el número de maneras en que él puede elegir los cuadrados
para plantar.

NOMBRE DEL PROBLEMA: cowfood

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por un espacio: M y N.

* Líneas 2..M+1: La línea i+1 describe la fila i del campo de pasteo
     con N enteros separados por espacio indicando cuando un cuadrado
     es fértil (1 para fértil, 0 para infértil).

ENTRADA EJEMPLO (archivo cowfood.in)

2 3
1 1 1
0 1 0

FORMATO DE SALIDA:

* Línea 1: Un solo entero: el número de maneras en que GJ puede elegir
     los cuadrados módulo 100,000,000.

EJEMPLO DE SALIDA (archivo cowfood.out):

9

DETALLES DE LA SALIDA:

Numerando los cuadrados como sigue:

1 2 3
  4

Hay cuatro maneras de plantar en solo un cuadrado (1, 2, 3, o 4), tres
maneras de plantar en solo dos cuadrados (13, 14, o 34), 1 manera de
plantar en tres cuadrados (134), y una manera de plantar en ningún
cuadrado. 4+3+1+1=9.
*/
