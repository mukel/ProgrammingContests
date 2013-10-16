/*
Alfonso2 Peterssen (mukel)
13 - 2 - 2009
SPOJ #1487 "Query on a tree III"
Online algorithm using a Segment Tree + Optimizations
O( n lg n + q lg^3 n )
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )


extern int __stklen = 1 << 24; // 16 MB stack

const int
	MAXV = 100000,
	MAXLGV = 18;

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

int cant;
int from[4 * MAXV];
int to[4 * MAXV];
int buff[MAXV * MAXLGV];

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
		from[x] = cant;
		buff[cant++] = val[lo];
		to[x] = cant;
		return ;
	}
	
	int mid = ( lo + hi ) / 2;
	build( 2 * x + 1, lo, mid );
	build( 2 * x + 2, mid + 1, hi );
	
	from[x] = cant;
	cant += ( hi - lo + 1 );
	to[x] = cant;
	
	merge(buff + from[2 * x + 1], buff + to[2 * x + 1],
		buff + from[2 * x + 2], buff + to[2 * x + 2],
		buff + from[x] );
}

int query( int x, int lo, int hi, int start, int end, int val ) {

	if ( lo > end || hi < start || lo > hi )
	      return 0;
	      
	if ( lo >= start && hi <= end )
		return lower_bound( buff + from[x], buff + to[x], val ) - (buff + from[x]);
		
	int mid = ( lo + hi ) / 2;
	return
		query( 2 * x + 1, lo, mid, start, end, val ) +
		query( 2 * x + 2, mid + 1, hi, start, end, val );
}

/* Fast IO */
#define FAST_IO 1
//#define getc_unlocked( kk ) getchar()
inline int next_int() {
	register int res = 0;
	register char ch;
	while ( ( ch = getc_unlocked( stdin ) ) < '0' );
	do {
		res *= 10;
		res += ch - '0';
	} while ( ( ch = getc_unlocked( stdin ) ) >= '0' );
	return res;
}

int main() {

	#ifdef FAST_IO
		V = next_int();
	#else
		scanf( "%d", &V );
	#endif
	
	fill( first, first + V, -1 );
	
	REP( i, V ) {

		#ifdef FAST_IO
			label[i] = next_int();
		#else
		      scanf( "%d", &label[i] );
		#endif
		
	      node[i] = label[i];
	}
	
	sort( node, node + V );
	REP( i, V )
		label[i] = lower_bound( node, node + V, label[i] ) - node;
		
	REP( i, V )
	      node[ label[i] ] = i;
	      
	REP( i, V - 1 ) {
		int u, v;
		
		#ifdef FAST_IO
			u = next_int();
			v = next_int();
		#else
			scanf( "%d %d", &u, &v );
		#endif

		u--; v--;
		edges[E] = (edge){ v, first[u] };
		first[u] = E++;
		edges[E] = (edge){ u, first[v] };
		first[v] = E++;
	}
	
	dfs( 0 );
	
	build( 0, 0, V - 1 );
	      
	#ifdef FAST_IO
		Q = next_int();
	#else
		scanf( "%d", &Q );
	#endif
	
	REP( i, Q ) {
		int nod, kth;
		
		#ifdef FAST_IO
			nod = next_int();
			kth = next_int();
		#else
			scanf( "%d %d", &nod, &kth );
		#endif

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
