/*
Alfonso2 Peterssen
SPOJ #116 "Intervals"
5 - 9 - 2008
O( n lg^2 n )
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 50000;

int T, N;
int tree[4 * MAXN];
struct interval {
	int lo, hi, c;
	bool operator < ( const interval& i ) const { return hi < i.hi; }
};
interval I[MAXN];

int query( int x, int lo, int hi, int start, int end ) {
	if ( lo > hi || lo > end || hi < start )
	      return 0;
	if ( lo >= start && hi <= end )
		return tree[x];
	if ( tree[x] == hi - lo + 1 )
	      return min( hi, end ) - max( lo, start ) + 1;
	int mid = lo + ( hi - lo ) / 2;
	return
		query( 2 * x + 1, lo, mid, start, end ) +
		query( 2 * x + 2, mid + 1, hi, start, end );
}

void update( int x, int lo, int hi, int start, int end ) {
	if ( lo > hi || lo > end || hi < start )
	      return;
	if ( lo >= start && hi <= end ) {
		tree[x] = hi - lo + 1;
		return ;
	}
	int mid = lo + ( hi - lo ) / 2;
	update( 2 * x + 1, lo, mid, start, end );
	update( 2 * x + 2, mid + 1, hi, start, end );
	if ( lo != hi )
	      tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		memset( tree, 0, sizeof( tree ) );
		
		scanf( "%d", &N );
		REP( i, N )
			scanf( "%d %d %d", &I[i].lo, &I[i].hi, &I[i].c );
			
		sort( I, I + N );
		
		REP( i, N ) {
			int lo = I[i].lo;
			int hi = I[i].hi;
			I[i].c -= query( 0, 0, MAXN, lo, hi );
			if ( I[i].c <= 0 )
				continue;
			
			while ( lo <= hi ) {
				int mid = ( lo + hi ) / 2;
				if ( I[i].hi - mid + 1 - query( 0, 0, MAXN, mid, I[i].hi ) >= I[i].c )
				      lo = mid + 1;
				else
				      hi = mid - 1;
			}
			update( 0, 0, MAXN, lo - 1, I[i].hi );
		}
		
		printf( "%d\n", tree[0] );
	}

	return 0;
}
