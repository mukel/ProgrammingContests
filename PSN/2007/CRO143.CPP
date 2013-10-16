/*
Alfonso Alfonso Peterssen
11 - 7 - 2007
CIIC 2007 Task 5
PSN 2007 #143 "Robots buscadores de agua"
Sexy Greedy
*/
#include <cstdio>

#define problem "d"
#define MAXC 10000

int F, C, start, end, cnt, sol;
int wall[MAXC];
bool mark[MAXC];

int main() {
  freopen( problem ".in", "r", stdin );
  freopen( problem "a.out", "w", stdout );

  int i, j;

  scanf( "%d %d\n", &F, &C );
  for ( ; F; F-- ) {

    scanf( "%d", &cnt );

    for ( i = 1; i <= cnt; i++ )
      scanf( "%d", &wall[i] );

    wall[++cnt] = C + 1;

    for ( i = cnt; i; i-- ) {

      start = wall[i] - 1;
      end = wall[i - 1];

      if ( start <= end ) continue;

      for ( j = start; j > end; j-- )
        if ( mark[j] ) {
          mark[j] = false;
          mark[start] = true;
          start = j - 1;
        }

      if ( start > end ) {
        sol++;
        mark[start] = true;
      }

    }
  }

  printf( "%d\n", sol );

  return 0;
}

/*
143ş Robots buscadores de agua.                           Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Para la b£squeda de agua subterr nea en la regi¢n de CIIC se van a
utilizar unos curiosos robots los cuales se pueden mover solamente
hacia el Sur () o hacia el Este (), y solamente por caminos donde no
circule otro robot pues esto provocar¡a errores en la recopilaci¢n de
la informaci¢n de los mismos. En el terreno hay obst culos por los
cuales los robots no pueden pasar.

Esta pudiera ser una vista superior del terreno donde las zonas en
negro ser¡an los obst culos por los cuales les ser¡a imposible caminar
a los robots.

             N
    ÚÄÄÂÄÄÂÄÄÂÄÄÂÄÄÂÄÄ¿
    ³  ³  ³  ³±±³  ³  ³
    ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´
    ³  ³  ³  ³  ³±±³  ³
O   ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´   E
    ³  ³±±³±±³  ³±±³  ³
    ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´
    ³  ³  ³  ³  ³  ³  ³
    ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÄ´
    ³±±³±±³  ³  ³±±³  ³
    ÀÄÄÙÄÄÁÄÄÁÄÄÙÄÄÁÄÄÙ
            S

Los robots fueron fabricados con una moderna tecnolog¡a y poseen la
capacidad de ser tele-transportados hacia cualquier lugar del terreno
para comenzar su trabajo de exploraci¢n, una vez terminada su tarea
son tele-transportados fuera del mismo.

El problema consiste en encontrar la menor cantidad posible de robots
que es necesario utilizar de tal manera que todo el terreno quede
correctamente explorado y por supuesto no existan dificultades con las
mediciones hechas por ellos.

Esta ser¡a una soluci¢n para el ejemplo anterior de terreno.

               N
      ÚÄÄÂÄÄÂÄÄÂÄÄÂÄÄÂÄÄ¿
      ³şÄÅÄÄÅÄş³±±³şÄÅÄ¿³
      ÃÄÄÅÄÄÅÄÄÅÄÄÅÄÄÅÄÅ´
      ³şÄÅÄÄÅÄÄÅÄ¿³±±³ ³³
      ÃÄÄÅÄÄÅÄÄÅÄÅÅÄÄÅÄÅ´
  O   ³ş ³±±³±±³ ³³±±³ ş³  E
      ÃÅÄÅÄÄÅÄÄÅÄÅÅÄÄÅÄÄ´
      ³ÀÄÅÄÄÅ¿ ³ ÀÅÄÄÅÄ¿³
      ÃÄÄÅÄÄÅÅÄÅÄÄÅÄÄÅÄÅ´
      ³±±³±±³ÀÄÅ ş³±±³ ş³
      ÀÄÄÙÄÄÁÄÄÁÄÄÁÄÄÁÄÄÙ
               S

Tarea

Hacer un programa que:

- Lea desde el fichero de entrada ROBOTS.ENT las dimensiones del
  terreno a explorar y la ubicaci¢n de los obst culos en el mismo.
- Calcule el n£mero m¡nimo de robots necesarios para explorar todo el
  terreno,
- Escriba hacia el fichero de salida ROBOTS.SAL el n£mero m¡nimo
  encontrado.

Entrada

El archivo de entrada ROBOTS.ENT contiene:

L¡nea 1: M, N: dos enteros separados entre si por un espacio en
         blanco, los cuales representan respectivamente la cantidad de
         filas y columnas de la regi¢n rectangular a explorar.

L¡neas 2..M+1: en cada l¡nea se colocar  un valor de P, el cual
               representa la cantidad de obst culos en esa l¡nea, a
               continuaci¢n se colocar n P enteros separados entre si
               por un espacio en blanco, los cuales en orden
               ascendente indican el n£mero de la columna donde
               aparece un obst culo.

Salida

El archivo de entrada ROBOTS.SAL contiene la m¡nima cantidad de robots
que son necesarios utilizar.

Ejemplo de Entrada y Salida

ROBOTS.ENT           ROBOTS.SAL

5 6                  4
1 4
1 5
3 2 3 5
0
3 1 2 5


Restricciones

1 <=  M, N  <=  100000.
1 <=  P  <=  N.
*/
