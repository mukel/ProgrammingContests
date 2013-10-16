/*
Alfonso2 Peterssen
17 - 6 - 2008
IOI 2006 "THE VALLEY OF MEXICO"
*/
#include <cstdio>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 2001;

int N, M;
int u, v;
int lo, hi, dir;
bool way[MAXN][MAXN];
bool dp[MAXN][MAXN][2];

int main() {

    scanf( "%d %d", &N, &M );
    REP( i, M ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        way[u][v] = way[v][u] = true;
    }

    REP( i, N )
        dp[i][i][0] = dp[i][i][1] = way[i][i] = true;

    REP( d, N ) if ( d )
    REP( i, N ) {
        int j = i + d;
        dp[i][j][0] = ( dp[i + 1][j][0] && way[(i+1)%N][i] ) ||
                      ( dp[i + 1][j][1] && way[i][j%N] );
        dp[i][j][1] = ( dp[i][j - 1][1] && way[(j-1)%N][j%N] ) ||
                      ( dp[i][j - 1][0] && way[i][j%N] );
    }

    for ( lo = 0; lo < N; lo++ )
        if ( dp[lo][lo+N-1][0] || dp[lo][lo+N-1][1] )
            break;

    if ( lo == N ) {
        printf( "-1\n" );
        return 0;
    }

    hi = lo + N - 1;
    dir = dp[lo][hi][1];
    while ( lo <= hi )
        if ( dir ) {
            if ( dp[lo][hi-1][dir^1] && way[lo][hi%N] ) dir ^= 1;
            printf( "%d\n", hi + 1 );
            hi--;
        } else {
            if ( dp[lo+1][hi][dir^1] && way[lo][hi%N] ) dir ^= 1;
            printf( "%d\n", lo + 1 );
            lo++;
        }

    return 0;
}
