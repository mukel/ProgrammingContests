/*
Alfonso2 Peterssen (mukel)
11 - 1 - 2009
USACO JAN09 Task: damage
*/
#include <cstdio>
#include <vector>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXV = 30000;

int V, L, E, R;
vector< int > G[MAXV];
bool mark[MAXV];

int dfs( int x ) {
	if ( mark[x] ) return 0;
	mark[x] = true;
	int cant = 1;
	REP( i, G[x].size() )
	      cant += dfs( G[x][i] );
	return cant;
}

int main() {

	scanf( "%d %d %d", &V, &L, &R );
	REP( i, L ) {
		int u, v;
		scanf( "%d %d", &u, &v );
		u--; v--;
		G[u].push_back( v );
		G[v].push_back( u );
	}
	
	REP( i, R ) {
		int u;
		scanf( "%d", &u );
		u--;
		mark[u] = true;
		REP( i, G[u].size() )
		      mark[ G[u][i] ] = true;
	}
	
	printf( "%d\n", V - dfs( 0 ) );

	return 0;
}
