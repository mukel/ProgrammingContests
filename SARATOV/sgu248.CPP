/*
Alfonso2 Peterssen
15 - 5 - 2008
Saratov #248 "Integer Linear Programming" -> I don't think so
*/
#include <cstdio>
#include <algorithm>

using std::fill;

const int
    MAXV = 1000001,
    MAXN = 3,
    oo = 1 << 30;

int V, N;
int i, j;
int c[MAXN];
int dp[MAXV];

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ )
        scanf( "%d", &c[i] );
    scanf( "%d", &V );

    fill( dp + 1, dp + V + 1, oo );
    for ( i = 0; i < N; i++ )
        for ( j = c[i]; j <= V; j++ )
            dp[j] <?= dp[j - c[i]] + 1;

    if ( dp[V] == oo )
         printf( "-1\n" );
    else printf( "%d\n", dp[V] );

    return 0;
}
