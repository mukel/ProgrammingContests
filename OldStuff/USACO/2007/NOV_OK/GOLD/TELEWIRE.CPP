/*
Alfonso Alfonso Peterssen
date
USACO 2007 NOV07 Gold "Telewire"
*/
#include <cstdio>

const int
    MAXN = 100000,
    MAXH = 100,
    oo = 1 << 29;

int N, C, i, j, low, sol;
int h[MAXN + 1];
int dp[2][MAXH + 1];

int main() {

    scanf( "%d %d", &N, &C );
    for ( i = 1; i <= N; i++ )
        scanf( "%d", &h[i] );

    for ( i = 1; i <= N; i++ ) {

        low = oo;
        for ( j = 0; j <= MAXH; j++ ) {
            low <?= dp[!(i&1)][j] - C * j;
            dp[i&1][j] = low + C * j;
        }
        
        low = oo;
        for ( j = MAXH; j >= 0; j-- ) {
            low <?= dp[!(i&1)][j] + C * j;
            dp[i&1][j] <?= low - C * j;
        }
        
        for ( j = 0; j <= MAXH; j++ )
            if ( j >= h[i] )
                dp[i&1][j] += ( j - h[i] ) * ( j - h[i] );
            else
                dp[i&1][j] = oo;
    }

    sol = oo;
    for ( i = 0; i <= MAXH; i++ )
        sol <?= dp[N&1][i];
        
    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
