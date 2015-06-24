/*
Alfonso2 Peterssen
SPOJ #201. The Game of Polygons
4 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

int T, N, a, b, c;

int dist( int a, int b ) {
	int x = ( abs( a - b ) + N ) % N;
	return min( x, N - x );
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d", &N );
		scanf( "%d %d %d", &a, &b, &c );
		
		if ( N % 2 == 0 )
		      printf( "YES\n" );
		else
			if (  ( dist( a, b ) == 2 && dist( a, c ) == 1 && dist( b, c ) == 1 ) ||
				( dist( b, c ) == 2 && dist( b, a ) == 1 && dist( c, a ) == 1 ) ||
				( dist( c, a ) == 2 && dist( c, b ) == 1 && dist( a, b ) == 1 ) )
			      printf( "YES\n" );
			else
				printf( "NO\n" );
				
		REP( i, N - 3 )
		      scanf( "%*d %*d %*d" );
	}

	return 0;
}
