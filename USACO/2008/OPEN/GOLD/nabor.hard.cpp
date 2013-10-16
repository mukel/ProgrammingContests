/*
Alfonso2 Peterssen (mukel)
23 - 1 - 2009
USACO OPEN08 "Cow Neighborhoods"
Hard2Code Bucketing algorithm
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

#define FOR_EACH( it, c ) \
	for ( typeof( (c).begin() ) it = (c).begin(); it != (c).end(); it++ )

#define ALL( c ) (c).begin(), (c).end()

const int
	MAXN = 100000,
	oo = (int)2e9 + 1;

int N, D;
int unions;
int data[MAXN];
int best[MAXN];
struct point {
	int x, y, id;
	point() {}
	point( int x, int y, int id = 0 ) : x( x ), y( y ), id( id ) {}
};

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

map< point, vector< point >, compX > bckts;

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

point box( const point& P ) {
	int x = P.x;
	int y = P.y;
	if ( x < 0 ) x -= D - 1;
	if ( y < 0 ) y -= D - 1;
	return point( x/D, y/D );
}

int main() {

	memset( data, -1, sizeof( data ) );

	scanf( "%d %d", &N, &D );
	REP( i, N ) {
		int x, y;
		scanf( "%d %d", &x, &y );
		x = x + y;
		y = x - 2 * y;
		bckts[ box( point( x, y ) ) ].push_back( point( x, y, i ) );
	}

	FOR_EACH( it, bckts )
		sort( ALL( (*it).second ), compY() );

	FOR_EACH( it, bckts ) {

		point B;
		typeof( bckts.begin() ) cell;
		vector< point >& pnts = (*it).second;

		// same box
		REP( i, pnts.size() )
			JOIN( pnts[0].id, pnts[i].id );

		// U
		B = box( pnts[0] ); B.y++;
		cell = bckts.find( B );
		if ( cell != bckts.end() ) {
			vector< point >& next = (*cell).second;
			int lo = +oo, hi = -oo;
			REP( i, pnts.size() )
			      hi = max( hi, pnts[i].y );
			REP( i, next.size() )
			      lo = min( lo, next[i].y );
			if ( abs( lo - hi ) <= D )
			      JOIN( pnts[0].id, next[0].id );
		}

		// R
		B = box( pnts[0] ); B.x++;
		cell = bckts.find( B );
		if ( cell != bckts.end() ) {
			vector< point >& next = (*cell).second;
			int lo = +oo, hi = -oo;
			REP( i, pnts.size() )
			      hi = max( hi, pnts[i].x );
			REP( i, next.size() )
			      lo = min( lo, next[i].x );
			if ( abs( lo - hi ) <= D )
			      JOIN( pnts[0].id, next[0].id );
		}

		// RU
		B = box( pnts[0] ); B.x++; B.y++;
		cell = bckts.find( B );
		if ( cell != bckts.end() ) {
			vector< point >& next = (*cell).second;
			REPD( i, pnts.size() ) {
				best[i] = i;
				if ( i < pnts.size() - 1 && pnts[ best[i + 1] ].x > pnts[ best[i] ].x )
					best[i] = best[i + 1];
			}

			int lo = 0, closer = +oo;
			REP( i, pnts.size() ) {
				while ( lo < next.size() && abs( next[lo].y - pnts[i].y ) <= D ) {
					closer = min( closer, next[lo].x );
				      lo++;
				}
				if ( abs( pnts[ best[i] ].x - closer ) <= D ) {
					JOIN( pnts[0].id, next[0].id );
					break;
				}
			}
		}

		// LU
		B = box( pnts[0] ); B.x--; B.y++;
		cell = bckts.find( B );
		if ( cell != bckts.end() ) {
			vector< point >& next = (*cell).second;
			REPD( i, pnts.size() ) {
				best[i] = i;
				if ( i < pnts.size() - 1 && pnts[ best[i + 1] ].x < pnts[ best[i] ].x )
					best[i] = best[i + 1];
			}

			int lo = 0, closer = -oo;
			REP( i, pnts.size() ) {
				while ( lo < next.size() && abs( next[lo].y - pnts[i].y ) <= D ) {
					closer = max( closer, next[lo].x );
				      lo++;
				}
				if ( abs( pnts[ best[i] ].x - closer ) <= D ) {
					JOIN( pnts[0].id, next[0].id );
					break;
				}
			}
		}
	}

	printf( "%d %d\n", N - unions, - *min_element( data, data + N ) );

	return 0;
}
