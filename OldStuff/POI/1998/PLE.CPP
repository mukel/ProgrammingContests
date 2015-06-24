/*
Alfonso2 Peterssen
12 - 5 - 2008
POI 1998 Stage II "Frogman"
*/
#include <cstdio>
#include <cstring>

const int MAXN = 80;

int O, N, T;
int dp[MAXN][MAXN];

int main() {

    scanf( "%d %d", &O, &N );
    scanf( "%d", &T );

    memset( dp, 63, sizeof( dp ) );
    dp[0][0] = 0;
    while ( T-- ) {
        int i, j, x, y, w;
        scanf( "%d %d %d", &x, &y, &w );
        for ( i = O; i >= 0; i-- )
            for ( j = N; j >= 0; j-- )
                dp[i][j] <?= dp[i - x >? 0][j - y >? 0] + w;
    }

    printf( "%d\n", dp[O][N] );

    return 0;
}
