/*
Alfonso2 Peterssen
4 - 5 - 2008
USACO MAR06 Gold
TASK: SKILIFT
*/
#include <cstdio>

const int MAXN = 5000;

int N, K, big, i, j;
int plot[MAXN];
int dp[MAXN];

int main() {

    scanf( "%d %d" ,&N, &K );
    for ( i = 0; i < N; i++ )
        scanf( "%d", &plot[i] );

    for ( i = 1; i < N; i++ ) {
        big = i - 1;
        dp[i] = 1000000000;
        for ( j = i - 1; j >= 0 && j >= i - K; j-- ) {
            int x1 = i - big;
            int x2 = i - j;
            int h1 = plot[big] - plot[i];
            int h2 = plot[j] - plot[i];
            if ( h2 * x1 >= h1 * x2 ) {
                big = j;
                dp[i] <?= dp[j] + 1;
            }
        }
    }

    printf( "%d\n", dp[N - 1] + 1 );
    fflush( stdout );

    return 0;
}
