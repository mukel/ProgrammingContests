/*
Alfonso2 Peterssen (mukel)
26 - 2 - 2008
Polish OI VIII (2001) Stage III "KOP"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

typedef pair< int, int > point;

const int
	MAXN = 15000,
	MAXC = 30000;

int F, C, N;
int ans;
point pnts[MAXN];
struct node {
	int best, delta;
} T[4 * 2 * MAXC];

void update( int x, int lo, int hi, int start, int end, int val ) {
	if ( lo > end || hi < start || lo > hi )
	      return ;

	if ( lo >= start && hi <= end ) {
		T[x].best += val;
		T[x].delta += val;
		return ;
	}

	int mid = lo + ( hi - lo ) / 2;
	if ( T[x].delta != 0 ) {
		// propagate
		update( 2 * x, lo, mid, lo, mid, T[x].delta );
		update( 2 * x + 1, mid + 1, hi, mid + 1, hi, T[x].delta );
		T[x].delta = 0;
	}

	update( 2 * x, lo, mid, start, end, val );
	update( 2 * x + 1, mid + 1, hi, start, end, val );

	T[x].best = max( T[2 * x].best, T[2 * x + 1].best );
}

// update interface
void update( int x, int val ) {
	update( 1, -MAXC, +MAXC, x, x + C, val );
}

int main() {

	scanf( "%d %d", &F, &C );
	scanf( "%d", &N );
	REP( i, N ) {
		int x, y;
		scanf( "%d %d", &x, &y );
		pnts[i] = make_pair( x, y );
	}

	sort( pnts, pnts + N );

	int lo = 0;
	REP( i, N ) {
		update( pnts[i].second, +1 );
		while ( lo < i && pnts[i].first - pnts[lo].first > F ) {
			update( pnts[lo].second, -1 );
			lo++;
		}
		ans = max( ans, T[1].best );
	}

	printf( "%d\n", ans );

	return 0;
}
