/*
Alfonso2 Peterssen
SPOJ #145 "Aliens"
16 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <complex>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef complex< double > point;

const int MAXN = 100000;
	
int T, N;
point P[MAXN];
struct circle {
	point O; double R;
	circle() {}
	circle( point O, double R = 0. ) : O( O ), R( R ) {}
};
circle best;

double dist( point a, point b ) {
	return abs( a - b );
}

// from 2 points
circle circle2( point a, point b ) {
	point O = ( a + b ) / 2.;
	return circle( O, dist( O, a ) );
}
// from 3 points
circle circle3( point a, point b, point c ) {
	point x = 1.0 / conj( b - a );
	point y = 1.0 / conj( c - a );
	point O = ( y - x ) / ( conj(x) * y - x * conj(y) ) + a;
	return circle( O, dist( O, a ) );
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		scanf( "%d", &N );
		REP( i, N ) {
			double x, y;
			scanf( "%lf %lf", &x, &y );
			P[i] = point( x, y );
		}

		random_shuffle( P, P + N );
		best = circle2( P[0], P[1] );
		REP( i, N )
		if ( dist( best.O, P[i] ) > best.R ) {
			best = circle2( P[0], P[i] );
		      REP( j, i )
			if ( dist( best.O, P[j] ) > best.R ) {
				best = circle2( P[i], P[j] );
			      REP( k, j )
				if ( dist( best.O, P[k] ) > best.R )
				      best = circle3( P[i], P[j], P[k] );
			}
		}
		
		printf( "%.2lf\n", best.R );
		printf( "%.2lf %.2lf\n", real( best.O ), imag( best.O ) );
	}
	
	return 0;
}
