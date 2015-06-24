/*
Alfonso Alfonso Peterssen
6 - 3 - 2008
IOI 2007 Day 1 Task 1 "Aliens"
My own lib -> #include "aliens.h" -> and solve it
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>

namespace aliens { // define library namespace

using std::abs;

const int MAXQUERIES = 300;

typedef long long int64;

int N, startX, startY;
int size;
int centerX, centerY;
int queries;

void raise_error( char *error_msg ) {
    printf( error_msg );
    exit( 0 ); // suicide
}

void check_range( int64 value, int64 lo, int64 hi ) {
    if ( value < lo || value > hi )
        raise_error( "Wrong!!! -> Range Overflow\n" );
}

bool examine( int64 x, int64 y ) {
    queries++;
    if ( queries > MAXQUERIES )
        raise_error( "Wrong!!! -> Too much queries.\n" );

    check_range( x, 1, N );
    check_range( y, 1, N );

    int diffX = abs( x - centerX );
    int diffY = abs( y - centerY );

    diffX -= size / 2 + 1;
    diffY -= size / 2 + 1;

    int parity = diffX / size + diffY / size;
    parity += ( diffX < 0 );
    parity += ( diffY < 0 );
    parity &= 1;

    if ( parity )
        return false;

    int64 limit = 2 * size;
    if ( diffX >= limit || diffY >= limit )
        return false;

    return true;
}

void solution( int64 x, int64 y ) {
    if ( x != centerX || y != centerY )
        raise_error( "Wrong!!! -> Wrong Answer\n" );
    printf( "OK!!! -> using %d queries\n", queries );
}

void init( int &n, int &x, int &y ) {
    scanf( "%d %d", &N, &size );
    scanf( "%d %d", &startX, &startY );
    scanf( "%d %d", &centerX, &centerY );
    n = N;
    x = startX;
    y = startY;
}

} // end namespace aliens

/* public interface */
using aliens::init;
using aliens::examine;
using aliens::solution;
