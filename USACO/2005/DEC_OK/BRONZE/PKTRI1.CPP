/*
Alfonso Alfonso Peterssen
3 - 8 - 2007
USACO 2005 DEC Bronze "Triángulo Parkside"
*/
#include <cstdio>

#define problem "d"

int N, offset, i, j;

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &N, &offset );

  for ( i = 0; i < N; i++ ) {

    for ( j = 0; j < i; j++ ) printf( "  " );

    for ( j = i; j < N; j++ ) {
      printf( "%d", ( j * ( j + 1 ) / 2 + i + offset - 1 ) % 9 + 1  );
      printf( ( j == N - 1 ) ? "\n" : " " );
    }

  }

  return 0;
}

/*
Problema 11: Triángulo Parkside [Don Piele, 2005]

Bessie les enseñó a las vacas a hacer el Triángulo Parkside. Se genera a
partir de dos números, el tamaño y la semilla. El tamaño N (1 <= N <= 20)
determina cuántas filas hay en el triángulo y la semilla S (1 <= S <= 9)
determina el primer número en el triángulo. Aquí hay dos ejemplos:

N=5, S=3                  N=6, S=1

3 4 6 9 4                1 2 4 7 2 7
  5 7 1 5                  3 5 8 3 8
    8 2 6                    6 9 4 9
      3 7                      1 5 1
        8                        6 2
                                   3

La primera línea de cualquier triángulo no tiene espacios en blanco al principio.

Analice los ejemplos antes mostrado, descubra la regla, y escriba un programa que
generará el Triángulo Parkside dados cualquier tamaño N (1 <= N <= 20) y cualquier
semilla S (1 <= S <= 9).


NOMBRE DEL PROBLEMA: pktri1

FORMATO DE ENTRADA:

* Lìnea 1: Dos enteros separados por espacio, N y S

ENTRADA EJEMPLO (archivo pktri1.in):

5 3

FORMATO DE SALIDA:

* Líneas 1..N: Un triángulo Parkside como el mostrado; no dejar espacios
        sobrantes en ninguna línea.


SALIDA EJEMPLO (archivo pktri1.out):

3 4 6 9 4
  5 7 1 5
    8 2 6
      3 7
        8
*/
