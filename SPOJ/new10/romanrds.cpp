/*
Alfonso2 Peterssen (mukel)
SPOJ #1961 "Roman Roads"
19 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXV = 1000;

int E;
int from[MAXV];
vector< int > G[MAXV];

bool bfs( int src ) {
	queue< int > Q;
	for ( Q.push( src ); !Q.empty(); Q.pop() ) {
		int u = Q.front();
		REP( i, G[u].size() ) {
			int v = G[u][i];
			if ( v == from[u] ) continue ;
			if ( from[v] != E && from[v] != from[u] )
			      return 0;
			if ( from[v] != E ) continue ;
			from[v] = u;
			Q.push( v );
		}
	}
	return 1;
}

int main() {

	scanf( "%d", &E );
	REP( i, E ) {
		int len;
		scanf( "%d", &len );
		REP( j, len ) {
			int x;
			scanf( "%d", &x );
			x--;
			G[i].push_back( x );
		}
	}
	
	// assumes that edge i is leaf edge
	REP( i, E ) {
		fill( from, from + E, E );
		if ( !bfs( i ) ) continue ;
		if ( count( from, from + E, E ) != 1 ) continue ;
		
		// build ans
		printf( "YES\n" );
		REP( j, E )
		      printf( "%d %d\n", j + 1, from[j] + 1 );
		
		return 0;
	}
	
	printf( "NO\n" );

	return 0;
}
