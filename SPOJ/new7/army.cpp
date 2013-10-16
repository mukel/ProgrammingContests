/*
Alfonso2 Peterssen (mukel)
13 - 1 - 2008
SPOJ #2727 "Army Strength"
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

int main() {

	int T, A, B;
	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d %d", &A, &B );
		priority_queue< int > pqA, pqB;
		REP( i, A ) { int x; scanf( "%d", &x ); pqA.push( x ); }
		REP( i, B ) { int x; scanf( "%d", &x ); pqB.push( x ); }
		while ( !pqA.empty() && !pqB.empty() ) {
			if ( pqA.top() < pqB.top() )
			      pqA.pop();
			else
			      pqB.pop();
		}
		if ( pqB.empty()  )
			printf( "Godzilla\n" );
		else
			printf( "MechaGodzilla\n" );
	}

	return 0;
}
