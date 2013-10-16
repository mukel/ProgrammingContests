/*
Alfonso2 Peterssen (mukel)
6 - 2 - 2009
SPOJ #375 "Query on a tree"
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXV = 10000;

int T, V, E, LIMIT;
int cant;
int Q[MAXV];
int first[MAXV];

int low[MAXV];
int prev[MAXV];
int best[MAXV];
int from[MAXV];
int depth[MAXV];
int start[MAXV];

struct edge {
	int u, v, w, next;
} edges[2 * MAXV];

void dfs( int u ) {

	Q[cant++] = u;
	start[u] = cant;

	for ( int e = first[u]; e != -1; e = edges[e].next ) {
		int v = edges[e].v;
		if ( !start[v] ) {
			depth[v] = depth[u] + 1;
			from[v] = e;
			prev[v] = u;
			dfs( v );
		}
	}

	if ( cant - start[u] > LIMIT || u == 0 /* always process the root */ ) {

		low[u] = u;
		best[u] = 0; // NONE

		for ( int i = start[u]; i < cant; i++ ) {
			int x = Q[i];
			low[x] = u;
			best[x] = max( best[ prev[x] ], edges[ from[x] ].w );
		}
		cant = start[u]; // leave u alive
	}
}

int query( int u, int v ) {

	int ans = 0;

	while ( u != v ) {
		if ( depth[ low[v] ] > depth[ low[u] ] )
			swap( u, v );

		if ( low[u] != low[v] ) {
			ans = max( ans, best[u] );
			u = low[u];
		} else {
			if ( depth[v] > depth[u] )
				swap( u, v );
			ans = max( ans, edges[ from[u] ].w );
			u = prev[u];
		}
	}

	return ans;
}

void update( int u ) {

	int val = edges[ from[u] ].w;
	if ( low[u] == low[ prev[u] ] )
		val = max( val, best[ prev[u] ] );

	if ( val != best[u] ) {
		best[u] = val;
		for ( int e = first[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			if ( low[v] == low[u] && from[v] == e )
				update( v );
		}
	}
}

int main() {

	scanf( "%d", &T );
	while ( T-- ) {

		scanf( "%d", &V );

		LIMIT = (int)sqrt( V ) + 1;

		E = 0;
		cant = 0;
		fill( first, first + V, -1 );
		fill( start, start + V, 0 );

		REP( i, V - 1 ) {
			int u, v, w;
			scanf( "%d %d %d", &u, &v, &w );
			u--; v--;
			edges[E] = (edge){ u, v, w, first[u] };
			first[u] = E++;
			edges[E] = (edge){ v, u, w, first[v] };
			first[v] = E++;
		}

		dfs( 0 );

		for (;;) {
			char op[10];
			scanf( "%s", &op );
			if ( op[0] == 'D' )
			      break;

			if ( op[0] == 'C' ) {
				int e, w;
				scanf( "%d %d", &e, &w );
				e--;
				e = 2 * e;

				edges[e].w = w;
				edges[e + 1].w = w;

				if ( depth[ edges[e].u ] > depth[ edges[e].v ] )
					update( edges[e].u );
				else
					update( edges[e].v );
			}
			else
			if ( op[0] == 'Q' ) {
				int u, v;
				scanf( "%d %d", &u, &v );
				u--; v--;
				printf( "%d\n", query( u, v ) );
			}
		}
	}

	return 0;
}
