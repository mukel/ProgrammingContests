/*
Alfonso2 Peterssen
SPOJ #2817 "Distinct Increasing Subsequences"
20 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )

const int
	MAXN = 10001,
	MODULO = 5000000;

int N, K, V;
int seq[MAXN];
int dp[MAXN];
int S[MAXN];
int vals[MAXN];
bool mark[MAXN];

int lobit( int x ) { return x & -x; }

int query( int x ) {
	int sum = 0;
	for ( ; x > 0; x -= lobit( x ) )
	      sum = ( sum + S[x] ) % MODULO;
	return sum;
}

void update( int x, int val ) {
	for ( ; x <= V; x += lobit( x ) )
	      S[x] = ( S[x] + val + MODULO ) % MODULO;
}

int main() {

	scanf( "%d %d", &N, &K );
	REP( i, N ) {
	      scanf( "%d", &seq[i] );
	      vals[i] = seq[i];
	}
	
	sort( vals, vals + N );
	V = unique( vals, vals + N ) - vals;
	REP( i, N )
	      seq[i] = lower_bound( vals, vals + V, seq[i] ) - vals + 1;
	      
	REP( i, K ) {
		if ( i == 0 ) {
			REP( j, N ) dp[j] = 1;
			continue;
		}
		memset( S, 0, sizeof( S ) );
		REP( j, N ) {
			int val = dp[j];
			dp[j] = query( seq[j] - 1 );
			update( seq[j], query( seq[j] - 1 ) - query( seq[j] ) );
			update( seq[j], val );
		}
	}
	
	int sol = 0;
	REPD( i, N )
	      if ( !mark[ seq[i] ] ) {
			mark[ seq[i] ] = true;
		      sol = ( sol + dp[i] ) % MODULO;
		}
		
	printf( "%d\n", sol );

	return 0;
}
