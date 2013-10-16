/*
Alfonso2 Peterssen (mukel)
SPOJ #4197 "Dominoes"
23 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )

#define ALL( c ) (c).begin(), (c).end()

const int
	MAXN = 1 << 17,
	oo = (int)2e9;

int N;
pair< int, int > D[MAXN];
int lo[MAXN], hi[MAXN];
int dp[MAXN];
vector< int > T;

inline int lobit( int x ) { return x & -x; }

int query( int x ) {
	int ans = oo;
	for ( ; x < T.size(); x += lobit( x + 1 ) )
		ans = min( ans, T[x] );
	return ans;
}

void update( int x, int val ) {
	for ( ; x >= 0; x -= lobit( x + 1 ) )
		T[x] = min( T[x], val );
}

void add( int val ) {
	T.push_back( val );
	update( T.size() - 1, val );
}

int main() {

	scanf( "%d", &N );
	REP( i, N ) {
		int x, h;
		scanf( "%d %d", &x, &h );
		D[i] = make_pair( x, h );
	}
	
	sort( D, D + N );
	
	// knock left
	T.clear();
	REP( i, N ) {
		int val = D[i].first - D[i].second;
		int pos = lower_bound( D, D + i + 1, make_pair( val, -oo ) ) - D;
		lo[i] = min( i, query( pos ) );
		add( lo[i] );
	}

	// knock right
	T.clear();
	REPD( i, N ) {
		int val = D[i].first + D[i].second;
		int pos = upper_bound( D + i, D + N, make_pair( val, +oo ) ) - D;
		pos--;
		hi[i] = -min( -i, query( N - pos - 1 ) );
		add( -hi[i] );
	}
	
	T.clear();
	T.resize( N );
	fill( ALL( T ), oo );
	REP( i, N ) {
		int prev = ( i > 0 ) ? dp[i - 1] : 0;
    		update( hi[i], prev );
    		prev = ( lo[i] > 0 ) ? dp[ lo[i] - 1 ] : 0;
		dp[i] = min( prev, query( i ) ) + 1;
	}

	printf( "%d\n", dp[N - 1] );

	return 0;
}
