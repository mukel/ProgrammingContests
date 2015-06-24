/*
Alfonso2 Peterssen
15 - 7 - 2008
Baltic 2002 "Triangles"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int
    MAXN = 2000,
    oo = (int)1e8;

int N, E, sol;
int lo, hi, id, y;
int lastx, offset;
int idy[MAXN];
bool mark[MAXN];
struct triangle {
    int x, y, m;
} T[MAXN];
struct event {
    int id, x;
    bool operator < ( const event &e ) const { return x < e.x; }
} events[2 * MAXN];

bool cmp_Y( const int &i, const int &j ) {
    return T[i].y < T[j].y;
}

int area2( int side, int h ) {
    int area = ( 2 * side - h ) * h;
    return area >? 0;
}

int main() {

    scanf( "%d", &N );
    REP( i, N ) {
        scanf( "%d %d %d", &T[i].x, &T[i].y, &T[i].m );
        events[E++] = (event){ i, T[i].x };
        events[E++] = (event){ i, T[i].x + T[i].m };
        idy[i] = i;
    }

    sort( events, events + E );
    sort( idy, idy + N, cmp_Y );

    lastx = events[0].x;
    REP( i, E ) {

        int dx = events[i].x - lastx;
        if ( !dx )
            goto skip;

        lo = hi = -oo;
        REP( j, N ) {

            id = idy[j];
            if ( !mark[id] ) continue;

            y = T[id].y;
            offset = T[id].m - ( lastx - T[id].x );

            if ( y + offset <= hi )
                continue;

            if ( y > hi - dx ) {
                sol += area2( hi - lo, dx );
                /* check overlap */
                if ( y < hi )
                    sol -= area2( hi - y, hi - y );
                lo = y;
            }

            hi = y + offset;
        }
        sol += area2( hi - lo, dx );

        skip:;
        mark[ events[i].id ] ^= true;
        lastx = events[i].x;
    }

    printf( "%.1lf\n", sol / 2. );

    return 0;
}
