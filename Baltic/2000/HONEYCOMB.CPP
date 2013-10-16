/*
Alfonso Alfonso Peterssen
15 - 3 - 2008
Baltic 2002 Task "HoneyComb"
*/
#include <cstdio>

const int MAXN = 300;

int n, m, i, j, d, sol;
int hi[MAXN];
int hc[MAXN][MAXN];
int dp[MAXN][MAXN][2];

int main() {

    scanf( "%d", &n );
    for ( i = 1; i <= 2 * n - 1; i++ ) {
        if ( i <= n )
             m = i + n - 1;
        else m = 3 * n - i - 1;
        for ( j = 1; j <= m; j++ ) {
            scanf( "%d", &hc[i][j] );
            hi[i] >?= hc[i][j];
        }
    }

    for ( i = 1; i <= 2 * n - 1; i++ ) {
        if ( i <= n )
             d = -1, m = i + n - 1;
        else d = +1, m = 3 * n - i - 1;
        for ( j = 1; j <= m; j++ ) {
            dp[i][j][0] >?= ( dp[i - 1][j][0] >?
                              dp[i - 1][j + d][0] ) + hc[i][j];
            dp[i][j][1] >?= dp[i - 1][j][0]     + hi[i] >?
                            dp[i - 1][j][1]     + hc[i][j];
            dp[i][j][1] >?= dp[i - 1][j + d][0] + hi[i] >?
                            dp[i - 1][j + d][1] + hc[i][j];
        }
    }

    for ( i = 1; i <= n; i++ )
        sol >?= dp[2 * n - 1][i][1];

    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
