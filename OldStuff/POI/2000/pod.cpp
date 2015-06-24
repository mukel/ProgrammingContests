/*
Alfonso2 Peterssen (mukel)
27 - 2 - 2009
Polish OI VII (2000) Stage II "POD"
O( V^2 ) but O( V + E ) with minor changes
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXV = 1000;

int V;
bool comm[MAXV];
int boss[MAXV];
int cant[MAXV];
vector< int > G[MAXV];

void dfs( int u, int __boss ) {
	boss[u] = __boss;
	cant[u]++;
	REP( i, G[u].size() ) {
		int v = G[u][i];
		if ( boss[v] != __boss )
		      dfs( v, __boss );
	}
}

int main() {

	scanf( "%d", &V );
	REP( i, V ) {
		int cant;
		scanf( "%d", &cant );
		if ( !cant )
			comm[i] = true;
		while ( cant-- ) {
			int nxt;
			scanf( "%d", &nxt );
			nxt--;
			G[nxt].push_back( i );
		}
		boss[i] = -1;
	}

	REP( i, V )
	      if ( comm[i] )
	            dfs( i, i );
 
	REP( i, V )
	      if ( !comm[i] && cant[i] < 2 )
	            printf( "%d\n", i + 1 );

	return 0;
}
