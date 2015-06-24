/*
Alfonso Alfonso Peterssen
TASK: NIKOLA
*/
#include <cstdio>
#include <algorithm>

using std::fill;

const int MAXN = 1000;

int n, i, j, sol;
int value[MAXN];
int dp[MAXN][MAXN];

int main() {

    scanf( "%d", &n );
    for ( i = 0; i < n; i++ )
        scanf( "%d", &value[i] );

    for ( i = 0; i < n; i++ )
        fill( dp[i], dp[i] + n, ( 1 << 29 ) );

    dp[0][0] = 0;
    for ( i = 1; i < n; i++ )
        for ( j = n - 1; j >= 0; j-- ) {
            if ( j + i < n  ) dp[i][j] <?= dp[i][j + i];
            if ( j - i >= 0 ) dp[i][j] <?= dp[i - 1][j - i];
            dp[i][j] += value[j];
        }

    sol = ( 1 << 29 );
    for ( i = 0; i < n; i++ )
        sol <?= dp[i][n - 1];

    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
