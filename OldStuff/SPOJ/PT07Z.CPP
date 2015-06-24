/*
Alfonso Alfonso Peterssen
18 - 7 - 2007
SPOJ #1437 "Longest path in a tree"
*/
#include <iostream>
using namespace std;

#define MAXV 10001

int V, i, j, k, sol;
int P[MAXV];
bool mark[MAXV];
struct edge {
  int b, id, next;
  edge ( int x = 0, int y = 0, int z = 0 )
  : b( x ), id( y ), next( z ) {}
} ls[ 2 * MAXV ];

  int dfs( int x ) {
    int i, t, longest = 0;
    for ( i = P[x]; i; i = ls[i].next )
      if ( !mark[ ls[i].id ] ) {
        mark[ ls[i].id ] = true;

        t = dfs( ls[i].b ) + 1;

        sol >?= t + longest;
        longest >?= t;
      }
    return longest;
  }

int main() {

  cin >> V;
  for ( i = 1; i < V; i++ ) {
    cin >> j >> k;
    ls[i] = edge( k, i, P[j] );
    P[j] = i;
    ls[V + i - 1] = edge( j, i, P[k] );
    P[k] = V + i - 1;
  }

  dfs( 1 );

  cout << sol << endl;

  return 0;
}
