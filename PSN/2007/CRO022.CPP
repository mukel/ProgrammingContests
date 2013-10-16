/*
Alfonso Alfonso Peterssen
23 - 12 - 2007
PSN 2007 #22 "Remover errors de un programa"
Simple Sum Heuristic
*/
#include <cstdio>
#include <cstdlib>

const int MAXF = 400;

int F, C, i, j, k, x, y;
char mat[MAXF][MAXF];
int T[MAXF][MAXF];

/*
Slow!!!
#define sum( x1, y1, x2, y2 ) \
    ( T[x2][y2] - T[x1 - 1][y2] - T[x2][y1 - 1] + T[x1 - 1][y1 - 1] )
*/

    inline int sum( int x1, int y1, int x2, int y2 ) {
        return T[x2][y2] - T[x1 - 1][y2] - T[x2][y1 - 1] + T[x1 - 1][y1 - 1];
    }

int main() {

    freopen( "d.in", "r", stdin );
    freopen( "d.out", "w", stdout );

    scanf( "%d %d", &F, &C );
    for ( i = 1; i <= F; i++ ) {
        scanf( "%s", &mat[i][1] );
        for ( j = 1; j <= C; j++ ) {
            T[i][j] = ( mat[i][j] == '1' ) ? 1 : 0;
            T[i][j] += T[i - 1][j] + T[i][j - 1] - T[i - 1][j - 1];
        }
    }

    for ( i = F <? C; i > 1; i-- )
        for ( j = i; j <= F; j++ )
            for ( k = i; k <= C; k++ ) {

                /* Simple Sum Heuristic */
                if ( sum( j - i + 1, k - i + 1, j - i / 2, k ) !=
                     sum( j - i / 2 + !( i & 1 ), k - i + 1, j, k ) )
                    continue;

                bool ok = true;
                for ( x = 0; ok && x * 2 < i; x++ )
                    for ( y = 0; y < i; y++ )
                        if ( mat[j + x - i + 1][k + y - i + 1] !=
                             mat[j - x][k - y] ) {
                            ok = false;
                            break;
                        }

                if ( ok ) {
                    printf( "%d\n", i );
                    exit( 0 );
                }
            }

    printf( "-1\n" );

    return 0;
}

/*
22þ Remover errors de un programa                         Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Mientras Mirko corregia un programa  not¢ un error en el  programa que
posia estar relacionado  con la existencia  de los llamados  cuadrados
asesinos en la  memoria del programa.  La memoria del  programa es una
matriz  compuesta de R filas   y C columans consistiendo solamente  de
ceros y  unos. Un  cuadrado asesino  es una  submatriz cuadrada  en la
memoria, consistiendo de  m s de un  caracter, que, cuando  lo rotamos
180  grados  vemos  exactamente lo  mismo. Por  ejemplo, la  siguiente
matriz contiene  3 cuadrados asesinos:

101010     ....10     ......       101...
111001     ....01     ...00.       111...
101001     ......     ...00.       101...
memory     killer     killer       killer

Mirko se pregunta si existe una conexi¢n entre el tama¤o del  cuadrado
asesino m s grande y el  error  del programa. Ayuda a Mirko a escribir
un programa que,  dado el esquema  de la memoria,  determine el tama¤o
del cuadrado asesino  m s grande. El  tama¤o del cuadro  asesino es el
n£mero de  filas (o  de columnas)  en que  consiste. En  el ejemplo de
arriba los tama¤os de los asesinos son 2, 2 y 3, respectivamente.

Entrada

La primera  l¡nea del  fichero DEBUG.IN  contiene dos  enteros, R y C,
menores  o  igual 300.  Las  pr¢ximas R  l¡neas  cada una  contiene  C
caracteres ('0' o '1') sin espacios.

Salida

En el fichero de salida DEBUG.OUT debe contener el tama¤o del cuadrado
asesino  m s grande  en una  simple l¡nea,  o  -1  si este  no es  un
cuadrado asesino.

Ejemplos de Entrada  y Salida

DEBUG.IN          DEBUG.IN           DEBUG.IN

3 6               4 5                3 3
101010            10010              101
111001            01010              111
101001            10101              100
                  01001


DEBUG.OUT         DEBUG.OUT          DEBUG.OUT

3                 3                  -1
*/
