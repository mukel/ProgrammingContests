/*
Alfonso Alfonso Peterssen
8 - 10 - 2007
SPOJ #1770 "Reliable Nets"
*/
#include <cstdio>
#include <cstring>

#define MAXV 30
#define MAXE 30
#define oo 1000000000

int T, V, E, i, j, k, cost, sol, bits;

bool result;

int P[MAXV];

struct edge {
  bool flag;
  int b, cost, id, next;
} ls[ 2 * MAXE ];

int cnt;
int dfsnum[MAXV];
int low[MAXV];
bool mark[MAXE];

  void dfs( int x ) {

    if ( !result ) return;

    dfsnum[x] = ++cnt;
    low[x] = ++cnt;

    int i, j;
    for ( i = P[x]; i; i = ls[i].next )
      if ( ls[i].flag && !mark[ ls[i].id ] ) {

        mark[ ls[i].id ] = true;

        j = ls[i].b;
        if ( !dfsnum[j] ) {
          dfs( j );
          low[x] <?= low[j];
          if ( low[j] > dfsnum[x] ) {
            result = false;
            return;
          }
        } else low[x] <?= dfsnum[j];
      }

    if ( low[x] > dfsnum[x] )
      result = false;
  }

  bool biconnected() {

    cnt = 0;
    result = true;
    memset( low, 0, sizeof( low ) );
    memset( dfsnum, 0, sizeof( dfsnum ) );
    memset( mark, 0, sizeof( mark ) );

    dfs( 1 );

    for ( i = 1; i <= V; i++ )
      if ( !dfsnum[i] ) break;

    if ( i <= V ) result = false;

    return result;
  }

int main() {

  for ( T = 1; ; T++ ) {

    memset( P, 0, sizeof( P ) );

    scanf( "%d %d", &V, &E );
    if ( V == 0 && E == 0 ) break;

    for ( i = 1; i <= E; i++ ) {
      scanf( "%d %d %d", &j, &k, &cost );
      ls[i] = ( edge ) { 0, j, cost, i, P[k] };
      P[k] = i;
      ls[E + i] = ( edge ) { 0, k, cost, i, P[j] };
      P[j] = E + i;
    }

    sol = oo;
    for ( bits = 1; bits < ( 1 << ( E + 1 ) ); bits++ )
      if ( __builtin_popcount( bits ) >= V ) {

        cost = 0;
        for ( i = 0; i < E; i++ )
          if ( bits & ( 1 << i ) ) {
            ls[i + 1].flag = ls[ E + i + 1].flag = true;
            cost += ls[i + 1].cost;
          }

        if ( cost < sol )
          if ( biconnected() )
            sol = cost;

        for ( i = 0; i < E; i++ )
          if ( bits & ( 1 << i ) )
            ls[i + 1].flag = ls[ E + i + 1].flag = false;
      }

    if ( sol == oo )
         printf( "There is no reliable net possible for test case %d.\n", T );
    else printf( "The minimal cost for test case %d is %d.\n", T, sol );
  }

  return 0;
}
