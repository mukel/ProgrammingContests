/*
Alfonso2 Peterssen
SPOJ #2143 "Dependency Problems"
17 - 9 - 2008
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int MAXV = 10000;

int V;
bool avail[MAXV];
bool mark[MAXV];
bool done[MAXV];
vector< int > G[MAXV];
vector< int > order;
map< string, int > M;

void topsort( int x ) {
	mark[x] = true;
	REP( i, G[x].size() ) {
		int y = G[x][i];
		if ( !mark[y] )
		      topsort( y );
	}
	order.push_back( x );
}

int main() {

	string pack;
	while ( cin >> pack ) {
		if ( M.find( pack ) == M.end() )
			M[pack] = V++;

		int u = M[pack];
		avail[u] = true;
		for (;;) {
			cin >> pack; if ( pack == "0" ) break;
			if ( M.find( pack ) == M.end() )
				M[pack] = V++;
				
			int v = M[pack];
			G[u].push_back( v );
		}
	}

	REP( i, V )
	      if ( !mark[i] )
			topsort( i );
			
	REP( i, order.size() ) {
		int u = order[i];
		bool found = false;
		REP( j, G[u].size() ) {
			int v = G[u][j];
			if ( !done[v] ) {
				found = true;
				break;
			}
		}
		if ( !found && avail[u] )
		      done[u] = true;
	}

	printf( "%d\n", count( done, done + V, true ) );

	return 0;
}
