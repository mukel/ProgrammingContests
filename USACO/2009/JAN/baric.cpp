/*
Alfonso2 Peterssen (mukel)
11 - 1 - 2009
USACO JAN09 Task: baric
*/
#include <cstdio>
#include <algorithm>

using std::min;

#define FOR( i, b, e ) \
	for ( int i = (b); i <= (e); i++ )
#define FORD( i, e, b ) \
	for ( int i = (e); i >= (b); i-- )

const int MAXN = 105;

int N, E;
int M[MAXN];
int cost[MAXN][MAXN];
int dp[MAXN];
int ans;

int main() {

	scanf( "%d %d", &N, &E );

	FOR( i, 2, N + 1 )
		scanf( "%d", &M[i] );

	N += 2;

	FOR( i, 1, N )
	FOR( j, i + 2, N ) {
		if ( i == 1 ) M[i] = M[j];
		if ( j == N ) M[j] = M[i];
		FOR( k, i + 1, j - 1 )
			cost[i][j] += abs( 2 * M[k] - M[i] - M[j] );
	}

	FOR( i, 2, N ) dp[i] = cost[1][i];

	FOR( i, 3, N ) {
		FORD( j, N, i ) {
			dp[j] = E + 1;
			FOR( k, i - 1, j - 1 )
				dp[j] = min( dp[j], dp[k] + cost[k][j] );
		}
		if ( dp[N] <= E ) {
			printf( "%d %d\n", i - 2, dp[N] );
			exit( 0 );
		}
	}

	return 0;
}

