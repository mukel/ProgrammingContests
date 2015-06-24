/*
Alfonso2 Peterssen
SPOJ #2526 "Decoding"
30 - 9 - 2008
*/
#include <cstdio>
#include <cstring>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int MAXC = 30;
const int mov[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int T, F, C;
char msg[MAXC*MAXC];
char mat[MAXC][MAXC];

int x, y, loX, loY, hiX, hiY, dir;

int main() {

	scanf( "%d", &T );
	REP( tc, T ) {
		scanf( "%d %d%*c", &F, &C );
		REP( i, F )
		REP( j, C )
		      scanf( "%c", &mat[i][j] );
		      
		loX = 0; hiX = F - 1;
		loY = 0; hiY = C - 1;
		x = y = 0;
		dir = 0;
		
		REP( i, F * C / 5 ) {
			int val = 0;
			REP( j, 5 ) {
				val = val * 2 + ( mat[x][y] - '0' );
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
			if ( val == 0 )
				msg[i] = ' ';
			else
			      msg[i] = val + 'A' - 1;
		}
		
		msg[F * C / 5] = '\0';
		printf( "%d %s\n", tc + 1, msg );
	}

	return 0;
}
