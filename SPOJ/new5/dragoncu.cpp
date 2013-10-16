/*
Alfonso2 Peterssen
SPOJ #1876 "Dragon Curves"
23 - 9 - 2008
*/
#include <cstdio>
#include <complex>

using namespace std;

typedef complex< long long > point;

int N;
point dp[33];

point solve( int n ) {
	if ( n == 0 ) return point( 0, 0 );
	int lg = n > 1 ? 32 - __builtin_clz( n - 1 ) : 0;
	return dp[lg] - solve( (1 << lg) - n ) * point( 0, 1 );
}

int main() {

	dp[0] = point( 1, 0 );
	for ( int i = 1; i <= 32; i++ )
	      dp[i] = dp[i - 1] * point( 1, 1 );

	for (;;) {
		scanf( "%d", &N ); if ( N == -1 ) break;
		point sol = solve( N );
		printf( "(%lld,%lld)\n", real( sol ), imag( sol ) );
	}
	
	return 0;
}
