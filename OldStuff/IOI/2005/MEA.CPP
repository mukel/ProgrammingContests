 /*
Alfonso2 Peterssen
15 - 6 - 2008
IOI 205 "Mean Sequence"
Very Easy!!!
*/
#include <cstdio>
const int oo = 1 << 30;
int N, x, lo, hi, kk;
int main() {
    lo = -oo;
    hi = +oo;
    for ( scanf( "%d", &N ); N && lo <= hi; N-- ) {
        scanf( "%d", &x );
        if ( N & 1 )
             lo >?= kk - x;
        else hi <?= x - kk;
        kk = 2 * x - kk;
    }
    printf( "%d\n", N ? 0 : hi - lo + 1 );
    return 0;
}
