/*
Alfonso Alfonso Peterssen
18 - 7 - 2007
SPOJ #1436 "Is it a tree"
*/
#include <cstdio>
#include <cstdlib>

#define MAXV 10001
#define MAXE 20001

int V, E, i, j, k;
int P[MAXV];
bool mark[MAXV], used[MAXE];
struct edge {
  int b, id, next;
  edge ( int x = 0, int y = 0, int z = 0 )
  : b( x ), id( y ), next( z ) {}
} ls[ 2 * MAXE ];

  void OUTPUT( char *answer ) {
    printf( "%s\n", answer );
    /* Suicide */
    exit( 0 );
  }

  void dfs( int x ) {
    mark[x] = true;
    for ( int i = P[x]; i; i = ls[i].next )
      if ( !used[ ls[i].id ] )
        if ( mark[ ls[i].b ] ) OUTPUT( "NO" );
        else {
          used[ ls[i].id ] = true;
          dfs( ls[i].b );
        }
  }

int main() {

  scanf( "%d %d", &V, &E );

  if ( E != V - 1 ) OUTPUT( "NO" );

  for ( i = 1; i <= E; i++ ) {
    scanf( "%d %d", &j, &k );
    ls[i] = edge( k, i, P[j] );
    P[j] = i;
    ls[E + i] = edge( j, i, P[k] );
    P[k] = E + i;
  }

  dfs( 1 );

  for ( i = 1; i <= V; i++ )
    if ( !mark[i] ) break;

  if ( i <= V ) OUTPUT( "NO" );

  OUTPUT( "YES" );

  return 0;
}
