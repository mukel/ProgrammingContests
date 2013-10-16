/*
Alfonso Alfonso Peterssen
12 - 3 - 2008
USACO JAN08 Gold "Fucking alake"
*/
#include <cstdio>

const int MAXN = 100001;

typedef long long int64;

int n, i, j, low;
int dist[MAXN];
int height[MAXN];
int last[MAXN];
int next[MAXN];
int64 sol[MAXN];
int64 used[MAXN];
int64 fill_last[MAXN];
int64 fill_next[MAXN];

    int64 needed( int lo, int hi, int64 level ) {
        return level * ( dist[hi - 1] - dist[lo] ) - ( used[hi - 1] - used[lo] );
    }

int main() {

    scanf( "%d", &n );
    for ( i = low = 1; i <= n; i++ ) {
        scanf( "%d %d", &dist[i], &height[i] );
        if ( height[i] < height[low] )
            low = i;
        used[i] = height[i] * dist[i] + used[i - 1];
        dist[i] += dist[i - 1];
    }

    /* next */
    for ( i = n; i >= 0; i-- ) {
        for ( j = i + 1;
              j <= n && height[i] >= height[j];
              j = next[j] );
        next[i] = j;
    }

    /* last */
    for ( i = 1; i <= n; i++ ) {
        for ( j = i - 1;
              j > 0 && height[i] >= height[j];
              j = last[j] );
        last[i] = j;
    }

    for ( i = 1; i <= n; i++ ) {
        sol[i] = needed( last[i], next[i], height[i] + 1 );
        fill_last[i] = needed( last[i], i, height[i] );
        fill_next[i] = needed( i, next[i], height[i] );
    }

    for ( i = low + 1; i <= n; i++ )
        if ( last[i] > low ) {
            fill_last[i] += fill_last[ last[i] ];
            sol[i] += fill_last[ last[i] ];
        }

    for ( i = low - 1; i > 0; i-- )
        if ( next[i] < low ) {
            fill_next[i] += fill_next[ next[i] ];
            sol[i] += fill_next[ next[i] ];
        }

    for ( i = 1; i <= n; i++ )
        printf( "%I64d\n", sol[i] );

    return 0;
}
