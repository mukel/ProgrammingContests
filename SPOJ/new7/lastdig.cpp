/*
Alfonso2 Peterssen (mukel)
25 - 1 - 2009
SPOJ #3442 "The last digit"
*/
#include <cstdio>

int T, A, B;

int power( int x, int n ) {
	if ( n == 0 ) return 1;
	int tmp = power( x, n / 2 );
	tmp *= tmp;
	if ( n % 2 ) tmp *= x;
	return tmp % 10;
}

int main() {
	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d %d", &A, &B );
		printf( "%d\n", power( A, B ) );
	}
	return 0;
}
