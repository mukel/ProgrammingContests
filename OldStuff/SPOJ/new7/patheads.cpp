/*
Alfonso2 Peterssen (mukel)
16 - 1 - 09
SPOJ #3591 "Patting Heads"
*/
#include <cstdio>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXN = 100000,
	LIMIT = 1000001;

int N;
int num[MAXN];
int cant[LIMIT];
int sol[LIMIT];

int main() {

	scanf( "%d", &N );
	REP( i, N ) {
	      scanf( "%d", &num[i] );
	      cant[ num[i] ]++;
	}
	
	REP( i, LIMIT )
		if ( cant[i] ) {
			sol[i] += cant[i] - 1;
			for ( int j = 2 * i; j < LIMIT; j += i )
			      sol[j] += cant[i];
		}
		
	REP( i, N )
	      printf( "%d\n", sol[ num[i] ] );

	return 0;
}
