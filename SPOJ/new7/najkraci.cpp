/*
Alfonso2 Peterssen (mukel)
16 - 1 - 2009
COCI 2009 Contest 3 NAJKRACI
*/
#include <cstdio>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

typedef long long int64;

const int
	MAXV = 1500,
	MAXE = 5000,
	MODULO = 1000000007,
	oo = 1e9;

int V, E;
int best[MAXV];
int first[MAXV];
int order[MAXV];
int64 ans[MAXE];
int64 waysL[MAXV], waysR[MAXV];
struct edge {
	int u, v, w, next;
} edges[MAXE];

set< pair< int, int > > S;

void process( int src ) {

	int cant = 0;
	fill( best, best + V, oo );
	best[src] = 0;
	S.insert( make_pair( best[src], src ) );

	while ( !S.empty() ) {
		int u = (*S.begin()).second;
		S.erase( S.begin() );
		order[cant++] = u; // topsort
		for ( int e = first[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			int w = edges[e].w;
			if ( best[u] + w < best[v] ) {
				if ( best[v] != oo )
					S.erase( make_pair( best[v], v ) );
				best[v] = best[u] + w;
				S.insert( make_pair( best[v], v ) );
			}
		}
	}

	fill( waysL, waysL + V, 0 );
	waysL[src] = 1;
	REP( i, cant ) {
		int u = order[i];
		for ( int e = first[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			int w = edges[e].w;
			if ( best[u] + w == best[v] )
			      waysL[v] = ( waysL[v] + waysL[u] ) % MODULO;
		}
	}

	fill( waysR, waysR + V, 0 );
	REPD( i, cant ) {
		int u = order[i];
		for ( int e = first[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			int w = edges[e].w;
			if ( best[u] + w == best[v] )
			      waysR[u] = ( waysR[u] + waysR[v] ) % MODULO;
		}
		waysR[u]++;
	}

	REP( i, E ) {
		int u = edges[i].u;
		int v = edges[i].v;
		int w = edges[i].w;
		if ( best[u] + w == best[v] )
			ans[i] = ( ans[i] + waysL[u] * waysR[v] ) % MODULO;
	}
}

int main() {

	memset( first, -1, sizeof( first ) );

	scanf( "%d %d", &V, &E );
	REP( i, E ) {
		int u, v, w;
		scanf( "%d %d %d", &u, &v, &w );
		u--; v--;
		edges[i] = (edge){ u, v, w, first[u] };
		first[u] = i;
	}

	REP( i, V )
		process( i );

	REP( i, E )
	      printf( "%I64d\n", ans[i] );

	return 0;
}
