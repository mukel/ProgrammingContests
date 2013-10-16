/*
Alfonso2 Peterssen
SPOJ #212 "Water among Cubes"
4 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXC = 100;
	
const int
	mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int T, F, C;
int board[MAXC][MAXC];
int lower[MAXC][MAXC];
struct position {
	int x, y;
	bool operator < ( const position& p ) const {
		return board[x][y] > board[p.x][p.y];
	}
};
queue< position > Q;
priority_queue< position > H;

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		scanf( "%d %d", &F, &C );
		REP( i, F )
		REP( j, C ) {
		      scanf( "%d", &board[i][j] );
		      lower[i][j] = -1;
		}

		REP( i, F ) {
			H.push( (position){ i, 0 } );
			H.push( (position){ i, C - 1 } );
		}
		
		REP( j, C ) {
			H.push( (position){ 0, j } );
			H.push( (position){ F - 1, j } );
		}
		
		while ( !H.empty() )
			for ( Q.push( H.top() ), H.pop(); !Q.empty(); Q.pop() ) {
				int x = Q.front().x;
				int y = Q.front().y;
				if ( lower[x][y] == -1 )
					lower[x][y] = board[x][y];
				REP( i, 4 ) {
					int nx = x + mov[i][0];
					int ny = y + mov[i][1];
					if ( nx < 0 || nx >= F || ny < 0 || ny >= C )
					      continue;
					if ( lower[nx][ny] == -1 )
						if ( board[nx][ny] < lower[x][y] ) {
							lower[nx][ny] = lower[x][y];
							Q.push( (position){ nx, ny } );
						} else
							H.push( (position){ nx, ny } );
				}
			}
			
		int water_amount = 0;
		REP( i, F )
		REP( j, C )
	            water_amount += lower[i][j] - board[i][j];
		
		printf( "%d\n", water_amount );
	}
	
	return 0;
}
