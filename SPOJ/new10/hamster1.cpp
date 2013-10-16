/*
Alfonso2 Peterssen (mukel)
SPOJ #4200 "Hamster flight"
22 - 5 - 2009
*/
#include <cstdio>
#include <cmath>

using namespace std;

const double
	PI = acos( -1 ),
	EPSILON = 1e-4;

int T, V, K1, K2;

double calc( double angle ) {

	double vy = V * sin( angle );
	double vx = V * cos( angle );
	
	double Y = vy * vy / (2 * 10.0);
	double X = 2 * vx * vy / 10.0;

	return K1 * X + K2 * Y;
}

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d %d %d", &V, &K1, &K2 );

		double lo = 0, hi = PI / 2.0;
		while( hi - lo > EPSILON ) {
			double mid = ( lo + hi ) / 2.0;
			if( calc( mid + EPSILON ) >= calc( mid ) )
				lo = mid;
			else
				hi = mid;
		}
		
		lo += EPSILON;

		printf( "%.3lf %.3lf\n", lo, calc( lo ) );
	}

	return 0;
}
