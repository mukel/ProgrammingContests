/*
Alfonso2 Peterssen (mukel)
8 - 1 - 2008
SPOJ "DQUERY"
Simple( and fast ) offline algorithm
*/
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXN = 40000,
	MAXQ = 200000;

int N, Q;
int cant;
int T[MAXN];
int sol[MAXQ];
map< int, int > pos;
struct event {
	int pos, val, idx;
	bool operator < ( const event& e ) const {
		if ( pos != e.pos ) return pos < e.pos;
		return idx < e.idx;
	}
} evts[MAXN + MAXQ];

int lobit( int x ) { return x & -x; }

int query( int x ) {
	int sum = 0;
	for ( ; x > 0; x -= lobit( x ) )
		sum += T[x];
	return sum;
}

void update( int x, int amount ) {
	for ( ; x <= N; x += lobit( x ) )
	      T[x] += amount;
}

int main() {

	scanf( "%d", &N );
	REP( i, N ) {
		int x;
		scanf( "%d", &x );
		evts[cant++] = (event){ i + 1, x, -1 };
	}
	
	scanf( "%d", &Q );
	REP( i, Q ) {
		int lo, hi;
		scanf( "%d %d", &lo, &hi );
		evts[cant++] = (event){ hi, lo, i };
	}
	
	sort( evts, evts + cant );
	REP( i, cant )
		if ( evts[i].idx < 0 ) {
			if ( pos[ evts[i].val ] != 0 )
			      update( pos[ evts[i].val ], -1 );
			update( evts[i].pos, +1 );
			pos[ evts[i].val ] = evts[i].pos;
		} else
		      sol[ evts[i].idx ] = query( evts[i].pos ) - query( evts[i].val - 1 );
	
	REP( i, Q )
	      printf( "%d\n", sol[i] );

	return 0;
}
