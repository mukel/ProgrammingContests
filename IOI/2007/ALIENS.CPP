/*
Alfonso Alfonso Peterssen
6 - 3 - 2008
IOI 2007 Day 1 Task 1 "Aliens"
*/
#include "aliens.h"

typedef long long int64;

int n, m, x, y;
int lo, hi;

bool query( int64 x, int64 y ) {
    if ( x <= 0 || x > n || y <= 0 || y > n )
         return 0;
    return examine( x, y );
}

int find( int64 x, int64 y, int64 dx, int64 dy ) {

    int delta = 1;
    while ( query( x + dx * delta, y + dy * delta ) )
        delta *= 2;

    int64 lo = delta / 2;
    int64 hi = delta;
    while ( lo <= hi ) {
        int64 mid = ( lo + hi ) / 2;
        if ( query( x + dx * mid, y + dy * mid ) )
             lo = mid + 1;
        else hi = mid - 1;
    }

    return lo - 1;
}

int main() {

    init( n, x, y );

    lo = find( x, y, 0, -1 );
    hi = find( x, y, 0, +1 );
    x -= find( x, y, -1, 0 );
    y -= lo;

    m = lo + hi + 1;
    while ( query( x - 2 * m, y ) ) x -= 2 * m;
    while ( query( x, y - 2 * m ) ) y -= 2 * m;
    while ( query( x - m, y - m ) )
        x -= m, y -= m;

    x += m / 2 + 2 * m;
    y += m / 2 + 2 * m;

    solution( x, y );

    return 0;
}
