/*
Alfonso2 Peterssen (mukel)
SPOJ #3389 "The Knights of the Round Circle"
20 - 5 - 2009
*/
#include <cstdio>

const int MAXN = 1 << 17;

int N;
double dp[MAXN];

int main() {

	for( int i = 2; i < MAXN; i++ )
		dp[i] = ( dp[i - 1] + 1.0 / i );

	while (1) {
		scanf( "%d", &N ); if ( !N ) break ;
		printf( "With %d competitors, a Jedi Knight will be replaced approximately %.2lf times.\n\n", N, dp[N] );
	}

	return 0;
}

