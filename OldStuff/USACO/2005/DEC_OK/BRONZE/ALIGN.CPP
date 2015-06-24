/*
Alfonso Alfonso Peterssen
3 - 8 - 2007
USACO 2005 DEC Bronze "Alineación de los Planetas"
*/
#include <cstdio>

#define problem "d"
#define MAXN 770
#define MAXSOL 5000

int N, i, j, k, sol;
int X[MAXN], Y[MAXN];
int p1[MAXSOL], p2[MAXSOL], p3[MAXSOL];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d", &N );
  for ( i = 0; i < N; i++ )
    scanf( "%d %d", &X[i], &Y[i] );

  for ( i = 0; i < N; i++ )
    for ( j = i + 1; j < N; j++ )
      for ( k = j + 1; k < N; k++ )
        if ( ( X[j] - X[i] ) * ( Y[k] - Y[i] ) ==
             ( X[k] - X[i] ) * ( Y[j] - Y[i] ) ) {
          p1[sol] = i;
          p2[sol] = j;
          p3[sol] = k;
          sol++;
        }

  printf( "%d\n", sol );
  for ( i = 0; i < sol; i++ )
    printf( "%d %d %d\n", p1[i] + 1, p2[i] + 1, p3[i] + 1 );

  return 0;
}

/*
Problema 12: Alineación de los Planetas [Tradicional, 2005]

En realidad, este problema es acerca de alinear N (1 <= N <= 770) vacas
numeradas 1..N las cuales están pasteando en su campo el cual tiene cerca
de 15,000x15,000 unidades. Todas sus posiciones de pasteo caen en
coordenadas enteras en esquema tradicional x, y (las coordenadas están
en el rango 0..15,000).

Bessie mira el campo y se da cuenta que está exactamente alineada con
Sara y Julie. Ella se pone a pensar en cuántos grupos de tres vacas
alineadas existen dentro del campo.

Dadas las ubicaciones de todas las vacas (ningún par de vacas ocupan
la misma posición), encuentre todos los conjuntos de tres vacas que son
exactamente colineales. Lleve registro de los conjuntos, ordenando las
vacas en cada conjunto por su número de identificación, el más bajo
primero. Luego ordene los conjuntos por los tres números de identificación
(el más bajo primero), rompiendo empates con los números de identificación
segundo y tercero.

NOMBRE DEL PROBLEMA: align

FORMATO DE ENTRADA:

* Líneas 1: Un solo entero, N.

* Líneas 2..N+1: La línea i+1 describe la posición de la vaca i con dos
        enteros separados por espacio que son las coordenadas x y y.


ENTRADA EJEMPLO (archivo align.in):

8
0 0
0 4
1 2
2 4
4 3
4 5
5 1
6 5

DETALLES DE LA ENTRADA

Ocho vacas pasteando en un arreglo cuya esquina inferior izquierda se ve como esto:

. . . . * . *
* . * . . . .
. . . . * . .
. * . . . . .
. . . . . * .
* . . . . . .

FORMATO DE SALIDA:

* Línea 1: Un solo entero que es el número de conjuntos de tres vacas que son
        exactamente colineales. Un conjunto de cuatro vacas colineales podría,
        por supuesto, resultar en cuatro conjuntos de tres vacas colineales.

* Líneas 2..?: Cada línea contiene tres enteros separados por espacio que
        son los números de identificación de tres vacas colineales. Las
        líneas deben estar ordenadas como se ha especificado antes. Esta
        sección es vacía si no existen conjuntos colineales.

SALIDA EJEMPLO (archivo align.out):

1
1 3 4

DETALLES DE LA SALIDA:

Los dígitos marcan los identificadores de vacas colineales:

. . . . * . *
* . 4 . . . .
. . . . * . .
. 3 . . . . .
. . . . . * .
1 . . . . . .
*/
