/*
Alfonso2 Peterssen
4 - 9 - 2008
SPOJ #1024 "Complete Chess Boards"
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXC = 30;
const int mov[8][2] =
	{{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

int T, F, C;
int cant = 0;
int sol[MAXC*MAXC][2];
bool mark[30][30];

bool comb( int x, int y ) {

	mark[x][y] = true;
	sol[cant][0] = x;
	sol[cant][1] = y;
	cant++;
	if ( cant == F * C ) {
		REP( i, cant )
			printf( "%c%d", sol[i][0] + 'A', sol[i][1] + 1 );
		printf( "\n" );
		return true;
	}
	
	REP( i, 8 ) {
		int nx = x + mov[i][0];
		int ny = y + mov[i][1];
		if ( nx < 0 || nx >= F || ny < 0 || ny >= C || mark[nx][ny] )
		      continue;
		if ( comb( nx, ny ) )
		      return true;
	}
	
	mark[x][y] = false;
	cant--;
	return false;
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d %d", &F, &C );
		swap( F, C );
		memset( mark, 0, sizeof( mark ) );
		cant = 0;
		if ( !comb( 0, 0 ) )
		      printf( "-1\n" );
	}
	
	return 0;
}
