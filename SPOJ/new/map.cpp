/*
Alfonso2 Peterssen
SPOJ #209 "The Map"
6 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) \
	for ( int i = (e); i >= (s); i-- )

typedef long long int64;

const int
	MAXN = 3001,
	MAXC = 11;

int T, N, C;
int64 dp[MAXC][MAXN];
int64 val[MAXN];

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d %d", &N, &C );
		
		FOR( i, 1, N )
		      scanf( "%lld", &val[i] );
		      
		sort( val + 1, val + N + 1 );
		      
		REP( i, MAXN )
		      dp[0][i] = 1e15;
		dp[0][0] = 0;

		FOR( i, 1, C )
		FOR( j, 1, N ) {
			dp[i][j] = 1e15;
			int64 value = 0;
			FORD( k, j, i ) {
				value -= val[k] - val[(j + k + 1) / 2];
				dp[i][j] = min( dp[i][j], dp[i - 1][k - 1] + value );
			}
		}

		printf( "%lld\n", dp[C][N] );
	}
	
	return 0;
}
