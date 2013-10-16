/*
Alfonso2 Peterssen
SPOJ #2525 "Encoding"
25 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int MAXC = 30;
const int mov[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int T, F, C, N;
char line[MAXC*MAXC];
char mat[MAXC][MAXC];

int x, y, loX, loY, hiX, hiY, dir;

int main() {

	scanf( "%d", &T );
	REP( tc, T ) {
		scanf( "%d %d%*c", &F, &C );
		gets( line );
		N = strlen( line );
		
		REP( i, F )
		REP( j, C )
		      mat[i][j] = 0;
		      
		loX = 0; hiX = F - 1;
		loY = 0; hiY = C - 1;
		x = y = 0;
		dir = 0;

		REP( i, N ) {
			int idx = line[i] - 'A' + 1;
			if ( line[i] == ' ' )
				idx = 0;
			REPD( j, 5 ) {
				mat[x][y] = ( idx >> j ) & 1;
				int nx = x + mov[dir][0];
				int ny = y + mov[dir][1];
				if ( nx < loX || nx > hiX || ny < loY || ny > hiY ) {
					switch ( dir ) {
						case 0: loX++; break;
						case 1: hiY--; break;
						case 2: hiX--; break;
						case 3: loY++; break;
					}
					dir = ( dir + 1 ) & 3;
				}
				x += mov[dir][0];
				y += mov[dir][1];
			}
		}
		
		printf( "%d ", tc + 1 );
		REP( i, F )
		REP( j, C )
		      printf( "%d", mat[i][j] );
		printf( "\n" );
	}

	return 0;
}
