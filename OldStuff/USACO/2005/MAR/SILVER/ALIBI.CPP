/*
Alfonso Alfonso Peterssen
13 - 8 - 2007
USACO 2005 MAR Silver "Verificando una coartada"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXV 501
#define MAXC 100

int V, E, cows, LIMIT, i, j, k, sol;
int C[MAXV][MAXV];
int D[MAXV];
int field[MAXC];
bool mark[MAXV];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> V >> E >> cows >> LIMIT;

  memset( C, 127, sizeof( C ) );
  memset( D, 127, sizeof( D ) );

  for ( i = 0; i < E; i++ ) {
    int u, v, w;
    fin >> u >> v >> w;
    C[u][v] = C[v][u] <?= w;
  }

  for ( i = 0; i < cows; i++ )
    fin >> field[i];

  /* Dijkstra */
  D[1] = 0;
  for ( i = 0; i < V; i++ ) {

    k = 0;
    for ( j = 1; j <= V; j++ )
      if ( !mark[j] && D[j] < D[k] ) k = j;

    for ( j = 1; j <= V; j++ )
      D[j] <?= D[k] + C[k][j];

    if ( D[k] > LIMIT ) break;
    mark[k] = true;
  }

  for ( i = 0; i < cows; i++ )
    if ( mark[ field[i] ] ) sol++;

  fout << sol << endl;

  for ( i = 0; i < cows; i++ )
    if ( mark[ field[i] ] )
      fout << i + 1 << endl;

  return 0;
}

/*
Problema 7: Verificando una coartada [Entrenadores, 2004]

Un crimen ha sido cometido: una carga de grano ha sido tomada del
establo por una de las vacas de GJ. GJ está tratando de determinar
cual de sus C (1 <= C <= 100) vacas es la culpable. Afortunadamente,
un satélite que pasaba por la zona tomó una imagen de su granja M (1
<= M <= 70000) segundos antes que el crimen tuviera lugar, dando la
ubicación de todas las vacas. El quiere saber cuales vacas tenían
tiempo para llegar al establo y robar el grano.

La granja del Granjero Juan comprende F (1 <= F <= 500) campos
numerados 1..F que están conectados por P (1 <= P <= 1,000) caminos
bidireccionales cuyo tiempo de recorrido está en el rango 1..70000
segundos (las vacas caminan muy despacio). El campo 1 contiene al
establo. No toma ningún tiempo desplazarse dentro de un campo.

Dada la distribución de la granja del Granjero Juan y la ubicación de
cada vaca cuando el satélite pasó por encima, determine el conjunto de
vacas que podrían ser culpables.

NOMBRE DEL PROLEMA: alibi

FORMATO DE ENTRADA:

* Línea 1: Cuatro enteros separados por espacios: F, P, C y M

* Líneas 2..P+1: Tres enteros separados por espacios describiendo un
    camino: F1, F2 y T. El camino conecta F1 y F2 y se requieren T
    segundos para recorrerlo.

* Líneas P+2..P+C+1: Un entero por línea, la ubicación de una vaca.
    La primera línea da el número del campo donde está la vaca 1, la
    segunda de la vaca 2, etc.

ENTRADA EJEMPLO (archivo alibi.in):

7 6 5 8
1 4 2
1 2 1
2 3 6
3 5 5
5 4 6
1 7 9
1
4
5
3
7


DETALLES DE LA ENTRADA:

Campos/distancias como esto:
          6
      4------5
      |      |
     2|      |
      |      |
7-----1      |5
   9  |      |
     1|      |
      |      |
      2------3
          6

FORMATO DE SALIDA

* Línea 1: Un solo entero N, el numero de vacas que podrían ser
    culpables del crimen.

* Líneas 2..N+1: Un solo número de vaca en cada línea que es una de
    las vacas que podrían ser culpables del crimen. La lista debe estar
    en orden ascendente.

SALIDA EJEMPLO (archivo alibi.out):

4
1
2
3
4

DETALLES DE LA SALIDA:

Cualquier vaca, excepto la 5 podría haberlo hecho. A la vaca 5 le
hubiera tomado 9 segundos llegar al establo.
*/
