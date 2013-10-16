/*
Alfonso Alfonso Peterssen
10 - 11 - 2007
SPOJ #1805 "Largest Rectangle in a Histogram"
O( n lg n ) -> RMQ
*/
#include <cstdio>

typedef long long int64;

const int
  MAXN = 100000,
  MAXLOG = 17;

int N, i, j, lg;
int RMQ[MAXLOG][MAXN];
int64 sol;

  int log2( int x ) {
    int res = 1;
    while ( 1 << res < x ) res++;
    return res - 1;
  }

  int query( int lo, int hi ) {
    int lg = log2( hi - lo + 1 );
    return ( RMQ[lg][lo] <? RMQ[lg][hi - ( 1 << lg ) + 1] );
  }

  int bs_lower( int lo, int hi ) {

    int h = RMQ[0][hi], x = hi;

    while ( lo < hi ) {
      int mid = ( lo + hi ) / 2;
      if ( query( mid, x ) < h )
           lo = mid + 1;
      else hi = mid;
    }

    return lo;
  }

  int bs_upper( int lo, int hi ) {

    int h = RMQ[0][lo], x = lo;

    while ( lo < hi ) {
      int mid = ( lo + hi + 1 ) / 2;
      if ( query( x, mid ) < h )
           hi = mid - 1;
      else lo = mid;
    }

    return hi;
  }

int main() {

  for (;;) {

    scanf( "%d", &N );
    if ( N == 0 ) break;

    for ( i = 0; i < N; i++ )
      scanf( "%d", &RMQ[0][i] );

    /* Preprocess */
    lg = log2( N );
    for ( i = 1; i <= lg; i++ )
      for ( j = N - ( 1 << i ); j >= 0; j-- )
        RMQ[i][j] = ( RMQ[i - 1][j] <?
                      RMQ[i - 1][j + ( 1 << ( i - 1 ) )] );

    /* Solve */
    sol = 0;
    for ( i = 0; i < N; i++ ) {
      int lo, hi;
      lo = bs_lower( 0, i );
      hi = bs_upper( i, N - 1 );
      sol >?= ( int64 )( hi - lo + 1 ) * RMQ[0][i];
    }

    printf( "%lld\n", sol );
  }

  return 0;
}
