/*
Alfonso Alfonso Peterssen
8 - 7 - 2007
PSN 2007 #109 "Fiesta Vacuna Bronce"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXV 1001

int V, E, X, i, j, k, h;
int D[MAXV];
int C[MAXV][MAXV];
bool mark[MAXV];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> V >> E >> X;

  memset( C, 127, sizeof( C ) );
  memset( D, 127, sizeof( D ) );
  D[X] = 0;

  for ( i = 0; i < E; i++ ) {
    fin >> j >> k >> h;
    C[j][k] = C[k][j] <?= h;
  }

  /* Dijkstra */
  for ( i = 0; i < V; i++ ) {
    for ( k = 0, j = 1; j <= V; j++ )
      if ( !mark[j] && D[j] < D[k] ) k = j;
    for ( j = 1; j <= V; j++ )
      D[j] <?= D[k] + C[k][j];
    mark[k] = true;
  }

  fout << D[k] * 2 << endl;

  return 0;
}

/*
109þ Fiesta Vacuna Bronce.                                Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Una vaca de cada  una de N granjas  (1 <= N <=  1000) convenientemente
numeradas 1..N van a ir a  una gran fiesta vacuna que tendr   lugar en
la granja  #X (1  <= X  <= N).  Un total  de  M  (1 <=  M <=  100,000)
carreteras bidireccionales conectan pares  de granjas; la carretera  i
requiere  Ti (1  <= Ti  <= 100)  unidades de  tiempo para  recorrerse.
Algunas granjas est n  conectadas por dos  caminos; todas las  granjas
est n conectadas por al menos una carretera.

Despu‚s que las vacas se reunen  en la granja #X, ellas se  dan cuenta
que cada vaca se olvid¢ algo en su granja. Ellas deciden suspender  la
fiesta y enviar todas las vacas de regreso a sus granjas para traer lo
que se les olvid¢.  Todas las vacas usan  rutas optimas para ir  a sus
granjas  y  devolverse a  la  fiesta. Cu l  es  el m¡nimo  n£mero  de
unidades de tiempo que la fiesta debe ser suspendida?

NOMBRE DEL PROBLEMA: bparty

FORMATO DE ENTRADA:

* L¡nea 1: Tres enteros separados por espacios, respectivamente: N, M
      y X.

* L¡neas 2..M+1: La l¡nea i+1 describe la carretera i con tres enteros
separados por espacios,  respectivamente: Ai, Bi,  y Ti. La  carretera
descrita  conecta  Ai y  Bi  y requiere  Ti  unidades de  tiempo  para
recorrerse.

Entrada Ejemplo (archivo bparty.in):

4 8 2
1 2 7
1 3 8
1 4 4
2 1 3
2 3 1
3 1 2
3 4 6
4 2 2

DETALLES DE LA ENTRADA:

Cuatro vacas; ocho caminos; la fiesta en la granja 2.

FORMATO DE SALIDA:

- L¡nea 1: Un entero: la m¡nima cantidad de tiempo en que la fiesta debe
ser suspendida.

ARCHIVO EJEMPLO (archivo bparty.out):

6

DETALLES DE LA SALIDA:

Existen carreteras directas que conectan  a la granja 2 con  las otras
granjas( a la granja 1: 7 y 3; a la granja 3: 1; a la granja 4: 2). El
camino m s  largo tiene  longitud 3,  por lo  tanto el  viaje de ida y
vuelta es de 6.
*/
