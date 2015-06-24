/*
Alfonso2 Peterssen
16 - 6 - 2008
IOI 2005 "Rectangle Game"
*/
#include "rec.h"
#include <algorithm>
using std::swap;

int x, y;

int main() {

    for (;;) {
        direction dir = horizontal;
        x = dimension_x();
        y = dimension_y();
        if ( y > x ) { swap( x, y ); dir = vertical; }
        for ( int i = 0; y + ((y + 1) << i) < x; i++ )
            y += ((y + 1) << i);
        cut( dir, y );
    }

    return 0;
}
