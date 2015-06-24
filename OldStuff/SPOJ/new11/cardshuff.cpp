/*
Alfonso2 Peterssen (mukel)
SPOJ #4390 "Cards shuffing"
4 - 6 - 2009
very cool
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

#define ITER(c) typeof( (c).begin() )
#define ALL( c ) (c).begin(), (c).end()

const int MAXN = 1 << 18;

int N, Q;
int root, nodes;
struct node {
	int key, size, prior, child[2];
	node() {}
	node( int key ) : key( key ), size( 1 ), prior( rand() * rand() + rand() ) {
		child[0] = child[1] = 0;
	}
} T[MAXN];

vector< int > V, seq;

void update( int x ) {
	T[x].size =
		T[ T[x].child[0] ].size +
		T[ T[x].child[1] ].size +
		1;
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

void erase( int& root, int pos = -1 ) {

	if ( !root ) return ;
	
	int L = T[root].child[0];
	if ( T[L].size == pos || pos == -1 ) {

		int R = T[root].child[1];
		bool dir;

		if ( L && R ) dir = !(T[L].prior > T[R].prior);
		else if ( L ) dir = 0;
		else if ( R ) dir = 1;
		else {
			// kill node
			root = 0;
			return ;
		}

		rotate( root, dir );
		erase( T[root].child[1 - dir] );
	} else {
		bool dir = !(pos <= T[L].size);
		if ( dir ) pos -= T[L].size + 1;
		erase( T[root].child[dir], pos );
	}
	
	update( root );
}

int find( int root, int pos ) {
	if ( T[ T[root].child[0] ].size == pos )
	      return T[root].key;
	      
	bool dir = !(pos <= T[ T[root].child[0] ].size);
	if ( dir ) pos -= T[ T[root].child[0] ].size + 1;
	return find( T[root].child[dir], pos );
}

void trav( int x ) {
	if ( !x ) return ;
	trav( T[x].child[0] );
	seq.push_back( T[x].key );
	trav( T[x].child[1] );
}

int main() {

	srand( time( 0 ) );

	scanf( "%d %d", &N, &Q );
	REP( i, N )
		insert( root, i, i );
	
	// simulate
	while ( Q-- ) {
		int u, v;
		scanf( "%d %d", &u, &v );
		u--; v--;
		if ( u == v )
			continue ;
		
 		int val = find( root, u );
		erase( root, u );
		insert( root, v, val );
	}
	
	// solve
	trav( root );
	
	// just LIS
	REP( i, N ) {
		ITER( V ) it = lower_bound( ALL( V ), seq[i] );
		if ( it == V.end() )
		      V.push_back( seq[i] );
		else
		      *it = seq[i];
	}
	
	int ans = N - V.size();
	
	printf( "%d\n", ans );

	return 0;
}
