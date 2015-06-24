/*
Alfonso2 Peterssen
SPOJ #2815 "Increasing Subsequences"
16 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXN = 10001,
	MODULO = 5000000;

int N, K, C;
int seq[MAXN];
int dp[MAXN];
int coords[MAXN];
int S[MAXN];

int lobit( int x ) { return x & -x; }

void update( int x, int value ) {
	for ( ; x <= C; x += lobit( x ) )
	      S[x] = ( S[x] + value ) % MODULO;
}

int query( int x ) {
	int sum = 0;
	for ( ; x > 0; x -= lobit( x ) )
		sum = ( sum + S[x] ) % MODULO;
	return sum;
}

int main() {

	scanf( "%d %d", &N, &K );
	REP( i, N ) {
	      scanf( "%d", &seq[i] );
	      coords[i] = seq[i];
	}
	
	sort( coords, coords + N );
	C = unique( coords, coords + N ) - coords;
	REP( i, N )
	      seq[i] = lower_bound( coords, coords + C, seq[i] ) - coords + 1;
	      
	REP( i, K ) {
		if ( i == 0 ) {
			REP( j, N ) dp[j] = 1;
			continue;
		}
		memset( S, 0, sizeof( S ) );
		REP( j, N ) {
			int val = dp[j];
			dp[j] = query( seq[j] - 1 );
			update( seq[j], val );
		}
	}
	
	int sol = 0;
	REP( i, N )
	      sol = ( sol + dp[i] ) % MODULO;
	      
	printf( "%d\n", sol );

	return 0;
}
