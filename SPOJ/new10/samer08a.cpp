/*
Alfonso2 Peterssen (mukel)
SPOJ #3405 "Almost Shortest Path"
18 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXV = 500,
	MAXE = 10000,
	oo = (int)1e9;

int V, E;
int distG[MAXV];
int distH[MAXV];
bool mark[MAXE];
struct graph {
	int E;
	int first[MAXV];
	struct edge {
		int u, v, w, next;
	} edges[MAXE];
	
	void reset() { E = 0; memset( first, -1, sizeof( first ) ); }
	graph() { reset(); };
	
	void add_edge( int u, int v, int w ) {
		edges[E] = (edge){ u, v, w, first[u] };
		first[u] = E++;
	}
} G, H;

void dijkstra( graph& G, int src, int dst, int dist[] ) {
	fill( dist, dist + V, oo );
	dist[src] = 0;
	
	set< pair< int, int > > S;
	S.insert( make_pair( dist[src], src ) );
	
	while ( !S.empty() ) {
		int u = (*S.begin()).second;
		S.erase( S.begin() );
 		
 		for ( int e = G.first[u]; e != -1; e = G.edges[e].next ) {
			if ( mark[e] ) continue ;
			int v = G.edges[e].v;
  			int w = G.edges[e].w;
			if ( dist[u] + w < dist[v] ) {
				if ( dist[v] != oo )
					S.erase( make_pair( dist[v], v ) );
				dist[v] = dist[u] + w;
				S.insert( make_pair( dist[v], v ) );
			}
		}
	}
}

int main() {

	while (1) {
		scanf( "%d %d", &V, &E );
		if ( !V && !E ) break ;
		
		G.reset();
		H.reset();
		
		int src, dst;
		scanf( "%d %d", &src, &dst );
		REP( i, E ) {
			int u, v, w;
			scanf( "%d %d %d", &u, &v, &w );
			G.add_edge( u, v, w );
  			H.add_edge( v, u, w );
		}
		
		fill( mark, mark + E, false );

		dijkstra( G, src, dst, distG );
		dijkstra( H, dst, src, distH );
		
		REP( i, E ) {
			int u = G.edges[i].u;
  			int v = G.edges[i].v;
    			int w = G.edges[i].w;
    			if ( distG[u] + w + distH[v] == distG[dst] )
				mark[i] = true;
		}
		
		dijkstra( G, src, dst, distG );
		
		if ( distG[dst] == oo )
		      printf( "-1\n" );
		else
		      printf( "%d\n", distG[dst] );
	}

	return 0;
}
