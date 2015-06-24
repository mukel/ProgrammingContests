/*
Alfonso Alfonso Peterssen
19 - 3 - 2008
USACO MAR08 Bronze "Oh Those Rollers"
*/
#include <cstdio>

const int MAXN = 2000;

int n, i;
int start, end;
bool mark[MAXN];
int x[MAXN], y[MAXN], r[MAXN];

template< typename T >
T sqr( const T x ) { return x * x; }

void dfs( int rol ) {

    mark[rol] = true;

    bool ok = true;
    for ( int i = 0; i < n; i++ ) {
        if ( mark[i] ) continue;
        if ( sqr( x[rol] - x[i] ) + sqr( y[rol] - y[i] ) ==
             sqr( r[rol] + r[i] ) ) {
             ok = false;
             dfs( i );
        }
    }

    if ( ok )
        end = rol;
}

int main() {

    freopen( "rollers.in", "r", stdin );
    freopen( "rollers.out", "w", stdout );

    scanf( "%d", &n );
    for ( i = 0; i < n; i++ ) {
        scanf( "%d %d %d", &x[i], &y[i], &r[i] );
        if ( x[i] == 0 && y[i] == 0 )
            start = i;
    }

    dfs( start );

    printf( "%d %d\n", x[end], y[end] );
    fflush( stdout );

    return 0;
}
