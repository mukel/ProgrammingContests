/*
Alfonso2 Peterssen
SPOJ #329 "Calls"
19 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int
	MAXV = 300,
	MAXE = 90000,
	oo = (int)1e9;

int T, V, L, E;
int cost[MAXV][MAXV];
struct edge {
	int u, v, w;
	bool operator < ( const edge& e ) const { return w < e.w; }
} edges[MAXE];

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		E = 0;

		scanf( "%d %d", &V, &L );
		REP( i, V )
		for ( int j = i + 1; j < V; j++ ) {
			int w;
		      scanf( "%d", &w );
		      cost[i][j] = cost[j][i] = oo;
		      edges[E++] = (edge){ i, j, w };
		}
		
		if ( L > V * ( V - 1) / 2 ) {
		      printf( "--NO\n" );
		      continue;
		}
		
		sort( edges, edges + E );
		REP( i, E ) {

			int u = edges[i].u;
			int v = edges[i].v;
			int w = edges[i].w;
			int best = cost[u][v];
			
			REP( j, V )
			      best = min( best, cost[u][j] + cost[j][v] );
			cost[u][v] = cost[v][u] = best;
			      
			if ( best < w ) {
				L = -1;
			      break;
			}
			      
			if ( best > w ) {
				L--;
				if ( L < 0 ) break;
				cost[u][v] = cost[v][u] = w;
				REP( j, V ) {
					int val = cost[j][u] + w;
					if ( val < cost[j][v] )
					      cost[j][v] = cost[v][j] = val;
					val = cost[j][v] + w;
					if ( val < cost[j][u] )
					      cost[j][u] = cost[u][j] = val;
				}
			}
		}
		
		if ( L >= 0 )
		      printf( "YES\n" );
		else
			printf( "NO\n" );
	}

	return 0;
}
