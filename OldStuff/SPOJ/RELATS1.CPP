/*
Alfonso Alfonso Peterssen
8 - 10 - 2007
SPOJ #70 "Relations"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXV 1000
#define MAXE 10001

int T, V, E, S, S_equal, i, j, k, sign, sol;
int deep[MAXV];
int P[MAXV], P_equal[MAXV];

struct edge {
  int b, next;
} ls[ 3 * MAXE ], ls_equal[ 3 * MAXE ];

  int dfs( int x ) {

    if ( deep[x] != -1 )
      return deep[x];

    deep[x] = 0;

    int i;

    /* non-equal */
    for ( i = P[x]; i; i = ls[i].next )
      deep[x] >?= dfs( ls[i].b ) + 1;

    /* equal */
    for ( i = P_equal[x]; i; i = ls_equal[i].next )
      deep[x] >?= dfs( ls_equal[i].b );

    return deep[x];
  }

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    scanf( "%d %d", &V, &E );

    /* Init */
    sol = S = S_equal = 0;
    fill( deep, deep + V, -1 );
    fill( P, P + V, 0 );
    fill( P_equal, P_equal + V, 0 );

    for ( i = 0; i < E; i++ ) {
      scanf( "%d %d %d", &j, &k, &sign );
      j--, k--;

      if ( sign == 0 ) {
        ls_equal[++S_equal] = ( edge ) { k, P_equal[j] };
        P_equal[j] = S_equal;

        ls_equal[++S_equal] = ( edge ) { j, P_equal[k] };
        P_equal[k] = S_equal;
        continue;
      }

      if ( sign == -1 ) swap( j, k );

      ls[++S] = ( edge ) { k, P[j] };
      P[j] = S;
    }

    for ( i = 0; i < V; i++ )
      sol >?= dfs( i );

    for ( i = 0; i < V; i++ ) {

      /* non-equal */
      for ( j = P[i]; j; j = ls[j].next )
        if ( deep[i] < deep[ ls[j].b ] ) break;

      if ( j ) break;

      /* equal */
      for ( j = P_equal[i]; j; j = ls_equal[j].next )
        if ( deep[i] != deep[ ls_equal[j].b ] ) break;

      if ( j ) break;

    }

    if ( i == V ) {
      printf( "%d\n", sol );
    } else printf( "NO\n" );
  }

  return 0;
}
