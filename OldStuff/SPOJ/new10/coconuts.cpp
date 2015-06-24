/*
Alfonso2 Peterssen (mukel)
SPOJ #1693 "Coconuts"
21 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXN = 300;

int N, M;
int V, E;
int pass;
int src, snk;
int mark[MAXN];
int first[MAXN];
struct edge {
	int v, cap, next;
} edges[2 * MAXN * MAXN];

void add_edge( int u, int v, int cap1, int cap2 ) {
	edges[E] = (edge){ v, cap1, first[u] };
	first[u] = E++;
	edges[E] = (edge){ u, cap2, first[v] };
	first[v] = E++;
}

bool augment( int u ) {
	mark[u] = pass;
	if ( u == snk )
	      return 1;
	for ( int e = first[u]; e != -1; e = edges[e].next ) {
		int v = edges[e].v;
		if ( mark[v] != pass && edges[e].cap && augment( v ) ) {
			edges[e].cap--;
			edges[e^1].cap++;
			return 1;
		}
	}
	
	return 0;
}

int main() {

	while (1) {
		scanf( "%d %d", &N, &M );
		if ( !N && !M ) break ;
		
		V = N + 2;
		E = 0;
		src = N;
		snk = N + 1;
		
		fill( first, first + V, -1 );
		
		REP( i, N ) {
			int x;
			scanf( "%d", &x );
			if ( x )
			      add_edge( src, i, 1, 0 );
			else
			      add_edge( i, snk, 1, 0 );
		}
		
		REP( i, M ) {
			int u, v;
			scanf( "%d %d", &u, &v );
			u--; v--;
			add_edge( u, v, 1, 1 );
		}
		
		int ans = 0;
		while (1) {
			pass++;
			if ( !augment( src ) ) break ;
			ans++;
		}
		
		printf( "%d\n", ans );
	}

	return 0;
}
