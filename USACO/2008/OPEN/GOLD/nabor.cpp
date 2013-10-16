/*
Alfonso2 Peterssen (mukel)
23 - 1 - 2009
USACO OPEN08 "Cow Neighborhoods"
Simple Sweep-line algorithm
*/
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 100000;

int N, D;
int unions;
int data[MAXN];
struct point {
	int x, y, id;
} pnts[MAXN];

struct compX {
	bool operator () ( const point &a, const point& b ) {
		return ( a.x != b.x ) ? a.x < b.x : a.y < b.y;
	}
};

struct compY {
	bool operator () ( const point &a, const point& b ) {
		return ( a.y != b.y ) ? a.y < b.y : a.x < b.x;
	}
};

multiset< point, compY > S;

int FIND( int x ) {
	return ( data[x] < 0 ) ? x : data[x] = FIND( data[x] );
}

void JOIN( int x, int y ) {
	x = FIND( x );
	y = FIND( y );
	if ( x != y ) {
		if ( data[y] < data[x] )
		      swap( x, y );
		data[x] += data[y];
		data[y] = x;
		unions++;
	}
}

int main() {

	memset( data, -1, sizeof( data ) );

	scanf( "%d %d", &N, &D );
	REP( i, N ) {
		int x, y;
		scanf( "%d %d", &x, &y );
		pnts[i] = (point){ x + y, x - y, i };
	}

	sort( pnts, pnts + N, compX() );

	for ( int lo = 0, hi = 0; hi < N; hi++ ) {

		while ( lo < hi && pnts[hi].x - pnts[lo].x > D ) {
			S.erase( S.find( pnts[lo] ) );
		      lo++;
		}

		typeof( S.begin() ) it;

		/* next point */
		it = S.upper_bound( pnts[hi] );
		if ( it != S.end() && abs( pnts[hi].y - (*it).y ) <= D )
			JOIN( pnts[hi].id, (*it).id );

		/* prev point */
		if ( it != S.begin() ) it--;
		if ( it != S.end() && abs( pnts[hi].y - (*it).y ) <= D )
			JOIN( pnts[hi].id, (*it).id );

		S.insert( pnts[hi] );
	}

	printf( "%d %d\n", N - unions, - *min_element( data, data + N ) );

	return 0;
}
