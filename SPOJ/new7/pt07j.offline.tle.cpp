/*
Alfonso2 Peterssen (mukel)
13 - 2 - 2009
SPOJ #1487 "Query on a tree III"
Offline algorithm using Treaps
O( n lg^2 n + q lg n )
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

extern int __stklen = 1 << 24; // 16 MB stack

const int
	MAXV = 100000,
	MAXNODES = 2 * MAXV,
	MAXQ = 10000;

int V, E, Q;
int label[MAXV];
bool mark[MAXV];
int ans[MAXQ];

int first[MAXV];
struct edge {
	int v, next;
} edges[2 * MAXV];

vector< pair< int, int > > qs[MAXV];

int tree[MAXV];
struct node {
	int val, size, prior, child[2];
	node() {}
	node( int val ) : val( val ), size( 1 ), prior( rand() * rand() + rand() ) {
		child[0] = 0;
		child[1] = 0;
	}
} buff[MAXNODES];

int F;
int free_nodes[MAXNODES];

inline int new_node() {
	return free_nodes[--F];
}

inline int delete_node( int idx ) {
	free_nodes[F++] = idx;
}

inline void update_size( int& root ) {
	buff[root].size =
	      buff[ buff[root].child[0] ].size +
	      buff[ buff[root].child[1] ].size +
	      1;
}

inline void rotate( int& root, int dir ) {

	int tmp = buff[root].child[dir];
	buff[root].child[dir] = buff[tmp].child[1 - dir];
	buff[tmp].child[1 - dir] = root;
	
	update_size( root );
	update_size( tmp );
	
	root = tmp;
}

void insert( int& root, int val ) {
	if ( root == 0 ) {
		buff[root = new_node()] = node( val );
		return ;
	}
	
	bool dir = !( label[val] < label[ buff[root].val ] );
	insert( buff[root].child[dir], val );
	if ( buff[root].prior < buff[root].child[dir] )
	      rotate( root, dir);
	      
	update_size( root );
}

int findKth( int root, int kth ) {
	for (;;) {
		int leftsz = buff[ buff[root].child[0] ].size;
		if ( kth >= leftsz ) {
			kth -= leftsz + 1;
			if ( kth < 0 )
			      return buff[root].val;
			      
			root = buff[root].child[1];
		} else
			root = buff[root].child[0];
	}
}

void meld( int& to, int from ) {
	if ( from == 0 ) return ;
	insert( to, buff[from].val );
	meld( to, buff[from].child[0] );
	meld( to, buff[from].child[1] );
	delete_node( from );
}

void merge( int& root1, int& root2 ) {
	if ( buff[root2].size > buff[root1].size )
		swap( root1, root2 );
	meld( root1, root2 );
}

void dfs( int u ) {

	mark[u] = true;
	for ( int e = first[u]; e != -1; e = edges[e].next ) {
		int v = edges[e].v;
		if ( mark[v] )
			continue;
		dfs( v );
		merge( tree[u], tree[v] );
	}
	
	insert( tree[u], u );
	
	REP( i, qs[u].size() )
		ans[ qs[u][i].first ] = findKth( tree[u], qs[u][i].second );
}

int main() {

	scanf( "%d", &V );
	
	fill( first, first + V, -1 );
	
	REP( i, V )
	      scanf( "%d", &label[i] );
	      
	REP( i, V - 1 ) {
		int u, v;
		scanf( "%d %d", &u, &v );
		u--; v--;
		edges[E] = (edge){ v, first[u] };
		first[u] = E++;
		edges[E] = (edge){ u, first[v] };
		first[v] = E++;
	}
	      
	scanf( "%d", &Q );
	REP( i, Q ) {
		int nod, kth;
		scanf( "%d %d", &nod, &kth );
		nod--; kth--;
		qs[nod].push_back( make_pair( i, kth ) );
	}
	
	for ( int i = 1; i < MAXNODES; i++ )
		free_nodes[F++] = i;
	
	dfs( 0 );
	
	REP( i, Q )
		printf( "%d\n", ans[i] + 1 );

	return 0;
}
