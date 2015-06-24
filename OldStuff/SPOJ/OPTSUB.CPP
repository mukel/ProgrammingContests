/*
Alfonso Alfonso Peterssen
28 - 11 - 2007
SPOJ #1453 "Optimal Connected Subset"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int
    MAXN = 1000,
    oo = 1000000000;

int T, N, E, i, j, k, sol;
int x[MAXN], y[MAXN], w[MAXN];
bool mark[MAXN];
int dp[MAXN][2];

int P[MAXN];
struct edge {
    int v, next;
} ls[ 2 * MAXN ];

    int dfs( int x ) {

        mark[x] = true;
        int i, j, val = w[x];

        for ( i = P[x]; i; i = ls[i].next )
            if ( !mark[ ls[i].v ] )
                if ( ( j = dfs( ls[i].v ) ) > 0 ) val += j;

        sol >?= val;

        return val;
    }

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        scanf( "%d", &N );
        for ( i = 0; i < N; i++ )
            scanf( "%d %d %d", &x[i], &y[i], &w[i] );

        /* Init */
        E = 0;
        memset( P, 0, sizeof( P ) );
        memset( mark, 0, sizeof( mark ) );

        for ( i = 0; i < N; i++ )
            for ( j = 0; j < N; j++ )
                if ( abs( x[i] - x[j] ) + abs( y[i] - y[j] ) == 1 ) {
                    ls[++E] = ( edge ) { j, P[i] };
                    P[i] = E;
                }

        sol = 0;
        dfs( 0 );

        printf( "%d\n", sol );
    }

    return 0;
}
