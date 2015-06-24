/*
Alfonso2 Peterssen
CEOI 2006 "Meandian"
*/
#include "libmean.h"
#include <cstring>

#define FOR( i, s, e ) \
    for ( int i = (s); i <= (e); i++ )

const int
    MAXN = 200,
    oo = 1 << 30;

int N;
int lo, hi;
int s[6];
int q[6];
int sol[MAXN];

int main() {

    memset( sol, -1, sizeof( sol ) );
    N = Init();

    FOR( i, 1, 5 ) s[i] = i;
    FOR( i, 6, N + 1 ) {
        q[1] = Meandian( s[5], s[2], s[3], s[4] );
        q[2] = Meandian( s[1], s[5], s[3], s[4] );
        q[3] = Meandian( s[1], s[2], s[5], s[4] );
        q[4] = Meandian( s[1], s[2], s[3], s[5] );
        q[5] = Meandian( s[1], s[2], s[3], s[4] );
        lo = +oo;
        hi = -oo;
        FOR( j, 1, 5 ) {
            lo <?= q[j];
            hi >?= q[j];
        }
        FOR( j, 1, 5 )
           if ( q[j] != lo && q[j] != hi ) {
               sol[ s[j] ] = lo + hi - q[j];
               s[j] = i;
               break;
           }
    }

    Solution( sol + 1 );

    return 0;
}
