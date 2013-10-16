/*
Alfonso Alfonso Peterssen
24 - 11 - 2007
COCI 2007 Contest 2 "TURBO"
*/
#include <cstdio>
#include <algorithm>

const int MAXN = 100000;

int N, i, j, x, number;
int pos[MAXN + 1];

struct fenwick_tree {

    int T[MAXN + 1];

    int lobit( int x ) { return x & -x; }

    void update( int x, int amount ) {
        for ( ; x <= N; x += lobit( x ) )
            T[x] += amount;
    }

    int sum( int x ) {
        int res = 0;
        for ( ; x > 0; x -= lobit( x ) )
            res += T[x];
        return res;
    }

} ABI;

int main() {

    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ ) {
        scanf( "%d", &j );
        pos[j] = i;
        ABI.update( i, 1 );
    }

    for ( i = 1; i <= N; i++ ) {

        if ( i & 1 )
             number = i / 2 + 1;
        else number = N - i / 2 + 1;

        x = ABI.sum( pos[number] );

        printf( "%d\n", abs( x - number ) );

        if ( x != number ) {
            ABI.update( pos[number], -1 );
            if ( x > number )
                ABI.update( 1, 1 );
        }
    }

    return 0;
}
