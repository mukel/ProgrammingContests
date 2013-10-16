/*
Alfonso Alfonso Peterssen
7 - 7 - 2007
PSN 2007 #110 "Cenando"
La implemetacion de siempre no me funciono,
pero esta( la del analisis ) esta mejor.
*/
#include <fstream>
#include <queue>
using namespace std;

#define problem "d"
#define MAXV 800

int N, F, D, src, snk, flow;
int sz[MAXV];
int ls[MAXV][MAXV];
int cap[MAXV][MAXV];
int prev[MAXV];

  void add( int u, int v ) {
    ls[u][ ++sz[u] ] = v;
    ls[v][ ++sz[v] ] = u;
    cap[u][v] = 1;
  }

  bool augment() {
    int i, j, x;
    queue< int > Q;

    Q.push( src );
    memset( prev, 0, sizeof( prev ) );

    while ( !Q.empty() && !prev[snk] ) {
      i = Q.front();
      Q.pop();
      for ( j = 1; j <= sz[i]; j++ ) {
        x = ls[i][j];
        if ( !prev[x] && cap[i][x] ) {
          prev[x] = i;
          if ( x == snk ) break;
          Q.push( x );
        }
      }
    }

    if ( !prev[snk] ) return false;

    for ( ; x != src; x = prev[x] )
      cap[ prev[x] ][x]--, cap[x][ prev[x] ]++;

    return true;
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  int i, j, k, h;

  fin >> N >> F >> D;

  for ( i = F + 1; i <= F + N; i++ ) {
    fin >> j >> k;
    for ( ; j; j-- )
      fin >> h, add( h, i );

    for ( ; k; k-- )
      fin >> h, add( N + i, F + 2 * N + h );

    add( i, N + i );
  }

  src = F + 2 * N + D + 1;
  snk = src + 1;;

  for ( i = 1; i <= D; i++ ) add( F + 2 * N + i, snk );
  for ( i = 1; i <= F; i++ ) add( src, i );

  while ( augment() ) flow++;

  fout << flow << endl;

  return 0;
}

/*
111þ Cenando.                                             Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Las  vacas  son  muy  caprichosas  para  comer.  Cada  vaca  tiene una
preferencia  por  ciertas comidas  y  bebidas, y  ellas  no consumir n
otras.

El Granjero Juan ha cocinado comidas fabulosas para sus vacas, pero ‚l
se olvid¢ verificar su men£ contra sus preferencias. Aunque ‚l  podr¡a
no ser capaz de  satisfacer a todas, ‚l  quiere dar una cena  completa
tanto de comida como de bebida a tantas vacas como sea posible.

El Granjero Juan ha cocinado F (1 <= F <= 100) tipos de  comidas
y preparado D (1 <= D <= 100) tipos de bebidas. Cada una de  sus
N (1  <= N  <= 100)  vacas ha  decidido si  ella desea comer una
comida  particular  o una  bebida  particular. El  Granjero  Juan debe
asignar  un tipo  de comida  y un  tipo de  bebida a  cada vaca  para
maximizar el n£mero de vacas que obtengan ambas cosas.

Cada plato o bebida  puede solo ser consumida  por una vaca (esto  es,
una vez que la comida de tipo 2 es asignada a una vaca, a ninguna otra
se le puede asignar comida de tipo 2).

NOMBRE DEL PROBLEMA: dining

FORMATO DE ENTRADA:

* L¡nea 1: Tres enteros separados por espacios: N, F, y D.

* L¡neas 2..N+1: Cada l¡nea i comienza con dos enteros F_i y D_i, el
         n£mero de comidas que le gustan a la vaca i y el n£mero de
         bebidas que le gustan a la vaca i. Los siguientes F_i enteros
         denotan las comidas que la vaca i comer , y los
         D_i enteros que siguen denotan las bebidas que la vaca i
         tomar .


ENTRADA EJEMPLO (archivo dining.in)

4 3 3
2 2 1 2 3 1
2 2 2 3 1 2
2 2 1 3 1 2
2 1 1 3 3

DETALLES DE LA ENTRADA:

Vaca 1:  comidas de {1,2}, bebidas de {1,3}
Vaca 2:  comidas de {2,3}, bebidas de {1,2}
Vaca 3:  comidas de {1,3}, bebidas de {1,2}
Vaca 4:  comidas de {1,3}, bebidas de {3}


FORMATO DE SALIDA:

* L¡nea 1: Un solo entero que es el n£mero m ximo de vacas a las que
         se les puede dar tanto comida y bebida que satisfagan sus deseos.

EJEMPLO DE SALIDA (archivo dining.out):

3
4

DETALLES DE LA SALIDA:

Una manera de satisfacer tres vacas es:
Vaca 1: ninguna comida ni bebida
Vaca 2: Comida #2, Bebida #2
Vaca 3: Comida #1, Bebida #1
Vaca 4: Comida #3, Bebida #3

El principio  de casillas  nos dice  que no  podemos hacer  nada mejor
desde  que  hay  solo  tres clases  de  bebidas  o  de bebidas.  Otros
conjuntos de prueba, son por supuesto, m s desafiantes.
*/
