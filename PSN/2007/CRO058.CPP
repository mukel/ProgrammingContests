/*
Alfonso Alfonso Peterssen
1 - 8 - 2007
PSN 2007 #58 "Espect culo Pirot‚cnico"
*/
#include <cstdio>

#define problem "d"

#define MAXM 3000000

int N, M, j, k, sol;
bool mark[MAXM];

int main () {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &N, &M );

  for ( ;N ; N-- ) {
    scanf( "%d", &k );
    for ( j = k; j <= M; j += k ) {
      if ( !mark[j] ) sol++;
      mark[j] = true;
    }
  }

  printf( "%d\n", sol );

  return 0;
}

/*
58þ Espect culo Pirot‚cnico.                              Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Es D¡a de la Independencia, y el Granjero Juan ha llevado a sus  vacas
al espect culo pirot‚cnico. Bessie se pregunta cu nto del  espect culo
ser  posible que sea visto, pues ellas no podr n quedarse durante todo
el espect culo.

El  espect culo  presenta  C  (1 <=  C  <=  100)  ca¤ones pirot‚cnicos
convenientemente numerados 1..C. El  ca¤¢n i tira fuegos  artificiales
cada T_i (1 <= T_i <= N) segundos (todos los tiempos en esta tarea son
segundos enteros).  En una  apertura espectacular,  todos los  ca¤ones
disparan primero en  el tiempo 0.  Los fuegos son  visibles £nicamente
durante el segundo en el cual  son lanzados desde el ca¤¢n. Las  vacas
permanecer n en  el espect culo  desde el  tiempo 1  hasta el tiempo N
(1<= N <= 2,000,000).

Ayude a  Bessie a  averiguar en  cu ntos tiempos  diferentes las vacas
ser n capaces de ver fuegos artificiales durante el per¡odo de  tiempo
en que ellas est n en el espect culo.


NOMBRE DEL PROBLEMA: fireshow

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por un espacio: C y N.

- L¡neas 2..C+1: La l¡nea i+1 contiene un solo entero T_i.

ENTRADA EJEMPLO (archivo fireshow.in):

2 20
4
6

DETALLES DE LA ENTRADA:

El  espect culo  presenta  2 ca¤ones:  uno  disparando  fuegos cada  4
segundos, el otro disparando  cada 6 segundos. Las  vacas permanecer n
en el espect culo desde el tiempo 1 hasta el tiempo 20. A continuaci¢n
hay una tabla  mostrando los tiros  de fuegos y  el tiempo en  que las
vacas est n presentes.

      VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV
2                                   2                                   2 ...
1           1     2     1           1           1     2     1           1 ...
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+ ...
0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24
...


FORMATO DE SALIDA:

- L¡nea 1: Un solo entero que es el n£mero de segundos distintos en el
       intervalo de tiempo desde 1 hasta N en que las vacas podr n ver
       fuegos.

SALIDA EJEMPLO (archivo fileshow.out):

7

DETALLES DE LA SALIDA:

Habr n fuegos en los tiempos 4, 6, 8, 12, 16, 18, y 20, para un  total
de 7 tiempos distintos. (Note que en el tiempo 12, donde ambos ca¤ones
tiran fuegos simult neamente, solo se cuenta una vez.) Vea el  gr fico
anterior.
*/
