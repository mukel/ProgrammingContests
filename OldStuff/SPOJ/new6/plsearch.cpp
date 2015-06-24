/*
Alfonso2 Peterssen
SPOJ #1698 "Polygonal Line Search"
30 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXM = 10;

int N;
struct pline {
	int size;
	struct point {
		int x, y;
		point() {}
		point( int x, int y ) : x( x ), y( y ) {}
		point operator - ( const point& p ) const { return point( x - p.x, y - p.y ); }
	} P[MAXM];
	
	bool operator == ( const pline& pl ) const {
		if ( size != pl.size ) return false;
		REP( i, size )
		      if ( P[i].x != pl.P[i].x || P[i].y != pl.P[i].y )
		            return false;
		return true;
	}
	
	void normalize() {
		REP( i, size )
			if ( i ) P[i] = P[i] - P[0];
		P[0] = point( 0, 0 );
		while ( P[1].x - P[0].x <= 0 )
			REP( i, size ) // rotate
				P[i] = point( -P[i].y, P[i].x );
	}
} A, B, pl;

void read( pline& pl ) {
	scanf( "%d", &pl.size );
	REP( i, pl.size )
		scanf( "%d %d", &pl.P[i].x, &pl.P[i].y );
	pl.normalize();
}

int main() {

	for (;;) {
		scanf( "%d", &N );
		if ( !N ) break;
		
		read( A );
		B = A;
		reverse( B.P, B.P + B.size );
		B.normalize();
		
		REP( i, N ) {
			read( pl );
			if ( pl == A || pl == B )
			      printf( "%d\n", i + 1 );
		}
		
		printf( "+++++\n" );
	}

	return 0;
}
