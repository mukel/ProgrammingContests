/*
Alfonso2 Peterssen (mukel)
USACO MAR09 "damage2"
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXV = 6000,
	MAXE = 100000;

int V, L, E, D;
int ans;
bool mark[MAXV];
bool sink[MAXV];
int first[MAXV];
struct edge {
	int v, cap, next;
} edges[MAXE];

void add_edge( int u, int v ) {
	edges[E] = (edge){ v, 1, first[u] };
	first[u] = E++;
	edges[E] = (edge){ u, 0, first[v] };
	first[v] = E++;
}

bool dfs( int u ) {
	if ( sink[u] )
		return true;
	mark[u] = true;
	for ( int e = first[u]; e != -1; e = edges[e].next ) {
		int v = edges[e].v;
		if ( !mark[v] && edges[e].cap && dfs( v ) ) {
			edges[e].cap--;
			edges[e^1].cap++;
			return true;
		}
	}
	return false;
}

int main() {

	memset( first, -1, sizeof( first ) );

	scanf( "%d %d %d", &V, &L, &D );
	REP( i, L ) {
		int u, v;
		scanf( "%d %d", &u, &v );
		u--; v--;
		add_edge( 2 * u + 1, 2 * v );
		add_edge( 2 * v + 1, 2 * u );
	}

	REP( i, V )
		add_edge( 2 * i, 2 * i + 1 );

	REP( i, D ) {
		int u;
		scanf( "%d", &u );
		u--;
		sink[2 * u] = true;
	}

	while ( dfs( 1 ) ) {
		ans++;
		fill( mark, mark + 2 * V, false );
	}

	printf( "%d\n", ans );

	return 0;
}
