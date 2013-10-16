/*
Alfonso2 Peterssen (mukel)
SPOJ #4350 "Giá tr? l?n nh?t 3"
4 - 6 - 2009
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )

const int
	MAXQ = 1 << 17,
	oo = (int)1e9;

int Q, N;

int root, nodes;
struct node {
	int key, size, prior, best, child[2];
	node() {}
	node( int key ) : key( key ), size( 1 ), prior( rand() * rand() + rand() ), best( key ) {
		child[0] = child[1] = 0;
	}
} T[MAXQ];

void update( int x ) {
	int L = T[x].child[0], R = T[x].child[1];
	T[x].size = T[L].size + T[R].size + 1;
	
	T[x].best = T[x].key;
	if ( L ) T[x].best = max( T[x].best, T[L].best );
	if ( R ) T[x].best = max( T[x].best, T[R].best );
}

void rotate( int& root, int dir ) {
	int tmp = T[root].child[dir];
	T[root].child[dir] = T[tmp].child[1 - dir];
	T[tmp].child[1 - dir] = root;

	update( root );
	update( tmp );

	root = tmp;
}

void insert( int& root, int pos, int val ) {
	if ( !root ) {
		T[root = ++nodes] = node( val );
		return ;
	}
	
	bool dir = !(pos <= T[ T[root].child[0] ].size);
	if ( dir ) pos -= T[ T[root].child[0] ].size + 1;

	insert( T[root].child[dir], pos, val );
	
	if ( T[ T[root].child[dir] ].prior > T[root].prior )
	      rotate( root, dir );

	update( root );
}

int query( int root, int lo, int hi, int start, int end ) {

	if ( !root || lo > end || hi < start || lo > hi )
	      return -oo;

	if ( lo >= start && hi <= end )
	      return T[root].best;

	int ans = -oo;
	int mid = lo + T[ T[root].child[0] ].size;
	if ( mid >= start && mid <= end )
	      ans = T[root].key;

	ans = max( ans,
		max(
		query( T[root].child[0], lo, mid - 1, start, end ),
		query( T[root].child[1], mid + 1, hi, start, end ) )
	);
	
	return ans;
}

void trav( int x ) {
	if ( !x ) return ;
	trav( T[x].child[0] );
	printf( "%d ", T[x].key );
	trav( T[x].child[1] );
}

int main() {

	srand( time(0) );

	scanf( "%d", &Q );
	while ( Q-- ) {
		char op[2]; int u, v;
		scanf( "%s %d %d", &op, &u, &v );
		if ( op[0] == 'A' ) // add
		      insert( root, v - 1, u );
		if ( op[0] == 'Q' ) // query
		      printf( "%d\n", query( root, 1, T[root].size, u, v ) );
		      
		//trav( root ); printf( "\n" );
	}

	return 0;
}
