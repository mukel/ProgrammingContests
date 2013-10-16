/*
Alfonso Alfonso Peterssen
11 - 2 - 2008
Saratov #113 "Nearly prime numbers"
*/
#include <cstdio>

int T, N, i;

    bool prime( int x ) {
        for ( int i = 2; i * i <= x; i++ )
            if ( x % i == 0 )
                return 0;
        return 1;
    }

int main() {

    scanf( "%d", &T );
    while ( T-- ) {

        scanf( "%d", &N ) ;

        if ( prime( N ) ) {
            printf( "No\n" );
            continue;
        }

        for ( i = 2; i < N; i++ )
            if ( N % i == 0 ) {
                printf( prime( N / i ) ? "Yes\n" : "No\n" );
                break;
            }
            
        if ( i >= N )
            printf( "No\n" );
    }

    return 0;
}
