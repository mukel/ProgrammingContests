/*
Alfonso2 Peterssen
19 - 6 - 2008
BalticOI 2003 "Lamps"
*/
#include <cstdio>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 1000000;

int N, M;
int seq[2][MAXN];
int next, last;

int main() {

    scanf( "%d %d", &N, &M );
    REP( i, N )
        scanf( "%d", &seq[next][i] );

    while ( M ) {
        last = next;
        next = 1 - next;
        int pow2 = 1 << ( 31 - __builtin_clz( M ) );
        REP( i, N )
            seq[next][i] = seq[last][i] ^ seq[last][(i + pow2) % N];
        M -= pow2;
    }

    REP( i, N )
        printf( "%d\n", seq[next][i] );

    return 0;
}
