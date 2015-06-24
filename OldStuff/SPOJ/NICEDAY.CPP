/*
Alfonso Alfonso Peterssen
6 - 10 - 2007
SPOJ #709 "The day of the competitors"
*/
#include <cstdio>

#define MAXN 100001
#define oo 1000000000

int T, N, i, j, sol;
int first[MAXN];
int place[2][MAXN];

struct {

  int size, T[MAXN];

  #define lobit( x ) ( x & -x )

  void reset( int new_size ) {
    size = new_size;
    for ( int i = 0; i <= size; i++ )
      T[i] = oo;
  }

  int update( int x, int value ) {
    for ( ; x <= size; x += lobit(x ) )
      T[x] <?= value;
  }

  int getmin( int x ) {
    int res = oo;
    for ( ; x; x -= lobit( x ) )
      res <?= T[x];
    return res;
  }

} ABI;

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    scanf( "%d", &N );

    for ( i = 1; i <= N; i++ ) {
      scanf( "%d %d %d", &j, &place[0][i], &place[1][i] );
      first[j - 1] = i;
    }

    /* Init */
    sol = 0;
    ABI.reset( N );

    /* Solve */
    for ( i = 0; i < N; i++ ) {

      j = first[i];

      if ( ABI.getmin( place[0][j] ) > place[1][j] ) {
        ABI.update( place[0][j], place[1][j] );
        sol++;
      }
	}

    printf( "%d\n", sol );
  }

  return 0;
}
