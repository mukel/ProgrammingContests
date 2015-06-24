/*
Alfonso2 Peterssen (mukel)
14 - 2 - 2009
SPOJ #1557 "Can you answer these queries II"
GSS2 reloaded
O( (n + q) lg n )
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int
	MAXN = 100000,
	MAXV = 100000,
	MAXQ = 100000;

int N, Q;
int id;
int val[MAXN];
int last[2 * MAXV + 1];

int64 ans[MAXQ];
struct itvl_query {
	int lo, hi, idx;
	bool operator < ( const itvl_query& q ) const { return hi < q.hi; }
} qs[MAXQ];

struct node {
	int64 sum, maxsum, cumul, best;
} T[4 * MAXN];

void refresh( int x, int64 sum, int64 maxsum ) {
	T[x].maxsum = max( T[x].maxsum, T[x].sum + maxsum );
	T[x].sum += sum;
	T[x].best = max( T[x].best, T[x].cumul + maxsum );
	T[x].cumul += sum;
}

void propagate( int x ) {
	refresh( 2 * x + 1, T[x].sum, T[x].maxsum );
	refresh( 2 * x + 2, T[x].sum, T[x].maxsum );
	T[x].sum = 0;
	T[x].maxsum = 0;
}

void update( int x, int lo, int hi, int start, int end, int val ) {
	if ( lo > end || hi < start || lo > hi )
	      return ;

	if ( lo >= start && hi <= end ) {
		T[x].sum += val;
		T[x].cumul += val;
		T[x].maxsum = max( T[x].maxsum, T[x].sum );
		T[x].best = max( T[x].best, T[x].cumul );
		return ;
	}

	if ( T[x].sum || T[x].maxsum )
	      propagate( x );

	int mid = ( lo + hi ) / 2;
	update( 2 * x + 1, lo, mid, start, end, val );
	update( 2 * x + 2, mid + 1, hi, start, end, val );

	T[x].cumul = max( T[2 * x + 1].cumul, T[2 * x + 2].cumul );
	T[x].best = max( T[x].best, max( T[2 * x + 1].best, T[2 * x + 2].best ) );
}

int64 query( int x, int lo, int hi, int start, int end ) {
	if ( lo > end || hi < start || lo > hi )
	      return 0;

	if ( lo >= start && hi <= end )
		return T[x].best;

	if ( T[x].sum || T[x].maxsum )
		propagate( x );

	int mid = ( lo + hi ) / 2;
	return max(
		query( 2 * x + 1, lo, mid, start, end ),
		query( 2 * x + 2, mid + 1, hi, start, end ) );
}

int main() {

	scanf( "%d", &N );
	REP( i, N )
	      scanf( "%d", &val[i] );

	scanf( "%d", &Q );
	REP( i, Q ) {
		int lo, hi;
		scanf( "%d %d", &lo, &hi );
		lo--; hi--;
		qs[i] = (itvl_query){ lo, hi, i };
	}

	sort( qs, qs + Q );
	REP( i, N ) {
		update( 0, 0, N - 1, last[ val[i] + MAXV ], i, val[i] );
		last[ val[i] + MAXV ] = i + 1;

		while ( id < Q && qs[id].hi == i ) {
		      ans[ qs[id].idx ] = query( 0, 0, N - 1, qs[id].lo, i );
		      id++;
		}
	}

	REP( i, Q )
	      printf( "%lld\n", ans[i] );

	return 0;
}
