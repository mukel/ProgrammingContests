/*
Alfonso Alfonso Peterssen
1 - 3 - 2008
POI 2002 Stage III "Minuses"
*/
#include <cstdio>

int n, i, ch, last;

int main() {

    scanf( "%d", &n );
    for ( i = 0; i < n - 1; i++ ) {
        scanf( "%s", &ch );
        if ( ch == '+' && last == '-' ) putchar( '(' );
        if ( ch == '-' && last == '+' ) putchar( ')' );
        putchar( '-' );
        last = ch;
    }

    if ( ch == '+' )
        putchar( ')' );

    putchar( '\n' );

    return 0;
}
