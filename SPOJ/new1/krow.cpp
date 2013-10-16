/*
Alfonso2 Peterssen
SPOJ #2128 "K-In-A-Row"
10 - 9 - 2008
*/
#include <cstdio>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXC = 300;
const int mov[8][2] =
	{{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

int T, F, C, K;
int H, G;
char board[MAXC][MAXC];
bool found;

void solve( int x, int y, int dir ) {
	if ( found ) return ;
	int cntO = 0, cntX = 0;
	while ( x >= 0 && x < F && y >= 0 && y < C ) {
		if ( board[x][y] == 'o' ) {
			if ( cntX ) cntO = cntX = 0;
			cntO++;
		} else
		if ( board[x][y] == 'x' ) {
			if ( cntO ) cntO = cntX = 0;
			cntX++;
		} else
			cntO = cntX = 0;
			
		if ( cntO >= K ) { found = true; G++; return ; }
		if ( cntX >= K ) { found = true; H++; return ; }
		
            x += mov[dir][0];
		y += mov[dir][1];
	}
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d %d %d", &C, &F, &K );
		REP( i, F )
		      scanf( "%s", &board[i] );

		found = false;
		REP( i, F )
		REP( j, 8 ) {
			solve( i, 0, j );
			solve( i, C - 1, j );
		}
		
		REP( i, C )
		REP( j, 8 ) {
			solve( 0, i, j );
			solve( F - 1, i, j );
		}
	}
	
	printf( "%d:%d\n", H, G );

	return 0;
}
