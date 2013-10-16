/*
Alfonso2 Peterssen (mukel)
14 - 2 - 2009
SPOJ #1043 "Can you answer these queries I"
GSS1 reloaded
O( n + q lg n )
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXN = 50000;

int N, Q;
int val[MAXN];
struct node {
	int sum, L, R, C;
} T[4 * MAXN];

void build( int x, int lo, int hi ) {

	if ( lo == hi ) {
		T[x].sum = T[x].L = T[x].R = T[x].C = val[lo];
		return ;
	}
	
	int mid = ( lo + hi ) / 2;
	build( 2 * x + 1, lo, mid );
	build( 2 * x + 2, mid + 1, hi );

	T[x].sum = T[2 * x + 1].sum + T[2 * x + 2].sum;
	T[x].L = max( T[2 * x + 1].L, T[2 * x + 1].sum + T[2 * x + 2].L );
	T[x].R = max( T[2 * x + 2].R, T[2 * x + 2].sum + T[2 * x + 1].R );
	T[x].C = max( T[x].L, T[x].R );
	T[x].C = max( T[x].C, max( T[2 * x + 1].C, T[2 * x + 2].C ) );
	T[x].C = max( T[x].C, T[2 * x + 1].R + T[2 * x + 2].L );

	//printf( "%d -> L %d C %d R %d\n", x, T[x].L, T[x].C, T[x].R );
}

int L, R, C, S;

bool query( int x, int lo, int hi, int start, int end ) {
	if ( lo > end || hi < start || lo > hi )
	      return false;

	if ( lo >= start && hi <= end ) {
		L = T[x].L;
		R = T[x].R;
		C = T[x].C;
		S = T[x].sum;
		return true;
	}

	int mid = ( lo + hi ) / 2;

	bool vL; int lR = 0, lL = 0, lC = 0, lS;
	if ( vL = query( 2 * x + 1, lo, mid, start, end ) ) {
		lL = L; lR = R; lC = C; lS = S;
	}

	bool vR; int rR = 0, rL = 0, rC = 0, rS;
	if ( vR = query( 2 * x + 2, mid + 1, hi, start, end ) ) {
		rL = L; rR = R; rC = C; rS = S;
	}

	S = 0;
	if ( vL ) { L = max( lL, lS + rL ); S += lS; } else L = rL;
	if ( vR ) { R = max( rR, rS + lR ); S += rS; } else R = lR;
	
	C = -(int)1e9;
	if ( vL ) C = max( C, lC );
	if ( vR ) C = max( C, rC );
	if ( vL && vR )
	      C = max( C, lR + rL );

	return true;
}

int main() {

	scanf( "%d", &N );
	REP( i, N )
	      scanf( "%d", &val[i] );
	      
	build( 0, 0, N - 1 );
	
	scanf( "%d", &Q );
	while ( Q-- ) {
		int lo, hi;
		scanf( "%d %d", &lo, &hi );
		lo--; hi--;
		query( 0, 0, N - 1, lo, hi );
		printf( "%d\n", C );
	}
	
	return 0;
}
