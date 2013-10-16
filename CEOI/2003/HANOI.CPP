/*
Alfonso2 Peterssen
CEOI 2003 "Hanoi"
*/
#include <cstdio>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )
#define FOR( i, s, e ) \
    for ( int i = (s); i <= (e); i++ )

const int
    MAXN = 100001,
    MODULO = 1000000,
    oo = (int)1e9;

int N;
int cost;
int sz[3];
int tower[MAXN];
int dp[MAXN][3];

int main() {

    scanf( "%d", &N );
    REP( i, 3 ) scanf( "%d", &sz[i] );
    REP( i, 3 )
        REP( j, sz[i] ) {
            int x; scanf( "%d", &x );
            tower[x] = i;
        }

    dp[1][ tower[1] ] = 0;
    dp[1][ ( tower[1] + 1 ) % 3 ] = 1;
    dp[1][ ( tower[1] + 2 ) % 3 ] = 1;
    FOR( i, 2, N ) {
        cost = ( 2 * cost + 1 ) % MODULO;
        dp[i][ tower[i] ] = ( dp[i - 1][ tower[i] ] ) % MODULO;
        dp[i][ ( tower[i] + 1 ) % 3 ] = ( dp[i - 1][ ( tower[i] + 2 ) % 3 ] + cost + 1 ) % MODULO;
        dp[i][ ( tower[i] + 2 ) % 3 ] = ( dp[i - 1][ ( tower[i] + 1 ) % 3 ] + cost + 1 ) % MODULO;
    }

    printf( "%d\n%d\n", tower[N] + 1, dp[N][ tower[N] ] );

    return 0;
}
