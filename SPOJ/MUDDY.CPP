/*
Alfonso Alfonso Peterssen
SPOJ #282 "Muddy Fields"
*/
#include <cstdio>
#include <cstring> // memset

#define MAXV 1251
#define MAXF 51

int T, F, C, H, V, i, j, flow;
char mat[MAXF][MAXF];
bool mark[MAXV];
int cap[MAXV][MAXV], prev[MAXV];
int vidx[MAXF][MAXF], hidx[MAXF][MAXF];

  bool augment( int x ) {

    if ( mark[x] ) return false;

    mark[x] = true;
    for ( int i = 1; i <= H; i++ )
      if ( cap[x][i] && ( !prev[i] || augment( prev[i] ) ) ) {
        prev[i] = x;
        return true;
      }

    return false;
  }

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    flow = 0;
    H = V = 0;
    memset( cap, 0, sizeof( cap ) );
    memset( prev, 0, sizeof( prev ) );

    scanf( "%d %d", &F, &C );
    for ( i = 0; i < F; i++ )
      scanf( "%s", &mat[i] );

    for ( i = 0; i < F; i++ )
      for ( j = 0; j < C; j++ )
        if ( mat[i][j] == '*' ) {

          if ( i == 0 || mat[i - 1][j] == '.' )
               vidx[i][j] = ++V;
          else vidx[i][j] = vidx[i - 1][j];

          if ( j == 0 || mat[i][j - 1] == '.' )
               hidx[i][j] = ++H;
          else hidx[i][j] = hidx[i][j - 1];

          cap[ vidx[i][j] ][ hidx[i][j] ] = 1;
        }

    for ( i = 1; i <= V; i++ ) {
      memset( mark, false, sizeof( mark ) );
      if ( augment( i ) ) flow++;
    }

    printf( "%d\n", flow );
  }

  return 0;
}
