/*
Alfonso2 Peterssen
21 - 6 - 2008
BalticOI 2002 "Moving Robots"
*/
#include <iostream>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )
#define FOR( i, s, e ) \
    for ( int i = (s); i <= (e); i++ )

const int
    MAXR = 10,
    MAXC = 60,
    oo = 1 << 29;

const int mov[4][2] =
    {{1,0},{0,1},{-1,0},{0,-1}};

int R, C;
int dir;
char op;
int next, last;
int sol, solx, soly;
int X[MAXR];
int Y[MAXR];

int __best[2][MAXR][2 * MAXC + 1][2 * MAXC + 1][4];
#define best( l, i, x, y, d ) \
    __best[l][i][(x) + MAXC][(y) + MAXC][d]

int main() {

    cin >> R;
    REP( i, R ) {

        cin >> X[i] >> Y[i] >> dir >> C;
        dir /= 90;

        next = C & 1; // make final state 0

        FOR( x, -MAXC, +MAXC )
        FOR( y, -MAXC, +MAXC )
            REP( d, 4 )
                best( next, i, x, y, d ) = oo;

        best( next, i, 0, 0, dir ) = 0;

        /* Initial DP */
        REP( j, C ) {

            last = next;
            next = 1 - next;

            cin >> op;
            if ( op == 'S' ) {
                FOR( x, -MAXC, +MAXC )
                FOR( y, -MAXC, +MAXC )
                    REP( d, 4 ) {
                        best( next, i, x, y, d ) = best( last, i, x, y, d ) + 1;
                        int lastx = x - mov[d][0];
                        int lasty = y - mov[d][1];
                        if ( lastx >= -MAXC && lastx <= +MAXC &&
                             lasty >= -MAXC && lasty <= +MAXC )
                             best( next, i, x, y, d ) <?= best( last, i, lastx, lasty, d );
                    }
            }

            if ( op == 'T' ) {
                cin >> dir;
                dir = 4 - dir / 90;
                FOR( x, -MAXC, +MAXC )
                FOR( y, -MAXC, +MAXC )
                    REP( d, 4 )
                        best( next, i, x, y, d ) =
                            best( last, i, x, y, (d+dir)%4 ) <?
                            best( last, i, x, y, d ) + 1;
            }
        }
    }

    /* Main DP */
    sol = oo;
    FOR( x, -MAXC, +MAXC )
    FOR( y, -MAXC, +MAXC ) {
        int sum = 0;
        REP( i, R ) {

            int dx = X[0] - X[i] + x;
            int dy = Y[0] - Y[i] + y;

            if ( dx < -MAXC || dx > +MAXC ||
                 dy < -MAXC || dy > +MAXC )
                 break;

            sum += best( 0, i, dx, dy, 0 ) <?
                   best( 0, i, dx, dy, 1 ) <?
                   best( 0, i, dx, dy, 2 ) <?
                   best( 0, i, dx, dy, 3 );

            if ( sum >= oo )
                break;

            if ( i == R - 1 && sum < sol ) {
                sol = sum;
                solx = X[0] + x;
                soly = Y[0] + y;
            }
        }
    }

    if ( sol == oo )
        printf( "-1\n" );
    else {
        printf( "%d\n", sol );
        printf( "%d %d\n", solx, soly );
    }

    return 0;
}
