/*
Alfonso2 Peterssen
SPOJ #2728 "Breaking in"
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
#include <bitset>

#include <cmath>
#include <complex>

#include <cstring>
#include <cstdlib>

using namespace std;
using namespace __gnu_cxx;

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
	MAXV = 9000,
	MAXE = 60000;

int T, V, E, L;
int src;
int imp[MAXV];
int idx[MAXV];
int head[MAXV];
bool memo[MAXV];
bitset< MAXV > used[MAXV];
struct edge {
	int v, next;
} edges[MAXE];

void dfs( int u ) {
	used[src][u] = true;
	for ( int e = head[u]; e != -1; e = edges[e].next ) {
		int v = edges[e].v;
		if ( memo[v] )
		      used[src] |= used[v];
		else
			if ( !used[src][v] )
				dfs( v );
	}
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		E = 0;
		memset( head, -1, sizeof( head ) );

		scanf( "%d %d", &V, &L );
		REP( i, L ) {
			int u, v;
			scanf( "%d %d", &v, &u );
			u--; v--;
			edges[E] = (edge){ v, head[u] };
			head[u] = E++;
		}
		
		REP( i, V ) {
			idx[i] = i;
			used[i].reset();
			memo[i] = false;
		}
		
		random_shuffle( idx, idx + V );
		
		REP( i, V ) {
			src = idx[i];
			dfs( src );
		      memo[src] = true;
			imp[src] = used[src].count();
		}
		
		int best = *max_element( imp, imp + V );
		
		REP( i, V )
		      if ( imp[i] == best )
		            printf( "%d ", i + 1 );
		            
		printf( "\n" );
	}

	return 0;
}
