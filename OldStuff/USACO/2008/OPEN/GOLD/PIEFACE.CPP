/*
Alfonso2 Peterssen
5 - 6 - 2008
USACO OPEN08 Gold "The Ultimate Battle"
*/
#include "pieface_lib.h"
#include <cstdio>
#include <algorithm>

using std::abs;

/*
// Test Interface
void MoveBessie( int x, int y ) { printf( " -> %d %d\n", x, y ); }
void Canmuu( int *x, int *y ) { scanf( "%d %d", x, y ); }
*/

int sign( int x ) { return ( x > 0 ) - ( x < 0 ); }

int main() {

    freopen( "pieface.in", "r", stdin );

    int F, C;
    int x1, y1, x2, y2;
    int dx, dy;

    init();
    scanf( "%d %d %d %d %d %d", &F, &C, &x1, &y1, &x2, &y2 );
    
    for (;;) {
        dx = abs( x1 - x2 );
        dy = abs( y1 - y2 );
        if ( dx > dy )
             x1 = x2 + dy * sign( x1 - x2 );
        else y1 = y2 + dx * sign( y1 - y2 );
        MoveBessie( x1, y1 );
        Canmuu( &x2, &y2 );
    }

    return 0;
}
