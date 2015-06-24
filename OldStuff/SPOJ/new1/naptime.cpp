/*
Alfonso2 Peterssen
13 - 9 - 2008
SPOJ #283 "Naptime"
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define FOR( i, s, e ) \
    for ( int i = (s); i <= (e); i++ )

const int MAXN = 4000;

int T, N, B, sol;
int V[MAXN];
int next, last;
int dp[2][MAXN][2];

int main() {

	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d %d", &N, &B );
		FOR( i, 1, N )
			scanf( "%d", &V[i] );

		// no overlap
		memset( dp, 0, sizeof( dp ) );
		FOR( i, 2, N ) {
			last = next;
			next ^= 1;
			FOR( j, 1, i ) {
				dp[next][j][0] = max( dp[last][j][0], dp[last][j][1] );
				dp[next][j][1] = dp[last][j - 1][0];
				if ( j > 1 )
					dp[next][j][1] >?= dp[last][j - 1][1] + V[i];
			}
		}
    
		sol = max( dp[next][B][0], dp[next][B][1] );

		// overlap
		memset( dp, 0, sizeof( dp ) );
		dp[next][1][1] = V[1];
		FOR( i, 2, N ) {
			last = next;
			next ^= 1;
			FOR( j, 1, i ) {
				dp[next][j][0] = dp[last][j][0] >? dp[last][j][1];
				dp[next][j][1] = dp[last][j - 1][0];
				if ( j > 1 )
					dp[next][j][1] >?= dp[last][j - 1][1] + V[i];
			}
		}

		sol = max( sol, dp[next][B][1] );
    
		printf( "%d\n", sol );
	}
	
    return 0;
}
