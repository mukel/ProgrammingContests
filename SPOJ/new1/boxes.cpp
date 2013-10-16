/*
Alfonso2 Peterssen
SPOJ #371 "Boxes"
10 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXV = 1002,
	MAXE = 10000,
	oo = (int)1e9;

int T, V, E;
int sol;
int src, snk;
int best[MAXV];
int from[MAXV];
int head[MAXV];
struct edge {
	int u, v, w, cap, next;
} edges[MAXE];

void add_edge( int u, int v, int w, int cap ) {
	edges[E++] = (edge){ u, v, +w, cap, head[u] };
	head[u] = E - 1;
	edges[E++] = (edge){ v, u, -w, 0, head[v] };
	head[v] = E - 1;
}

bool augment( int src, int snk ) {

	fill( best, best + V + 2, oo );
	best[src] = 0;
	
	queue< int > Q;
	for ( Q.push( src ); !Q.empty(); Q.pop() ) {
		int u = Q.front();
		for ( int e = head[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
		      if ( edges[e].cap && best[u] + edges[e].w < best[v] ) {
				Q.push( v );
				best[v] = best[u] + edges[e].w;
				from[v] = e;
			}
		}
	}
	
	if ( best[snk] == oo )
	      return false;
	      
	sol += best[snk];
	for ( int x = snk; x != src; x = edges[ from[x] ].u ) {
		edges[ from[x] ].cap--;
		edges[ from[x]^1 ].cap++;
	}

	return true;
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		E = 0;
		memset( head, -1, sizeof( head ) );

		scanf( "%d", &V );
		
		src = V;
		snk = V + 1;
		
		REP( i, V ) {
			int boxes;
			scanf( "%d", &boxes );
			add_edge( src, i, 0, boxes );
			add_edge( i, snk, 0, 1 );
			add_edge( i, (i+1) % V, 1, oo );
			add_edge( i, (i-1+V) % V, 1, oo );
		}
		
		sol = 0;
		while ( augment( src, snk ) );
		
		printf( "%d\n", sol );
	}

	return 0;
}
