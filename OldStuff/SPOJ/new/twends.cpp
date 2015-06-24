/*
Alfonso2 Peterssen
SPOJ #1710 "Two Ends"
5 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXN = 1000,
	oo = (int)1e9;

int T, N;
int value[MAXN];
int dp[MAXN][MAXN];

int memo( int lo, int hi ) {
	if ( lo > hi ) return 0;
	
	int& val = dp[lo][hi];
	if ( val != -oo )
		return val;
	
	if ( ( hi - lo + 1 ) % 2 ) {
		// greedy
		if ( value[lo] >= value[hi] )
		      val = memo( lo + 1, hi ) - value[lo];
		else
			val = memo( lo, hi - 1 ) - value[hi];
	} else {
		// smarter
		val = max(
			memo( lo + 1, hi) + value[lo],
			memo( lo, hi - 1) + value[hi]	);
	}
	
	return dp[lo][hi] = val;
}

int main() {

	while ( ++T ) {
		scanf( "%d", &N ); if ( !N ) break;
		
		REP( i, N )
		REP( j, N )
		      dp[i][j] = -oo;
		
		REP( i, N )
		      scanf( "%d", &value[i] );
		printf( "In game %d, the greedy strategy might lose by as many as %d points.\n", T, memo( 0, N - 1 ) );
	}

	return 0;
}
