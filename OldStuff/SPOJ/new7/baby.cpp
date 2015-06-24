/*
Alfonso2 Peterssen (mukel)
25 - 1 - 2009
SPOJ #3477 "Baby"
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXQ = 16,
	MAXV = 40,
	MAXE = 1000,
	oo = (int)1e9;

int N, V, E;
int ans;
int L[MAXQ], R[MAXQ];
int first[MAXV];
int best[MAXV];
int from[MAXV];
int src, snk;
struct edge {
	int u, v, w, cap, next;
} edges[MAXE];

void add_edge( int u, int v, int w, int cap ) {
	edges[E] = (edge){ u, v, +w, cap, first[u] };
	first[u] = E++;
	edges[E] = (edge){ v, u, -w, 0, first[v] };
	first[v] = E++;
}

bool augment( int src, int snk ) {

	queue< int > Q;
	fill( best, best + V, oo );
	best[src] = 0;
	from[src] = -1;
	
	for ( Q.push( src ); !Q.empty(); Q.pop() ) {
		int u = Q.front();
		for ( int e = first[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			int w = edges[e].w;
			if ( edges[e].cap > 0 && best[u] + w < best[v] ) {
				best[v] = best[u] + w;
				from[v] = e;
				Q.push( v );
			}
		}
	}
	
	if ( best[snk] == oo )
	      return false;
	      
	ans += best[snk];
	for ( int e = from[snk]; e != -1; e = from[ edges[e].u ] ) {
		edges[e].cap--;
		edges[e^1].cap++;
	}
	
	return true;
}

int main() {

	for(;/* ever */;) {
		scanf( "%d", &N ); if ( N == 0 ) break;

		E = 0;
		memset( first, -1, sizeof( first ) );
		src = 2 * N;
		snk = 2 * N + 1;
		V = 2 * N + 2; // 2N queens + src + snk
		
		REP( i, N ) {
			scanf( "%d", &L[i] );
			add_edge( src, i, 0, 1 );
		}
		
		REP( i, N ) {
			scanf( "%d", &R[i] );
			add_edge( i + N, snk, 0, 1 );
		}
		
		REP( i, N )
		REP( j, N )
			add_edge( i, j + N, abs( i - j ) + abs( L[i] - R[j] ), oo );
		
		ans = 0;
		while ( augment( src, snk ) );
		
		printf( "%d\n", ans );
	}

	return 0;
}
