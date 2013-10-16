/*
Alfonso2 Peterssen (mukel)
16 - 2 - 2009
SPOJ #3579 "Disjoint Paths"
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXV = 10000,
	MAXE = 200000,
	oo = (int)1e9;

int T, K, N, V, E;
int src, snk;
bool mark[MAXV];
int from[MAXV];
int first[MAXV];
struct edge {
	int u, v, cap, flow, next;
} edges[MAXE];

void add_edge( int u, int v, int cap ) {
	edges[E] = (edge){ u, v, cap, 0, first[u] };
	first[u] = E++;
	edges[E] = (edge){ v, u, cap, cap, first[v] };
	first[v] = E++;
}

bool augment( int src, int snk ) {

	fill( mark, mark + V, false );
	mark[src] = true;

	queue< int > Q;
	for ( Q.push( src ); !Q.empty() && !mark[snk]; Q.pop() ) {
		int u = Q.front();
		for ( int e = first[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			if ( !mark[v] && edges[e].flow < edges[e].cap ) {
				mark[v] = true;
				from[v] = e;
				Q.push( v );
			}
		}
	}
	
	if ( !mark[snk] )
		return false;
	
	for ( int x = snk; x != src; x = edges[ from[x] ].u ) {

		edges[ from[x] ].flow++;
		edges[ from[x] ^ 1 ].flow--;
	}

	return true;
}

void dfs( int u, int snk ) {
	if ( u == snk )
		return ;
		
	if ( u % 2 )
		printf( "%d ", (u / 2) + 1 );
		
	for ( int e = first[u]; e != -1; e = edges[e].next ) {
		int v = edges[e].v;
		if ( edges[e].flow > 0 && e % 2 == 0 ) {
			edges[e].flow--;
			dfs( v, snk );
			break;
		}
	}
}

int main() {

	while ( ++T ) {
		scanf( "%d %d", &K, &N );
		if ( !K && !N ) break;
		
		src = 2 * 0 + 1;
		snk = 2 * 1;
		V = 2 * N;
		E = 0;
		
		fill( first, first + V, -1 );
		
		REP( i, N ) {
			char ch; int nxt;
			for (;;) {
				scanf( "%d%c", &nxt, &ch );
				nxt--;
				add_edge( 2 * i + 1, 2 * nxt, oo );
				if ( ch == '\n' ) break;
			}
		      add_edge( 2 * i, 2 * i + 1, 1 );
		}
		      
		int paths = 0;
		while ( paths < K && augment( src, snk ) )
			paths++;
		      
		printf( "Case %d:\n", T );
		if ( paths < K )
			printf( "Impossible\n" );
		else {
			REP( i, K ) {
				dfs( src, snk );
				printf( "2\n" );
			}
		}
		
		printf( "\n" );
	}

	return 0;
}
