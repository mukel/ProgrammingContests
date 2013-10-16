/*
Alfonso Alfonso Peterssen
25 - 2 - 2008
USACO FEB08 Gold "Grading"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 2000,
    oo = 1 << 30;

int n, i, sol;
int ls[MAXN], sorted[MAXN];
int dp[MAXN][MAXN];

    void process() {

        for ( int i = 0; i < n; i++ )
            dp[0][i] = abs( sorted[i] - ls[0] );

        for ( int i = 0; i < n; i++ ) {
            int low = oo;
            for ( int j = 0; j < n; j++ ) {
                low <?= dp[i - 1][j];
                dp[i][j] = low + abs( sorted[j] - ls[i] );
            }
        }

        for ( int i = 0; i < n; i++ )
            sol <?= dp[n - 1][i];
    }

int main() {

    scanf( "%d", &n );
    for ( i = 0; i < n; i++ ) {
        scanf( "%d", ls + i );
        sorted[i] = ls[i];
    }

    sort( sorted, sorted + n );

    sol = oo;

    process();
    reverse( ls, ls + n );
    process();

    printf( "%d\n", sol );

    return 0;
}
