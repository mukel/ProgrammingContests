/*
Alfonso2 Peterssen
SPOJ #397 "I Conduit"
17 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <complex>
#include <cstring>
#include <cassert>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef long long int64;
typedef complex< double > point;

const double EPSILON = 1e-9;
const int MAXN = 10000;

int N;

namespace std {
	bool operator < ( const point& a, const point& b ) {
		if ( real(a) != real(b) )
		      return real(a) < real(b);
		return imag(a) < imag(b);
	}
};

double cross( point a, point b ) {
	return imag( conj(a) * b );
}

double area2( point a, point b, point c ) {
	return cross( b - a, c - a );
}

struct segment {
	point P1, P2; double angle;
	segment() {}
	segment( double x1, double y1, double x2, double y2 ) {
		P1 = point( x1, y1 );
		P2 = point( x2, y2 );
		if ( P2 < P1 ) swap( P2, P1 );
		point D = P2 - P1;
		angle = atan2( imag(D), real(D) );
	}
	bool operator < ( const segment& s ) const {
		if ( fabs( angle - s.angle ) > EPSILON )
		      return angle < s.angle;
		double cp = area2( P1, P2, s.P1 );
		if ( fabs( cp ) > EPSILON )
		      return cp < 0;
		return P1 < s.P1;
	}
} S[MAXN];

int main() {

	for ( int t = 1;;t++) {
		scanf( "%d", &N ); if ( !N ) break;
		int cant = 0;
		REP( i, N ) {
			double x1, y1, x2, y2;
			scanf( "%lf %lf %lf %lf", &x1, &y1, &x2, &y2 );
			S[i] = segment( x1, y1, x2, y2 );
		}
		
		sort( S, S + N );
		
		int sol = N;
		for ( int i = 0, j; i < N; i = j ) {
			point P = S[i].P2;
			for ( j = i + 1; j < N &&
				fabs( S[i].angle - S[j].angle ) < EPSILON &&
				fabs( area2( S[i].P1, S[i].P2, S[j].P2 ) ) < EPSILON; j++ ) {
				if ( !(P < S[j].P1) )
				      sol--;
				if ( P < S[j].P2 )
				      P = S[j].P2;
			}
		}

		printf( "%d\n", sol );
	}

	return 0;
}
