/*
Alfonso2 Peterssen
11 - 6 - 2008
IOI 2002 "Two Rods"
See IOI 2007 Aliens
*/
#include "rods.h"
#include <algorithm>

using std::swap;

int N;
int x1, x2, y1, y2;
int c1, c2, c3, c4;
int dx, dy;
int sum;

int my_rect( int x1, int y1, int x2, int y2 ) {
    if ( x1 > x2 ) swap( x1, x2 );
    if ( y1 > y2 ) swap( y1, y2 );
    x1 >?= 1; x2 <?= N;
    y1 >?= 1; y2 <?= N;
    return rect( x1, y1, x2, y2 );
}

/* All-in-one BS */
int bsearch( int x, int y, int dx, int dy, int offx = 0, int offy = 0 ) {

    int lo = 0;
    int hi = N;
    while ( lo <= hi ) {
        int mid = ( lo + hi ) / 2;
        if ( my_rect( x + offx, y + offy,
                      x + dx * mid, y + dy * mid ) == 1 )
             hi = mid - 1;
        else lo = mid + 1;
    }

    return hi + 1;
}

int main() {

    N = gridsize();

    x1 = 1 + bsearch( 1, 1, +1, 0, 0, +N );
    y1 = 1 + bsearch( 1, 1, 0, +1, +N, 0 );
    x2 = N - bsearch( N, N, -1, 0, 0, -N );
    y2 = N - bsearch( N, N, 0, -1, -N, 0 );

    c1 = rect( x1, y1, x1, y1 );
    c2 = rect( x1, y2, x1, y2 );
    c3 = rect( x2, y2, x2, y2 );
    c4 = rect( x2, y1, x2, y1 );
    sum = c1 + c2 + c3 + c4;

    if ( sum == 0 ) {
        dx = bsearch( x1, y1, +1, 0 );
        dy = bsearch( x1, y1, 0, +1 );
        report( x1 + dx, y1, x1 + dx, y2, x1, y1 + dy, x2, y1 + dy );
    }

    if ( sum == 2 ) {
        if ( c1 && c2 ) {
            dy = bsearch( x2, y1, 0, +1 );
            dx = bsearch( x1 + 1, y1 + dy, +1, 0 ); dx += ( dx != 0 );
            report( x1, y1, x1, y2, x1 + dx, y1 + dy, x2, y1 + dy );
        }
        if ( c2 && c3 ) {
            dx = bsearch( x1, y1, +1, 0 );
            dy = bsearch( x1 + dx, y2 - 1, 0, -1 ); dy += ( dy != 0 );
            report( x1 + dx, y1, x1 + dx, y2 - dy, x1, y2, x2, y2 );
        }
        if ( c3 && c4 ) {
            dy = bsearch( x1, y1, 0, +1 );
            dx = bsearch( x2 - 1, y1 + dy, -1, 0 ); dx += ( dx != 0 );
            report( x2, y1, x2, y2, x1, y1 + dy, x2 - dx, y1 + dy );
        }
        if ( c4 && c1 ) {
            dx = bsearch( x1, y2, +1, 0 );
            dy = bsearch( x1 + dx, y1 + 1, 0, +1 ); dy += ( dy != 0 );
            report( x1 + dx, y1 + dy, x1 + dx, y2, x1, y1, x2, y1 );
        }
        if ( c1 && c3 )
            if ( rect( x1 + 1, y1, x1 + 1, y1 ) ) {
                dx = bsearch( x2, y1, -1, 0 );
                dy = bsearch( x2, y1, 0, +1 );
                report( x2, y1 + dy, x2, y2, x1, y1, x2 - dx, y1 );
            } else {
                dx = bsearch( x1, y2, +1, 0 );
                dy = bsearch( x1, y2, 0, -1 );
                report( x1, y1, x1, y2 - dy, x1 + dx, y2, x2, y2 );
            }
        if ( c2 && c4 )
            if ( rect( x1 + 1, y2, x1 + 1, y2 ) ) {
                dx = bsearch( x2, y2, -1, 0 );
                dy = bsearch( x2, y2, 0, -1 );
                report( x2, y1, x2, y2 - dy, x1, y2, x2 - dx, y2 );
            } else {
                dx = bsearch( x1, y1, +1, 0 );
                dy = bsearch( x1, y1, 0, +1 );
                report( x1, y1 + dy, x1, y2, x1 + dx, y1, x2, y1 );
            }
    }

    if ( sum == 3 ) {
        if ( !c1 ) {
            dx = bsearch( x2 - 1, y2, -1, 0 ); dx += ( dx != 0 );
            dy = bsearch( x2, y2 - 1, 0, -1 ); dy += ( dy != 0 );
            report( x2, y1, x2, y2 - dy, x1, y2,  x2 - dx, y2 );
        }
        if ( !c2 ) {
            dx = bsearch( x2 - 1, y1, -1, 0 ); dx += ( dx != 0 );
            dy = bsearch( x2, y1 + 1, 0, +1 ); dy += ( dy != 0 );
            report( x2, y1 + dy, x2, y2, x1, y1, x2 - dx, y1 );
        }
        if ( !c3 ) {
            dx = bsearch( x1 + 1, y1, +1, 0 ); dx += ( dx != 0 );
            dy = bsearch( x1, y1 + 1, 0, +1 ); dy += ( dy != 0 );
            report( x1, y1 + dy, x1, y2, x1 + dx, y1, x2, y1 );
        }
        if ( !c4 ) {
            dx = bsearch( x1 + 1, y2, +1, 0 ); dx += ( dx != 0 );
            dy = bsearch( x1, y2 - 1, 0, -1 ); dy += ( dy != 0 );
            report( x1, y1, x1, y2 - dy, x1 + dx, y2, x2, y2 );
        }
    }

    return 0;
}
