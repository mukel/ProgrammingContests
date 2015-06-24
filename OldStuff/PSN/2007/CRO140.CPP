/*
Alfonso Alfonso Peterssen
12 - 7 - 2007
CIIC 2007 Task 1
PSN 2007 #140 "MCD"
*/
#include <cstdio>

#define problem "d"

#define MAXN 200000
#define MAXLOG 19

int N, i, j;
int t[MAXLOG][2 * MAXN];

  int GCD( int a, int b ) {
    while ( a && b ) if ( a %= b ) b %= a;
    return a | b;
  }

  int lg( int x ) {
    int res = 1;
    while ( ( 1 << res ) < x ) res++;
    return res - 1;
  }

  int query( int d, int h ) {
    int l = lg( h - d + 1 );
    return GCD( t[l][d],
                t[l][ h - ( 1 << l ) + 1 ] );
  }

  bool ok( int value ) {
    for ( int i = 0; i + value <= 2 * N; i++ )
      if ( query( i, i + value - 1 ) != 1 ) return true;
    return false;
  }

int main() {
  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d\n", &N );
  for ( i = 0; i < N; i++ ) {
    scanf( "%d", &j );
    t[0][N + i] = t[0][i] = j;
  }

  /* Preprocess */
  int l = lg( 2 * N );
  for ( i = 1; i <= l; i++ )
    for ( j = 0; j + ( 1 << i ) <= 2 * N; j++ )
      t[i][j] = GCD( t[i - 1][j],
                     t[i - 1][ j + ( 1 << ( i - 1 ) ) ] );

  /* Binary Search */
  int d = 0, h = N + 1, mid;
  while ( d < h ) {
    mid = ( d + h ) / 2;
    if ( ok( mid ) ) d = mid + 1;
    else h = mid;
  }

  if ( h - 1 == N ) printf( "-1\n" );
  else printf( "%d\n", h - 1 );

  return 0;
}
/*
140þ MCD.                                                 Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Se tiene una secuencia S de N n£meros enteros positivos S1, S2, S3,
S4, ...SN.  Luego, cada n£mero de la secuencia se reemplaza por el
m ximo com£n divisor (MCD) de él mismo y el siguiente n£mero en la
secuencia. El £ltimo n£mero de la secuencia se reemplaza por el m ximo
com£n divisor de él mismo y el primero:

MCD(S1, S2), MCD(S2, S3), ..., MCD(SN, S1)

Esta operaci¢n se repite varias veces intentando que todos los n£meros
en la  secuencia sean  1, aunque algunas veces esto no es posible.

Por ejemplo, la secuencia 4, 12, 3, 9 se tendr¡a que reemplazar 3
veces:

4, 3, 3, 1
1, 3, 1, 1
1, 1, 1, 1

Tarea

Escriba un programa que:
-	lea desde el archivo de entrada MCD.ENT la secuencia S,
- determine cu ntas veces se tiene que reemplazar la secuencia
  completa para obtener una secuencia formada por solamente n£meros 1,
- escriba el valor  correspondiente al n£mero de veces hacia el
  archivo de salida MCD.SAL.

Entrada

El archivo de entrada MCD.ENT contiene:
L¡nea1: un n£mero entero N,
L¡nea2: N n£meros enteros positivos separados por espacios,
        representando la secuencia S.

Salida

El archivo de salida MCD.OUT contiene un  solo n£mero entero, el
n£mero de veces que se tiene que reemplazar la secuencia completa para
obtener una secuencia de solamente n£meros 1. Si no es posible escriba
simplemente -1.

Ejemplo de Entrada y Salida

MCD.IN                        MCD.OUT

4
4 12 3 9                      3

Consideraciones

1  <=  N  <= 200000
1  <=  Si  <= 1000 para todo 1 <= i <= N
*/
