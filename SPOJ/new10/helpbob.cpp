/*
Alfonso2 Peterssen (mukel)
SPOJ #2856 "Help Bob"
21 - 5 - 2009
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int MAXN = 16;

int N;
int disc[MAXN][MAXN];
int P[MAXN];
int A[MAXN];
double dp[1 << MAXN];
int area[1 << MAXN];

int main() {

	while (1) {
		scanf( "%d", &N ); if ( !N ) break ;
		
		memset( disc, 0, sizeof( disc ) );
		
		REP( i, N ) {
			int len;
			scanf( "%d %d %d", &P[i], &A[i], &len );
			while ( len-- ) {
				int x, y;
				scanf( "%d %d", &x, &y );
				x--;
				disc[i][x] = y;
			}
		}
		
		for ( int i = 1; i < (1 << N); i++ )
		      dp[i] = 1e9;
		
		double ans = 1e9;
		for ( int i = 0; i < (1 << N); i++ ) {
			if ( !i )
				area[i] = 0;
			else {
				int id = __builtin_ctz( i );
				area[i] = area[i - (1 << id)] + A[id];
			}
			
			REP( j, N )
			if ( !((i >> j) & 1) ) {
				double val = P[j];
				REP( k, N )
				if ( (i >> k) & 1 )
					val = val * (100 - disc[k][j]) / 100.0;

				dp[i|(1 << j)] = min( dp[i|(1 << j)], dp[i] + val );
			}
			
			if ( i )
				ans = min( ans, dp[i] / area[i] );
		}
		
		printf( "%.4lf\n", ans );
	}

	return 0;
}
