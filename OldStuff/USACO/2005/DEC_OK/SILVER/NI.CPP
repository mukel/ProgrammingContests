/*
Alfonso Alfonso Peterssen
4 - 8 - 2007
USACO 2005 DEC Silver "Caballeros de Ni"
*/
#include <cstdio>
#include <cstdlib>

#define problem "d"
#define MAXF 1500

const int mov[4][2] =
  { {-1,0}, {0,-1}, {0,1}, {1,0} };

int F, C, i, j;
int front, rear;
int map[MAXF][MAXF], dist[MAXF][MAXF];
int qX[MAXF * MAXF], qY[MAXF * MAXF];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &C, &F );
  for ( i = 0; i < F; i++ )
    for ( j = 0; j < C; j++ ) {
      scanf( "%d", &map[i][j] );
      if ( map[i][j] == 2 ) {
        qX[front] = i;
        qY[front] = j;
        front++;
      }
    }

  /* BFS */
  while ( front != rear ) {
    for ( i = 0; i < 4; i++ ) {

      int rx = qX[rear], x = rx + mov[i][0],
          ry = qY[rear], y = ry + mov[i][1];

      if ( ( x >= 0 && x < F ) && ( y >= 0 && y < C ) ) {

        if ( ( map[x][y] == 1 ) || ( map[x][y] == map[rx][ry] ) ||
             ( map[rx][ry] != 4 && map[x][y] == 3 ) ) continue;

        if ( map[x][y] == 3 ) {
          printf( "%d\n", dist[rx][ry] + 1 );
          exit( 0 );
        }

        if ( map[x][y] != 4 ) map[x][y] = map[rx][ry];

        dist[x][y] = dist[rx][ry] + 1;
        qX[front] = x; qY[front] = y;

        front++;
      }
    }
    rear++;
  }

  return 0;
}

/*
Problema 6: Caballeros de Ni [Carl Hultquist, Sudafrica, 2005]

Bessie está en Camelot y se ha encontrado en una situación incómoda:
ella necesita pasar a través del bosque que es vigilado por los
Caballeros de Ni. Para que ella pueda pasar con seguridad, los
Caballeros han demandado que ella les lleve una sola fresa. El tiempo
es esencial, y Bessie debe encontrar y llevarles una fresa tan pronto
como sea posible.

Bessie tiene un mapa del bosque, el cual está particionado en un
arreglo cuadrado arreglado en la manera usual, con los ejes paralelos
a los ejes X y Y. El mapa tiene tamaño W x H unidades (1 <= W <= 1000;
1 <= H <= 1000).

El mapa muestra donde Bessie comienza su recorrido, el único cuadrado
en donde están los Caballeros de Ni, y la ubicación de todas las
fresas en el territorio. También muestra que áreas del mapa pueden ser
atravesadas (algunos bloques del arreglo son impasables debido a
pantanos, montañas y conejos asesinos). Bessie no puede pasar a través
del cuadrado de los Caballeros de Ni sin una fresa.

Para estar seguros que Bessie siga el mapa correctamente, Bessie puede
moverse únicamente en cuatro direcciones: Norte, Este, Sur, U oeste
(esto es diagonalmente NO). Ella requiere un día para completar un
recorrido de un bloque del arreglo a un bloque vecino del arreglo.

Se garantiza que Bessie será capaz de conseguir una fresa y luego
llevarla a los Caballeros de Ni. Determine la manera más rápida en que
ella pueda hacer eso.

NOMBRE DEL PROBLEMA: ni

FORMATO DE ENTRADA:

* Línea 1: Dos enteros separados por espacio W y H.

* Líneas 2..?: Estas líneas describen el bosque, fila por fila. La
         primera línea describe la parte más al noroeste del bosque.
         La última línea describe la parte más sudeste del bosque.
         Enteros sucesivos en la entrada describen columnas del bosque
         de oeste a este. Cada nueva fila de la descripción del bosque
         comienza en una nueva línea de entrada, y cada línea de la
         entrada contiene no más de 40 enteros separados por espacios.
         Si W <= 40, entonces cada línea de la entrada describe una
         fila completa del bosque. Si W > 40, entonces más de una
         línea es usada para describir una sola fila, 40 enteros en
         cada línea exceptuando potencialmente la última. Ninguna
         línea de la entrada describirá elementos de más de una fila.

Los enteros que describen el bosque vienen de este conjunto:
0: Cuadrado a través del cual Bessie puede desplazarse
1: Cuadrado impasable, a través del Cual Bessie no puede desplazarse
2: Posición inicial de Bessie
3: Posición de los Caballeros de Ni
4: Posición de una fresa

ENTRADA EJEMPLO (archivo ni.in):

8 4
4 1 0 0 0 0 1 0
0 0 0 1 0 1 0 0
0 2 1 1 3 0 4 0
0 0 0 4 1 1 1 0

DETALLES DE LA ENTRADA:

Ancho=8, alto=4. Bessie comienza en la tercera fila, solo unos
cuadrados lejos de los Caballeros.


FORMATO DE LA SALIDA:

* Línea 1: D, el mínimo número de días que le tomará a Bessie llegar a
        una fresa y llevársela a los Caballeros de Ni.

SALIDA EJEMPLO (archivo ni.out):

11

DETALLES DE LA SALIDA:

Bessie puede moverse en este patrón para llevar una frase a los
Caballeros: N, O, N, S, E, E, N, E, E, S, S. Ella consigue la fresa en
la esquina noroeste y luego rodea las barreras hacia el este y luego
al sur hacia los Caballeros.
*/
