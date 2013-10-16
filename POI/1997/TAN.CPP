/*
Alfonso Alfonso Peterssen
28 - 2 - 2008
POI 1997 Stage I "Cheap travels"
*/
#include <cstdio>

const int
    MAXN = 1001,
    LIMIT = 800;

int n, d, i, j, k;
int sol[2];
int dist[MAXN], cost[MAXN];
int dp[MAXN][2], from[MAXN][2];

    void print( int hotel, int path ) {
        if ( hotel == 0 )
            return;
        print( from[hotel][path], path );
        printf( "%d ", dist[hotel] );
    }

int main() {

    scanf( "%d %d", &d, &n );
    for ( i = 1; i <= n; i++ ) {        
        
        scanf( "%d %d", &dist[i], &cost[i] );
        
        from[i][0] = from[i][1] = i - 1;
        dp[i][0] = dp[i][1] = ( 1 << 29 ); // oo
        
        for ( j = 0; j < i; j++ ) {
            if ( dist[i] - dist[j] > LIMIT )
                continue;
            for ( k = 0; k < 2; k++ )
                if ( dp[j][k] < dp[i][k] ||
                   ( dp[j][k] == dp[i][k] &&
                     dp[j][k^1] <= dp[ from[i][k^1] ][k^1] ) ) {
                    dp[i][k] = dp[j][k];
                    from[i][k] = j;
                }
        }

        dp[i][0] += cost[i];
        dp[i][1] += 1;
    }

    sol[0] = sol[1] = n;
    for ( i = n; i >= 0; i-- ) {
        if ( d - dist[i] > LIMIT )
            break;
        for ( k = 0; k < 2; k++ )
            if ( dp[i][k] < dp[ sol[k] ][k] ||
               ( dp[i][k] == dp[ sol[k] ][k] &&
                 dp[i][k^1] < dp[ sol[k] ][k^1] ) )
               sol[k] = i;
    }

    print( sol[0], 0 ); printf( "\n" );
    print( sol[1], 1 ); printf( "\n" );

    return 0;
}
