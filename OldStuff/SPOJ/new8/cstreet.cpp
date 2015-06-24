/*
Alfonso2 Peterssen (mukel)
SPOJ #368 "Cobbled streets"
24 - 3 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXV = 1000,
	MAXE = 300000;

int T, coef, V, E;
int data[MAXV];
struct edge {
	int u, v, w;
	bool operator < ( const edge& e ) const {
		return w < e.w;
	}
} edges[MAXE];

int FIND( int u ) {
	return data[u] < 0 ? u : data[u] = FIND( data[u] );
}

void JOIN( int u, int v ) {
	u = FIND( u );
	v = FIND( v );
	if ( u == v ) return ;
	if ( -data[u] < -data[v] ) swap( u, v );
	data[u] += data[v];
	data[v] = u;
}

int main() {

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d %d %d", &coef, &V, &E );
		REP( i, E ) {
			int u, v, w;
			scanf( "%d %d %d", &u, &v, &w );
			u--; v--;
			edges[i] = (edge){ u, v, w };
		}
		
		fill( data, data + V, -1 );
		sort( edges, edges + E );
		
		int ans = 0;
		REP( i, E ) {
			int u = edges[i].u;
			int v = edges[i].v;
			int w = edges[i].w;
			if ( FIND(u) != FIND(v) ) {
				JOIN( u, v );
				ans += w;
			}
		}
		
		printf( "%d\n", ans * coef );
	}

	return 0;
}
