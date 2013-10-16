/*
Alfonso2 Peterssen (mukel)
23 - 12 - 2008
USACO NOV08 "Mixed Up Cows"
*/
#include <cstdio>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int MAXN = 17;

int N, K;
int id[MAXN];
int64 dp[ 1 << MAXN ][MAXN];

template< typename T > T abs( const T x ) { return x < 0 ? -x : x; }

int main() {

	scanf( "%d %d", &N, &K );
	REP( i, N )
	      scanf( "%d", &id[i] );

	REP( i, N )
		dp[1 << i][i] = 1;

	REP( i, ( 1 << N ) )
	REP( j, N )
		if ( ( i >> j ) & 1 )
		REP( k, N )
		if ( k != j && ( ( i >> k ) & 1 ) && abs( id[j] - id[k] ) > K )
			dp[i][j] += dp[i - ( 1 << j)][k];


	int64 sol = 0;
	REP( i, N )
		sol += dp[(1 << N) - 1][i];

	printf( "%I64d\n", sol );

	return 0;
}
