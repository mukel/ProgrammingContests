/*
Alfonso2 Peterssen
SPOJ #2735 "Simplify the Railroad System"
8 - 10 - 2008 Che :-(
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

const int
	MAXV = 2000,
	MAXE = 4000,
	oo = (int)1e9;

int T, V, E;
int deg[MAXV];
struct edge {
	int u, v, w, next;
	bool operator < ( const edge& e ) const {
		if ( u != e.u ) return u < e.u;
		if ( v != e.v ) return v < e.v;
		return w < e.w;
	}
};
set< edge > S, sol;
typedef set< edge >::iterator sit;

void remove( set< edge >& S, edge e ) {
	if ( S.find( e ) != S.end() )
	      S.erase( S.find( e ) );
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		E = 0;
		S.clear();
		sol.clear();
		memset( deg, 0, sizeof( deg ) );

		scanf( "%d %d", &V, &E );
		REP( i, E ) {
			int u, v, w;
			scanf( "%d %d %d", &u, &v, &w );
			u--; v--;
			deg[u]++;
			deg[v]++;
			S.insert( (edge){ u, v, w } );
			S.insert( (edge){ v, u, w } );
		}
		
		REP( i, V )
		      if ( deg[i] == 2 ) {
				sit itu = S.upper_bound( (edge){ i - 1, oo, oo } );
				sit itv = itu; itv++;
				int u = (*itu).v;
				int v = (*itv).v;
				int w = (*itu).w + (*itv).w;
				remove( S, (edge){ i, u, (*itu).w } );
				remove( S, (edge){ u, i, (*itu).w } );
				remove( S, (edge){ i, v, (*itv).w } );
				remove( S, (edge){ v, i, (*itv).w } );
				S.insert( (edge){ u, v, w } );
				S.insert( (edge){ v, u, w } );
			}
			
		for ( sit it = S.begin(); it != S.end(); it++ ) {
			int u = (*it).u;
			int v = (*it).v;
			int w = (*it).w;
			edge e1 = (edge){ u, v, w };
			edge e2 = (edge){ v, u, w };
			if (
				sol.find( e1 ) == sol.end() &&
				sol.find( e2 ) == sol.end() )
				sol.insert( (edge){ min( u, v ), max( u, v ), w } );
		}
			
		printf( "%d\n", sol.size() );
		for ( sit it = sol.begin(); it != sol.end(); it++ ) {
			int u = (*it).u + 1;
			int v = (*it).v + 1;
			int w = (*it).w;
			printf( "%d %d %d\n", u, v, w );
		}
	}

	return 0;
}
