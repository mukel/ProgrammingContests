/*
Alfonso2 Peterssen (mukel)
SPOJ #3923 "Philosophers Stone"
24 - 3 - 2009
*/
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
	
const int MAXC = 200;

int T, F, C;
int next, last;
int dp[2][MAXC];

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d %d", &F, &C );
		
		next = 0;
		last = 1;
		
		fill( dp[next], dp[next] + C, 0 );
		REP( i, F ) {
			swap( last, next );
			REP( i, C ) {
				scanf( "%d", &dp[next][i] );
				int best = dp[last][i];
				if ( i > 0 ) best = max( best, dp[last][i - 1] );
				if ( i < C - 1 ) best = max( best, dp[last][i + 1] );
				dp[next][i] += best;
			}
		}
		
		printf( "%d\n", *max_element( dp[next], dp[next] + C ) );
	}

	return 0;
}
