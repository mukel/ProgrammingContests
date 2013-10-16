/*
Alfonso2 Peterssen
SPOJ #964 "Entrapment"
19 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXV = 70000,
	MAXE = 400000;

int T, V, L, E;
bool mark[MAXV];
int from[MAXV];
int head[MAXV];
struct edge {
	int u, v, cap, next;
} edges[MAXE];

void add_edge( int u, int v ) {
	edges[E++] = (edge){ u, v, 1, head[u] }; head[u] = E - 1;
	edges[E++] = (edge){ v, u, 0, head[v] }; head[v] = E - 1;
}

void dfs( int u ) {
	mark[u] = true;
	for ( int e = head[u]; e != -1; e = edges[e].next ) {
		int v = edges[e].v;
		if ( edges[e].cap && !mark[v] ) {
			from[v] = e;
		      dfs( v );
		}
	}
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		E = 0;
		memset( head, -1, sizeof( head ) );

		scanf( "%d %d", &V, &L );
		REP( i, L ) {
			int u, v;
			scanf( "%d %d", &u, &v );
			u--; v--;
			add_edge( 2 * u + 1, 2 * v );
		}
		
		REP( i, V ) add_edge( 2 * i, 2 * i + 1 );
		
		fill( mark, mark + 2 * V, false );
		dfs( 0 );

		for ( int x = 2 * (V-1) + 1; x != 0; x = edges[ from[x] ].u ) {
			edges[ from[x] ].cap--;
			edges[ from[x]^1 ].cap++;
		}
		
		fill( mark, mark + 2 * V, false );
		for ( int e = head[1]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			if ( !mark[v] )
			      dfs( v );
		}
		
		REP( i, V )
		      if ( i && mark[2 * i] && !mark[2 * i + 1] ) {
				printf( "%d\n", i + 1 );
		            break;
			}
	}

	return 0;
}
