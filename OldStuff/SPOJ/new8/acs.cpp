/*
Alfonso2 Peterssen (mukel)
SPOJ #376 "A concrete simulation"
5 - 3 - 2009
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXR = 1234,
	MAXC = 5678;
	
int R[MAXR], WR[MAXR];
int C[MAXC], WC[MAXC];

int main() {

	REP( i, MAXR ) R[i] = WR[i] = i;
	REP( i, MAXC ) C[i] = WC[i] = i;

	char op[5];
	while ( scanf( "%s", &op ) == 1 ) {
		int a, b;
		scanf( "%d", &a );
		if ( op[0] != 'W' ) scanf( "%d", &b );
		a--; b--;
		
		if ( op[0] == 'R' ) {
			swap( WR[ R[a] ], WR[ R[b] ] );
			swap( R[a], R[b] );
		} else
		if ( op[0] == 'C' ) {
			swap( WC[ C[a] ], WC[ C[b] ] );
			swap( C[a], C[b] );
		} else
		if ( op[0] == 'Q' )
			printf( "%d\n", (R[a] * MAXC + C[b]) + 1 );
		else
		if ( op[0] == 'W' )
			printf( "%d %d\n", WR[a / MAXC] + 1, WC[a % MAXC] + 1 );
	}

	return 0;
}
