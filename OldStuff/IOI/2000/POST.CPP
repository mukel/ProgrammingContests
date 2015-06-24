/*
Alfonso2 Peterssen
9 - 6 - 2008
IOI 2000 "Post Office"
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

#define FOR( i, s, e ) \
    for ( int i = (s); i <= (e); i++ )

const int
    MAXN = 400,
    MAXP = 40;

int N, P;
int T[MAXN];
int D[MAXN][MAXN];
int dp[MAXN][MAXP];
int from[MAXN][MAXP];

void print( int n, int p ) {
    if ( p == 0 ) return ;
    print( from[n][p] - 1, p - 1 );
    printf( "%d ", T[ ( from[n][p] + n ) / 2 ] );
}

int main() {

    scanf( "%d %d", &N, &P );
    FOR( i, 1, N ) {
        scanf( "%d", &T[i] );
        FOR( j, 1, i ) {
            int piv = ( i + j ) / 2;
            FOR( k, j, i )
                D[j][i] += std::abs( T[piv] - T[k] );
        }
    }

    memset( dp, 63, sizeof( dp ) );
    dp[0][0] = 0;
    FOR( i, 1, N )
    FOR( j, 1, i <? P )
    FOR( k, j, i ) {
        int value = dp[k - 1][j - 1] + D[k][i];
        if ( value < dp[i][j] ) {
            dp[i][j] = value;
            from[i][j] = k;
        }
    }

    printf( "%d\n", dp[N][P] );
    print( N, P );
    printf( "\n" );

    return 0;
}
