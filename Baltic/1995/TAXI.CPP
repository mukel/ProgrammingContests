/*
Alfonso2 Peterssen
8 - 5 - 2008
BalticOI 1995 TASK: TAXI
*/
#include <cstdio>

const int MAXN = 200;

int N, i, j;
int cost[11];
int dp[MAXN];
int from[MAXN];

void print( int km ) {
    if ( km == 0 ) return ;
    print( km - from[km] );
    printf( "%d %d\n", from[km], cost[ from[km] ] );
}

int main() {

    for ( i = 1; i <= 10; i++ )
        scanf( "%d", &cost[i] );
        
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ ) {
        dp[i] = 1 << 30; // oo
        for ( j = 1; j <= 10 && i - j >= 0; j++ )
            if ( dp[i - j] + cost[j] <= dp[i] ) {
                dp[i] = dp[i - j] + cost[j];
                from[i] = j;
            }
    }
    
    print( N );
    printf( "%d", dp[N] );

    return 0;
}
