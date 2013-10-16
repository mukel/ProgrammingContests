/*
Alfonso2 Peterssen (mukel)
SPOJ #4177 "Herding"
22 - 5 - 2009
*/
#include <cstdio>

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXC = 1 << 10;

int F, C, pass, ans;
char mat[MAXC][MAXC];
int mark[MAXC][MAXC];

void dfs( int x, int y ) {
	if ( mark[x][y] == pass ) ans++;
	if ( mark[x][y] )
	      return ;
	mark[x][y] = pass;
	if ( mat[x][y] == 'N' ) x--;
	if ( mat[x][y] == 'S' ) x++;
	if ( mat[x][y] == 'E' ) y++;
	if ( mat[x][y] == 'W' ) y--;
	dfs( x, y );
}

int main() {

	scanf( "%d %d", &F, &C );
	REP( i, F )
	      scanf( "%s", &mat[i] );
	      
	REP( i, F )
	REP( j, C ) {
		pass++;
	      dfs( i, j );
	}
		
	printf( "%d\n", ans );

	return 0;
}
