/*
Alfonso2 Peterssen
SPOJ #396 "Hit or Miss"
22 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int
	MAXP = 100,
	LIMIT = 10000; // just a guess

int T, P;
int idx[MAXP];
int sol[MAXP];

int main() {

	scanf( "%d", &T );
	REP( t, T ) {

		scanf( "%d", &P );

		queue< int > Q[MAXP];
		fill( idx, idx + P, 0 );
		
		REP( i, 52 ) {
			int card;
		      scanf( "%d", &card );
		      Q[0].push( card - 1 );
		}
		
		REP( i, LIMIT )
		REP( j, P ) {
			if ( Q[j].empty() )
				continue;
			int x = Q[j].front(); Q[j].pop();
			if ( x == idx[j] ) {
				sol[j] = x;
				if ( j < P - 1 )
					Q[j + 1].push( x );
//				i = 0;
			} else
			      Q[j].push( x );
			idx[j] = ( idx[j] + 1 ) % 13;
		}
		
		printf( "Case %d: ", t + 1 );
		
		bool found = false;
		REP( i, P )
		      if ( !Q[i].empty() ) {
				found = true;
				break;
			}
			
		if ( found )
		      printf( "unwinnable\n" );
		else {
			REP( i, P )
				printf( i < P - 1 ? "%d " : "%d", sol[i] + 1 );
			printf( "\n" );
		}
	}

	return 0;
}
