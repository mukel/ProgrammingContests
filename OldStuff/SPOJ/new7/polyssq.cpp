/*
Alfonso2 Peterssen (mukel)
15 - 1 - 2009
SPOJ #2668 "Polygon"
*/
#include <cstdio>
#include <algorithm>
#include <complex>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef complex< int > point;

const int MAXN = 100;

int N, K;
point pnts[MAXN];
point hull[MAXN];
point lower;
int ans;

namespace std {
	bool operator < ( const point& a, const point& b ) {
		if ( real(a) != real(b) ) return real(a) < real(b);
		return imag(a) < imag(b);
	}
};

int cross( const point& a, const point& b ) {
	return imag( conj(a) * b );
}

int area2( const point& a, const point& b, const point& c ) {
	return cross( b - a, c - a );
}

bool cross_cmp( const point& a, const point& b ) {
	return area2( lower, a, b ) > 0;
}

void comb( int pos, int taken, int area ) {

	if ( area >= ans )
		return ;
		
	if ( taken == K ) {
		ans = min( ans, area );
		return ;
	}
	
	if ( pos > N - (K - taken) )
	      return ;

	comb( pos + 1, taken, area );
	if (	area2( hull[taken - 2], hull[taken - 1], pnts[pos] ) > 0 &&
		area2( hull[taken - 1], pnts[pos], hull[0] ) > 0 ) {
		hull[taken] = pnts[pos];
		comb( pos + 1, taken + 1, area + area2( hull[0], hull[taken - 1], hull[taken] ) );
	}
}

int main() {

	scanf( "%d %d", &N, &K );
	REP( i, N ) {
		int x, y;
		scanf( "%d %d", &x, &y );
		pnts[i] = point( x, y );
	}
	
	ans = 1e9;
	
	REP( i, N ) {

		swap( *min_element( pnts + i, pnts + N ), pnts[i] );
		            
		lower = pnts[i];
		sort( pnts + i + 1, pnts + N, cross_cmp );

		hull[0] = pnts[i];
		for ( int j = i + 1; j < N; j++ ) {
			hull[1] = pnts[j];
			comb( j + 1, 2, 0 );
		}
	}
	
	if ( ans == 1e9 )	ans = 0;
	
	printf( "%d\n", ans / 2 );

	return 0;
}
