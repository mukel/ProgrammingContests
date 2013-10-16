/*
Alfonso2 Peterssen (mukel)
3 - 2 - 2009
SGU #118 "Digital Root"
*/
#include <cstdio>
#include <cassert>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, b, e ) \
	for ( int i = (b); i <= (e); i++ )

typedef long long int64;

const int MAXN = 1000;

int T, N;
int64 val[MAXN];

int droot( int x ) {
	if ( x < 10 ) return x;
	int ans = 0;
	while ( x > 0 ) {
	      ans += x % 10;
	      x /= 10;
	}
	return droot( ans );
}

int main() {

	/*FOR( i, 1, 1000 )
	FOR( j, 1, 1000 ) {
		int ij = droot( i * j );
		int kk = droot( droot(i) * droot(j) );
		if ( ij != kk )
		      printf( "droot(%d, %d) = %d, not %d\n", i, j, ij, kk );
	}
	*/

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d", &N );
		#warning READ LLD
		REP( i, N )
		      scanf( "%I64d", &val[i] );
		int64 ans = droot( val[N - 1] );
		REPD( i, N - 1 )
			ans = droot( droot(val[i]) * droot(ans+1) );
		printf( "%I64d\n", ans );
	}

	return 0;
}
