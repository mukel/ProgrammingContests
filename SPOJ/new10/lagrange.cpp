/*
Alfonso2 Peterssen (mukel)
SPOJ #3394 "Lagrange’s Four-Square Theorem"
18 - 5 - 2009
*/
#include <cstdio>

const int MAXN = 1 << 16;

int N;
int dp[MAXN][5];

int main() {

	dp[0][0] = 1;
	for ( int i = 1; i * i < MAXN; i++ ) {
		int ii = i * i;
		for ( int j = ii; j < MAXN; j++ )
		for ( int k = 1; k <= 4; k++ )
		      dp[j][k] += dp[j - ii][k - 1];
	}

	while (1) {
		scanf( "%d", &N ); if ( !N ) break ;
		printf( "%d\n", dp[N][1] + dp[N][2] + dp[N][3] + dp[N][4] );
	}

	return 0;
}
