/*
Alfonso Alfonso Peterssen
18 - 3 - 2008
USACO MAR08 Silver "Cow Travelling"
*/
#include <cstdio>

const int
    MAXC = 200,
    MAXT = 16;

int f, c, t, i, j, k;
int x, y;
char mat[MAXC][MAXC];
long long dp[MAXT][MAXC][MAXC];

int main() {

    freopen( "ctravel.in", "r", stdin );
    freopen( "ctravel.out", "w", stdout );

    scanf( "%d %d %d", &f, &c, &t );
    for ( i = 1; i <= f; i++ )
        scanf( "%s", mat[i] + 1 );

    scanf( "%d %d", &x, &y );

    dp[0][x][y] = 1;
    for ( i = 1; i <= t; i++ )
        for ( j = 1; j <= f; j++ )
        for ( k = 1; k <= c; k++ )
            if ( mat[j][k] != '*' )
                dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j + 1][k] +
                              dp[i - 1][j][k - 1] + dp[i - 1][j][k + 1];

    scanf( "%d %d", &x, &y );
    printf( "%d\n", dp[t][x][y]  );
    fflush( stdout );

    return 0;
}
