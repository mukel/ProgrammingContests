/*
Alfonso2 Peterssen
SPOJ #92 "Cutting off Squares"
15 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

int T, F, C;
int can_win;
int ways, wins;

int memo( int F, int C ) {

	if ( F == 0 || C == 0 ) return 0; // nothing
	if ( F == C ) return 1; // last square
	
	if ( F > C ) swap( F, C );
	
	int B = C / F;
	ways += B - 1;
	
	int res = memo( C - F * B, F );
	if ( B == 1 ) return 1 - res; // only 1 choice
	return 1; // we always win
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d %d", &F, &C );
		
		ways = 0;
		can_win = memo( F, C );

		if ( ways == 0 ) ways = 1; // 2^0 = 1
		wins = ways - 1;
		if ( wins == 0 ) wins = 1; // 2^0 = 1

		int size =
			(int)ceil( log10( 2 ) * ways ) +
			(int)ceil( log10( 2 ) * wins ) +
			5 + !can_win;

		printf( "%d\n", size );
	}

	return 0;
}
