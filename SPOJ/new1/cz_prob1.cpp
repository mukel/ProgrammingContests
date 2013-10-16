/*
Alfonso2 Peterssen
SPOJ #1391 "Summing to a Square Prime"
8 - 9 - 2008
*/
#include <cstdio>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define FOR( i, s, e ) \
	for ( int i = (s); i <= (e); i++ )

typedef long long int64;

const int
	MAXN = 500,
	MAXK = 4,
	MAXP = 8000;

int T, N, K, cant;
int S[MAXN];
bool mark[MAXP];
bool square[MAXP];
int dp[MAXK][MAXP];

int main() {

	for ( int i = 0; i * i < MAXP; i++ )
	      square[i * i] = true;

	for ( int i = 2; i < MAXP; i++ )
	      if ( !mark[i] ) {
			for ( int j = 0; j * j < i; j++ )
			      if ( square[i - j * j] ) {
					S[cant++] = i;
					break;
				}
			for ( int j = i * i; j < MAXP; j += i )
			      mark[j] = true;
		}
		
	FOR( i, 0, S[MAXN - 1] ) {
	      dp[1][i] = 1;
	      dp[2][i] = i / 2 + 1;
	}

	REP( i, cant ) {
		int j = S[i];
		int k = S[i];
		while ( k >= 0 ) {
			dp[3][j] += dp[2][k];
			k -= 3;
		}
	}
		
	for ( scanf( "%d", &T ); T--; ) {
		scanf( "%d %d", &N, &K );
		printf( "%d\n", dp[K][ S[N - 1] ] );
	}
	
	return 0;
}
