/*
Alfonso2 Peterssen
SPOJ #666 "Con-Junctions"
10 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXV = 100010,
	MODULO = 10007;

int T, V;
int cov[MAXV][2];
int wys[MAXV][2];
bool mark[MAXV];
vector< int > G[MAXV];

void dfs( int x ) {

	cov[x][0] = 0; wys[x][0] = 1;
	cov[x][1] = 1; wys[x][1] = 1;

	mark[x] = true;
	REP( i, G[x].size() ) {
		int y = G[x][i];
		if ( !mark[y] ) {
			dfs( y );
			cov[x][0] += cov[y][1];
			wys[x][0] = ( wys[x][0] * wys[y][1] ) % MODULO;
			
			cov[x][1] += min( cov[y][0], cov[y][1] );

			int val = wys[y][0] + wys[y][1];
			if ( cov[y][0] < cov[y][1] )
			      val = wys[y][0];
			else
			if ( cov[y][1] < cov[y][0] )
			      val = wys[y][1];
			      
			wys[x][1] = ( wys[x][1] * val ) % MODULO;
		}
	}
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		scanf( "%d", &V );
		
		REP( i, V ) {
			G[i].clear();
			mark[i] = false;
		}
		
		REP( i, V - 1 ) {
			int u, v;
			scanf( "%d %d", &u, &v );
			u--; v--;
			G[u].push_back( v );
			G[v].push_back( u );
		}
		
		dfs( 0 );
		
		if ( cov[0][0] < cov[0][1] )
		      printf( "%d %d\n", cov[0][0], wys[0][0] );
		else
		if ( cov[0][1] < cov[0][0] )
		      printf( "%d %d\n", cov[0][1], wys[0][1] );
		else
		      printf( "%d %d\n", cov[0][0], ( wys[0][0] + wys[0][1] ) % MODULO );
	}

	return 0;
}
