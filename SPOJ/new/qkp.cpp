/*
Alfonso2 Peterssen
SPOJ #1706 "Queens, Knights and Pawns"
6 - 9 - 2008
*/
#include <cstdio>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXC = 1000,
	MAXP = 200;
	
const int diag[4][2] =
	{{-1,-1},{-1,1},{1,-1},{1,1}};
	
const int horse[8][2] =
	{{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

int T, F, C;
int N;
char kind[MAXC][MAXC];
struct point {
	int x, y;
};
point piece[200];

int main() {

	while ( ++T ) {
		scanf( "%d %d", &F, &C );
		if ( !F && !C )
		      break;
		      
		memset( kind, -1, sizeof( kind ) );
		
		int cant = 0, sol = 0;
		REP( i, 3 ) {
			scanf( "%d", &N );
			REP( j, N ) {
				int x, y;
			      scanf( "%d %d", &x, &y );
			      x--; y--;
			      kind[x][y] = i;
			      if ( i != 2 ) {
				      piece[cant].x = x;
				      piece[cant].y = y;
				      cant++;
				}
				sol++;
			}
		}
		
		REP( i, cant ) {
			int x = piece[i].x;
			int y = piece[i].y;
			if ( kind[x][y] == 0 ) { // queen
			
			      // horizontal
				for ( int i = x + 1; i < F && kind[i][y] < 0; i++ )
				      if ( kind[i][y] == -1 ) {
						kind[i][y] = -2;
						sol++;
					}
				for ( int i = x - 1; i >= 0 && kind[i][y] < 0; i-- )
				      if ( kind[i][y] == -1 ) {
						kind[i][y] = -2;
						sol++;
					}

				// vertical
				for ( int i = y + 1; i < C && kind[x][i] < 0; i++ )
				      if ( kind[x][i] == -1 ) {
						kind[x][i] = -2;
						sol++;
					}
				for ( int i = y - 1; i >= 0 && kind[x][i] < 0; i-- )
				      if ( kind[x][i] == -1 ) {
						kind[x][i] = -2;
						sol++;
					}
					
				// diagonals
				REP( k, 4 )
				for ( int i = x + diag[k][0], j = y + diag[k][1];
					i >= 0 && i < F && j >= 0 && j < C && kind[i][j] < 0;
					i += diag[k][0], j += diag[k][1] )
				      if ( kind[i][j] == -1 ) {
						kind[i][j] = -2;
						sol++;
					}
			} else
			if ( kind[x][y] == 1 ) { // knight
			      REP( i, 8 ) {
					int nx = x + horse[i][0];
					int ny = y + horse[i][1];
					if ( nx >= 0 && nx < F && ny >= 0 && ny < C )
				      if ( kind[nx][ny] == -1 ) {
						kind[nx][ny] = -2;
						sol++;
					}
				}
			}
		}
		
		printf( "Board %d has %d safe squares.\n", T, F * C - sol );
	}

	return 0;
}
