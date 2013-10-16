/*
Alfonso2 Peterssen
SPOJ #1725 "The Importance"
1 - 10 - 2008
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int
	MAXV = 100,
	oo = (int)1e9;

int T, V, E;
int best[MAXV][MAXV];
int dist[MAXV][MAXV];
int64 dp[MAXV][MAXV];
double sol[MAXV];

int64 memo( int u, int v ) {
	if ( u == v ) return 1;
	if ( dp[u][v] != -1 ) return dp[u][v];
	int64 val = 0;
	REP( i, V )
	      if ( i != u )
	            if ( dist[u][i] + best[i][v] == best[u][v] )
				val += memo( i, v );
	return dp[u][v] = dp[v][u] = val;
}

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d %d", &V, &E );
		
		REP( i, V )
		REP( j, i ) {
			dp[i][j] = dp[j][i] = -1;
			dist[i][j] = dist[j][i] = oo;
			best[i][j] = best[j][i] = oo;
		}
		
		REP( i, V ) sol[i] = 0;
		
		REP( i, E ) {
			int u, v, w;
			scanf( "%d %d %d", &u, &v, &w );
			u--; v--;
			best[u][v] = best[v][u] = w;
			dist[u][v] = dist[v][u] = w;
		}

		/* Floyd */
		REP( k, V )
		REP( i, V ) if ( best[i][k] != oo )
		REP( j, V )
		      best[i][j] = min( best[i][j], best[i][k] + best[k][j] );
		      
		REP( i, V )
		REP( j, V ) if ( i != j )
		REP( k, V )
		if ( k != i && k != j )
		if ( best[i][k] + best[k][j] == best[i][j] )
			sol[k] += ( memo( i, k ) * memo( k, j ) ) / (double)memo( i, j );
		
		REP( i, V )
		      printf( "%.3lf\n", sol[i] );
	}

	return 0;
}
