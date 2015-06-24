/*
Alfonso2 Peterssen
SPOJ #2416 "Distinct Subsequences"
6 - 9 - 2008
*/
#include <cstdio>
#include <cstring>

#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )

typedef long long int64;

const int
	MAXN = 100005,
	MODULO = 1000000007;

int T, N;
char S[MAXN];
int64 dp[MAXN];
int pos[26];

int main() {

	for ( scanf( "%d", &T ); T--; ) {

		memset( pos, -1, sizeof( pos ) );

		scanf( "%s", S + 1 );
		N = strlen( S + 1 );
		
		dp[0] = 1;
		FOR( i, 1, N ) {
			dp[i] = dp[i - 1] * 2;
			if ( pos[ S[i] - 'A' ] != -1 )
			      dp[i] -= dp[ pos[ S[i] - 'A' ] - 1 ];
			dp[i] = ( dp[i] + MODULO ) % MODULO;
			pos[ S[i] - 'A' ] = i;
		}
		
		printf( "%lld\n", dp[N] );
	}

	return 0;
}
