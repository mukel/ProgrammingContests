/*
Alfonso2 Peterssen (mukel)
made during contest...
USACO HOL09 "Cattle Bruisers"
*/
#include <cstdio>
#include <algorithm>
#include <complex>
#include <cmath>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

#define X(p) real(p)
#define Y(p) imag(p)

typedef long long int64;
typedef complex< int64 > point;

const int MAXN = 50000;
const double EPSILON = 1e-6;

int N, R;
int cant, depth, sol;
int64 A, B, C, D;
point Pa, Va, Pb, Vb, Dp, Dv;
struct event {
	double time;
	int kind;
	bool operator < ( const event& e ) const {
		if ( fabs( time - e.time ) < EPSILON )
			return kind > e.kind; // in first
	      return time < e.time;
	}
} evts[2 * MAXN];

int main() {

	scanf( "%d %d", &N, &R );
	scanf( "%I64d %I64d %I64d %I64d", &X(Pa), &Y(Pa), &X(Va), &Y(Va) );

	REP( i, N ) {
		scanf( "%I64d %I64d %I64d %I64d", &X(Pb), &Y(Pb), &X(Vb), &Y(Vb) );
		Dp = Pa - Pb;
		Dv = Va - Vb;

		A = norm( Dv );
		B = 2 * ( X( Dp ) * X( Dv ) + Y( Dp ) * Y( Dv ) );
		C = norm( Dp ) - R * R;

		D = B * B - 4 * A * C;
		if ( D < 0 )
			continue;
		else {
			double sol1, sol2;
			if ( A == 0 ) {
				if ( C > 0 ) continue;
				// forever
				sol1 = -1e14;
				sol2 = +1e14;
			} else {
				sol1 = ( -B - sqrt( D ) ) / (2 * A);
				sol2 = ( -B + sqrt( D ) ) / (2 * A);
			}
			evts[cant++] = (event){ sol1, +1 }; // in
			evts[cant++] = (event){ sol2, -1 }; // out
		}
	}

	sort( evts, evts + cant );
	REP( i, cant ) {
		// time must be positive
		if ( evts[i].time >= 0 )
			sol = max( sol, max( depth, depth + evts[i].kind ) );
		depth += evts[i].kind;
	}

	printf( "%d\n", sol );

	return 0;
}
