/*
Alfonso Alfonso Peterssen
TASK: SKYLINE
*/
#include <cstdio>

const int
    MAXN = 50000,
    MAXC = 16383; // > 10000

int N, i, j, k, limit;
int tree[5 * MAXN];
int height[MAXC];
int sol[4 * MAXN];

void update( int node, int start, int end,
             int lo, int hi, int value ) {
    if ( end < lo || start > hi || start > end )
        return ;
    if ( start >= lo && end <= hi ) {
        tree[node] >?= value;
        return ;
    }
    int mid = ( start + end ) / 2;
    update( 2 * node    , start  , mid, lo, hi, value );
    update( 2 * node + 1, mid + 1, end, lo, hi, value );
}

int query( int node, int start, int end, int pos ) {
    if ( end < pos || start > pos || start > end )
        return 0;
    if ( start >= pos && end <= pos )
        return tree[node];
    int mid = ( start + end ) / 2;
    return tree[node] >?
           query( 2 * node    , start  , mid, pos ) >?
           query( 2 * node + 1, mid + 1, end, pos );
}

int main() {

    #warning READ FROM FILES!!!!
    
//    freopen( "skyline.in", "r", stdin );
//   freopen( "skyline.out", "w", stdout );

    while ( scanf( "%d %d %d", &i, &k, &j ) != EOF ) {
        limit >?= j;
        update( 1, 0, MAXC, i, j - 1, k );
    }

    for ( i = 0; i < limit; i++ )
        height[i] = query( 1, 0, MAXC, i );
        
    for ( i = 0; i < limit; ) {
        for ( j = i; j < limit && height[j] == height[i]; j++ );
        sol[N++] = j;
        sol[N++] = height[j];
        i = j;
    }

    for ( i = 0; i < N; i++ )
        printf( i < N - 1 ? "%d " : "%d\n", sol[i] );

    fflush( stdout );

    return 0;
}
