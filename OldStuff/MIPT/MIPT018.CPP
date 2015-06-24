/*
Alfonso2 Peterssen
18 - 7 - 2008
MIPT #018 "What is the number?"
*/
#include <cstdio>

#define FOR( i, s, e ) \
    for ( int i = (s); i <= (e); i++ )

const int MAXN = 2000001;

int N, sol;
bool mark[MAXN];
int dp[MAXN];

int main() {

    scanf( "%d", &N );
    FOR( i, 2, N ) dp[i] = i;
    FOR( i, 2, N )
        if ( !mark[i] )
            for ( int j = i; j <= N; j += i ) {
                dp[j] = dp[j] / i * (i - 1);
                mark[j] = true;
            }

    FOR( i, 2, N )
        dp[i] += dp[i - 1];

    sol = ( N == 2 ) ? 0 : 32 - __builtin_clz( dp[N] - 1 );
    // 0 is undefined for __builtin_clz

    printf( "%d\n", sol );

    return 0;
}
