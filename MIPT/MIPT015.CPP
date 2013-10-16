/*
Alfonso2 Peterssen
18 - 7 - 2008
MIPT #015 "One rectangle"
*/
#include <cstdio>
#include <algorithm>

using std::sort;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 200;

int N, sol;
struct point {
    int x, y;
    bool operator < ( const point &p ) const { return x < p.x; }
} P[MAXN];

int main() {

    scanf( "%d", &N );
    REP( i, N )
        scanf( "%d %d", &P[i].x, &P[i].y );

    // sentinels
    P[N++] = (point){ 0, 0 };
    P[N++] = (point){ 100, 100 };

    sort( P, P + N );

    REP( i, N )
    REP( j, N ) {
        int delta = P[j].y - P[i].y;
        if ( delta > 0 ) {
            int lastx = 0;
            REP( k, N )
                if ( P[k].y < P[j].y && P[k].y > P[i].y ) {
                     sol >?= ( P[k].x - lastx ) * delta;
                     lastx = P[k].x;
                }
            sol >?= ( 100 - lastx ) * delta;
        }
    }

    printf( "%d\n", sol );

    return 0;
}
