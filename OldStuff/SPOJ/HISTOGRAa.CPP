/*
Alfonso Alfonso Peterssen
16 - 11 - 2007
SPOJ #1805 "Largest Rectangle in a Histogram"
O( n )
*/
#include <cstdio>

typedef long long int64;

const int MAXN = 100005;

int N, i, j;
int ls[MAXN];
int next[MAXN], last[MAXN];

int main() {

  for (;;) {

    scanf( "%d", &N );
    if ( !N ) break;

    for ( i = 1; i <= N; i++ )
      scanf( "%d", &ls[i] );

    ls[0] = ls[N + 1] = -1;

    /* Preprocess */
    for ( i = N; i; i-- ) {
      for ( j = i + 1; ls[j] >= ls[i]; j = next[j] );
      next[i] = j;
    }

    for ( i = 1; i <= N; i++ ) {
      for ( j = i - 1; ls[j] >= ls[i]; j = last[j] );
      last[i] = j;
    }

    /* Solve */
    int64 sol = 0;
    for ( i = N; i; i-- )
      sol >?= ( int64 )ls[i] * ( next[i] - last[i] - 1 );

    printf( "%lld\n", sol );
  }

  return 0;
}
