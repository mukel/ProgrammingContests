/*
Alfonso2 Peterssen
SPOJ #904 "Image Perimeters"
22 - 9 - 2008
just for fun...
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

int F, C, X, Y;
char board[MAXC][MAXC];
bool mark[MAXC][MAXC];
int tree[4 * MAXC];
int cant[4 * MAXC];

void dfs( int x, int y ) {
	if ( x < 0 || x >= F || y < 0 || y >= C ||
		mark[x][y] || board[x][y] == '.' )
	      return;
	mark[x][y] = true;
	dfs( x - 1, y );
	dfs( x + 1, y );
	dfs( x, y - 1 );
	dfs( x, y + 1 );
	dfs( x - 1, y - 1 );
	dfs( x - 1, y + 1 );
	dfs( x + 1, y - 1 );
	dfs( x + 1, y + 1 );
}

void update( int x, int lo, int hi, int pos, int value ) {
	if ( lo > hi || lo > pos || hi < pos )
	      return;
	      
	if ( lo >= pos && hi <= pos )
		cant[x] += value;
	else {
		int mid = ( lo + hi ) / 2;
		update( 2 * x + 1, lo, mid, pos, value );
		update( 2 * x + 2, mid + 1, hi, pos, value );
	}
	
	if ( cant[x] > 0 )
		tree[x] = hi - lo + 1;
	else {
		if ( lo < hi )
		      tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
		else
		      tree[x] = 0;
	}
}

int main() {

	for (;;) {

		memset( mark, 0, sizeof( mark ) );

		scanf( "%d %d", &F, &C );
		scanf( "%d %d", &X, &Y );
		if ( !X && !Y ) break;
		
		X--; Y--;
		REP( i, F )
		      scanf( "%s", &board[i] );
		dfs( X, Y );
		
		int sol = 0, last;
		
		memset( tree, 0, sizeof( tree ) );
		memset( cant, 0, sizeof( cant ) );
		
		last = 0;
		REP( i, F + 1 ) {
			if ( i < F )
			REP( j, C )
			if ( mark[i][j] ) {
				update( 0, 0, C - 1, j, +1 );
				sol += abs( last - tree[0] );
				last = tree[0];
			}
			if ( i )
			REP( j, C )
			if ( mark[i - 1][j] ) {
				update( 0, 0, C - 1, j, -1 );
				sol += abs( last - tree[0] );
				last = tree[0];
			}
		}
			
		memset( tree, 0, sizeof( tree ) );
		memset( cant, 0, sizeof( cant ) );
		
		last = 0;
		REP( j, C + 1 ) {
			if ( j < C )
			REP( i, F )
			if ( mark[i][j] ) {
				update( 0, 0, F - 1, i, +1 );
				sol += abs( last - tree[0] );
				last = tree[0];
			}
			if ( j )
			REP( i, F )
			if ( mark[i][j - 1] ) {
				update( 0, 0, F - 1, i, -1 );
				sol += abs( last - tree[0] );
				last = tree[0];
			}
		}

		printf( "%d\n", sol );
	}

	return 0;
}
