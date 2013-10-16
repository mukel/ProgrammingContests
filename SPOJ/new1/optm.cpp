/*
Alfonso2 Peterssen
SPOJ #839 "Optimal Marks"
10 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
	
const int
	MAXV = 1000,
	MAXE = 100000,
	oo = (int)1e9;

int T, V, L, E, M;
int src, snk;
int mark[MAXV];
int from[MAXV];
int head[MAXV];
int known[MAXV];
int value[MAXV];
struct edge {
	int u, v, cap, next;
} edges[MAXE];

void add_edge( int u, int v, int cap  ) {
	edges[E++] = (edge){ u, v, cap, head[u] };
	head[u] = E - 1;
	edges[E++] = (edge){ v, u, 0, head[v] };
	head[v] = E - 1;
}

bool augment( int src, int snk ) {

	fill( from, from + V + 2, -1 );
	from[src] = -2;
	
	queue< int > Q;
	for ( Q.push( src ); !Q.empty(); Q.pop() ) {
		int u = Q.front();
		for ( int e = head[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			if ( edges[e].cap && from[v] == -1 ) {
				Q.push( v );
				from[v] = e;
			}
		}
	}
	
	if ( from[snk] == -1 )
	      return false;

	for ( int x = snk; x != src; x = edges[ from[x] ].u ) {
		edges[ from[x] ].cap--;
		edges[ from[x]^1 ].cap++;
	}

	return true;
}

void dfs( int x, int bit ) {
	mark[x] = bit;
	if ( x != src && x != snk )
		value[x] |= ( 1 << bit );
	for ( int e = head[x]; e != -1; e = edges[e].next ) {
		int y = edges[e].v;
		if ( !(e&1) && edges[e].cap && mark[y] != bit )
			dfs( y, bit );
	}
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		
		E = 0;
		memset( head, -1, sizeof( head ) );
		memset( mark, -1, sizeof( mark ) );
		memset( value, 0, sizeof( value ) );
		
		scanf( "%d %d", &V, &L );
		REP( i, L ) {
			int u, v;
			scanf( "%d %d", &u, &v );
			u--; v--;
			add_edge( u, v, 1 );
			add_edge( v, u, 1 );
		}

		int biggest = 0;
		scanf( "%d", &M );
		REP( i, M ) {
			int u, w;
			scanf( "%d %d", &u, &w );
			u--;
			known[i] = u;
			value[u] = w;
			biggest = max( biggest, w );
		}

		src = V;
		snk = V + 1;
		
		for ( int i = 0; biggest >> i; i++ ) {
			      
			REP( j, M ) {
				int x = known[j];
				if ( ( value[x] >> i ) & 1 )
			            add_edge( src, x, oo );
				else
			            add_edge( x, snk, oo );
			}

			while ( augment( src, snk ) );
			dfs( src, i );

			// delete edges
			REP( i, 2 * M ) {
				E--;
				head[ edges[E].u ] = edges[E].next;
			}
			
			// reset capacity
			REP( j, E )
				edges[j].cap = !(j & 1);
		}
		
		REP( i, V )
		      printf( "%d\n", value[i] );
	}

	return 0;
}
