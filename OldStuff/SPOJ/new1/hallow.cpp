/*
Alfonso2 Peterssen
SPOJ #1677 "Halloween treats"
7 - 9 - 2008
*/
#include <cstdio>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXC = 200000;

int N, C;
int from[MAXC];
int value[MAXC];

int main() {

	for (;;) {

		scanf( "%d %d", &C, &N );
		if ( !N && !C ) break;
		
		REP( i, N )
		      scanf( "%d", &value[i] );

		REP( i, C ) from[i] = -2;
		from[0] = -1;
		
		int sum = 0;
		REP( i, N ) {
		      sum = ( sum + value[i] ) % C;
		      if ( from[sum] != -2 ) {
				for ( int j = from[sum] + 1; j <= i; j++ )
				      printf( j < i ? "%d " : "%d\n", j + 1 );
				goto next_case;
			}
			from[sum] = i;
		}
		
		next_case:;
	}

	return 0;
}
