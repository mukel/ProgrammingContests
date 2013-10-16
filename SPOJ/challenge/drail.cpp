/*
Alfonso2 Peterssen
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>

#include <cmath>
#include <complex>

#include <cstring>
#include <cstdlib>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) \
	for ( int i = (e); i >= (s); i-- )

#define ALL( c ) (c).begin(), (c).end()

typedef long long int64;

const int MAXV = 20000;

int T, V, E, K, L;
int father[MAXV];
int x[MAXV], y[MAXV];
int sol[MAXV];
struct edge {
	int u, v, w, idx;
	bool operator < ( const edge& e ) const {
		return w < e.w;
	}
} edges[MAXV];

int sqr( int x ) { return x * x; }

int dist( int u, int v ) {
	return sqr( x[u] - x[v] ) + sqr( y[u] - y[v] );
}

int FIND( int x ) {
	if ( father[x] != x ) father[x] = FIND( father[x] );
	return father[x];
}

int main() {

	scanf( "%d", &T );
	REP( tc, T ) {
		scanf( "%d %d", &V, &E );
		scanf( "%d %d", &K, &L );
		
		REP( i, V )
		      scanf( "%d %d", &x[i], &y[i] );
		
		REP( i, E ) {
			int u, v;
			scanf( "%d %d", &u, &v );
			u--; v--;
			edges[i] = (edge){ u, v, dist( u, v ), i };
		}
		
		REP( i, V ) father[i] = i;
		
		sort( edges, edges + E );
		
		int taken = 0;
		REP( i, E ) {
			if ( taken == V - 1 )
			      break;
			int u = edges[i].u;
			int v = edges[i].v;
			if ( FIND( u ) != FIND( v ) ) {
				sol[taken++] = edges[i].idx;
			      father[FIND(u)] = FIND(v);
			}
		}
		
		printf( "case %d Y\n", tc + 1 );
		REP( i, taken )
			printf( "%d\n", sol[i] + 1 );
	}

	return 0;
}
