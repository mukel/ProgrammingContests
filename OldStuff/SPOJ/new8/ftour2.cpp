/*
Alfonso2 Peterssen (mukel)
SPOJ #1825 "Free tour II"
27 - 3 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXV = 200000,
	oo = (int)1e9;

int V, E, K, M;
int ans;
int idx[MAXV];
bool mark[MAXV];
bool crowd[MAXV];
int first[MAXV];
struct edge {
	int v, w, next;
} edges[2 * MAXV];

struct kkona {
	int offset;
	vector< int > T;
	
	inline int lobit( int x ) { return x & -x; }
	
	int query( int x ) {

		x = min( x, (int)T.size() - 1 );
		x = T.size() - x - 1;

		int val = -oo;
		for ( ; x < T.size(); x += lobit( x + 1 ) )
			val = max( val, T[x] );

		return val + offset;
	}
	
	void update( int x, int val ) {

		x = min( x, (int)T.size() - 1 );
		x = T.size() - x - 1;

		val -= offset;
		for ( ; x >= 0; x -= lobit( x + 1 ) )
			T[x] = max( T[x], val );
	}

	void add( int val ) {
		T.push_back( val - offset );
		update( 0, val );
	}

	void add_offset( int val ) { offset += val; }
	
} S[MAXV];

void find_longest_chain( int u, int v ) { // by val -> doesnt changes idx
	if ( S[v].T.size() > S[u].T.size() )
		swap( u, v );

	int limit = min( K, (int)S[v].T.size() - 1 );

	for ( int i = 0; i <= limit; i++ )
		ans = max( ans, S[v].query( i ) + S[u].query( K - i ) );
}

// keep u alive!!!
void unite( int& u, int& v ) { // by ref -> swap in idx[]
	if ( S[v].T.size() > S[u].T.size() )
		swap( u, v );

	int limit = min( K, (int)S[v].T.size() - 1 );
	
	for ( int i = 0; i <= limit; i++ )
		S[u].update( i, S[v].query( i ) );

	S[v].T.clear();
	// -> S[v].T.resize( 0 );
	// -> S[v].T.erase( ALL( S[v].T ) );
}

void dfs( int u ) {
	mark[u] = true;
	idx[u] = u;

      S[ idx[u] ].add( 0 );
	if ( crowd[u] )
		S[ idx[u] ].add( -oo );

	for ( int e = first[u]; e != -1; e = edges[e].next ) {
		int v = edges[e].v;
		if ( mark[v] ) continue ;
		dfs( v );
		
		S[ idx[v] ].add_offset( edges[e].w );
		
		find_longest_chain( idx[u], idx[v] );
		
		if ( crowd[u] )
		      S[ idx[v] ].add( -oo );

		unite( idx[u], idx[v] );
	}

	ans = max( ans, S[ idx[u] ].query( K ) );
}

int main() {

	scanf( "%d %d %d", &V, &K, &M );
	REP( i, M ) {
		int u;
		scanf( "%d", &u );
		u--;
		crowd[u] = true;
	}

	fill( first, first + V, -1 );
	REP( i, V - 1 ) {
		int u, v, w;
		scanf( "%d %d %d", &u, &v, &w );
		u--; v--;
		edges[E] = (edge){ v, w, first[u] };
		first[u] = E++;
		edges[E] = (edge){ u, w, first[v] };
		first[v] = E++;
	}

	dfs( 0 );
	
	printf( "%d", ans );

	return 0;
}
