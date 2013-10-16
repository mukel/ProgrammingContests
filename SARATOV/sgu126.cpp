/*
Alfonso2 Peterssen (mukel)
11 - 2 - 2009
SGU #126 "Boxes"
*/
#include <cstdio>
#include <cstdlib>

const int LIMIT = 10000;

int A, B, ans;

void solution( int x ) {
	printf( "%d\n", x );
	exit( 0 );
}

int main() {

	scanf( "%d %d", &A, &B );
	while ( A && B ) {
		if ( A < B ) A^=B^=A^=B; // swap
		A -= B;
		B *= 2;
		ans++;
		if ( ans > LIMIT ) solution( -1 );
	}
	
	solution( ans );
	
	return 0;
}
