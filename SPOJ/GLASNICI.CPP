/*
Alfonso2 Peterssen
6 - 7 - 2008
SPOJ #2715 "Glasnici"
O( n )
O( 1 ) space
*/
#include <cstdio>
#include <algorithm>

using std::swap;

int T, N;
double x, y;
double delta, cost, target;

int main() {
    scanf( "%d", &T );
    while ( T-- ) {
        cost = 0;
        scanf( "%lf %d", &delta, &N );
        for ( int i = 0; i < N; i++ ) {
            swap( x, y );
            scanf( "%lf", &x );
            if ( !i )
                continue;
            y += delta;
            if ( x > y )
                if ( x - y > cost ) {
                    x -= cost;
                    double d = ( x - y ) / 2.;
                    x -= d;
                    cost += d;
                }
                else
                    x = y;
            else
                x = y <? x + cost;
        }
        printf( "%lf\n", cost );
    }

    return 0;
}
