/*
Alfonso2 Peterssen
11 - 6 - 2008
Simple test lib
#include "rods.h"
*/
#include <cstdio>
#include <cstdlib>

namespace rods { // define library namespace

int N;
int queries;
int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;

int gridsize() {
    scanf( "%d", &N );
    scanf( "%d %d %d %d", &ax1, &ay1, &ax2, &ay2 );
    scanf( "%d %d %d %d", &bx1, &by1, &bx2, &by2 );
    return N;
}

int rect( int x1, int y1, int x2, int y2 ) {
    queries++;
    int ans = 0;
    if ( ax1 <= x2 && ax2 >= x1 && ay1 <= y2 && ay2 >= y1 ) ans = 1;
    if ( bx1 <= x2 && bx2 >= x1 && by1 <= y2 && by2 >= y1 ) ans = 1;
    //printf( "rect( %d, %d, %d, %d ) = %d\n", x1, y1, x2, y2, ans );
    return ans;
}

void report( int r1, int c1, int r2, int c2, int p1, int q1, int p2, int q2 ) {
    //printf( "%d %d %d %d\n%d %d %d %d\n", r1, c1, r2, c2, p1, q1, p2, q2 );
    if ( r1 == ax1 && c1 == ay1 && r2 == ax2 && c2 == ay2 &&
         p1 == bx1 && q1 == by1 && p2 == bx2 && q2 == by2 )
         printf( "OK!!!" );
    else printf( "Wrong!!!" );
    printf( " -> using %d queries\n", queries );
    exit( 0 );
}

} // end namespace

/* public interface */
using rods::gridsize;
using rods::rect;
using rods::report;
