/*
Alfonso2 Peterssen (mukel)
SPOJ #3868 "Total Flow"
*/
#include <iostream>
#include <cstring>

using namespace std;

#define FOR( i, lo, hi ) for ( int i = (lo); i <= (hi); i++ )

const int MAXV = 0x100;

int E, ans;
bool mark[MAXV];
int cap[MAXV][MAXV];

bool dfs( char u ) {
	if ( u == 'Z' ) return true; // sink
	mark[u] = true;
	FOR( v, 'A', 'z' )
	if ( !mark[v] && cap[u][v] > 0 && dfs( v ) ) {
		cap[u][v]--;
		cap[v][u]++;
		return true;
	}
	return false;
}

int main() {

	scanf( "%d", &E );
	while ( E-- ) {
		char u, v; int w;
		cin >> u >> v >> w;
		cap[u][v] += w;
		cap[v][u] += w;
	}
	
	for (;;) {
		memset( mark, 0, sizeof( mark ) );
		if ( !dfs( 'A' ) )
		      break;
		ans++;
	}
	
	cout << ans << endl;

	return 0;
}
