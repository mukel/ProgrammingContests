/*
Alfonso2 Peterssen (mukel)
11 - 2 - 2009
SGU #128 "Snake"
The solution is unique, so build and check it...
2-SAT not needed
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXN = 10000,
	MAXC = 10005,
	MAXT = 2 * MAXC;

int N;
int ans;
struct point {
	int x, y, id;
	bool operator < ( const point& p ) const {
		if ( x != p.x ) return x < p.x;
		return y < p.y;
	}
} pnts[MAXN];

int next[2][MAXN];
bool used[MAXN];

int T[MAXT];

int lobit( int x ) { return x & -x; }

void update( int x, int val ) {
	for ( ++x; x < MAXT; x += lobit( x ) )
	      T[x] += val;
}

int query( int x ) {
	int sum = 0;
	for ( ++x; x > 0; x -= lobit( x ) )
	      sum += T[x];
	return sum;
}

int dfs( int x, int dir = 0 ) {
	if ( used[x] ) return 0;
	used[x] = true;
	return dfs( next[1 - dir][x], 1 - dir ) + 1;
}

void solution( int ans ) {
	printf( "%d\n", ans );
	exit( 0 );
}

int main() {

	scanf( "%d", &N );

	if ( N % 2 )
	      solution( 0 );

	REP( i, N ) {
		int x, y;
		scanf( "%d %d", &x, &y );
		x += MAXC;
		y += MAXC;
		pnts[i] = (point){ x, y, i };
	}

	REP( dir, 2 ) {
		sort( pnts, pnts + N );

		for ( int i = 0; i < N; i += 2 ) {
			if ( pnts[i].x != pnts[i + 1].x )
				solution( 0 );

			next[dir][ pnts[i].id ] = pnts[i + 1].id;
			next[dir][ pnts[i + 1].id ] = pnts[i].id;

			ans += abs( pnts[i].y - pnts[i + 1].y );
		}

		REP( i, N )
			swap( pnts[i].x, pnts[i].y );
	}

	if ( dfs( 0 ) != N )
		solution( 0 );

	sort( pnts, pnts + N ); // already sorted
	REP( i, N ) {

		int val;
		if ( query( pnts[i].y ) - query( pnts[i].y - 1 ) == 0 )
		      val = +1; // mark
		else
		      val = -1; // unmark

		update( pnts[i].y, val );

		if ( i % 2 == 0 )
			if ( query( pnts[i + 1].y - 1 ) - query( pnts[i].y ) > 0 )
			      solution( 0 );
	}

	solution( ans );

	return 0;
}
