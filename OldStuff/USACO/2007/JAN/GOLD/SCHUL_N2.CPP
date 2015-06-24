/*
Alfonso2 Peterssen
6 - 5 - 2008
TASK: SCHUL
O( n^2 )
*/
#include <cstdio>
#include <algorithm>
#include <complex>

using namespace std;

#define X( p ) real(p)
#define Y( p ) imag(p)

typedef complex< int > point;

const int
    MAXN = 50000,
    oo = 1 << 29;

int N, P, T, cant;
int i, j;
double lo, hi, score;
int ans[MAXN];
point test[MAXN];

bool slope_cmp( const point &a, const point &b ) {
    return imag( conj( a ) * b ) < 0;
}

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d", &X( test[i] ), &Y( test[i] ) );
        P += X( test[i] );
        T += Y( test[i] );
    }

    sort( test, test + N, slope_cmp );

    for ( i = 0; i < N - 1; i++ ) {
        lo = +oo;
        hi = -oo;
        P -= X( test[i] );
        T -= Y( test[i] );
        score = (double)P / T;
        for ( j = 0; j <= i; j++ )
            hi >?= X( test[j] ) - score * Y( test[j] );
        for ( j = i + 1; j < N; j++ )
            lo <?= X( test[j] ) - score * Y( test[j] );
        if ( lo < hi )
            ans[cant++] = i + 1;
    }
    
    printf( "%d\n", cant );
    for ( i = 0; i < cant; i++ )
        printf( "%d\n", ans[i] );

    return 0;
}
