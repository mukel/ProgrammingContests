/*
Alfonso2 Peterssen (mukel)
Task: OTOCI
note that paths maintained here arent heavy, but in practice they are quite fast
This is the biggest code I have ever made.
During contest, I was the only who can fully solve the problem... Sometimes I surprise myself.
*/
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

#define ALL( c ) (c).begin(), (c).end()

#define NDEBUG 0

const int
	MAXLG = 16,
	MAXV = 1 << MAXLG;

int V, Q, E;
struct disjoint_set {
	int data[MAXV];
	disjoint_set() { memset( data, -1, sizeof( data ) ); }
	int FIND( int u ) { return data[u] < 0 ? u : data[u] = FIND( data[u] ); }
	int SIZE( int u ) { return -data[ FIND( u ) ]; }
	void JOIN( int u, int v ) {
		u = FIND( u ); v = FIND( v );
		if ( u == v ) return ;
		if ( SIZE(u) < SIZE(v) )
		      swap( u, v );
		data[u] += data[v];
		data[v] = u;
	}
} S;

int first[MAXV];
struct edge {
	int u, v, next;
} edges[2 * MAXV];

char op[0x100];

int cant;
int mark[MAXV];

int parent[MAXV];
int chain[MAXV];

int level[MAXV];

int total[MAXV];
int top[MAXV];
int bot[MAXV];

int pen[MAXV];

int pos[MAXV];

int size[MAXV];
int best[MAXV];
bool used[MAXV];

int LCA[MAXLG][MAXV];

vector< int > T[MAXV]; // BITs for heavy paths
vector< int > buff;

void clear( int id ) {
	if ( !used[id] ) return ;
	total[id] = 0;
//	printf( "!!!!!clear %d\n", id );
	used[id] = false;
	T[id].clear();
	buff.push_back( id );
}

int getFreePath() {
	assert( !buff.empty() );
	int ans = buff.back();
	buff.pop_back();
	used[ans] = true;
	return ans;
}

// reroot and prepare for HL Decomposition
void dfs( int u ) {
	mark[u] = cant;
	
	clear( chain[u] ); // clear heavy path
	
	size[u] = 1; best[u] = -1;
	
	for ( int e = first[u]; e != -1; e = edges[e].next ) {
		int v = edges[e].v;
		if ( mark[v] == cant ) continue ;
		parent[v] = u;
		dfs( v );
		//size[u] += size[v];
		size[u] = max( size[u], size[v] + 1 );
		if ( best[u] < 0 || size[v] > size[ best[u] ] )
		      best[u] = v;
	}
}

int log2( int x ) {
	x++;
	return 31 - __builtin_clz( x );
}

inline int lobit( int x ) { return x & -x; }

void updateSum( int id, int x, int val ) {
	for ( ; x < T[id].size(); x += lobit( x + 1 ) )
	      T[id][x] += val;
}

int querySum( int id, int x ) {
	int sum = 0;
	for ( ; x >= 0; x -= lobit( x + 1 ) )
	      sum += T[id][x];
	return sum;
}

void insert( int id, int u ) {
	if ( T[id].empty() )
		top[id] = u;

	chain[u] = id;
	total[id] += pen[u];
	
	int x = T[id].size();
	pos[u] = x;
	T[id].push_back( total[id] - querySum( id, x - lobit( x + 1 ) ) );

	//printf( "-->> insertion %d in %d\n", u + 1 , id );
	bot[id] = u;
}

void hl_build( int u, int id ) {
	// add u to T[id] path
	insert( id, u );
	
	// build LCA for u
	level[u] = level[ parent[u] ] + 1;
	int lg = log2( level[u] );
	LCA[0][u] = parent[u];
	for ( int i = 1; i <= lg; i++ )
		LCA[i][u] = LCA[i - 1][ LCA[i - 1][u] ];
	
	mark[u] = cant;
	for ( int e = first[u]; e != -1; e = edges[e].next ) {
		int v = edges[e].v;
		if ( mark[v] == cant ) continue ;
		if ( v != best[u] )
		      hl_build( v, getFreePath() );
	}

	if ( best[u] != -1 )
	      hl_build( best[u], id );
}

void unite( int u, int v ) {
	if ( S.SIZE( u ) < S.SIZE( v ) )
	      swap( u, v );
	      
	// v is the smallest tree -> append v to u
	// now join them
	S.JOIN( u, v );

	// root v
	cant++; dfs( v );
	
	// update heavy paths
	parent[v] = u;

	cant++;
	int id = chain[u];
	if ( bot[id] == u )
		hl_build( v, chain[u] );
	else
		hl_build( v, getFreePath() );

	// make link
	edges[E] = (edge){ u, v, first[u] };
	first[u] = E++;
	edges[E] = (edge){ v, u, first[v] };
	first[v] = E++;
}

void updateTreeSum( int u, int val ) {
	int id = chain[u];
	updateSum( id, pos[u], -pen[u] + val );
	total[id] += -pen[u] + val;
	pen[u] = val;
}

int getLCA( int u, int v ) {
	// u is the deepest
	if ( level[v] > level[u] )
	      swap( u, v );

	for ( int i = log2( level[u] ); i >= 0; i-- ) {
		if ( level[u] - (1 << i) >= level[v] )
			u = LCA[i][u];
	}

	if ( u == v ) return v;

	for ( int i = log2( level[u] ); i >= 0; i-- )
		if ( level[u] >= (1 << i) && LCA[i][u] != LCA[i][v] ) {
			u = LCA[i][u];
			v = LCA[i][v];
		}

	//printf( "hello %d %d\n", u + 1, v + 1 );
	assert( parent[u] == parent[v] );
	return parent[u];
}

int getTreeSum( int u, int v ) {
	if ( u == v )
	      return pen[u];
	      
	assert( level[v] <= level[u] );
	
	if ( chain[u] == chain[v] ) {
	//	printf( "same chain %d %d\n", u + 1, v + 1 );
		int ans = querySum( chain[u], pos[u] ) - querySum( chain[v], pos[v] - 1 );
		//printf( "retsame: %d\n", ans );
		return ans;
	}

	/*REP( i, V )
	      printf( "%d ", chain[i] );
	printf( "\n" );
	
	printf( "father = %d\n", parent[u] + 1 );
	printf( "top %d\n", top[ chain[u] ] );
*/
	int ans = 0;
	while ( chain[u] != chain[v] ) {
		int id = chain[u];
		ans += querySum( id, pos[u] );
		u = parent[ top[id] ];
	}
	
	ans += querySum( chain[u], pos[u] ) - querySum( chain[v], pos[v] - 1 );
	
	return ans;
}

int query( int u, int v ) {
	if ( u == v )
	      return pen[u];
	int z = getLCA( u, v );
	//printf( "LCA(%d,%d) = %d\n", u + 1, v+ 1, z + 1  );
	return getTreeSum( u, z ) + getTreeSum( v, z ) - pen[z];
}

/* Fast IO */
//#define getc_unlocked( stdin ) getchar()

inline int next_int() {
	register int ans = 0;
	register char ch;
	while ( ( ch = getc_unlocked( stdin ) ) < '0' );
	do {
		ans *= 10;
		ans += ( ch - '0' );
	} while ( ( ch = getc_unlocked( stdin ) ) >= '0' );
	return ans;
}

inline char skip_string() {
	register char ch, ans;
	while ( ( ch = getc_unlocked( stdin ) ) < '0' );
	ans = ch;
	while ( ( ch = getc_unlocked( stdin ) ) >= '0' );
	return ans;
}

int main() {

	//scanf( "%d", &V );
	V = next_int();
	REP( i, V )
		pen[i] = next_int(); //scanf( "%d", &pen[i] );
	      
	// init
	fill( first, first + V, -1 );
	fill( parent, parent + V, -1 );
	REP( i, V ) {
		used[i] = true;
		insert( i, i );
	}
	      
	Q = next_int(); //scanf( "%d", &Q );
	while ( Q-- ) {
		int u, v;
		op[0] = skip_string();
		u = next_int();
		v = next_int();
		//scanf( "%s %d %d", &op, &u, &v );
		
		if ( op[0] == 'b' ) { // bridge
		      u--; v--;
		      if ( S.FIND( u ) == S.FIND( v ) ) {
				printf( "no\n" ); fflush( stdout );
		            continue ;
			}

			printf( "yes\n" ); fflush( stdout );
			unite( u, v );
		}
		
		if ( op[0] == 'e' ) { // excursion
		      u--; v--;
		      if ( S.FIND( u ) != S.FIND( v ) ) {
				printf( "impossible\n" ); fflush( stdout );
		            continue ;
			}
			
			printf( "%d\n", query( u, v ) ); fflush( stdout );
		}
		
		if ( op[0] == 'p' ) { // penguins
		      u--;
		      if ( pen[u] == v )
		            continue ;
		            
			updateTreeSum( u, v );
		}
	}

	return 0;
}
