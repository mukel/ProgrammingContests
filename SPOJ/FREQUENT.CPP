/*
Alfonso Alfonso Peterssen
22 - 7 - 2007
SPOJ #1684 "Frequent values"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 100001
#define MAXLOG 17

int N, Q, lg, i, j;
int seq[MAXN];
int t1[2 * MAXN], t2[2 * MAXN], *P, *F;
int T[MAXLOG][MAXN];

  int log2( int x ) {
    int lg = 1;
    while ( 1 << lg < x ) lg++;
    return lg - 1;
  }

  int query( int a, int b ) {

    if ( seq[a] == seq[b] )
      return b - a + 1;

    int lg = log2( b - a + 1 ),
        mid = seq[ ( a + b ) / 2 ],
        frq = min( b, F[mid] ) - max( a, P[mid] ) + 1;

    frq >?= max( T[lg][a],
                 T[lg][ b - ( 1 << lg ) + 1 ] );
    return frq;
  }

int main() {

  /* Neg Arrays */
  P = t1 + MAXN;
  F = t2 + MAXN;

  fill_n( T[0], MAXN, 1 );

  for (;;) {

    scanf( "%d", &N ); if ( !N ) break;
    scanf( "%d", &Q );

    fill_n( t1, MAXN * 2, -1 );

    for ( i = 0; i < N; i++ ) {
      scanf( "%d", &seq[i] );
      if ( P[ seq[i] ] == -1 ) P[ seq[i] ] = i;
      F[ seq[i] ] = i;
    }

    lg = log2( N );
    for ( i = 1; i <= lg; i++ )
      for ( j = 0; j + ( 1 << i ) <= N; j++ )
        T[i][j] = query( j, j + ( 1 << i ) - 1 );

    for ( ; Q; Q-- ) {
      scanf( "%d %d", &i, &j );
      printf( "%d\n", query( i - 1, j - 1 ) );
    }

  }

  return 0;
}
