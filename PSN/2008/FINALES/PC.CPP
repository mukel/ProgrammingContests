/*
Alfonso Alfonso Peterssen
25 - 4 - 2008
TASK: PC
*/
#include <cstdio>

const int
      MAXN = 1111,
      oo = 1000000000;

int N, C, i, j;
int dp[MAXN];
int cost[MAXN][MAXN];

int main() {
    
    #warning READ FROM FILES!!!
    freopen( "pc.in", "r", stdin );
    freopen( "pc.out", "w", stdout );

    scanf( "%d", &C );
    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ )
        for ( j = i; j <= N; j++ )
            scanf( "%d", &cost[i][j] );
            
    for ( i = 1; i <= N; i++ ) {
        dp[i] = oo;
        for ( j = 0; j < i; j++ )
            dp[i] <?= dp[j] + C + cost[j + 1][i];
    }
    
    printf( "%d\n", dp[N] );
    fflush( stdout );
     
    return 0;   
}

