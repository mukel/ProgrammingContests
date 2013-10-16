/*
Alfonso2 Peterssen
SPOJ #196 "Musketeers"
5 - 9 - 2008
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )

const int MAXN = 105;

int T, N;
char mat[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		memset( dp, 0, sizeof( dp ) );

		scanf( "%d", &N );
		REP( i, N )
		      scanf( "%s", &mat[i] );
		      
		REP( i, N )
		      dp[i][(i + 1) % N] = 1;
		      
		FOR( delta, 2, N )
			REP( i, N ) {
				int j = ( i + delta ) % N;
				for ( int k = (i + 1) % N; k != j; k = (k + 1) % N )
					if ( dp[i][k] && dp[k][j] && ( mat[i][k] == '1' || mat[j][k] == '1' ) ) {
						dp[i][j] = 1;
						break;
					}
			}
		
		int winners = 0;
		REP( i, N )
		      if ( dp[i][i] )
		            winners++;
		
		printf( "%d\n", winners );
		REP( i, N )
		      if ( dp[i][i] )
		            printf( "%d\n", i + 1 );
	}

	return 0;
}
