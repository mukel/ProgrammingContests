/*
Alfonso2 Peterssen
SPOJ #1183 "Accomodate the palace"
4 - 9 - 2008
*/
#include <cstdio>

typedef long long int64;

const int MODULO = 98777;

int T, N;

template< typename T >
T sqr( T x ) { return x * x; }

int64 pow( int a, int64 b ) {
	if ( b == 0 ) return 1;
	int64 x = sqr( pow( a, b / 2 ) ) % MODULO;
	if ( b & 1 ) x = x * a % MODULO;
	return x;
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d", &N );
		printf( "%d\n", pow( 2, sqr( N - 1 ) ) );
	}

	return 0;
}
