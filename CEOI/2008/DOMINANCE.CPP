/*
Alfonso2 Peterssen
14 - 7 - 2008
CEOI 2008 "Dominance"
*/
#include <iostream>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int MAXN = 7000;

int X, Y, N, E, C;
char color;
int64 x, y, d;
int64 coords[MAXN];
int cant[MAXN];
struct event {
    int64 x, lo, hi;
    char color;
    bool operator < ( const event &e ) const {
        return x < e.x;
    }
} events[MAXN];

struct kk {
    int64 odd, even;
    kk() {}
    kk( int64 odd, int64 even ) : odd( odd ), even( even ) {}
    #define KK_OPERATOR( op ) \
        kk operator op ( const kk &t ) { return kk( odd op t.odd, even op t.even ); }
    KK_OPERATOR( += );
    KK_OPERATOR( -= );
    KK_OPERATOR( * );
};

kk squares;
kk totalW, W;
kk totalB, B;

kk GetSquares( int lo, int hi ) {
    kk sq( ( hi - lo ) >> 1, ( hi - lo ) >> 1 );
    if ( ( hi - lo ) & 1 )
        (hi & 1) ? sq.odd++ : sq.even++;
    return sq;
}

int main() {

    cin >> X >> Y;
    cin >> N;
    REP( i, N ) {
        cin >> color >> x >> y >> d;
        x = x - y;
        y = x + 2 * y;
        color = ( color == 'W' ) ? +1 : -1;
        events[E++] = (event){ x - d - 1, y - d - 1, y + d, color };
        events[E++] = (event){ x + d    , y - d - 1, y + d, color * -1 };
        coords[C++] = y - d - 1;
        coords[C++] = y + d;
    }

    sort( coords, coords + C );
    C = unique( coords, coords + C ) - coords;

    sort( events, events + E );

    int64 lastx = events[0].x;
    REP( i, E ) {

        squares = GetSquares( lastx, events[i].x );
        totalW += W * squares;
        totalB += B * squares;
        lastx = events[i].x;

        color = events[i].color;
        int lo = lower_bound( coords, coords + C, events[i].lo ) - coords + 1;
        int hi = lower_bound( coords, coords + C, events[i].hi ) - coords;

        for ( int j = lo; j <= hi; j++ ) {
            squares = GetSquares( coords[j - 1], coords[j] );
            if ( cant[j] == 0 && color == +1 ) W += squares;
            if ( cant[j] == 0 && color == -1 ) B += squares;
            if ( cant[j] == +1 && color == -1 ) W -= squares;
            if ( cant[j] == -1 && color == +1 ) B -= squares;
            cant[j] += color;
        }
    }

    cout << totalW.odd + totalW.even << " "
         << totalB.odd + totalB.even << endl;

    return 0;
}
