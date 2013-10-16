/*
Alfonso Alfonso Peterssen
24 - 12 - 2007
PSN 2007 #25 "El Juego del Dado"
*/
#include <cstdio>
#include <queue>

using namespace std;

const int MAXF = 1000;

int F, C, i, j, k, x, y;
int link[MAXF * MAXF];
int last[MAXF * MAXF];
int dado[MAXF * MAXF];
queue< int > Q;

    void print_path( int x, int steps ) {

        if ( x == 0 ) {
            printf( "%d\n", steps );
            return;
        }

        print_path( last[x], steps + 1 );
        printf( "%d ", dado[x] );
    }

int main() {

    freopen( "d.in", "r", stdin );
    freopen( "d.out", "w", stdout );

    scanf( "%d %d", &F, &C );

    for ( i = F * C; i; i-- )
        last[i] = -1, link[i] = i;

    while ( scanf( "%d %d", &j, &k ) != EOF )
        link[j] = k;

    /* BFS */
    for ( Q.push( 0 ); !Q.empty(); Q.pop() ) {
        x = Q.front();
        for ( i = 1; i < 7; i++ )
            if ( last[ y = link[x + i] ] < 0 ) {
                dado[y] = i;
                last[y] = link[x];
                Q.push( y );
            }
    }

    print_path( F * C, 0 );

    return 0;
}

/*
25þ El Juego del Dado.                                    Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Un  tablero de NxM casillas se ha enumerado  consecutivamente con  los
n£meros  del  1  al  NxM  comenzando  por  la £ltima fila llenando las
casillas  de izquierda a derecha, luego la pen£ltima fila de derecha a
izquierda  y  asi alternadamente  hasta  la primera  fila  (figura 1).
Algunas  casillas tienen pase directo a otras casillas, bien en avance
o  en  retroceso  (se  indica  con una flecha). Estos pases  solo  son
validos cuando se termina de contar en una casilla que contenga enlace
directo con otra casilla.

Un  jugador con su ficha se va moviendo por las casillas (en el  orden
en  que fueron enumeradas) a medida que lanza un dado y avanza  tantas
casillas  como puntos salen. Las caras del dado est n enumeradas del 1
al  6. El objetivo del juego es  llegar  a la casilla  de mayor n£mero
(meta)  con la menor cantidad posible de tiros del dado. Se comienza a
contar la primera vez a partir de la casilla n£mero 1.

Determine  la puntuaci¢n que debe sacar un jugador en cada uno  de sus
turnos para ganar el juego lo m s pronto posible.

Figura 1 (Hoja).

Entrada

El  archivo de Entrada contiene en la primera l¡nea el n£mero de filas
del   tablero  N y el  n£mero  de  columnas  separados por un  espacio
(4  <= N,  M  <= 1000). Las  pr¢ximas  l¡neas  tienen los  enlaces  de
las casillas  que tienen pase  directo a otra, uno por  l¡nea, primero
esta el n£mero de la casilla y luego, separado por espacio, el  n£mero
de la casilla a donde se dirigir  la flecha.

Salida

El  archivo de  Salida  deber   contener en  una l¡nea la cantidad  de
veces  que  habra  que  lanzar  el  dado,  la  segunda l¡nea tendra la
puntuaci¢n que alcanzar  en cada tirada.

ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿ ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
³  Ejemplo de Entrada  ³ ³ Ejemplo de Salida ³
ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´ ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´
³ 5 5                  ³ ³ 4                 ³
³ 3 12                 ³ ³ 3 6 1 1           ³
³ 13 1                 ³ ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
³ 17 7                 ³
³ 19 24                ³  Nota: S¢lo se dar  una soluci¢n.
³ 22 11                ³
ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

Descripci¢n  del ejemplo de salida:

En el primer  lanzamiento sali¢  la cara 3, entonces movemos  la ficha
por las casillas  1, 2 y  3. Al llegar  a  la casilla  3 esta tiene un
enlace directo  hasta  la  casilla 12  por lo  que  autom ticamente la
ficha se  mueve hasta dicha  casilla.  En el segundo tiro sali¢ un  6,
por tanto nos movemos por las  casillas  desde la  13 hasta la  18. En
el tercer lance sali¢ un 1  y nos movemos  hasta la  casilla  19, esta
tiene un pase directo hasta la  casilla 24. En  el £ltimo lance  sali¢
un 1 y con esto llegamos a la casilla final, la 25.
*/
