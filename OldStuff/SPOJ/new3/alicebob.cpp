/*
Alfonso2 Peterssen
SPOJ #105 "Alice and Bob"
16 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXV = 10000,
	MAXE = 100000;

int T, N, D, P;
int discover_time;
int low[MAXV];
int dfsnum[MAXV];
int poly[MAXV];
bool mark[MAXV];
struct graph {
	int V, E, head[MAXV];
	struct edge {
		int u, v, next;
	} edges[MAXE];
	
	void init( int _V ) {
		V = _V;
		E = 0;
		memset( head, -1, sizeof( head ) );
	}
	
	void add_edge( int u, int v ) {
		edges[E++] = (edge){ u, v, head[u] };
		head[u] = E - 1;
		edges[E++] = (edge){ v, u, head[v] };
		head[v] = E - 1;
	}
} G, H;

void dfs( const graph& G, int x, int father ) {
	dfsnum[x] = low[x] = ++discover_time;
	
	int sons = 0, best = x, z;
	for ( int e = G.head[x]; e != -1; e = G.edges[e].next ) {
		int y = G.edges[e].v;
		if ( y == father ) continue;
		if ( !dfsnum[y] ) {
			sons++; z = y;
			dfs( G, y, x );
			if ( low[y] < low[x] ) {
				low[x] = low[y]; best = y;
			}
		} else
			if ( dfsnum[y] < low[x] ) {
				low[x] = dfsnum[y]; best = y;
			}
	}
	
	if ( sons == 0 ) {
		H.add_edge( x, father );
		H.add_edge( x, best );
	} else
	if ( sons == 1 )
		if ( father == 0 || low[z] < dfsnum[father] )
			H.add_edge( x, father );
		else
			H.add_edge( x, best );
}

// just walk the graph
void euler( const graph& G, int x, int father ) {
	mark[x] = true;
	for ( int e = G.head[x]; e != -1; e = G.edges[e].next ) {
		int y = G.edges[e].v;
		if ( !mark[y] )
			euler( G, y, x );
	}
	poly[P++] = x;
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		scanf( "%d %d", &N, &D );
		
		P = 0;
		discover_time = 0;
		memset( mark, 0, sizeof( mark ) );
		memset( dfsnum, 0, sizeof( dfsnum ) );
		G.init( N );
		H.init( N );
		
		REP( i, N + D ) {
			int u, v;
			scanf( "%d %d", &u, &v );
			u--; v--;
			G.add_edge( u, v );
		}
		
		dfs( G, 0, -1 );
		euler( H, 0, -1 );
		
		int delta;
		if ( poly[0] < poly[N - 2] )
		      delta = +1;
		else
		      delta = -1;

		printf( "1" );
		int pos = N - 1;
		for (;;) {
			pos = ( pos + delta + N ) % N;
			if ( pos == N - 1 ) break;
			printf( " %d", poly[pos] + 1 );
		}
		printf( "\n" );
	}

	return 0;
}
