/*
Alfonso2 Peterssen (mukel)
16 - 2 - 2009
SPOJ #1741 "Tetris 3D"
2-dimensional segment tree
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXNOD = 1 << 11;

int F, C, N;

int xlo, ylo, xhi, yhi; // query interface

void prepare_box( int _xlo, int _ylo, int _xhi, int _yhi ) {
	xlo = _xlo; xhi = _xhi;
	ylo = _ylo; yhi = _yhi;
}

struct segTree1D {

	struct node {
		int best, height;
	} T[MAXNOD];
	
	void update( int x, int lo, int hi, int nval ) {
		if ( lo > yhi || hi < ylo || lo > hi )
			return ;
			
		if ( lo >= ylo && hi <= yhi ) {
			T[x].height = max( T[x].height, nval );
			T[x].best = max( T[x].best, nval );
			return ;
		}
		
		int mid = ( lo + hi ) / 2;
		update( 2 * x + 1, lo, mid, nval );
		update( 2 * x + 2, mid + 1, hi, nval );
		T[x].best = max( T[x].best, nval );
	}
	
	int query( int x, int lo, int hi ) {
		if ( lo > yhi || hi < ylo || lo > hi )
			return 0;

		if ( lo >= ylo && hi <= yhi )
			return T[x].best;

		int mid = ( lo + hi ) / 2;
		return max( T[x].height,
		 		max(
				 	query( 2 * x + 1, lo, mid ),
					query( 2 * x + 2, mid + 1, hi ) )
			 );
	}
	
};

struct segTree2D {

	struct node {
		segTree1D best, height;
	} T[MAXNOD];

	void update( int x, int lo, int hi, int nval ) {
		if ( lo > xhi || hi < xlo || lo > hi )
			return ;

		if ( lo >= xlo && hi <= xhi ) {
			T[x].height.update( 0, 0, C, nval );
			T[x].best.update( 0, 0, C, nval );
			return ;
		}

		int mid = ( lo + hi ) / 2;
		update( 2 * x + 1, lo, mid, nval );
		update( 2 * x + 2, mid + 1, hi, nval );
		T[x].best.update( 0, 0, C, nval );
	}
	
	int query( int x, int lo, int hi ) {
		if ( lo > xhi || hi < xlo || lo > hi )
			return 0;

		if ( lo >= xlo && hi <= xhi )
			return T[x].best.query( 0, 0, C );

		int mid = ( lo + hi ) / 2;
		return max( T[x].height.query( 0, 0, C ),
		 		max(
				 	query( 2 * x + 1, lo, mid ),
					query( 2 * x + 2, mid + 1, hi ) )
			 );
	}
	
} T;

int query() { return T.query( 0, 0, F ); }
void update( int val ) { T.update( 0, 0, F, val ); }

int main() {

	scanf( "%d %d %d", &F, &C, &N );
	REP( i, N ) {
		int dx, dy, x, y, h;
		scanf( "%d %d %d %d %d", &dx, &dy, &h, &x, &y );
		prepare_box( x, y, x + dx - 1, y + dy - 1 );
		update( query() + h );
	}
	
	prepare_box( 0, 0, F, C );
	printf( "%d\n", query() );

	return 0;
}
