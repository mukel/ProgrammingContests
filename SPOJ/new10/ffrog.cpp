/*
Alfonso2 Peterssen (mukel)
SPOJ #2418 "Flying Frogs"
20 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXBIT = 16,
	MAXC = (1 << MAXBIT);

int T, F, C, K;
int P[MAXC];
int sum[MAXBIT];

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d %d %d", &F, &C, &K );
		
		fill( P, P + max( F, C ), 0 );
		fill( sum, sum + MAXBIT, 0 );
		
		REP( i, F )
		REP( j, C ) {
			char buff[1 << 7];
			scanf( "%s", &buff );
			
			int val = 0;
			for ( int k = 0; buff[k]; k++ )
			      val = ( val * 10 + buff[k] - '0' ) % ( K + 1 );

			P[i] = ( P[i] + val ) % ( K + 1 );
  			P[j] = ( P[j] + val ) % ( K + 1 );
		}
		
		REP( i, max( F, C ) )
		      REP( j, MAXBIT )
		            if ( (i >> j) & 1 )
					sum[j] = ( sum[j] + P[i] ) % ( K + 1 );
					
		REP( i, MAXBIT )
		      if ( sum[i] != 0 ) {
				printf( "SensibleFrog!.\n" );
				goto next_case;
			}

		printf( "SmartFrog!.\n" );
		      
		next_case:;
	}

	return 0;
}
