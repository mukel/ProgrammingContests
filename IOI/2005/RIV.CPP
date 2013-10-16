/*
Alfonso2 Peterssen
16 - 6 - 2008
IOI 2005 "Rivers"
*/
#include <cstdio>

const int MAXN = 101;

int N, K;
int dist[MAXN];
int cost[MAXN];
int boss[MAXN];
int first[MAXN];
int next[MAXN];
int dp[MAXN][MAXN][MAXN];

int dfs( int x, int depth ) {

    dist[x] += depth;

    int sons = 1;
    for ( int y = first[x]; y; y = next[y] ) {
        sons += dfs( y, dist[x] );
        for ( int i = x; i != -1; i = boss[i] )
            for ( int j = sons <? K; j >= 0; j-- ) {
                int best = 1 << 29;
                for ( int k = 0; k <= j; k++ )
                    best <?= dp[x][i][j - k] + dp[y][i][k];
                dp[x][i][j] = best;
            }
    }

    for ( int i = x; i != -1; i = boss[i] )
        for ( int j = 0; j <= sons <? K; j++ ) {
            dp[x][i][j] += ( dist[x] - dist[i] ) * cost[x];
            if ( j ) dp[x][i][j] <?= dp[x][x][j - 1];
        }

    return sons;
}

int main() {

    scanf( "%d %d", &N, &K );
    for ( int i = 1; i <= N; i++ ) {
        int j;
        scanf( "%d %d %d", &cost[i], &j, &dist[i] );
        boss[i] = j;
        next[i] = first[j];
        first[j] = i;
    }

    boss[0] = -1;
    dfs( 0, 0 );

    printf( "%d\n", dp[0][0][K] );

    return 0;
}
