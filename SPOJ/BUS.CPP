/*
Alfonso Alfonso Peterssen
8 - 10 - 2007
SPOJ #99 "Bus"
*/
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;

#define MAXN 50

int N, i, j, k, sol;
int pos[MAXN], sz[MAXN];
int ls[MAXN][MAXN];
bitset< MAXN > know[MAXN];
bool ok;

int main() {

  for (;;) {

    scanf( "%d", &N );
    if ( !N ) break;

    for ( i = 0; i < N; i++ ) {
      scanf( "%d", &sz[i] );
      for ( j = 0; j < sz[i]; j++ )
        scanf( "%d", &ls[i][j] );
    }

    /* Init */
    memset( pos, 0, sizeof( pos ) );
    for ( i = 0; i < N; i++ )
      for ( j = 0; j < N; j++ )
      know[i][j] = false;

    for ( i = 0; i < N; i++ )
      know[i][i] = true;

    ok = false;
    for ( sol = 0; sol < 200000; sol++ ) {

      for ( j = 0; j < N; j++ )
        for ( k = j + 1; k < N; k++ )
          if ( ls[j][ pos[j] ] == ls[k][ pos[k] ] ) {
            know[j] |= know[k];
            know[k] |= know[j];
          }

      /* FIX */
      for ( i = 0; i < N; i++ )
        if ( ++pos[i] == sz[i] )
          pos[i] = 0;

      for ( i = 0; i < N; i++ )
        for ( j = 0; j < N; j++ )
          if ( !know[i][j] ) {
            i = N + 2;
            break;
          }

      if ( i == N ) {
        ok = true;
        break;
      }

    }

    if ( ok )
         printf( "%d\n", sol );
    else printf( "NEVER\n" );
  }

  return 0;
}
