/*
Alfonso2 Peterssen (mukel)
23 - 12 - 2008
USACO NOV08 "Light Switching"
*/
#include <cstdio>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXN = 100000;

int N, Q;
int cant[4 * MAXN];
bool mark[4 * MAXN];

/* forward */ void flip( int x, int lo, int hi, int start, int end );

int query( int x, int lo, int hi, int start, int end ) {
	if ( lo > end || hi < start || lo > hi )
	      return 0;

	if ( lo >= start && hi <= end )
		return cant[x];

	int mid = ( lo + hi ) / 2;
	if ( mark[x] ) {
		flip( 2 * x + 1, lo, mid, lo, mid );
		flip( 2 * x + 2, mid + 1, hi, mid + 1, hi );
		mark[x] = false;
	}

	return
		query( 2 * x + 1, lo, mid, start, end ) +
		query( 2 * x + 2, mid + 1, hi, start, end );
}

void flip( int x, int lo, int hi, int start, int end ) {
	if ( lo > end || hi < start || lo > hi )
	      return ;

	if ( lo >= start && hi <= end ) {
		cant[x] = ( hi - lo + 1 ) - cant[x];
		mark[x] ^= true;
		return ;
	}

	int mid = ( lo + hi ) / 2;

	if ( mark[x] ) {
		flip( 2 * x + 1, lo, mid, lo, mid );
		flip( 2 * x + 2, mid + 1, hi, mid + 1, hi );
		mark[x] = false;
	}

	flip( 2 * x + 1, lo, mid, start, end );
	flip( 2 * x + 2, mid + 1, hi, start, end );

	if ( lo < hi )
	      cant[x] = cant[2 * x + 1] + cant[2 * x + 2];
}

int main() {

	scanf( "%d %d", &N, &Q );
	while ( Q-- ) {
		int op, lo, hi;
		scanf( "%d %d %d", &op, &lo, &hi );
		if ( op )
			printf( "%d\n", query( 0, 1, N, lo, hi ) );
		else
		      flip( 0, 1, N, lo, hi );
	}

	return 0;
}
