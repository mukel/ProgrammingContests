/*
Alfonso Alfonso Peterssen
16 - 11 - 2007
SPOJ #109 "Exchanges"
*/
#include <cstdio>

const int MAXR = 10000;

int T, R, E, i, j, k, sol;
int mark[MAXR];

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    scanf( "%d %d", &R, &E );

    mark[0] = 0;
    for ( i = 1; i < R; i++ )
      mark[i] = 2;

    for ( ; E; E-- ) {
      scanf( "%d %d", &j, &k );
      j--; k--;
      if ( mark[k] ) {
        if ( j && mark[j] < 2 ) mark[j] = mark[k];
        mark[k]--;
      }
    }

    sol = 0;
    for ( i = 1; i < R; i++ )
      sol += mark[i];

    printf( "%d\n", sol );
  }

  return 0;
}
