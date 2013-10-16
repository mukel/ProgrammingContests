/*
Alfonso Alfonso Peterssen
12 - 3 - 2008
Croatia 2003 Regional "Brodovi"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair< int, int > par;

const int MAXN = 100666;

int n, m, i, j;
int b, d, lo, hi;
int dp[MAXN];
int sum[MAXN];
int fish[MAXN];
par ships[MAXN];

int main() {

    scanf( "%d", &n );
    for ( i = 1; i <= n; i++ ) {
        scanf( "%d", &fish[i] );
        fish[i] += fish[i - 1];
    }

    scanf( "%d", &m );
    for ( i = 0; i < m; i++ ) {
        scanf( "%d %d", &b, &d );
        ships[i] = make_pair( b, d );
        sum[b] = 1;
    }

    for ( i = 1; i <= n + 1; i++ )
        sum[i] += sum[i - 1];

    sort( ships, ships + m );

    /* DP */
    for ( i = 0; i < m; i++ ) {
        b = ships[i].first;
        d = ships[i].second;
        for ( j = 0; j < d; j++ ) {
            lo = b - j;
            hi = lo + d - 1;
            if ( lo < 1 || hi > n ||
                 sum[hi] - sum[lo - 1] > 1 ) // more than 1 ship
                 continue;
            dp[hi] = dp[lo - 1] + ( fish[hi] - fish[lo - 1] );
        }
        /* update */
        for ( j = b; j <= ships[i + 1].first; j++ )
            dp[j] >?= dp[j - 1];
    }

    printf( "%d\n", *max_element( dp, dp + n + 1 ) );

    return 0;
}
