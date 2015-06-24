/*
Alfonso Alfonso Peterssen
4 - 3 - 2008
SPOJ #176 "Sum of one-sequence"
Fucking O( n )
*/
#include <cstdio>
#include <algorithm>

using std::abs;

int T, n, target, i;

    int sum( int x ) {
        return x * ( x - 1 ) / 2 ;
    }

int main() {

    scanf( "%d", &T );
    while ( T-- ) {

        scanf( "%d %d", &n, &target );

        if ( abs( target ) > sum( n ) || // check range
           ( abs( target ) & 1 ) != ( sum( n ) & 1 ) ) { // check parity
            printf( "No\n" );
            continue;
        }

        i = 0;
        while ( n-- ) {
            printf( "%d\n", i );
            if ( target + n > sum( n ) )
                 target -= n, i++;
            else target += n, i--;
        }
    }

    return 0;
}
