/*
Alfonso2 Peterssen
16 - 6 - 2008
IOI 2005 "Rectangle Game"
Simple Test Lib
*/
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>

// global
typedef enum __direction {vertical, horizontal} direction;

namespace rec { // define lib namespace

int x = -1, y = -1;

void init() {
    srand( time(0) );
    scanf( "%*d %d %d", &x, &y );
    printf( "init -> %d %d\n", x, y );
}

int dimension_x() {
    if ( x == -1 && y == -1 )
        init();
    return x;
}

int dimension_y() {
    if ( x == -1 && y == -1 )
        init();
    return y;
}

void cut( direction dir, int pos ) {

    //printf( "%s %d\n", dir == horizontal ? "H" : "V", position );

    if ( dir == horizontal ) {
        assert( pos > 0 && pos < x );
        x = pos >? x - pos;
    } else {
        assert( pos > 0 && pos < y );
        y = pos >? y - pos;
    }

    if ( x == 1 && y == 1 ) {
        printf( "You win!!!\n" );
        exit( 0 );
    }

    int a = x >? y;
    int b = x <? y;

    for ( int i = 0; b + ((b + 1) << i) < a; i++ )
        b += ((b + 1) << i);

    if ( a == b && b != x <? y ) {
        printf( "You loose!!!\n" );
        exit( 0 );
    }

    /* make my move */
    if ( y == 1 || ( x > 1 && ( rand() % 2 ) ) ) {
        int pos = rand() % ( x - 1 ) + 1;
        x = pos >? x - pos;
    } else {
        int pos = rand() % ( y - 1 ) + 1;
        y = pos >? y - pos;
    }
}

}// end rec namespace

/* public interface */
//using rec::init;
using rec::dimension_x;
using rec::dimension_y;
using rec::cut;
