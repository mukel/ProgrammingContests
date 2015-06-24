/*
Alfonso2 Peterssen
10 - 5 - 2008
IOI 2006 Task "Points"
*/
#include <cstdio>
#include <algorithm>
#include <cstdlib>

using std::swap;

const int MAXP = 100000;

typedef long long int64;

#define FILTER( piv, lo, hi, a, b, c ) \
    for ( int i = (lo); i <= (hi); i++ ) \
        if ( in_triangle( i, (a), (b), (c) ) ) \
            swap( points[i], points[piv] ), piv++;

int R, G, P;
int x, y;
struct point {
    int x, y, id, color;
} points[MAXP];

int64 area2( int a, int b, int c ) {
    return ( int64 )( points[b].x - points[a].x ) *
           ( int64 )( points[c].y - points[a].y ) -
           ( int64 )( points[c].x - points[a].x ) *
           ( int64 )( points[b].y - points[a].y );
}

bool in_triangle( int p, int a, int b, int c ) {
    return llabs( area2( p, a, b ) ) +
           llabs( area2( p, a, c ) ) +
           llabs( area2( p, b, c ) ) == llabs( area2( a, b, c ) );
}

// p1 & p2 must have the same color
void solve( int glo, int ghi, int rlo, int rhi,
            int p1, int p2, int p3 ) {
    /*
    printf( "%d%c %d%c %d%c -> %dg %dr\n",
        points[p1].id, points[p1].color ? 'r' : 'g',
        points[p2].id, points[p2].color ? 'r' : 'g',
        points[p3].id, points[p3].color ? 'r' : 'g',
        ghi - glo, rhi - rlo );
    */

    // no points in this triangle
    if ( glo > ghi && rlo > rhi ) return ;
    
    // only green points
    if ( rlo > rhi ) {
        int piv = p1;
        if ( points[piv].color == 1 ) piv = p2;
        if ( points[piv].color == 1 ) piv = p3;
        for ( int i = glo; i <= ghi; i++ )
            printf( "%d %d g\n", points[piv].id, points[i].id );
        return ;
    }
    
    // only red points
    if ( glo > ghi ) {
        int piv = p1;
        if ( points[piv].color == 0 ) piv = p2;
        if ( points[piv].color == 0 ) piv = p3;
        for ( int i = rlo; i <= rhi; i++ )
            printf( "%d %d r\n", points[piv].id, points[i].id );
        return ;
    }
    
    // green and red points
    int p4, gpiv, rpiv;
    if ( points[p3].color == 0 ) { p4 = glo; glo++; } // get random
    if ( points[p3].color == 1 ) { p4 = rlo; rlo++; } // random too
    
    printf( "%d %d %c\n", points[p4].id, points[p3].id,
                          points[p4].color ? 'r' : 'g' );

    // p1, p2, p4
    gpiv = glo; FILTER( gpiv, glo, ghi, p1, p2, p4 );
    rpiv = rlo; FILTER( rpiv, rlo, rhi, p1, p2, p4 );
    solve( glo, gpiv - 1,
           rlo, rpiv - 1,
           p1, p2, p4 );

    // p1, p4, p3
    glo = gpiv; FILTER( gpiv, glo, ghi, p1, p4, p3 );
    rlo = rpiv; FILTER( rpiv, rlo, rhi, p1, p4, p3 );
    solve( glo, gpiv - 1,
           rlo, rpiv - 1,
           p3, p4, p1 );

    // p4, p2, p3
    solve( gpiv, ghi,
           rpiv, rhi,
           p3, p4, p2 );
}

int main() {

    scanf( "%d", &G );
    for ( int i = 0; i < G; i++ ) {
        scanf( "%d %d", &x, &y );
        points[P++] = (point){ x, y, i + 1, 0 };
    }

    scanf( "%d", &R );
    for ( int i = 0; i < R; i++ ) {
        scanf( "%d %d", &x, &y );
        points[P++] = (point){ x, y, i + 1, 1 };
    }
    
    printf( "1 2 g\n" );
    printf( "1 2 r\n" );
    
    int gpiv = 2;     FILTER( gpiv, 2    , G - 1    , 0, 1, 0 + G );
    int rpiv = 2 + G; FILTER( rpiv, 2 + G, R - 1 + G, 0, 1, 0 + G );

    /*
    printf( "green points\n" );
    for ( int i = 2; i < gpiv; i++ ) printf( "%d ", points[i].id );
    printf( "\nred points\n" );
    for ( i = 2 + G; i < rpiv; i++ ) printf( "%d ", points[i].id );
    return 0;
    */
    
    solve( 2, gpiv - 1,
           2 + G, rpiv - 1,
           0, 1, 0 + G );
           
    solve( gpiv, G - 1,
           rpiv, R - 1 + G,
           0 + G, 1 + G, 1 );
           
    return 0;
}
