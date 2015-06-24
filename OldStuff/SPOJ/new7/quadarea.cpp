/*
Alfonso2 Peterssen (mukel)
13 - 1 - 2009
SPOJ #2716 "Maximal Quadrilateral Area"
*/
#include <cstdio>
#include <cmath>

int T;
double a, b, c, d;
int main() {

	for ( scanf( "%d", &T ); T--; ) {
	      scanf( "%lf %lf %lf %lf", &a, &b, &c, &d );
		double P = ( a + b + c + d ) / 2;
		printf( "%lf\n", sqrt( (P - a) * (P - b) * (P - c) * (P - d) ) );
	}

	return 0;
}
