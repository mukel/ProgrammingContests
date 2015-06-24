/*
Alfonso2 Peterssen (mukel)
SPOJ #3885 "Coins Game"
21 - 5 - 2009
*/
#include <cstdio>

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXN = 1 << 20;

int N, A, B;
bool dp[MAXN];

int main() {

	scanf( "%d %d %d", &A, &B, &N );

	REP( i, MAXN ) {
	      if ( i - 1 >= 0 ) dp[i] |= !dp[i - 1];
 	      if ( i - A >= 0 ) dp[i] |= !dp[i - A];
  	      if ( i - B >= 0 ) dp[i] |= !dp[i - B];
	}
	
	REP( i, N ) {
		int val;
		scanf( "%d", &val );
		printf( "%c", dp[val] ? 'A' : 'B' );
	}

	return 0;
}
