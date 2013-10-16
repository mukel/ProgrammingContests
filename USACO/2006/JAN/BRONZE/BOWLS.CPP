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

Las vacas tienen una línea de 20 tazones de agua de donde ellas toman.
Los tazones pueden estar orientados hacia arriba (orientados
apropiadamente para servir agua fría refrescante) o hacia abajo (una
posición en la cual no pueden tener agua).  Ellas quieren que sus 20
tazones de agua estén hacia arriba y por lo tanto usar sus hocicos anchos
para voltear los tazones.

Sus hocicos, sin embargo, son tan anchos que no solamente voltean un
tazón sino los tazones en cualquier lado de ese tazón (un total tres o –
en el caso de cualquier tazón de un extremo – dos tazones).

Dado el estado inicial de los tazones (1=no tomable, 0=tomable) ¿cuál es
el mínimo numero de volteadas de tazones para poner todos los tazones
hacia arriba?

NOMBRE DEL PROBLEMA: bowls

FORMATO DE ENTRADA:

* Lìnea 1: Un solo entero con 20 enteros separados por espacios


ENTRADA EJEMPLO (archivo bowls.in):

0 0 1 1 1 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0

FORMATO DE SALIDA:

* Línea 1: El número mínimo de volteadas de tazones necesario para poner
          todos los tazones hacia arriba (esto es, a 0). Para las
          las entradas dadas siempre será posible encontrar alguna
          combinación de volteadas que manipularan los tazones a 20
          0´s.



SALIDA EJEMPLO (archivo bowls.out):

3

DETALLES DE LA SALIDA:

Voltear los tazones 4, 9, y 11 para hacer que se pueda tomar de todos:
0 0 1 1 1 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0 [estado inicial]
0 0 0 0 0 0 0 1 1 0 1 1 0 0 0 0 0 0 0 0 [después de voltear el tazón 4]
0 0 0 0 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 [después de voltear el tazón 9]
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 [después de voltear el tazón 11]
*/
