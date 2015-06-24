/*
Alfonso2 Peterssen
SPOJ #90. Minimizing maximizer
5 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXN = 50001,
	oo = (int)1e9;

int T, N, M;
int S[MAXN];

int lobit( int x ) { return x & -x; }

void update( int x, int value ) {
	for ( ; x <= N; x += lobit( x ) )
	      S[x] = min( S[x], value );
}

int query( int x ) {
	int value = oo;
	for ( ; x > 0; x -= lobit( x ) )
	      value = min( value, S[x] );
	return value;
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		scanf( "%d %d", &N, &M );
		
		REP( i, N + 1 )
			S[i] = (int)1e9;
		
		update( N, 0 );
		
		REP( i, M ) {
			int lo, hi;
			scanf( "%d %d", &lo, &hi );
			int best = query( N - lo + 1 );
			if ( best != oo )
			      update( N - hi + 1, best + 1 );
		}
		
		printf( "%d\n", query( 1 ) );
	}

	return 0;
}
