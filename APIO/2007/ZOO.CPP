/*
Alfonso2 Peterssen
23 - 7 - 2008
APIO 2007 "Zoo"
*/
#include <cstdio>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 10001;

int N, C, sol;
int E, F, L, x;
int fear, love;
int dp[MAXN][32];
int value[MAXN][32];

int get( int x, int lo, int hi ) {
    return (x >> lo) & ( (1 << (hi-lo+1)) - 1 );
}

int main() {

    scanf( "%d %d", &N, &C );
    REP( i, C ) {

        scanf( "%d %d %d", &E, &F, &L );
        fear = love = 0;

        REP( j, F + L ) {
            scanf( "%d", &x );
            x = ( x - E + N ) % N;
            if ( x < 5 )
                if ( j < F )
                     fear |= ( 1 << (4 - x) );
                else love |= ( 1 << (4 - x) );
        }

        REP( j, 32 )
            if ( ( j & fear ) != fear || ( j & love ) != 0 )
                value[E][j]++;
    }

    REP( k, 32 ) // first k bits
    for ( int i = 1; i <= N; i++ )
        REP( j, 32 )
            if ( ( i <= 5     && ( get( k, 0, 5 - i ) != get( j, i - 1, 4 ) ) ) ||
                 ( i >= N - 3 && ( get( k, 1-i+N, 4 ) != get( j, 0, i-N+3 ) ) ) )
                dp[i][j] = -C;
            else
                sol >?= dp[i][j] = ( dp[i - 1][(j >> 1)] >? dp[i - 1][(j >> 1) + 16] ) + value[i][j];

    printf( "%d\n", sol );

    return 0;
}
