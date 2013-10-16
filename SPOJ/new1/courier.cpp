/*
Alfonso2 Peterssen
SPOJ #151 "The Courier"
6 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
	MAXV = 100,
	MAXD = 12,
	oo = (int)1e9;

int T, V, E, D;
int home;
int C[MAXV][MAXV];
int dp[1 << MAXD][MAXD];
int src[MAXD];
int dst[MAXD];

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		scanf( "%d %d %d", &V, &E, &home );
		home--;
		
		REP( i, V )
		REP( j, i )
		      C[i][j] = C[j][i] = oo;
		      
		REP( i, E ) {
			int u, v, w;
			scanf( "%d %d %d", &u, &v, &w );
			u--; v--;
			C[u][v] = C[v][u] = min( C[u][v], w );
		}
		
		REP( k, V )
		REP( i, V )
		REP( j, V )
		      C[i][j] = min( C[i][j], C[i][k] + C[k][j] );
		
		int cant = 0;
		
		scanf( "%d", &D );
		REP( i, D ) {
			int u, v, w;
			scanf( "%d %d %d", &u, &v, &w );
			u--; v--;
			while ( w-- ) {
			      src[cant] = u;
			      dst[cant] = v;
			      cant++;
			}
		}

//		printf( "cant %d\n", cant );

		REP( i, 1 << cant )
		REP( j, cant ) {
		      if ( ( i >> j ) & 1 ) {
				dp[i][j] = oo;
				int s = i ^ ( 1 << j );
				if ( s == 0 )
					dp[i][j] = min( dp[i][j], C[home][ src[j] ] + C[ src[j] ][ dst[j] ] );
				else
				REP( k, cant )
			      if ( ( s >> k ) & 1 )
					dp[i][j] = min( dp[i][j], dp[s][k] + C[ dst[k] ][ src[j] ] + C[ src[j] ][ dst[j] ] );
//				printf( "dp[%d][%d] = %d\n", i, j, dp[i][j] );
			}
		}

		int best = oo;
		REP( i, cant )
		      best = min( best, dp[(1 << cant) - 1][i] + C[ dst[i] ][home] );
		
		printf( "%d\n", best );
	}

	return 0;
}
