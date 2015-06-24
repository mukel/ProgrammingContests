/*
Alfonso2 Peterssen
SPOJ #1713 "Funny scales"
7 - 9 - 2008
*/
#include <cstdio>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int MAXL = 100;

int N, X;
int A[MAXL], lenA;
int B[MAXL], lenB;
int dig[MAXL];

int main() {

	scanf( "%d %d", &N, &X );
	
	for ( int i = 0; X != 0; i++ ) {
		dig[i] += X % 3;
		if ( dig[i] > 1 ) {
			dig[i + 1]++;
			dig[i] = dig[i] - 3;
		}
		X /= 3;
	}

	REPD( i, MAXL )
	      if ( dig[i] != 0 )
			if ( dig[i] == -1 )
				A[lenA++] = i + 1;
			else
			if ( dig[i] == +1 )
				B[lenB++] = i + 1;
		
	if ( A[0] > N || B[0] > N )
	      printf( "-1\n" );
	else {
		REPD( i, lenA )
		      printf( i ? "%d " : "%d", A[i] );
		printf( "\n" );
		REPD( i, lenB )
		      printf( i ? "%d " : "%d", B[i] );
		printf( "\n" );
	}
	
	return 0;
}
