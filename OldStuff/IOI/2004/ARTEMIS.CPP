/*
Alfonso2 Peterssen
14 - 6 - 2008
IOI 2004 "Artemis"
*/
#include <cstdio>
#include <algorithm>

using std::sort;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 20000;

int N, T, sol;
int t1, t2;
int value, cant;
int loY[MAXN];
int dom[MAXN];
struct point {
    int x, y, id;
    bool operator < ( const point &p ) const {
        return x != p.x ? x < p.x : y < p.y;
    }
} P[MAXN];

int main() {

    scanf( "%d %d", &N, &T );
    REP( i, N ) {
        scanf( "%d %d", &P[i].x, &P[i].y );
        P[i].id = i;
    }

    sort( P, P + N );

    sol = N + 1;
    REP( i, N ) {
        loY[i] = i;
        REP( j, i )
            if ( P[j].y > P[i].y ) {
                loY[j]++;
                loY[i]--;
            }
        dom[i] = loY[i];

        cant = 0;
        int limit = i - T + 2;
        REP( j, limit ) {
            value = abs( dom[i] - loY[j] - cant + dom[j] ) + 1;
            if ( value >= T && value < sol ) {
                sol = value;
                t1 = P[i].id + 1;
                t2 = P[j].id + 1;
            }
            if ( P[j].y < P[i].y )
                cant++;
        }

        if ( sol == T )
            break;
    }

    printf( "%d %d\n", t1, t2 );

    return 0;
}
