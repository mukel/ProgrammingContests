/*
Alfonso Alfonso Peterssen
9 - 4 - 2008
TASK: SMRTFUN
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXN = 100,
    MAXC = 100001,
    oo = 1000000000;

int N, i, j, sol;
int S[MAXN];
int F[MAXN];
int _dp1[3 * MAXC];
int _dp2[3 * MAXC];
int *last = _dp1 + MAXC;
int *next = _dp2 + MAXC;

int main() {

    #warning READ FROM FILES!!!!

    freopen( "smrtfun.in", "r", stdin );
    freopen( "smrtfun.out", "w", stdout );


    scanf( "%d", &N );
    for ( i = 0; i < N; i++ )
        scanf( "%d %d", &S[i], &F[i] );

    fill( next - MAXC, next + MAXC, -oo );
    next[0] = 0;

    for ( i = 0; i < N; i++ ) {
        swap( last, next );
        for ( j = MAXC - 1; j > -MAXC; j-- )
            next[j] = last[j];
        for ( j = MAXC - 1; j > -MAXC; j-- ) {
            if ( j - S[i] > -MAXC &&
                 j - S[i] < +MAXC &&
                 last[ j - S[i] ] != -oo )
                 next[j] >?= last[ j - S[i] ] + F[i];
        }
    }

    sol = 0;
    for ( i = 0; i < MAXC; i++ )
        if ( next[i] >= 0 )
            sol >?= next[i] + i;

    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
