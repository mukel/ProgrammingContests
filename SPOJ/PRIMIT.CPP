/*
Alfonso Alfonso Peterssen
17 - 11 - 2007
SPOJ #211 "Primitivus recurencis"
Que pillo, por eso los polacos estan tan bien...
*/
#include <cstdio>
#include <cstring>

const int MAXV = 1000;

int T, N, i, j, k, sol;
bool used[MAXV];
int P[MAXV], comp[MAXV], cnt[MAXV];

  int find( int x ) {
    if ( x != P[x] ) P[x] = find( P[x] );
    return P[x];
  }

  void join( int x, int y ) {
    P[ find( x ) ] = find( y );
  }

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    /* Init */
    sol = 0;
    memset( used, 0, sizeof( used ) );
    memset( cnt, 0, sizeof( cnt ) );
    for ( i = 0; i < MAXV; i++ )
      P[i] = i, comp[i] = -1;

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
      scanf( "%d %d", &j, &k );
      j--; k--;
      join( j, k );
      used[j] = used[k] = true;
      cnt[j]++; cnt[k]--;
    }

    for ( i = 0; i < MAXV; i++ )
      if ( used[i] ) {
        int x = find( i );
        if ( comp[x] == -1 ) comp[x] = 0;
        if ( cnt[i] > 0 )
          comp[x] += cnt[i];
      }

    for ( i = 0; i < MAXV; i++ )
      if ( comp[i] != -1 )
        sol += ( comp[i] == 0 ? 1 : comp[i] );

    printf( "%d\n", sol + N );
  }

  return 0;
}
