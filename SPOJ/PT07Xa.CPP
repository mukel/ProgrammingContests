/*
Alfonso Alfonso Peterssen
10 - 11 - 2007
SPOJ #1435 "Vertex Cover"
*/
#include <cstdio>

const int MAXV = 100000;

int V, i, j, k;
int vc[MAXV][2];
bool mark[MAXV];
int P[MAXV];
struct edge {
  int v, next;
} ls[ 2 * MAXV ];

  void dfs( int x ) {

    mark[x] = true;
    vc[x][1] = 1;

    int i, y;
    for ( i = P[x]; i; i = ls[i].next )
      if ( !mark[ y = ls[i].v ] ) {
        dfs( y );
        vc[x][0] += vc[y][1];
        vc[x][1] += ( vc[y][0] <? vc[y][1] );
      }

  }

int main() {

  scanf( "%d", &V );
  for ( i = 1; i < V; i++ ) {
    scanf( "%d %d", &j, &k );
    j--; k--;
    ls[i] = ( edge ) { k, P[j] };
    P[j] = i;
    ls[V + i] = ( edge ) { j, P[k] };
    P[k] = V + i;
  }

  dfs( 0 );

  printf( "%d\n", vc[0][0] <? vc[0][1] );

  return 0;
}
