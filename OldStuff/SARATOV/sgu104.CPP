/*
Alfonso Alfonso Peterssen
11 - 2 - 2008
Saratov #104 "Little shop of flowers"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXF = 101,
    MAXV = 101;

#define FOR( i, s, e ) \
    for ( i = (s); i <= (e); i++ )

int F, V, i, j;
int cost[MAXF][MAXV];
int dp[MAXF][MAXV];
int last[MAXF][MAXV];

    void print( int x, int y ) {
        if ( x == 0 ) return ;
        print( x - 1, last[x][y] - 1 );
        printf( x == F ? "%d\n" : "%d ", last[x][y] );
    }

int main() {

    scanf( "%d %d", &F, &V );
    FOR( i, 1, F )
        FOR( j, 1, V )
            scanf( "%d", &cost[i][j] );

    FOR( i, 1, F )
        fill( dp[i], dp[i] + V + 1, -(1 << 29) );

    FOR( i, 1, F )
        FOR( j, i, V - F + i ) {
            dp[i][j] = dp[i][j - 1];
            last[i][j] = last[i][j - 1];
            if ( dp[i - 1][j - 1] + cost[i][j] >= dp[i][j - 1] ) {
                dp[i][j] = dp[i - 1][j - 1] + cost[i][j];
                last[i][j] = j;
            }
        }

    printf( "%d\n", dp[F][V] );
    print( F, V );

    return 0;
}
