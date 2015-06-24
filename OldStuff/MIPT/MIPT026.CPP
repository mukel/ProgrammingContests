/*
Alfonso2 Peterssen
18 - 7 - 2008
MIPT #026 "Operations"
*/
#include <cstdio>

const int
    MAXN = 2000010,
    oo = (int)1e9;

int N;
int dp[MAXN];

int solve( int x ) {
    if ( x < 4 ) return x;
    if ( dp[x] ) return dp[x];
    if ( x % 2 == 0 )
        return dp[x] = solve( x / 2 ) + 1;
    return dp[x] = ( solve( x - 1 ) <? solve( x + 1 ) ) + 1;
}

int main() {

    scanf( "%d", &N );
    printf( "%d\n", solve( N ) );

    return 0;
}
