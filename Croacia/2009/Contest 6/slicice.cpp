/*
Alfonso2 Peterssen (mukel)
*/
#include <cstdio>
#include <iostream>
#include <cassert>

#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>

#include <cmath>
#include <complex>

#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long int64;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) for ( int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) for ( int i = (e); i >= (s); i-- )

#define FOREACH( it, c ) \
	for ( typeof( (c).begin() ) it = (c).begin(); it != (c).end(); it++ )

#define ALL( c ) (c).begin(), (c).end()

const int
	MAXN = 100,
	MAXL = 2000,
	MAXV = MAXN + MAXL + 2,
	MAXE = 100000;
	
int N, L, V, E;
int first[MAXV];
struct edge {
	int u, v, flow, cap, next;
} edges[MAXE];

int val[MAXN];

int flow[MAXV];
int from[MAXV];

pair< int, int > ed[MAXL];

int src, snk;

struct pur { int u, v, w; };
vector< pur > ans;

void add_edge( int u, int v, int cap ) {
	edges[E] = (edge){ u, v, 0, cap, first[u] };
	first[u] = E++;
	edges[E] = (edge){ v, u, cap, cap, first[v] };
	first[v] = E++;
}

bool augment( int src, int snk ) {

	fill( flow, flow + V, 0 );
	flow[src] = (int)1e9;
	from[src] = -1;
	
	queue< int > Q;
	for ( Q.push( src ); !Q.empty() && !flow[snk]; Q.pop() ) {
		int u = Q.front();
		for ( int e = first[u]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			if ( !flow[v] && edges[e].cap > edges[e].flow ) {
			      flow[v] = min( flow[u], edges[e].cap - edges[e].flow );
			      from[v] = e;
				Q.push( v );
			}
		}
	}

	if ( !flow[snk] )
		return false;
		
	for ( int e = from[snk]; e != -1; e = from[ edges[e].u ] ) {
		edges[e].flow += flow[snk];
		edges[e^1].flow -= flow[snk];
	}
	
	return true;

}

void add_purchase( int u, int v, int w ) {
	ans.push_back( (pur){u+1, v+1, w} );
	val[u]-=w;
	val[v]-=(2 - w);
}

int main() {

	memset( first, -1, sizeof( first ) );

	scanf( "%d %d", &N, &L );
	
	V = N + L + 2;
	
	src = N + L;
	snk = N + L + 1;
	
	REP( i, N ) {
	      scanf( "%d", &val[i] );
	      add_edge( L + i, snk, val[i] );
	}
	
	REP( i, L ) {
		int u, v;
		scanf( "%d %d", &u, &v );
		u--; v--;
		ed[i] = make_pair( u, v );
		add_edge( src, i, 2 );
		add_edge( i, L + u, 2 );
		add_edge( i, L + v, 2 );
	}

	while ( augment( src, snk ) );
	
	REP( i, L ) {
		for ( int e = first[i]; e != -1; e = edges[e].next ) {
			int v = edges[e].v;
			if ( v == src ) continue;
			if ( v == L + ed[i].first ) {
				add_purchase( ed[i].first, ed[i].second, edges[e].flow );
				break;
			}
		}
	}
	
	// be greedy
	REP( i, N ) {
		while ( val[i] >= 2 )
			add_purchase( i, (i + 1) % N, 2 );
	}
	
	REP( i, N ) {
		if ( val[i] == 1 ) {
			for ( int j = i + 1; j < N; j++ )
			      if ( val[j] == 1 ) {
					add_purchase( i, j, 1 );
					break;
				}
		}
		assert( val[i] == 0 );
	}
	
	printf( "%d\n", ans.size() );
	REP( i, ans.size() )
		printf( "%d %d %d\n", ans[i].u, ans[i].v, ans[i].w );

	return 0;
}
