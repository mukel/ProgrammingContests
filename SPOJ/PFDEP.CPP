/*
Alfonso Alfonso Peterssen
28 - 10 - 2007
SPOJ #1846 "Project File Dependencies"
*/
#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;

const int MAXV = 101;

int V, E, S, i, j, k;
int sz[MAXV];
int ls[MAXV][MAXV];
int sorted[MAXV];
bool mark[MAXV];

  void topsort( int x ) {
    mark[x] = true;
    for ( int i = 0; i < sz[x]; i++ )
      if ( !mark[ ls[x][i] ] )
        topsort( ls[x][i] );
    sorted[S++] = x;
  }

int main() {

  scanf( "%d %d", &V, &E );

  for ( i = 0; i < E; i++ ) {
    scanf( "%d %d", &j, &k );
    for ( ; k; k-- ) {
      int x;
      scanf( "%d", &x );
      ls[x][ sz[x]++ ] = j;
    }
  }

  for ( i = 1; i <= V; i++ )
    sort( ls[i], ls[i] + sz[i], greater< int >() );

  for ( i = V; i; i-- )
    if ( !mark[i] )
      topsort( i );

  for ( i = V - 1; i; i-- )
    printf( "%d ", sorted[i] );

  printf( "%d\n", sorted[0] );

  return 0;
}
