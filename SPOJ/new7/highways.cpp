/*
Alfonso2 Peterssen (mukel)
25 - 1 - 2009
SPOJ #3381 "Highways"
*/
#include <cstdio>
#include <iostream>

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
	MAXV = 100000,
	MAXE = 200000,
	oo = (int)1e9;

int T, V, L, E;
int src, dst;
int first[MAXV];
int best[MAXV];
struct edge {
	int v, w, next;
} edges[MAXE];

/* Fast IO */
int next_int() {
//	int x; scanf( "%d", &x ); return x;
	register int res = 0;
	register char ch;
	while ( ( ch = getc_unlocked( stdin ) ) < '0' );
	do {
		res *= 10;
		res += ( ch - '0' );
	} while ( ( ch = getc_unlocked( stdin ) ) >= '0' );
	return res;

}

void dijkstra( int src, int dst ) {
	set< pair< int, int > > S;
	fill( best, best + V, oo );
	best[src] = 0;
	S.insert( make_pair( best[src], src ) );
	while ( !S.empty() ) {
		int u = (*S.begin()).second;
		if ( u == dst ) return ;
		S.erase( S.begin() );
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
}

int main() {

	T = next_int();
	while ( T-- ) {
		V = next_int();
		L = next_int();
		
		src = next_int();
		dst = next_int();
		src--; dst--;
		
		E = 0;
		REP( i, V ) first[i] = -1;
		
		REP( i, L ) {
			int u, v, w;
			u = next_int();
			v = next_int();
			w = next_int();
			u--; v--;
			edges[E] = (edge){ v, w, first[u] };
			first[u] = E++;
			edges[E] = (edge){ u, w, first[v] };
			first[v] = E++;
		}
		
		dijkstra( src, dst );
		if ( best[dst] == oo )
		      printf( "NONE\n" );
		else
		      printf( "%d\n", best[dst] );
	}

	return 0;
}
