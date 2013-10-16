/*
Alfonso2 Peterssen
SPOJ #1802 "Edge"
6 - 9 - 2008
*/
#include <iostream>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXLEN = 300;

int x, y;
int lastx, lasty;
int tx, ty;
string line;

int main() {

	while ( cin >> line ) {
		lastx = 30;
		lasty = 42;
		x = 31;
		y = 42;
		
		printf( "300 420 moveto\n310 420 lineto\n" );
		REP( i, line.size() ) {
			int dir = ( line[i] == 'A' ) ? -1 : +1;
			tx = x;
			ty = y;
			x -= ( ty - lasty ) * dir;
			y += ( tx - lastx ) * dir;
			printf( "%d0 %d0 lineto\n", x, y );
			lastx = tx;
			lasty = ty;
		}
		
		printf( "stroke\nshowpage\n" );
	}

	return 0;
}
