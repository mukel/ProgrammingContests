/*
Alfonso2 Peterssen (mukel)
SPOJ #3791 "Street"
21 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR( i, lo, hi ) for ( int i = (lo); i <= (hi); i++ )
#define FORD( i, hi, lo ) for ( int i = (hi); i >= (lo); i-- )

const int MAXN = 501;

int N, K, T;
int H[MAXN];
int dp[MAXN][MAXN];

int main() {

	scanf( "%d %d %d", &N, &K, &T );
	FOR( i, 1, N )
		scanf( "%d", &H[i] );
		
	int ans = 0;
	FOR( i, 1, N ) {
		int top = min( i, K );
		FOR( j, 1, top ) {

			dp[i][j] = dp[i - 1][j];

			int lowh = (int)1e9;
			int limit = max( 1, i - T + 1 );
			
			int len = 0;
			
			FORD( k, i, limit ) {
				lowh = min( lowh, H[k] );
				len++;
				dp[i][j] >?= dp[k - 1][j - 1] + lowh * len;
			}
			ans = max( ans, dp[i][j] );
		}
	}
	
	printf( "%d\n", ans );

	return 0;
}
