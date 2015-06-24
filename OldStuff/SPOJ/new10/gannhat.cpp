/*
Alfonso2 Peterssen (mukel)
SPOJ #2678 "Closest distance"
20 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )

typedef pair< int, int > par;

const int
	MAXN = 1 << 18,
	oo = (int)1e9;

int N, C;
int X[MAXN];
int Y[MAXN];
int idx[MAXN];
int coords[MAXN];
int compY[MAXN];
int ans[MAXN];

struct Fenwick { // 0-based
	par T[MAXN];
	void reset( int N ) { fill( T, T + N, make_pair( oo, -1 ) ); }
	inline int lobit( int x ) { return x & -x; }
	int query( int x ) {
		par ans = T[x];
		for ( ; x >= 0; x -= lobit(x + 1) )
		      ans = min( ans, T[x] );
		return ans.second;
	}
	void update( int x, par val ) {
		for ( ; x < N; x += lobit(x + 1) )
		      T[x] = min( T[x], val );
	}
} L, R;

int dist( int i, int j ) {
	return abs( X[i] - X[j] ) + abs( Y[i] - Y[j] );
}

bool X_cmp( const int& i, const int& j ) {
	return X[i] < X[j];
}

void update( int id, int x ) {
	if ( ans[id] == -1 || dist( id, x ) < dist( id, ans[id] ) )
	      ans[id] = x;
}

/* Fast IO */
//#define getc_unlocked( kk ) getchar()
inline int nextInt() {
	register int res = 0;
	register char ch;
	while ( ( ch = getc_unlocked( stdin ) ) < '0' );
	do {
		res *= 10;
		res += ch - '0';
	} while ( ( ch = getc_unlocked( stdin ) ) >= '0' );
	return res;
}

int main() {

	N = nextInt();
	REP( i, N ) {
		X[i] = nextInt();
		Y[i] = nextInt();
		coords[C++] = Y[i];
		idx[i] = i;
	}

	sort( coords, coords + C );
	C = unique( coords, coords + C ) - coords;
	REP( i, N ) compY[i] = lower_bound( coords, coords + C, Y[i] ) - coords;
	
	sort( idx, idx + N, X_cmp );
	
	fill( ans, ans + N, -1 );
	
	/* case 1 */
	L.reset( N );
	R.reset( N );
	REP( i, N ) {
		int id = idx[i];
		int a = L.query( compY[id] );
		int b = R.query( N - compY[id] - 1 );
		
		if ( a != -1 ) update( id, a );
 		if ( b != -1 ) update( id, b );

		L.update( compY[id], make_pair( -X[id] - Y[id], id ) );
		R.update( N - compY[id] - 1, make_pair( Y[id] - X[id], id ) );
	}

	/* case 2 */
	L.reset( N );
	R.reset( N );
	REPD( i, N ) {
		int id = idx[i];
		int a = L.query( compY[id] );
		int b = R.query( N - compY[id] - 1 );

		if ( a != -1 ) update( id, a );
 		if ( b != -1 ) update( id, b );

		L.update( compY[id], make_pair( X[id] - Y[id], id ) );
		R.update( N - compY[id] - 1, make_pair( X[id] + Y[id], id ) );
	}
	
	REP( i, N )
	      printf( "%d\n", dist( i, ans[i] ) );

	return 0;
}
