/*
Alfonso Alfonso Peterssen
11 - 8 - 2007
USACO 2005 NOV Bronze "Fotografías Satelitales"
*/
#include <cstdio>

#define problem "d"
#define MAXC 1000

int F, C, i, j, cnt, sol;
char mat[MAXC][MAXC];

  void dfs( int x, int y ) {
    cnt++;
    mat[x][y] = '.';
    if ( x > 0 && mat[x - 1][y] == '*' ) dfs( x - 1, y );
    if ( y > 0 && mat[x][y - 1] == '*' ) dfs( x, y - 1 );
    if ( x < F - 1 && mat[x + 1][y] == '*' ) dfs( x + 1, y );
    if ( y < C - 1 && mat[x][y + 1] == '*' ) dfs( x, y + 1 );
  }

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d\n", &C, &F );
  for ( i = 0; i < F; i++ )
    scanf( "%s\n", &mat[i] );

  for ( i = 0; i < F; i++ )
    for ( j = 0; j < C; j++ )
      if ( mat[i][j] == '*' ) {
        cnt = 0;
        dfs( i, j );
        sol >?= cnt;
      }

  printf( "%d\n", sol );

  return 0;
}

/*
Problema 13: Fotografías Satelitales [Rob Kolstad, 2005]

El Granjero Juan compró fotos satelitales de W x H pixels de su granja (1
<= W <= 80, 1 <= H <= 1000) y desea determinar el pastizal conexo más
grande. Un pastizal es conexo cuando cualquier par de pixels en él pueden
ser conectados atravesando pixels adyacentes vertical u horizontalmente
que también son parte del pastizal. (Es fácil crear pastizales de formas
muy extrañas, aún círculos que rodeen otros círculos).

Cada foto ha sido digitalizada permitiendo mostrar áreas de pastizales
como un asterisco ('*') y las áreas de no-pastizales como un punto ('.').
Aquí hay un ejemplo de una foto satelital 10 x 5:

..*.....**
.**..*****
.*...*....
..****.***
..****.***

Esta foto muestra tres pastizales conexos de 4, 16, y 6 pixels. Ayude al
Granjero Juan ha encontrar el pastizal conexo más grande en cada una de
sus fotos satelitales.

NOMBRE DEL PROBLEMA: satpix

FORMATO DE ENTRADA:

* Lìnea 1: Dos enteros separados por espacio: W y H

* Lìneas 2..H+1: Cada línea contiene W caracteres '*' o '.' representando una
        línea de una foto satelital.


ENTRADA EJEMPLO (archivo satpix.in):

10 5
..*.....**
.**..*****
.*...*....
..****.***
..****.***

FORMATO DE SALIDA:

Línea 1: El tamaño de la región conexa más grande en la foto satelital.

SALIDA EJEMPLO (archivo satpix.out):

16
*/
