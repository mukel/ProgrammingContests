/*
Alfonso2 Peterssen
14 - 6 - 2008
IOI 2004 "Phidias"
*/
#include <cstdio>

const int MAXC = 601;

#define FOR( i, n ) \
    for ( int i = 1; i <= (n); i++ )

int F, C, N;
int x, y;
int dp[MAXC][MAXC];

int main() {

    scanf( "%d %d", &F, &C );
    FOR( i, F )
    FOR( j, C )
        dp[i][j] = i * j;
    
    scanf( "%d", &N );
    FOR( i, N ) {
        scanf( "%d %d", &x, &y );
        dp[x][y] = 0;
    }
    
    FOR( i, F )
    FOR( j, C ) {
        int i2 = i / 2;
        FOR( k, i2 )
            dp[i][j] <?= dp[k][j] + dp[i - k][j];
        int j2 = j / 2;
        FOR( k, j2 )
            dp[i][j] <?= dp[i][k] + dp[i][j - k];
    }

    printf( "%d\n", dp[F][C] );

    return 0;
}
