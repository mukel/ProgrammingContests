/*
Alfonso2 Peterssen
SPOJ #387 "Travelling tours"
8 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXV = 402,
	MAXE = 1000000,
	oo = (int)1e9;

int T, V, L, N, E, sol;
int src, snk;
int from[MAXV];
int best[MAXV];
bool mark[MAXV];
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

	fill( mark, mark + N, false );
	fill( best, best + N, oo );
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

		scanf( "%d %d", &V, &L );
		
		E = 0;
		memset( head, -1, sizeof( head ) );
		src = 2 * V;
		snk = 2 * V + 1;
		N = 2 * V + 2;
		
		REP( i, L ) {
			int u, v, w;
			scanf( "%d %d %d", &u, &v, &w );
			u--; v--; v += V;
			add_edge( u, v, w, 1 );
		}
		
		REP( i, V ) {
			add_edge( src, i, 0, 1 );
			add_edge( i + V, snk, 0, 1 );
		}
		
		sol = 0;
		while ( augment( src, snk ) );
		
		printf( "%d\n", sol );
	}
	
	return 0;
}
