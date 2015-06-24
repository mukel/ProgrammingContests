/*
Alfonso Alfonso Peterssen
24 - 6 - 2007
PSN 2007 #52 "Tr fico Vacuno"
*/
#include <fstream>
#include <vector>
using namespace std;

#define problem "d"
#define MAXV 5001

#define tr( v, it ) for ( typeof( v.begin() ) it = v.begin(); it != v.end(); it++ )
typedef vector< vector< int > > graph;

int V, E, i, j, k, sol;
int C1[MAXV], C2[MAXV];
graph G1, G2;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> V >> E;
  G1.resize( V + 1 ); G2.resize( V + 1 );
  for ( i = 0; i < E; i++ ) {
    fin >> j >> k;
    G1[j].push_back( k );
    G2[k].push_back( j );
  }

  for ( i = 1; i <= V; i++ ) {
    if ( !C1[i] ) C1[i] = 1;
    tr( G1[i], it ) C1[ *it ] += C1[i];
  }

  C2[V] = 1;
  for ( i = V; i ; i-- )
    tr( G2[i], it ) C2[ *it ] += C2[i];

  for ( i = V; i; i-- )
    tr( G1[i], it ) sol >?= C1[i] * C2[ *it ];

  fout << sol << endl;

  return 0;
}

/*
52þ Tr fico Vacuno.                                       Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

El  incremento  de  poblaci¢n  bovina  en  la  granja  ha  causado una
congesti¢n seria en los senderos que conducen al establo. El  Granjero
Juan ha  decidido conducir  un estudio  para encontrar  los cuellos de
botella con  el prop¢sito de  aliviar  los `tranques  de tr fico?   en
los tiempos de orde¤o

El pastizal contiene una  red de M (1  <= M <= 50,000)  senderos de un
sentido, cada uno de los cuales conecta exactamente dos intersecciones
diferentes  del  conjunto  de  N  (1  <=  N  <=  5,000) intersecciones
convenientemente numeradas 1..N; el establo est  en la intersecci¢n N.
Cada  sendero  conecta un  punto  de intersecci¢n  con  otro punto  de
intersecci¢n  con un  n£mero mayor.  Como resultado  de esto,  no hay
ciclos y, como se  dice en la granja,  todos los senderos conducen  al
establo. Un par de puntos  de intersecci¢n podr  estar conectados  por
m s de un sendero.

Durante  la  hora  pico  de  orde¤o  las  vacas  empiezan  desde   sus
ubicaciones  respectivas  de  pasteo  y  se  dirigen  al  establo. Las
ubicaciones de pasteo son exactamente aquellos puntos de  intersecci¢n
con nig£n senderos que lleguen a ellos. Cada vaca recorre un ïcaminoï,
el  cual  est   definido  como  una  secuencia  de  senderos  desde su
ubicaci¢n de pasteo hasta el establo.

Ayude al GJ encontrando  el(los) sendero(s) m s ocupado(s)  calculando
el  n£mero m s  grande de  caminos  posibles  que  contiene  cualquier
sendero. Se garantiza que la respuesta entra en un entero de 32 bits.

NOMBRE DEL PROBLEMA: traffic

FORMATO DE ENTRADA:

- L¡nea 1: Dos enteros separados por espacio, respectivamente: N y M

- L¡nea 2..M+1: Dos puntos de intersecci¢n separados por espacio.


ENTRADA EJEMPLO (archivo traffic.in):

7 7
1 3
3 4
3 5
4 6
2 3
5 6
6 7

DETALLES DE LA ENTRADA:

     1   4
      \ / \
       3   6 -- 7
      / \ /
     2   5

FORMATO DE SALIDA:

- El n£mero m¡nimo de caminos pasando a trav‚s de un sendero

SALIDA EJEMPLO (archivo traffic.OUT):

4

DETALLES DE LA SALIDA:

Aqu¡ est n los cuatro caminos posibles que conducen al establo:

         1 3 4 6 7
         1 3 5 6 7
         2 3 4 6 7
         2 3 5 6 7
*/
