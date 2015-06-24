/*
Alfonso2 Peterssen (mukel)
SPOJ #
23 - 5 - 2009
*/
#include <cstdio>
#include <cmath>

const double PI = acos( -1 );

int main() {

	while (1) {
		int L;
		scanf( "%d", &L ); if ( !L ) break ;
		printf( "%.2lf\n", (L * L) / PI / 2 );
	}


	return 0;
}
