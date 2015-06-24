/*
Alfonso Alfonso Peterssen
2 - 2 - 2008
MIPT #105 "MRQ problem"
*/
#include <cstdio>

const int
    MAXN = 250000,
    MAXLOG = 19;

int N, Q, i, j, lo, hi, lg;
double ls[MAXN];
int RMQ[MAXLOG][MAXN];

    int hibit( int x ) {
        return 31 - __builtin_clz( x );
    }

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%lf", &ls[i] );
        RMQ[0][i] = i;
    }
    
    lg = hibit( N );
    for ( i = 1; i <= lg; i++ )
        for ( j = N - ( 1 << i ) + 1; j >= 0; j-- ) {
            lo = RMQ[i - 1][j];
            hi = RMQ[i - 1][j + (1 << ( i - 1 ))];
            RMQ[i][j] = ls[lo] < ls[hi] ? lo : hi;
        }

    scanf( "%d", &Q );
    while ( Q-- ) {
        scanf( "%d %d", &lo, &hi );
        hi--;
        lg = hibit( hi - lo + 1 );
        lo = RMQ[lg][lo];
        hi = RMQ[lg][hi - ( 1 << lg ) + 1];
        printf( "%lf\n", ls[lo] <? ls[hi] );
    }

    return 0;
}
