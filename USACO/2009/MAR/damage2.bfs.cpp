/*
Alfonso2 Peterssen (mukel)
USACO MAR09 "damage2"
*/
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXV = 6000,
	MAXE = 100000;

int V, L, E, D;
int ans;
bool sink[MAXV];
int from[MAXV];
int first[MAXV];
struct edge {
	int u, v, cap, next;
} edges[MAXE];

void add_edge( int u, int v ) {
	edges[E] = (edge){ u, v, 1, first[u] };
	first[u] = E++;
	edges[E] = (edge){ v, u, 0, first[v] };
	first[v] = E++;
}

void reflow( int snk ) {
	for ( int e = from[snk]; e != -2; e = from[ edges[e].u ] ) {
		edges[e].cap--;
		edges[e^1].cap++;
	}
}

bool augment( int src ) {
	queue< int > Q;
	fill( from, from + 2 * V, -1 );
	from[src] = -2;
	
	for ( Q.push( src ); !Q.empty(); Q.pop() ) {
		int u = Q.front();
		for ( int e = first[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			if ( from[v] == -1 && edges[e].cap ) {
				from[v] = e;
				Q.push( v );
				if ( sink[v] ) {
					reflow( v ); return true;
				}
			}
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

	while ( augment( 1 ) ) ans++;

	printf( "%d\n", ans );

	return 0;
}
