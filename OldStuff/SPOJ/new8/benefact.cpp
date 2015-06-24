/*
Alfonso2 Peterssen (mukel)
SPOJ #372 "The Benefactor"
25 - 3 - 2009
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXV = 50000;

int T, V, E;
int ans;
bool mark[MAXV];
int first[MAXV];
struct edge {
	int v, w, next;
} edges[2 * MAXV];

int dfs( int u ) {
	mark[u] = true;
	
	int best = 0;
	for ( int e = first[u]; e != -1; e = edges[e].next ) {
		int v = edges[e].v;
		if ( mark[v] ) continue;
		int chain = dfs( v ) + edges[e].w;
		ans = max( ans, best + chain );
		best = max( best, chain );
	}
	
	return best;
}

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d", &V );
		
		E = 0;
		fill( first, first + V, -1 );
		fill( mark, mark + V, false );
		
		REP( i, V - 1 ) {
			int u, v, w;
			scanf( "%d %d %d", &u, &v, &w );
			u--; v--;
			edges[E] = (edge){ v, w, first[u] };
			first[u] = E++;
			edges[E] = (edge){ u, w, first[v] };
			first[v] = E++;
		}
		
		ans = 0;
		dfs( 0 );

		printf( "%d\n", ans );
	}

	return 0;
}
