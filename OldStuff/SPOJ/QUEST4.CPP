/*
Alfonso Alfonso Peterssen
26 - 10 - 2007
SPOJ #660 "Dungeon of Death"
*/
#include <cstdio>
#include <cstring>

const int MAXV = 121;

int T, N, i, j, k, sol;
int prev[MAXV];
bool mark[MAXV];
int cap[MAXV][MAXV];

  bool augment( int x ) {

    if ( mark[x] ) return false;
    mark[x] = true;

    for ( int i = 1; i < MAXV; i++ )
      if ( cap[x][i] && ( !prev[i] || augment( prev[i] ) ) ) {
        prev[i] = x;
        return true;
      }

    return false;
  }

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    sol = 0;
    memset( cap, 0, sizeof( cap ) );
    memset( prev, 0, sizeof( prev ) );

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
      scanf( "%d %d", &j, &k );
      j++; k++;
      cap[j][k] = 1;
    }

    for ( i = 1; i < MAXV; i++ ) {
      memset( mark, false, sizeof( mark ) );
      if ( augment( i ) ) sol++;
    }

    printf( "%d\n", sol );
  }

  return 0;
}
