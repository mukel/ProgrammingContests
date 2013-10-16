/*
Alfonso Alfonso Peterssen
3 - 7 - 2007
PSN 2006 #94 "Caminos Redundantes"
*/
#include <fstream>
#include <algorithm>
#include <stack>
using namespace std;

#define problem "d"
#define MAXV 5001
#define MAXE 10001

int V, E, BCC, i, j, k, cnt, sol;
int P[MAXV];
int bcc[MAXV];
int degree[MAXV];
int low[MAXV], dfsnum[MAXV];
bool bridge[MAXV], mark[MAXV];
stack< int > stk;

struct edge {
  int b, id, next;  
  edge ( int x = 0, int y = 0, int z = 0 )
  : b( x ), id( y ), next( z ) {}
} ls[2 * MAXE];

  void dfs( int x ) {
    int i, j;
    stk.push( x );
    low[x] = dfsnum[x] = ++cnt;
    
    for ( i = P[x]; i; i = ls[i].next )
      if ( !mark[ ls[i].id ] ) {
        j = ls[i].b;
        mark[ ls[i].id ] = true;
        
        if ( !low[j] ) {
          dfs( j );
          low[x] <?= low[j];
          if ( low[j] > dfsnum[x] )
            bridge[ ls[i].id ] = true;
        } else low[x] <?= dfsnum[j];
      }

    if ( low[x] == dfsnum[x] ) {
       BCC++;
       do {
         j = stk.top();
         stk.pop();
         bcc[j] = BCC;
       } while ( j != x );
    }
  }
  
ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );  

int main() {

  fin >> V >> E;
  for ( i = 1; i <= E; i++ ) {
    fin >> j >> k;
    ls[i] = edge( k, i, P[j] );
    P[j] = i;
    ls[E + i] = edge( j, i, P[k] );
    P[k] = E + i;
  }

  dfs( 1 );

  for ( i = 1; i <= 2 * E; i++ )
    if ( bridge[ ls[i].id ] )
      degree[ bcc[ ls[i].b ] ]++;

  for ( i = 1; i <= BCC; i++ )
    if ( degree[i] == 1 ) sol++;

  fout << ( sol + 1 ) / 2 << endl;

  return 0;
}

/*
94þ Caminos Redundantes.                                   M‚xico 2006
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Con el prop¢sito de  ir de uno de  los F (1 <=  F <= 5,000) campos  de
pasteo (los  cuales est n  numerados 1..F)  a otro  campo, Bessie y el
resto del  reba¤o son  forzadas a  cruzar cerca  del Arbol de Manzanas
Podridas. Las vacas est n ahora cansadas de se forzadas frecuentemente
a  tomar  un camino  particular  y quieren  construir  algunos caminos
nuevos  de tal  manera que  ellas siempre  tendr n la  posibilidad  de
elegir  entre al  menos dos  rutas separadas  entre cualquier  par  de
campos. Actualmente ellas tienen al menos una ruta entre cualquier par
de  campos y  quieren tener  al menos  dos. Por  supuesto, ellas  solo
pueden desplazarse entre Caminos  Oficiales cuando ellas se  mueven de
un campo a otro.

Dada una descripci¢n  del conjunto actual  de R (F-1  <= R <=  10,000)
caminos que conectan exactamente  dos campos diferentes, determine  el
m¡nimo  n£mero  de caminos  nuevos  (cada uno  de  los cuales  conecta
exactamente dos campos) que deben ser construidos de tal manera que al
menos hayan  dos rutas  separadas entre  cualquier par  de campos.  Se
considera que  las rutas  son separadas  si no  usan ning£n  camino en
com£n, aunque visiten el mismo campo en el recorrido.

Podr¡a ya haber m s de un camino entre el mismo par de campos, y usted
tambi‚n podr¡a construir un nuevo camino que conecte los mismos campos
con otro camino.

NOMBRE DEL PROBLEMA: rpaths

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacio: F y R.

- L¡neas 2..R+1: Cada l¡nea contiene dos enteros separados por espacio
       que son los campos en los extremos de alg£n camino.

ENTRADA EJEMPLO (archivo RPATHS.IN):

7 7
1 2
2 3
3 4
2 5
4 5
5 6
5 7

DETALLES DE LA ENTRADA:

Una visualizaci¢n de los caminos es:

   1   2   3
   +---+---+
       |   |
       |   |
 6 +---+---+ 4
      / 5
     /
    /
 7 +

FORMATO DE SALIDA:

* L¡nea 1: Un solo entero que es el n£mero de nuevos caminos que deben
        ser construidos.

SALIDA EJEMPLO (archivo RPATHS.OUT):

2

DETALLES DE LA SALIDA:

Construyendo nuevos caminos de 1 a 6 y de 4 a 7 satisface las
condiciones.
   1   2   3
   +---+---+
   :   |   |
   :   |   |
 6 +---+---+ 4
      / 5  :
     /     :
    /      :
 7 + - - - -


Verifique algunas de las rutas:
1 - 2:  1 -> 2 y 1 -> 6 -> 5 -> 2
1 - 4:  1 -> 2 -> 3 -> 4 y 1 -> 6 -> 5 -> 4
3 - 7:  3 -> 4 -> 7 y 3 -> 2 -> 5 -> 7
Cada par de caminos est , de hecho, conectado por dos rutas
*/
