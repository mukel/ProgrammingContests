/*
Alfonso2 Peterssen
SPOJ #2053 "Key Task"
26 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXC = 102;
const int mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int F, C;
char board[MAXC][MAXC];
int dist[MAXC][MAXC][16];
struct pos {
	int x, y, keys;
	pos() {}
	pos( int _x, int _y, int _keys ) {
		x = _x;
		y = _y;
		keys = _keys;
	}
};

int main() {

	for (;;) {

		scanf( "%d %d", &F, &C );
		if ( !F && !C ) break;
		
		queue< pos > Q;
		memset( dist, -1, sizeof( dist ) );
		
		REP( i, F ) {
		      scanf( "%s", &board[i] );
		      REP( j, C )
			      if ( board[i][j] == '*' ) {
					Q.push( pos( i, j, 0 ) );
					dist[i][j][0] = 0;
				}
		}
		
		int sol = -1;
		while ( !Q.empty() ) {
			int x = Q.front().x;
			int y = Q.front().y;
			int keys = Q.front().keys;
			Q.pop();
			
			if ( board[x][y] == 'X' ) {
				sol = dist[x][y][keys];
				break;
			}
			
			REP( i, 4 ) {
				int nx = x + mov[i][0];
				int ny = y + mov[i][1];
				if ( nx < 0 || nx >= F || ny < 0 || ny >= C )
				      continue;
				if ( board[nx][ny] == '#' )
				      continue;

				int nkeys = keys;
				if ( board[nx][ny] == 'b' ) nkeys |= 1; else
				if ( board[nx][ny] == 'y' ) nkeys |= 2; else
				if ( board[nx][ny] == 'r' ) nkeys |= 4; else
				if ( board[nx][ny] == 'g' ) nkeys |= 8;
				
				if ( dist[nx][ny][nkeys] != -1 )
				      continue;
				
				if ( board[nx][ny] == 'B' && !( keys & 1 ) ) continue;
				if ( board[nx][ny] == 'Y' && !( keys & 2 ) ) continue;
				if ( board[nx][ny] == 'R' && !( keys & 4 ) ) continue;
				if ( board[nx][ny] == 'G' && !( keys & 8 ) ) continue;
				
				dist[nx][ny][nkeys] = dist[x][y][keys] + 1;
				Q.push( pos( nx ,ny, nkeys ) );
			}
		}
		
		if ( sol == -1 )
		      printf( "The poor student is trapped!\n" );
		else
			printf( "Escape possible in %d steps.\n", sol );
	}

	return 0;
}
