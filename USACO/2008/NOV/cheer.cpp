/*
Alfonso2 Peterssen (mukel)
23 - 12 - 2008
USACO NOV08 "Cheering up the Cows"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXV = 10000,
	MAXE = 100000;

int V, E;
int sol;
int cost[MAXV];
int parent[MAXV];
struct edge {
	int u, v, w;
	bool operator < ( const edge& e ) const {
		return w < e.w;
	}
} edges[MAXE];

int FIND( int x ) {
	if ( parent[x] != x )
		parent[x] = FIND( parent[x] );
	return parent[x];
}

void JOIN( int u, int v ) {
	u = FIND( u );
	v = FIND( v );
	if ( u != v )
		parent[u] = v;
}

int main() {

	scanf( "%d %d", &V, &E );
	REP( i, V )
		scanf( "%d", &cost[i] );

	REP( i, E ) {
		int u, v, w;
		scanf( "%d %d %d", &u, &v, &w );
		u--; v--;
		edges[i] = (edge){ u, v, 2 * w + cost[u] + cost[v] };
	}

	REP( i, V ) parent[i] = i;

	sort( edges, edges + E );
	REP( i, E ) {
		int u = edges[i].u;
		int v = edges[i].v;
		if ( FIND( u ) != FIND( v ) ) {
			JOIN( u, v );
			sol += edges[i].w;
		}
	}

	sol += *min_element( cost, cost + V );
	printf( "%d\n", sol );

	return 0;
}
