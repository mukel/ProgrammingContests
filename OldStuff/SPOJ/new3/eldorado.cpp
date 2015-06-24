/*
Alfonso2 Peterssen
SPOJ #2854 "El Dorado"
15 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <numeric>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )

typedef long long int64;

const int MAXN = 101;

int N, K;
int seq[MAXN];
int64 dp[MAXN][MAXN];

int main() {

	for (;;) {
		scanf( "%d %d", &N, &K );
		if ( !N && !K ) break;
		
		FOR( i, 1, N )
		      scanf( "%d", &seq[i] );
		      
		FOR( i, 1, N ) dp[1][i] = 1;

		FOR( i, 2, K )
		FOR( j, i, N ) {
			dp[i][j] = 0;
			FOR( k, 1, j - 1 )
			      if ( seq[k] < seq[j] )
					dp[i][j] += dp[i - 1][k];
		}
		
		printf( "%lld\n", accumulate( dp[K] + K, dp[K] + N + 1, 0LL ) );
	}

	return 0;
}
