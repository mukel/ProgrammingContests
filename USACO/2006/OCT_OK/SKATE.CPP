/*
Alfonso Alfonso Peterssen
21 - 9 - 2007
USACO 2006 OCT Open "Vacas en Patines"
*/
#include <cstdio>

#define problem "d"
#define MAXD 200

const int mv[4][2] =
  {{-1, 0},{0, -1},{0, 1},{1, 0}};

int F, C, i, j, k;
char mat[MAXD][MAXD];
int lastx[MAXD][MAXD], lasty[MAXD][MAXD];

int head, tail;
int qX[ MAXD * MAXD ], qY[ MAXD * MAXD ];

  void print( int x, int y ) {
    if ( x || y ) print( lastx[x][y], lasty[x][y] );
    printf( "%d %d\n", x + 1, y + 1 );
  }

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &F, &C );
  for ( i = 0; i < F; i++ )
    scanf( "%s", mat[i] );

  head++;
  mat[0][0] = '*';
  
  while ( mat[F - 1][C - 1] == '.' ) {

    int x = qX[tail],
        y = qY[tail];

    tail++;

    for ( i = 0; i < 4; i++ ) {

      int new_x = x + mv[i][0],
          new_y = y + mv[i][1];

      if ( new_x >= 0 && new_x < F &&
           new_y >= 0 && new_y < C &&
           mat[new_x][new_y] == '.' ) {

        head++;

        qX[head] = new_x;
        qY[head] = new_y;

        lastx[new_x][new_y] = x;
        lasty[new_x][new_y] = y;

        mat[new_x][new_y] = '*';
      }
    }
  }

  print( F - 1, C - 1 );

  return 0;
}

/*
Problema 3: Vacas en Patines [Rob Kolstad, 2004]


Finalmente, después de años de súplicas, el Granjero Juan dio su brazo
a torcer y ha comprado patines en línea para todo su rebaño de vacas.
Un pedazo grande de la granja es ideal para el patinaje, pero varias
parcelas tienen muchas rocas que las hacen imposibles para patinar.

La granja está representada convenientemente como una cuadrícula de
cuadrados con N (1 <= N <= 113) filas y C (1 <= C <= 77) columnas.
Bessie se encuentra en el cuadrado (1,1) cerca de su tiempo de
alimentación y quiere volver al establo el cual está ubicado en el
cuadrado (R,C). Ella sabe que al menos hay una manera de hacerlo
patinando a cuadrados adyacentes (pero no en diagonal) que no
contengan rocas. Encuentre y muestre cualquier camino que Bessie puede
seguir para llegar al establo.

Considere la distribución R=5, C=8 de granja mostrada en la izquierda,
donde '*' quiere decir "demasiadas rocas aquí". El mapa de la derecha
muestra un camino posible que Bessie podría usar para llegar al establo
en la esquina inferior derecha:

  12345678     12345678
1 B.*...**   1 @@*@@@**
2 *.*.*.**   2 *@*@*@**
3 *...*...   3 *@@@*@@@
4 *.*.*.*.   4 *.*.*.*@
5 ....*.*B   5 ....*.*@


NOMBRE DEL PROBLEMA: skate

FORMATO DE ENTRADA:

* Lìnea 1: Dos enteros separados por espacio, respectivamente R y C

* Lìneas 2..N+1: Cada línea contiene C caracteres (sin espacios). Cada
       caracteres es o un '.' indicando que Bessie puede patinar en ese
       cuadrado o un '*'   indicando que el cuadrado tiene demasiadas
       rocas.

ENTRADA EJEMPLO (archivo skate.in):

..*...**
*.*.*.**
*...*...
*.*.*.*.
....*.*.

FORMATO DE SALIDA:

* Líneas 1..?: Cada línea contiene dos enteros separados por espacio que
       son las coordenadas R,C de un cuadrado que Bessie ocupa. La
       primera línea debería ser 1 1; la última línea debería tener los
       enteros R y C.

SALIDA EJEMPLO (archivo skate.out):

1 1
1 2
2 2
3 2
3 3
3 4
2 4
1 4
1 5
1 6
2 6
3 6
3 7
3 8
4 8
5 8
*/
