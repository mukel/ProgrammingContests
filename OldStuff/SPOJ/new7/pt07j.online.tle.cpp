/*
Alfonso2 Peterssen (mukel)
13 - 2 - 2009
SPOJ #1487 "Query on a tree III"
Online algorithm using a Segment Tree
O( n lg n + q lg^3 n )
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

#define ALL( c ) (c).begin(), (c).end()

extern int __stklen = 1 << 24; // 16 MB stack

const int
	MAXV = 100000;

int V, E, Q;
int label[MAXV];
int node[MAXV];
bool mark[MAXV];
int lower[MAXV];
int upper[MAXV];

int first[MAXV];
struct edge {
	int v, next;
} edges[2 * MAXV];

int dtime;
int start[MAXV];
int end[MAXV];
int val[MAXV];
vector< int > T[4 * MAXV];

void dfs( int u ) {

	mark[u] = true;
	
	val[dtime] = label[u];
	start[u] = dtime++;
	
	lower[u] = upper[u] = label[u];
	
	for ( int e = first[u]; e != -1; e = edges[e].next ) {
		int v = edges[e].v;
		if ( mark[v] )
			continue;
		dfs( v );
		lower[u] = min( lower[u], lower[v] );
		upper[u] = max( upper[u], upper[v] );
	}
	
	end[u] = dtime - 1;
}

void build( int x, int lo, int hi ) {

	if ( lo > hi ) return ;
	
	if ( lo == hi ) {
		T[x].push_back( val[lo] );
		return ;
	}
	
	int mid = ( lo + hi ) / 2;
	build( 2 * x + 1, lo, mid );
	build( 2 * x + 2, mid + 1, hi );
	
	T[x].resize( T[2 * x + 1].size() + T[2 * x + 2].size() );
	merge( ALL( T[2 * x + 1] ), ALL( T[2 * x + 2] ), T[x].begin() );
}

int query( int x, int lo, int hi, int start, int end, int val ) {

	if ( lo > end || hi < start || lo > hi )
	      return 0;
	      
	if ( lo >= start && hi <= end )
		return lower_bound( ALL( T[x] ), val ) - T[x].begin();
		
	int mid = ( lo + hi ) / 2;
	return
		query( 2 * x + 1, lo, mid, start, end, val ) +
		query( 2 * x + 2, mid + 1, hi, start, end, val );
}

int main() {

	scanf( "%d", &V );
	
	fill( first, first + V, -1 );
	
	REP( i, V ) {
	      scanf( "%d", &label[i] );
	      node[i] = label[i];
	}
	
	sort( node, node + V );
	REP( i, V )
		label[i] = lower_bound( node, node + V, label[i] ) - node;
		
	REP( i, V )
	      node[ label[i] ] = i;
	      
	REP( i, V - 1 ) {
		int u, v;
		scanf( "%d %d", &u, &v );
		u--; v--;
		edges[E] = (edge){ v, first[u] };
		first[u] = E++;
		edges[E] = (edge){ u, first[v] };
		first[v] = E++;
	}
	
	dfs( 0 );
	
	build( 0, 0, V - 1 );
	      
	scanf( "%d", &Q );
	REP( i, Q ) {
		int nod, kth;
		scanf( "%d %d", &nod, &kth );
		nod--; kth--;
		
		int lo = lower[nod];
		int hi = upper[nod];
		while ( lo <= hi ) {
			int mid = ( lo + hi ) / 2;
			if ( query( 0, 0, V - 1, start[nod], end[nod], mid ) <= kth )
			      lo = mid + 1;
			else
			      hi = mid - 1;
		}
		
		lo--;
		printf( "%d\n", node[lo] + 1 );
	}
	
	return 0;
}
