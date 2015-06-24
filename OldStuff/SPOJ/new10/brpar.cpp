/*
Alfonso2 Peterssen (mukel)
SPOJ #4202 "Brackets Parade"
22 - 5 - 2009
*/
#include <cstdio>

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int64 MOD = 1000000007;

const int MAXN = 1 << 11;

int T, N, M;
int cnt[MAXN];
int64 C[MAXN][MAXN];

int main() {

	REP( i, MAXN ) {
		C[i][0] = 1LL;
		for ( int j = 1; j <= i; j++ )
		      C[i][j] = ( C[i - 1][j - 1] + C[i - 1][j] ) % MOD;
	}

	scanf( "%d", &T );
	while ( T-- ) {
		scanf( "%d", &M );
		REP( i, M ) {
		      scanf( "%d", &cnt[i] );
		      N += cnt[i];
		}
		
		int64 ans = C[2 * N][N] - C[2 * N][N - 1];
		if ( ans < 0 ) ans += MOD;

		REP( i, M ) {
			ans = ( ans * C[N][ cnt[i] ] ) % MOD;
			N -= cnt[i];
		}
		
		printf( "%d\n", (int)ans );
	}

	return 0;
}
