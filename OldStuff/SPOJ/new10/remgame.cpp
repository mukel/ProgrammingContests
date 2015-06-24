/*
Alfonso2 Peterssen (mukel)
SPOJ #2047 "Stone Removing Game"
21 - 5 - 2009
*/
#include <cstdio>

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

int T;
int M;
int move[250];
char memo[1 << 25];

char solve( int mask ) {
	if ( mask == 0 ) return 1; // win
	char& ans = memo[mask];
	if ( ans )
		return ans;
	REP( i, M )
	      if ( (mask & move[i]) == move[i] && solve( mask ^ move[i] ) == 2 )
			return (ans = 1); // assign
	return (ans = 2); // assign
}

int main() {

	REP( i, 5 )
	REP( j, 5 ) {
		for ( int k = i, mv = 0; k < 5; k++ )
		      move[M++] = (mv |= 1 << (k*5+j));
		for ( int k = j, mv = 0; k < 5; k++ )
		      move[M++] = (mv |= 1 << (i*5+k));
	}

	scanf( "%d", &T );
	while ( T-- ) {

		int board = 0;
		REP( i, 25 ) {
			int x;
			scanf( "%d", &x );
			if ( x ) board |= (1 << i);
		}
		
		if ( solve( board ) == 1 )
		      printf( "winning\n" );
		else
		      printf( "losing\n" );
	}

	return 0;
}
