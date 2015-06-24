/*
Alfonso Alfonso Peterssen
30 - 9 - 2007
SPOJ #1799 "The Bottom of a Graph"
*/
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;

#define MAXV 5001
#define MAXE 1000000

int V, E, cnt, dfs_tree, SCC, i, j, k;
stack< int > S;
int P[MAXV];
bool mark[MAXV];
int visited[MAXV];
int comp[MAXV];
int dfsnum[MAXV], low[MAXV];
struct node { int B, next; } ls[MAXE];

  void dfs( int x ) {

    S.push( x );
    visited[x] = dfs_tree;
    dfsnum[x] = low[x] = ++cnt;

    int i, j;
    for ( i = P[x]; i; i = ls[i].next ) {
      j = ls[i].B;
      if ( !low[j] ) {
        dfs( j );
        low[x] <?= low[j];
      } else if ( visited[j] == dfs_tree ) low[x] <?= dfsnum[j];
    }

    if ( low[x] == dfsnum[x] ) {
      do {
        j = S.top();
        comp[j] = SCC;
        S.pop();
      } while ( j != x );
      SCC++;
    }
  }

int main() {

  for (;;) {

    scanf( "%d", &V );
    if ( !V ) break;

    /* Init */
    cnt = dfs_tree = SCC = 0;
    fill( P, P + V, 0 );
    fill( comp, comp + V, 0 );
    fill( low, low + V, 0 );
    fill( dfsnum, dfsnum + V, 0 );
    fill( mark, mark + V, false );
    fill( visited, visited + V, 0 );

    scanf( "%d", &E );
    for ( i = 1; i <= E; i++ ) {
      scanf( "%d %d", &j, &k );
      j--, k--;
      ls[i] = ( node ) { k, P[j] };
      P[j] = i;
    }

    for ( i = 0; i < V; i++ )
      if ( !dfsnum[i] ) {
        dfs_tree++;
        dfs( i );
      }

    for ( i = 0; i < V; i++ )
      for ( j = P[i]; j; j = ls[j].next )
        if ( comp[ ls[j].B ] != comp[i] )
          mark[ comp[i] ] = true;

    bool empty = true;
    for ( i = 0; i < V; i++ )
      if ( !mark[ comp[i] ] ) {
        if ( !empty ) printf( " " );
        printf( "%d", i + 1 );
        empty = false;
      }

    printf( "\n" );
  }

  return 0;
}
