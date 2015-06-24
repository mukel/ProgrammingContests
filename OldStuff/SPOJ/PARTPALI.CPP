/*
Alfonso2 Peterssen
3 - 7 - 2008
SPOJ #428 "Particular Palindromes"
*/
#include <cstdio>
#include <cstring>

#define FOR( i, s, e ) \
    for ( int i = (s); i <= (e); i++ )

typedef long long int64;

const int
    MAXN = 21,
    MAXP = 1001;

int T, N, P;
int64 dp[MAXN][MAXP];
int64 pow;

int main() {

    scanf( "%d", &T );
    while ( T-- ) {
        scanf( "%d %d", &P, &N );

        /* Init */
        memset( dp, 0, sizeof( dp ) );
        FOR( i, 1, 9 ) {
            dp[1][i % P]++;
            dp[2][(11 * i) % P]++;
        }
        if ( N > 1 ) dp[1][0]++;
        if ( N > 2 ) dp[2][0]++;

        /* DP */
        pow = 10 % P;
        FOR( i, 1, N - 2 ) {
            pow = ( pow * 10 ) % P;
            FOR( j, 0, P - 1 ) {
                if ( i < N - 2 )
                    dp[i + 2][(j * 10) % P] += dp[i][j];
                FOR( k, 1, 9 )
                    dp[i + 2][( pow * k + j * 10 + k ) % P] += dp[i][j];
            }
        }

        printf( "%d\n", dp[N][0] );
    }

    return 0;
}
