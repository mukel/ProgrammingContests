/*
Alfonso2 Peterssen
SPOJ #59 "Bytelandian Information Agency"
19 - 9 - 2008
Lengauer-Tarjan O( E lg V )
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int
	MAXV = 5000,
	MAXE = 200000;

int T, V, E;
int discover_time;
int cant;
int sol[MAXV];
int order[MAXV];
int dfsnum[MAXV];
int parent[MAXV];
int father[MAXV];
int best[MAXV];
int dom[MAXV]; // dominators
int sdom[MAXV]; // semidominators
struct graph {
	int E;
	int head[MAXV];
	struct edge {
		int v, next;
	} edges[MAXE];
	void reset() { E = 0; memset( head, -1, sizeof( head ) ); }
	void insert( int u, int v ) {
		edges[E++] = (edge){ v, head[u] }; head[u] = E - 1;
	}
} succ, pred, B;

void dfs( int u ) {
	order[discover_time] = u;
	dfsnum[u] = discover_time++;
	for ( int e = succ.head[u]; e != -1; e = succ.edges[e].next ) {
		int v = succ.edges[e].v;
		if ( dfsnum[v] == -1 ) {
			parent[v] = u;
		      dfs( v );
		}
	}
}

int FIND( int u ) {
	if ( father[u] != u ) {
		int v = father[u];
		father[u] = FIND( v );
		if ( dfsnum[ best[v] ] < dfsnum[ best[u] ] )
			best[u] = best[v];
	}
	return father[u];
}

int main() {

	for ( T = 10; T--; ) {

		succ.reset();
		pred.reset();
		B.reset();
		discover_time = 0;
		memset( dfsnum, -1, sizeof( dfsnum ) );

		scanf( "%d %d", &V, &E );
		REP( i, E ) {
			int u, v;
			scanf( "%d %d", &u, &v );
			u--; v--;
			succ.insert( u, v );
			pred.insert( v, u );
		}
		
		parent[0] = -1;
		REP( i, V ) {
			father[i] = i;
			best[i] = sdom[i] = i;
		}
		
		dfs( 0 );
		
		REPD( i, V ) {
			int u = order[i];

			for ( int e = B.head[u]; e != -1; e = B.edges[e].next ) {
				int v = B.edges[e].v;
				FIND( v );
				int k = best[v];
				if ( dfsnum[k] < dfsnum[ sdom[v] ] )
				      dom[v] = k;
				else
				      dom[v] = u;
			}

			for ( int e = pred.head[u]; e != -1; e = pred.edges[e].next ) {
				int v = pred.edges[e].v;
				FIND( v );
				int k = best[v];
				if ( dfsnum[k] < dfsnum[ sdom[u] ] )
					sdom[u] = k;
			}
			
			B.insert( sdom[u], u );
			best[u] = sdom[u];
			
			// UNION( u, parent[u] )
			father[u] = parent[u];
		}

		cant = 0;
		REP( i, V ) {
			int u = order[i];
			if ( dom[u] != sdom[u] )
			      dom[u] = dom[ dom[u] ];
			if ( dom[u] != u )
			      sol[cant++] = dom[u];
		}
		
		sort( sol, sol + cant );
		cant = unique( sol, sol + cant ) - sol;
		
		printf( "%d\n", cant );
		REP( i, cant )
			printf( i < cant - 1 ? "%d " : "%d", sol[i] + 1 );
		printf( "\n" );
	}

	return 0;
}
