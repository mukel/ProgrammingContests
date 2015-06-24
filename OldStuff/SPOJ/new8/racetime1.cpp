/*
Alfonso2 Peterssen (mukel)
Augmented Fenwick Tree + Treaps
O( lg^2 N ) update && query but fast due to Fenwick Tree structure
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXLG = 18,
	MAXN = 1 << MAXLG;

int N, Q;
int cant;
int buff[5 * MAXLG * MAXN];

int vals[MAXN];
int tree[MAXN];

struct node {
	int key, cant, size, prior, child[2];
	node() {}
	node( int key ) : key( key ), cant( 1 ), size( 1 ), prior( rand() * rand() + rand() ) {
		child[0] = child[1] = 0;
	}
} T[MAXLG * MAXN];

void update_size( int x ) {
	T[x].size =
		T[ T[x].child[0] ].size +
		T[ T[x].child[1] ].size +
		T[x].cant;
}

void rotate( int& root, int dir ) {
	int tmp = T[root].child[dir];
	T[root].child[dir] = T[tmp].child[1 - dir];
	T[tmp].child[1 - dir] = root;
	
	update_size( root );
	update_size( tmp );
	
	root = tmp;
}

int newNode() {
	return buff[--cant];
}

void freeNode( int &root ) {
	buff[cant++] = root;
	root = 0;
}

void insert( int& root, int val ) {
	if ( !root ) {
		T[root = newNode()] = node( val );
		return ;
	}
	if ( val == T[root].key) {
		T[root].cant++;
	} else {
		bool dir = !(val < T[root].key);
		insert( T[root].child[dir], val );
		if ( T[root].prior < T[ T[root].child[dir] ].prior )
		      rotate( root, dir );
	}
	
	update_size( root );
}

void erase( int& root, int val ) {
	if ( !root ) return ;
	
	if ( val == T[root].key ) {
		if ( T[root].cant > 1 )
		      T[root].cant--;
		else {
			int L = T[root].child[0];
			int R = T[root].child[1];
			bool dir;
			if ( L && R ) dir = (T[L].prior < T[R].prior);
			else if ( L ) dir = 0;
			else if ( R ) dir = 1;
			else { freeNode( root ); return ; }
			rotate( root, dir );
			erase( T[root].child[1 - dir], val );
		}
	} else {
		bool dir = !(val < T[root].key);
		erase( T[root].child[dir], val );
	}
	
	update_size( root );
}

// iterative count less or equal to val
int countLessEqThan( int root, int val ) {
	int ans = 0;
	while ( root ) {
		bool dir = !(val < T[root].key);
		if ( dir )
			ans += T[ T[root].child[0] ].size + T[root].cant;
	      root = T[root].child[dir];
	}
	return ans;
}

inline int lobit( int x ) { return x & -x; }

int query( int x, int val ) {
	int rank = 0;
	for ( ; x >= 0; x -= lobit( x + 1 ) )
	      rank += countLessEqThan( tree[x], val );
	return rank;
}

void add( int x, int val ) {
	for ( ; x < N; x += lobit( x + 1 ) )
		insert( tree[x], val );
}

void modify( int x, int val ) {
	int old_val = vals[x];
	if ( val == old_val ) return ;
	vals[x] = val;
	for ( ; x < N; x += lobit( x + 1 ) ) {
		erase( tree[x], old_val );
		insert( tree[x], val );
	}
}

int main() {

	srand( time(0) );

	scanf( "%d %d", &N, &Q );
	
	// skip 0 -> null node
	cant = N * MAXLG;
	REP( i, cant )
		buff[i] = i + 1;
	
	REP( i, N ) {
            scanf( "%d", &vals[i] );
		add( i, vals[i] );
	}
	
	while ( Q-- ) {
		char op[5];
		scanf( "%s", &op );
		if ( op[0] == 'M' ) { // modify
			int x, val;
			scanf( "%d %d", &x, &val );
			x--;
			modify( x, val );
		}
		if ( op[0] == 'C' ) { // count
			int lo, hi, val;
			scanf( "%d %d %d", &lo, &hi, &val );
			lo--; hi--;
			printf( "%d\n", query( hi, val ) - query( lo - 1, val ) );
		}
	}

	return 0;
}
