/*
Alfonso2 Peterssen (mukel)
3 - 2 - 2009
SGU #121 "Bridges painting"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXV = 100;
	
int V;
int dtime;
int BCC;
stack< int > S;
bool mark[MAXV];
int col[MAXV][MAXV];
vector< int > G[MAXV];
int bcomp[MAXV];
int dfsnum[MAXV];
int low[MAXV];

void dfs( int x, int color ) {
	mark[x] = true;
	color = 3 - color;
	REP( i, G[x].size() ) {
		int nxt = G[x][i];
		if ( !col[x][nxt] ) {
			//printf( "edge %d %d = %d\n", x + 1, nxt + 1, color );
			col[x][nxt] = color;
			col[nxt][x] = color;
		}
		if ( !mark[nxt] )
		      dfs( nxt, color );
	}
}

void dfs1( int x, int father = -1 ) {
	S.push( x );
	dfsnum[x] = low[x] = ++dtime;
	REP( i, G[x].size() ) {
		int nxt = G[x][i];
		if ( nxt == father ) continue;
		if ( !dfsnum[nxt] ) {
			dfs1( nxt, x );
		      low[x] = min( low[x], low[nxt] );
		} else
		      low[x] = min( low[x], dfsnum[nxt] );
	}
	
	if ( dfsnum[x] == low[x] ) {
		for (;;) {
			int z = S.top();
			bcomp[z] = BCC;
			S.pop();
			if ( z == x ) break;
		}
		BCC++;
	}
}

int main() {

	scanf( "%d", &V );
	REP( i, V ) {
		for (;;) {
			int nxt;
			scanf( "%d", &nxt );
			if ( nxt == 0 ) break;
			nxt--;
			G[i].push_back( nxt );
		}
	}
	
	REP( i, V )
	      if ( !dfsnum[i] )
	            dfs1( i );

	REP( i, V )
	REP( j, G[i].size() ) {
		int nxt = G[i][j];
		if ( !col[i][nxt] && bcomp[i] != bcomp[nxt] ) {
			//printf( "edge %d %d = %d\n", i + 1, nxt + 1, 1 );
			col[i][nxt] = 1;
			col[nxt][i] = 1;
		      mark[i] = true;
		      mark[nxt] = true;
		      dfs( i, 1 );
		      dfs( nxt, 1 );
		}
	}
	
	REP( i, V )
	REP( j, G[i].size() ) {
		int nxt = G[i][j];
		if ( !col[i][nxt] ) {
			//printf( "edge %d %d = %d\n", i + 1, nxt + 1, 1 );
			col[i][nxt] = 1;
			col[nxt][i] = 1;
		      mark[i] = true;
		      mark[nxt] = true;
		      dfs( i, 1 );
		      dfs( nxt, 1 );
		}
	}
	
	/* check */
	REP( i, V ) {
		if ( G[i].size() < 2 ) continue;
		int cant[2] = { 0, 0 };
		REP( j, G[i].size() )
			cant[ col[i][ G[i][j] ] - 1 ]++;
		if ( cant[0] == 0 || cant[1] == 0 ) {
			printf( "No solution\n" );
			exit( 0 );
		}
	}
	
	REP( i, V ) {
		REP( j, G[i].size() )
			printf( "%d ", col[i][ G[i][j] ] );
		printf( "0\n" );
	}

	return 0;
}
