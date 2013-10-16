/*
Alfonso2 Peterssen
CEOI 2003 "Square"
*/
#include "square_lib.h"

int N, L, value;
int dir, edge, x, y;

int main() {

    N = getN();
    L = getL();

    x = y = 1;
    for (;;) {
        if ( x == N ) break;
        edge = getWeight( x, y, 0 );
        if ( value + edge > L )
            break;
        x++;
        value += edge;
    }

    if ( value == L )
        solution( x, y );

    for (;;) {

        for (;;) {
            if ( y == N ) break;
            edge = getWeight( x, y, 1 );
            if ( value + edge > L )
                break;
            y++;
            value += edge;
        }

        if ( value == L )
            solution( x, y );

        if ( x == 1 ) solution( -1, - 1 );
        value -= getWeight( x - 1, y, 0 );
        x--;
    }

    return 0;
}
