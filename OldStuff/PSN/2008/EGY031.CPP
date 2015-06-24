/*
Alfonso Alfonso Peterssen
18 - 3 - 2008
USACO MAR08 Silver "River Crossing"
*/
#include <cstdio>

const int MAXN = 3000;

int n, i, j;
int cost[MAXN];
int dp[MAXN];

int main() {

    freopen( "river.in", "r", stdin );
    freopen( "river.out", "w", stdout );

    scanf( "%d %d", &n, &cost[0] );
    for ( i = 1; i <= n; i++ ) {
        scanf( "%d", &cost[i] );
        cost[i] += cost[i - 1];
    }

    for ( i = 1; i <= n; i++ ) {
        dp[i] = ( 1 << 29 );
        for ( j = 1; j <= i; j++ )
            dp[i] <?= dp[i - j] + cost[j] + cost[0];
    }

    printf( "%d\n", dp[n] - cost[0] );
    fflush( stdout );

    return 0;
}
