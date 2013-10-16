/*
Alfonso2 Peterssen
SPOJ #2527 "Flipping Burned Pancakes"
8 - 10 - 2008 Che :-(
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) \
	for ( int i = (e); i >= (s); i-- )
	
const int MAXN = 100;

int T, N;
int cant;
int moves[MAXN];
int pos[MAXN];
int panck[MAXN];

void doMove( int k ) {
	moves[cant++] = k;
	reverse( panck + 1, panck + k + 1 );
	FOR( i, 1, k ) {
		pos[ abs( panck[i] ) ] = i;
		panck[i] = -panck[i];
	}
}

int main() {

	scanf( "%d", &T );
	REP( tc, T ) {

		cant = 0;

		scanf( "%d", &N );
		FOR( i, 1, N ) {
		      scanf( "%d", &panck[i] );
		      pos[ abs( panck[i] ) ] = i;
		}
		
		FORD( i, N, 1 ) {
			if( pos[i] != i ) {
				if ( pos[i] != 1 )doMove( pos[i] );
				if ( panck[1] > 0 ) doMove( 1 );
				doMove( i );
			} else
			      if ( panck[i] < 0 ) {
					if ( i == 1 ) doMove( 1 );
					else {
						doMove( i );
						doMove( 1 );
						doMove( i );
					}
				}
		}
		
		printf( "%d", tc + 1 );
		printf( " %d", cant );
		REP( i, cant )
		      printf( " %d", moves[i] );
		printf( "\n" );
	}

	return 0;
}
