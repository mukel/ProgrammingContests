/*
Alfonso2 Peterssen
SPOJ #224 "Vonny and her dominos"
5 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	F = 7,
	C = 8;

int T, ways;
int mat[F][C];
bool mark[F][C];
bool used[F][C];

void comb( int x, int y ) {

	if ( y == C ) { y = 0; x++; }
	if ( x == F ) {
		ways++;
		return ;
	}
	
	if ( mark[x][y] )
		comb( x, y + 1 );
	else {
		/* right */
		mark[x][y] = 1;
		if ( y < C - 1 && !mark[x][y + 1] && !used[ mat[x][y] ][ mat[x][y + 1] ] ) {
			used[ mat[x][y] ][ mat[x][y + 1] ] = 1;
			used[ mat[x][y + 1] ][ mat[x][y] ] = 1;
			mark[x][y + 1] = 1;
			comb( x, y + 1 );
			mark[x][y + 1] = 0;
			used[ mat[x][y] ][ mat[x][y + 1] ] = 0;
			used[ mat[x][y + 1] ][ mat[x][y] ] = 0;
		}
		/* down */
		if ( x < F - 1 && !mark[x + 1][y] && !used[ mat[x][y] ][ mat[x + 1][y] ] ) {
			used[ mat[x][y] ][ mat[x + 1][y] ] = 1;
			used[ mat[x + 1][y] ][ mat[x][y] ] = 1;
			mark[x + 1][y] = 1;
			comb( x, y + 1 );
			mark[x + 1][y] = 0;
			used[ mat[x][y] ][ mat[x + 1][y] ] = 0;
			used[ mat[x + 1][y] ][ mat[x][y] ] = 0;
		}
		mark[x][y] = 0;
	}
}

int main() {

	for( scanf( "%d", &T ); T--; ) {
		REP( i, F )
		REP( j, C )
		      scanf( "%d", &mat[i][j] );
		ways = 0;
		comb( 0, 0 );
		printf( "%d\n", ways );
	}

	return 0;
}
