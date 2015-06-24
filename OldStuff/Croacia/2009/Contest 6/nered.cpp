/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define FOR( i, b, e ) for ( int i = (b); i <= (e); i++ )

const int MAXC = 105;

int C, N;
int T[MAXC][MAXC];

int sum( int x1, int y1, int x2, int y2 ) {
	return T[x2][y2] - T[x1][y2] - T[x2][y1] + T[x1][y1];
}

int main() {

	scanf( "%d %d", &C, &N );
	REP( i, N ) {
		int x, y;
		scanf( "%d %d", &x, &y );
		T[x][y] = 1;
	}
	
	FOR( i, 1, C )
	FOR( j, 1, C )
		T[i][j] += T[i - 1][j] + T[i][j - 1] - T[i - 1][j - 1];

	int ans = (int)1e9;
	FOR( x, 1, C )
	FOR( y, 1, C ) {
		if ( x * y != N ) continue;
		FOR( i, x, C )
		FOR( j, y, C )
			ans = min( ans, N - sum( i - x, j - y, i, j ) );
	}

	printf( "%d\n", ans );

	return 0;
}
