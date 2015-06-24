/*
Alfonso Alfonso Peterssen
18 - 3 - 2008
USACO MAR08 Silver "River Crossing"
*/
#include <cstdio>

const int MAXN = 3000;

int n, i, j;
int v[MAXN], dp[MAXN];

int main() {

    scanf( "%d %d", &n, &v[0] );
    for ( i = 1; i <= n; i++ ) {
        scanf( "%d", &v[i] );
        v[i] += v[i - 1];
    }

    for ( i = 1; i <= n; i++ ) {
        dp[i] = ( 1 << 29 );
        for ( j = 1; j <= i; j++ )
            dp[i] <?= dp[i - j] + v[j] + v[0];
    }

    printf( "%d\n", dp[n] - v[0] );
    fflush( stdout );

    return 0;
}
