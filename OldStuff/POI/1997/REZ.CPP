/*
Alfonso2 Peterssen
12 - 5 - 2008
POI 1997 Stage III "Lecture halls reservation"
O( n lg n )
*/
#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

const int
    MAXN = 20000,
    oo = 1 << 30;

int N;
int dp[MAXN];
struct lecture {
    int lo, hi;
    bool operator < ( const lecture &l ) const {
        if ( hi != l.hi ) return hi < l.hi;
        return lo > l.lo;
    }
} lec[MAXN];

int bsrch( int id ) {
    return lower_bound( lec, lec + id,
           (lecture){ oo, lec[id].lo + 1 } ) - lec - 1;
}

int main() {

    scanf( "%d", &N );
    for ( int i = 1; i <= N; i++ )
        scanf( "%d %d", &lec[i].lo, &lec[i].hi );

    lec[0] = (lecture) { -1, -1 }; // sentinel
    sort( lec, lec + N + 1 );
    for ( int i = 1; i <= N; i++ )
        dp[i] = dp[i - 1] >?
                dp[ bsrch( i ) ] + ( lec[i].hi - lec[i].lo );

    printf( "%d\n", dp[N] );

    return 0;
}
