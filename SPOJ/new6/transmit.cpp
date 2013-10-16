/*
Alfonso2 Peterssen
SPOJ #898 "Transmitters"
1 - 10 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <complex>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
	
typedef complex< double > point;

const int MAXN = 200;
const double EPSILON = 1e-8;

int N, P;
double R;
point S;
point pnts[MAXN];

namespace std {
	bool operator < ( const point& a, const point& b ) {
		return atan2( imag(a), real(a) ) < atan2( imag(b), real(b) );
	}
};

double cross( const point& a, const point& b ) {
	return imag( conj(a) * b );
}

double dist( const point& a, const point& b ) {
	return abs( a - b );
}

int main() {

	for (;;) {

		scanf( "%lf %lf %lf", &real( S ), &imag( S ), &R );
		if ( R <= 0 ) break;
		
		P = 0;
		
		scanf( "%d", &N );
		REP( i, N ) {
			double x, y;
			scanf( "%lf %lf", &x, &y );
			pnts[P] = point( x, y );
			if ( dist( S, pnts[P] ) - R > EPSILON )
				continue;
			P++;
		}
		
		REP( i, P ) pnts[i] -= S;
		sort( pnts, pnts + P );
		
		int sol = 0, lo = 0, hi = 0;
		REP( i, 2 * P ) {
			hi = (hi + 1) % P;
			while ( cross( pnts[lo], pnts[hi] ) < 0 )
			      lo = (lo + 1) % P;
			sol = max( sol, ( P + hi - lo ) % P + 1 );
		}
		
		printf( "%d\n", sol );
	}

	return 0;
}
