/*
Alfonso Alfonso Peterssen
4 - 3 - 2008
Saratov #107 "987654321 problem"
*/
#include <cstdio>

int n;

int main() {

    scanf( "%d", &n );
    if ( n < 9 )
        printf( "0\n" );
    else if ( n == 9 )
        printf( "8\n" );
    else {
        printf( "72" );
        for ( n -= 10; n > 0; n-- )
            putchar( '0' );
        printf( "\n" );
    }

    return 0;
}
