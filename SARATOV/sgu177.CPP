/*
Alfonso Alfonso Peterssen
15 - 2 - 2008
Saratov #177 "Square"
*/
#include <cstdio>
#include <algorithm>

using std::swap;

const int MAXR = 5000;

int N, R, i, sol;
int x1, y1, x2, y2, color;
struct rect {
    int x1, y1, x2, y2;
    bool white;
} ls[MAXR + 1];

void paint( int x1, int y1, int x2, int y2, int id ) {
    for ( ; id <= R; id++ )
        if ( x1 < ls[id].x2 && y1 < ls[id].y2 &&
             x2 > ls[id].x1 && y2 > ls[id].y1 ) {
            if ( x1 < ls[id].x1 ) { paint( x1, y1, ls[id].x1, y2, id + 1 ); x1 = ls[id].x1; }
            if ( x2 > ls[id].x2 ) { paint( ls[id].x2, y1, x2, y2, id + 1 ); x2 = ls[id].x2; }
            if ( y1 < ls[id].y1 ) paint( x1, y1, x2, ls[id].y1, id + 1 );
            if ( y2 > ls[id].y2 ) paint( x1, ls[id].y2, x2, y2, id + 1 );
            return ;
        }
    sol += ( x2 - x1 ) * ( y2 - y1 );
}

int main() {

    scanf( "%d %d", &N, &R );
    ls[0] = ( rect ){ 0, 0, N, N, 1 /* white */ };
    for ( i = 1; i <= R; i++ ) {
        scanf( "%d %d %d %d %c", &x1, &y1, &x2, &y2, &color );
        if ( x1 > x2 ) swap( x1, x2 );
        if ( y1 > y2 ) swap( y1, y2 );
        x1--; y1--;
        ls[i] = ( rect ){ x1, y1, x2, y2, color == 'w' };
    }

    for ( i = R; i >= 0; i-- ) {
        rect r = ls[i];
        if ( r.white )
            paint( r.x1, r.y1, r.x2, r.y2, i + 1 );
    }

    printf( "%d\n", sol );

    return 0;
}
