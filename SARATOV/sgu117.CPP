/*
Alfonso Alfonso Peterssen
3 - 2 - 2008
Saratov #117 "Counting"
*/
#include <cstdio>

int N, M, K, x, sol;

    int power( int x, int n, int MOD ) {
        int p = 1;
        for ( ; n; n /= 2 ) {
            if ( n & 1 )
                p = ( p * x ) % MOD;
            x = ( x * x ) % MOD;
        }
        return p;
    }

int main() {

    scanf( "%d %d %d", &N, &M, &K );
    while ( N-- ) {
        scanf( "%d", &x );
        if ( power( x, M, K ) == 0 )
            sol++;
    }

    printf( "%d\n", sol );

    return 0;
}
