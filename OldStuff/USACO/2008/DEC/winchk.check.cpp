/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cassert>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int MAXN = 600;

int N, step, x, y, lastx, lasty;
int checkers;
char line[0xff];
char mat[MAXN][MAXN];

int main( int argc, char* argv[] ) {

	freopen( argv[1], "r", stdin );
	scanf( "%d", &N );
	REP( i, N ) {
		scanf( "%s", &mat[i] );
		REP( j, N )
		      if ( mat[i][j] == 'o' )
				checkers++;
	}
		
	freopen( argv[2], "r", stdin );
	scanf( "%[^\n]", &line );
	
	if ( strcmp( line, "impossible" ) == 0 ) {
		printf( "You print impossible.\n" );
		exit( 0 );
	} else
	      sscanf( line, "%d %d", &x, &y );
	
	do {
		x--; y--;
		assert( x >= 0 && x < N && y >= 0 && y < N );
		step++;
		
		if ( step == 1 ) {
			assert( mat[x][y] == 'K' );
			mat[x][y] = '+';
		}
		else {
			int dx = x - lastx;
			int dy = y - lasty;
			assert( mat[x][y] == '+' );
			assert( abs( dx ) == 2 && abs( dy ) == 2 );
			assert( mat[x - dx / 2][y - dy / 2] == 'o' );
			mat[x - dx / 2][y - dy / 2] = '*';
		}
		
		lastx = x;
		lasty = y;
	} while ( scanf( "%d %d", &x, &y ) == 2 );
	
	assert( step == checkers + 1 );
		
	printf( "It should be OK!!!!\n" );

	return 0;
}
