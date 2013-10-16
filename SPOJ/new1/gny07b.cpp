/*
Alfonso2 Peterssen
SPOJ #2524 "Conversions"
10 - 9 - 2008
*/
#include <cstdio>

int T;
double val;
char unit[5];

int main() {

	scanf( "%d", &T );
	for ( int t = 1; t <= T; t++ ) {
		scanf( "%lf %s", &val, &unit );
		if ( unit[0] == 'k' ) printf( "%d %.4lf lb\n", t, val * 2.2046 ); else
		if ( unit[1] == 'b' ) printf( "%d %.4lf kg\n", t, val * 0.4536 ); else
		if ( unit[0] == 'l' ) printf( "%d %.4lf g\n", t, val * 0.2642 ); else
		if ( unit[0] == 'g' ) printf( "%d %.4lf l\n", t, val * 3.7854 );
	}

	return 0;
}
