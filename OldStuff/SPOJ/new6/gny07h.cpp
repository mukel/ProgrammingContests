/*
Alfonso Alfonso Peterssen
9 - 7 - 2007
*/
#include <cstdio>

int T, N;
int dp[2], S[2], A[2];
int main() {
	scanf( "%d", &T );
	for ( int tc = 1; tc <= T; tc++ ) {
		scanf( "%d", &N );
		dp[1] = S[1] = A[1] = 0;
		dp[0] = S[0] = A[0] = 1;
		int j;
		for ( int i = 1; i <= N; i++ ) {
			j = i & 1;
			int j1 = ( i - 1 ) & 1;
			dp[j] = dp[j] + dp[j1] + 2 * S[j] + A[j];
			S[j] = S[j1] + dp[j];
			A[j] = A[j] + dp[j];
		}
		printf( "%d %d\n", tc, dp[j] );
	}

  return 0;
}
