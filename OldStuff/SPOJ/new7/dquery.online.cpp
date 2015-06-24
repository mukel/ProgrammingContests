/*
Alfonso2 Peterssen (mukel)
8 - 1 - 2008
SPOJ "DQUERY"
Online algorithm
Preprocessing: O( n lg n )
Query: O( lg n )
Memory: O( n lg n )
*/
#include <cstdio>
#include <map>

using std::map;

const int
	MAXN = 40000,
	MAXLGN = 16;

int N, Q;
map< int, int > pos;
int tree[MAXN];
int cant;
struct node {
	int val, L, R, size;
} buff[2 * MAXN * MAXLGN];

int build( int lo, int hi ) {
	if ( lo > hi ) return 0;

	int idx = ++cant;
	
	int mid = ( lo + hi ) / 2;
	buff[idx] = (node){ mid, build( lo, mid - 1 ), build( mid + 1, hi ), 0 };
	return idx;
}

int update( int x, int val, int amount ) {

	if ( x == 0 ) return 0;

	int idx = ++cant;
	
	int L = buff[x].L;
	int R = buff[x].R;
	if ( val < buff[x].val ) L = update( L, val, amount );
	if ( val > buff[x].val ) R = update( R, val, amount );
	
	buff[idx] = (node){ buff[x].val, L, R, buff[x].size + amount };

	return idx;
}

int query( int x, int val ) {
	if ( val < buff[x].val )
		return query( buff[x].L, val ) + buff[x].size -	buff[ buff[x].L ].size;

	if ( val > buff[x].val )
		return query( buff[x].R, val );

	return buff[x].size - buff[ buff[x].L ].size;
}

int main() {

	scanf( "%d", &N );

	tree[0] = build( 1, N );
	for ( int i = 1; i <= N; i++ ) {
		int x, posx;
		scanf( "%d", &x ); posx = pos[x];
		if ( posx != 0 )
			tree[i] = update( update( tree[i - 1], posx, -1 ), i, +1 );
		else
			tree[i] = update( tree[i - 1], i, +1 );
		pos[x] = i;
	}

	scanf( "%d", &Q );
	while ( Q-- ) {
		int lo, hi;
		scanf( "%d %d", &lo, &hi );
		printf( "%d\n", query( tree[hi], lo ) );
	}

	return 0;
}
