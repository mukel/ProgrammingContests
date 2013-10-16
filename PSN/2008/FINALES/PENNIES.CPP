/*
Alfonso Alfonso Peterssen
17 - 4 - 2008
TASK: PENNIES
O( n lg n )
*/
#include <cstdio>

typedef long long int64;

int radius, pennies;
int lo, hi, mid;

bool fit( int64 x, int64 y, int64 r ) {
    return x * x + y * y <= r * r;
}

int main() {

    #warning READ FROM FILES!!!

    freopen( "pennies.in", "r", stdin );
    freopen( "pennies.out", "w", stdout );

    scanf( "%d", &radius );

    for ( int i = 0; i < radius; i++ ) {
        lo = 0;
        hi = radius;
        while ( lo <= hi ) {
            mid = ( lo + hi ) / 2;
            if ( fit( i, mid, radius ) )
                 lo = mid + 1;
            else hi = mid - 1;
        }
        pennies += lo - 1;
    }

    printf( "%d\n", pennies * 4 + 1 );
    fflush( stdout );

    return 0;
}
