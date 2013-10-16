/*
Alfonso2 Peterssen
SPOJ #286 "Selfish Cities"
5 - 9 - 2008
*/
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int
	MAXV = 202,
	MAXE = 100000,
	oo = (int)1e9,
	xx = (int)1e6;

int T, S, B, V, E;
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

	fill( best, best + V, oo );
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

	sol += xx - best[snk];
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

		scanf( "%d %d", &S, &B );
		for (;;) {
			int u, v, w;
			scanf( "%d %d %d", &u, &v, &w );
			if ( !u && !v && !w ) break;
			u--; v--;
			add_edge( u, v + S, xx - w, oo );
		}

		V = S + B;
		src = V++;
		snk = V++;

		REP( i, S ) add_edge( src, i, 0, 1 );
		REP( i, B ) add_edge( i + S, snk, 0, 1 );
		
		sol = 0;
		while ( augment( src, snk ) );
		
		printf( "%d\n", sol );
	}

	return 0;
}
