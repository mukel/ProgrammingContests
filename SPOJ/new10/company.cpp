/*
Alfonso2 Peterssen (mukel)
SPOJ #3580 "Company"
18 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) for ( int i = (n) - 1; i >= 0; i-- )

#define ALL( c ) (c).begin(), (c).end()

const int MAXV = 1 << 10;

int V, E;
int dad[MAXV];
bool mark[MAXV];
int depth[MAXV];
vector< int > G[MAXV];
vector< int > order;
vector< pair< int, int > > ans;

void dfs( int u ) {
	mark[u] = true;
	REP( i, G[u].size() ) {
		int v = G[u][i];
		if ( !mark[v] ) dfs( v );
	}
	order.push_back( u );
}

int main() {

	scanf( "%d %d", &V, &E );
	REP( i, E ) {
		int u, v;
		scanf( "%d %d", &u, &v );
		u--; v--;
		G[u].push_back( v );
	}
	
	fill( dad, dad + V, -1 );
	
	REP( i, V )
		if ( !mark[i] )
		      dfs( i );
		      
	REPD( i, V ) {
		int u = order[i];
		REP( j, G[u].size() ) {
			int v = G[u][j];
			depth[v] = max( depth[v], depth[u] + 1 );
		}
	}
		      
	REPD( i, V ) {
		int u = order[i];
		mark[u] = false;
		REP( j, G[u].size() ) {
			int v = G[u][j];
			if ( depth[v] == depth[u] + 1 )
				ans.push_back( make_pair( u, v ) );
		}
	}

	printf( "%d\n", ans.size() );
	REP( i, ans.size() )
	      printf( "%d %d\n", ans[i].first + 1, ans[i].second + 1 );

	return 0;
}
