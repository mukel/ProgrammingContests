/*
Alfonso2 Peterssen
SPOJ #153 "Balancing the Stone"
7 - 9 - 2008
*/
#include <cstdio>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXL = 10000001;

int T, N, L, D;
char M[MAXL];
int dp[2];

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d %d %d", &N, &L, &D );
		scanf( "%s", &M );
		dp[0] = 1; dp[1] = 0;
		REP( i, N - L )
			dp[1] = ( dp[0] + dp[1] ) % D;
		REP( i, L )
			dp[ M[i] == '0' ] = ( dp[0] + dp[1] ) % D;
		printf( "%d\n", dp[0] );
	}

	return 0;
}
