/*
Alfonso2 Peterssen (mukel)
SPOJ #4457 "Shopping II"
4 - 6 - 2009
*/
#include <cstdio>
#include <iostream>
#include <sstream>

#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <bitset>

#include <complex>
#include <cmath>

#include <cstdlib>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, lo, hi ) for ( int i = (lo); i <= (hi); i++ )
#define FORD( i, hi, lo ) for ( int i = (hi); i >= (lo); i-- )

#define ITER(c) typeof( (c).begin() )
#define FORALL( it, c ) for ( ITER(c) it = (c).begin(); it != (c).end(); it++ )
#define FORRANGE( it, lo, hi ) for ( typeof(lo) it = (lo); it != (hi); it++ )
	
#define ALL( c ) (c).begin(), (c).end()

typedef long long int64;

const int
	MAXV = 5000,
	oo = (int)1e9;

int T, N, M, V, E;
int sum, ans;
int src, snk;
int flow[MAXV];
int from[MAXV];
int first[MAXV];
struct edge {
	int u, v, cap, next;
} edges[1 << 19];
int nc[MAXV];
int mc[MAXV];

void add_edge( int u, int v, int cap ) {
	edges[E] = (edge){ u, v, cap, first[u] };
	first[u] = E++;
	edges[E] = (edge){ v, u, 0, first[v] };
	first[v] = E++;
}

void reflow() {
      for ( int e = from[snk]; e != -1; e = from[ edges[e].u ] ) {
		edges[e].cap -= flow[snk];
 		edges[e^1].cap += flow[snk];
	}
	ans += flow[snk];
}

bool augment( int src, int snk) {

	queue< int > Q;
	fill( flow, flow + V, 0 );
	flow[src] = oo;
	from[src] = -1;
	
	for ( Q.push( src ); !Q.empty(); Q.pop() ) {
		int u = Q.front();
		for ( int e = first[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			if ( !edges[e].cap ) continue ;
			if ( flow[v] ) continue ;
			flow[v] = min( edges[e].cap, flow[u] );
			from[v] = e;
			Q.push( v );
		}
		
		if ( flow[snk] ) break ;
	}
	
	if ( !flow[snk] ) return 0;

	
	reflow();
	
	return 1;
}


int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d %d", &N, &M );
		
		src = N + M;
		snk = N + M + 1;
		
		V = N + M + 2;
		
		ans = 0, sum = 0;
		E = 0;
		fill( first, first + V, -1 );
		
		REP( i, N ) {
			scanf( "%d", &nc[i] );
			add_edge( src, i, nc[i] );
			sum += nc[i];
		}
		
		REP( i, M ) {
			scanf( "%d", &mc[i] );
			add_edge( i + N, snk, mc[i] );
		}
		
		REP( i, M ) {
			int cant;
			scanf( "%d", &cant );
			while ( cant-- ) {
				int u;
				scanf( "%d", &u );
				u--;
				add_edge( u, N + i, oo );

				flow[snk] = min( mc[i], nc[u] );
				if ( flow[snk] ) {
					nc[u] -= flow[snk];
					mc[i] -= flow[snk];
					
					from[snk] = N * 2 + (i*2);
    					from[N + i] = E - 2;
					from[u] = 2 * (u);
					from[src] = -1;
					reflow();
				}
			}
		}
		
		while ( augment( src, snk ) );
		
		printf( "%d\n", sum - ans );
	}


	return 0;
}
