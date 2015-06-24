/*
Alfonso Alfonso Peterssen
18 - 3 - 2008
USACO MAR08 Silver "The Loathesome Hay Baler"
*/
#include <cstdio>

const int MAXN = 2000;
const double EPSILON = 1e-7;

int n, i;
int xt, yt;
int start, end;
int x[MAXN], y[MAXN], r[MAXN];
bool mark[MAXN];
double sol;

template< typename T >
T sqr( const T x ) { return x * x; }

bool find( int rol, double rph ) {

    mark[rol] = true;
    if ( rol == end ) {
        sol += rph;
        return true;
    }
    
    for ( int i = 0; i < n; i++ )
        if ( !mark[i] ) {
            int dx = x[rol] - x[i];
            int dy = y[rol] - y[i];
            if ( sqr( dx ) + sqr( dy ) != sqr( r[rol] + r[i] ) )
                continue;
            if ( find( i, ( rph * r[rol] ) / r[i]  ) ) {
                sol += rph;
                return true;
            }
        }
        
    return false;
}

int main() {

    freopen( "baler.in", "r", stdin );
    freopen( "baler.out", "w", stdout );

    scanf( "%d %d %d", &n, &xt, &yt );

    for ( i = 0; i < n; i++ ) {
        scanf( "%d %d %d", &x[i], &y[i], &r[i] );
        if ( x[i] == 0 && y[i] == 0 )
            start = i;
        if ( x[i] == xt && y[i] == yt )
            end = i;
    }

    find( start, 10000. );

    printf( "%d\n", ( int )( sol + EPSILON ) );

    fflush( stdout );

    return 0;
}
