/*
Alfonso2 Peterssen
SPOJ #112 "Horizontally Visible Segments"
17 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <bitset>
#include <set>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef pair< int, int > par;

const int
	MAXN = 8000,
	MAXE = 100000;

int T, N, E;
int last_nod;
int tree[4 * 2 * MAXN];
int degree[MAXN];
int mark[MAXN];
int head[MAXN];
int ls[MAXN];
struct edge {
	int v, next;
} edges[MAXE];
struct triple {
	int a, b, c;
	triple() {}
	triple( int _a, int _b, int _c ) : a( _a ), b( _b ), c( _c ) {
		if ( b < a ) swap( a, b );
		if ( c < a ) swap( a, c );
		if ( c < b ) swap( b, c );
		assert( a < b && b < c );
	}
	bool operator < ( const triple& t ) const {
		if ( a != t.a ) return a < t.a;
		if ( b != t.b ) return b < t.b;
		return c < t.c;
	}
	bool operator == ( const triple& t ) const {
		return ( a == t.a && b == t.b && c == t.c );
	}
} sol[MAXE];

struct segment {
	int x, lo, hi;
	bool operator < ( const segment &s ) const { return x < s.x; }
} S[MAXN];

bitset< MAXN > adj[MAXN];
set< par > H;

void add_edge( int u, int v ) {
	degree[u]++;
	degree[v]++;
	adj[u][v] = true;
	adj[v][u] = true;
	edges[E++] = (edge){ v, head[u] }; head[u] = E - 1;
	edges[E++] = (edge){ u, head[v] }; head[v] = E - 1;
}

void update( int x, int lo, int hi, int start, int end, int value ) {
	if ( lo > hi || lo > end || hi < start )
	      return ;

	if ( lo >= start && hi <= end ) {
		tree[x] = value;
		return ;
	}
	
	int mid = ( lo + hi ) / 2;
	if ( tree[x] != -1 ) {
		update( 2 * x + 1, lo, mid, lo, mid, tree[x] );
		update( 2 * x + 2, mid + 1, hi, mid + 1, hi, tree[x] );
		tree[x] = -1;
	}
	
	update( 2 * x + 1, lo, mid, start, end, value );
	update( 2 * x + 2, mid + 1, hi, start, end, value );
}

void query( int x, int lo, int hi, int start, int end, int u ) {
	if ( lo > hi || lo > end || hi < start )
	      return ;

	if ( tree[x] != -1 ) {
		int v = tree[x];
		if ( v != -2 && last_nod != v ) { // nothing
		      add_edge( u, v );
		      last_nod = v;
		}
		return ;
	}
	
	int mid = ( lo + hi ) / 2;
	query( 2 * x + 1, lo, mid, start, end, u );
	query( 2 * x + 2, mid + 1, hi, start, end, u );
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		E = 0;
		memset( tree, -1, sizeof( tree ) );
		memset( head, -1, sizeof( head ) );
		memset( degree, 0, sizeof( degree ) );
		memset( mark, 0, sizeof( mark ) );

		scanf( "%d", &N );
		REP( i, N ) {
			adj[i].reset();
			scanf( "%d %d %d", &S[i].lo, &S[i].hi, &S[i].x );
			S[i].lo *= 2;
			S[i].hi *= 2;
		}
			
		sort( S, S + N );
		
		update( 0, 0, 2 * MAXN, 0, 2 * MAXN, -2 ); // nothing
		REP( i, N ) {
			last_nod = -1;
			query( 0, 0, 2 * MAXN, S[i].lo, S[i].hi, i );
			update( 0, 0, 2 * MAXN, S[i].lo, S[i].hi, i );
		}
		
		REP( i, N )
			H.insert( make_pair( degree[i], i ) );
			
		int cant = 0;
		while ( !H.empty() ) {
			int u = (*H.begin()).second;
			H.erase( H.begin() );
			
			int last = -1, sz = 0;
			for ( int e = head[u]; e != -1; last = e, e = edges[e].next ) {
				int v = edges[e].v;
				if ( degree[v] == -1 ) { // remove edge
				      if ( last == -1 )
						head[u] = edges[e].next;
				      else
				            edges[last].next = edges[e].next;
				} else
					ls[sz++] = v;
			}
			
			degree[u] = -1;
			REP( i, sz ) {
				int x = ls[i];
				H.erase( make_pair( degree[x], x ) );
				degree[x]--;
				if ( degree[x] > 1 )
					H.insert( make_pair( degree[x], x ) );
				REP( j, i ) {
					int y = ls[j];
					if ( x != y && adj[x][y] )
					      sol[cant++] = triple( u, x, y );
				}
			}
		}
		
		sort( sol, sol + cant );
		cant = unique( sol, sol + cant ) - sol;

		printf( "%d\n", cant );
	}
	
	return 0;
}
