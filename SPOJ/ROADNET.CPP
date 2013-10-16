/*
Alfonso Alfonso Peterssen
19 - 7 - 2007
SPOJ #178 "Road net"
*/
#include <cstdio>

#define MAXV 200

int T, V, i, j, k;
int C[MAXV][MAXV];

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    scanf( "%d", &V );
    for ( i = 0; i < V; i++ )
      for ( j = 0; j < V; j++ )
        scanf( "%d", &C[i][j] );

    for ( i = 0; i < V; i++ )
      for ( j = i + 1; j < V; j++ ) {

        for ( k = 0; k < V; k++ )
          if ( k != i && k != j )
            if ( C[i][k] + C[k][j] == C[i][j] ) break;

        if ( k == V )
          printf( "%d %d\n", i + 1, j + 1 );
      }

    printf( "\n" );

  }

  return 0;
}
