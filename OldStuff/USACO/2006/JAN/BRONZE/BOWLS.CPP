/*
Alfonso Alfonso Peterssen
16 - 9 - 2007
USACO 2006 JAN Silver "Los Tazones de Agua"
*/
#include <fstream>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXN 20

int i, j, bowls;

  int test( int bowls ) {

    int i, swaps = 0;

    for ( i = 0; i < MAXN - 1; i++ )
      if ( bowls & ( 1 << i ) ) {
        swaps++;
        bowls ^= 7 << i;
      }

    if ( bowls & ( 1 << i ) ) return MAXN;
    return swaps;
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  for ( i = 0; i < MAXN; i++ ) {
    fin >> j;
    bowls |= j << i;
  }

  fout << min( test( bowls ),
               test( bowls ^ 3 ) + 1 )
       << endl;

  return 0;
}

/*

Problema 13: Los Tazones de Agua [Hal Burch, 2005]

Las vacas tienen una l�nea de 20 tazones de agua de donde ellas toman.
Los tazones pueden estar orientados hacia arriba (orientados
apropiadamente para servir agua fr�a refrescante) o hacia abajo (una
posici�n en la cual no pueden tener agua).  Ellas quieren que sus 20
tazones de agua est�n hacia arriba y por lo tanto usar sus hocicos anchos
para voltear los tazones.

Sus hocicos, sin embargo, son tan anchos que no solamente voltean un
taz�n sino los tazones en cualquier lado de ese taz�n (un total tres o �
en el caso de cualquier taz�n de un extremo � dos tazones).

Dado el estado inicial de los tazones (1=no tomable, 0=tomable) �cu�l es
el m�nimo numero de volteadas de tazones para poner todos los tazones
hacia arriba?

NOMBRE DEL PROBLEMA: bowls

FORMATO DE ENTRADA:

* L�nea 1: Un solo entero con 20 enteros separados por espacios


ENTRADA EJEMPLO (archivo bowls.in):

0 0 1 1 1 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0

FORMATO DE SALIDA:

* L�nea 1: El n�mero m�nimo de volteadas de tazones necesario para poner
          todos los tazones hacia arriba (esto es, a 0). Para las
          las entradas dadas siempre ser� posible encontrar alguna
          combinaci�n de volteadas que manipularan los tazones a 20
          0�s.



SALIDA EJEMPLO (archivo bowls.out):

3

DETALLES DE LA SALIDA:

Voltear los tazones 4, 9, y 11 para hacer que se pueda tomar de todos:
0 0 1 1 1 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0 [estado inicial]
0 0 0 0 0 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0 [despu�s de voltear el taz�n 4]
0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 [despu�s de voltear el taz�n 9]
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 [despu�s de voltear el taz�n 11]
*/
