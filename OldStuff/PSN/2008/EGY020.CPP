/*
Alfonso Alfonso Peterssen
TASK: HIDE
*/
#include <cstdio>
#include <cstring>

const int MAXLEN = 2000000;

int len, i, j;
int delta, digit, carry;
char number[MAXLEN];

int main() {

    gets( number );
    len = strlen( number );

    for ( i = 0; i < len; i++ ) {
        number[i] -= '0';
        if ( i & 1 )
             delta -= number[i];
        else delta += number[i];
    }

    carry = ( delta % 11 + 11 ) % 11;
    if ( carry == 0 | carry == 10 ) {
        printf( "IMPOSSIBLE\n" );
        fflush( stdout );
        return 0;
    }

    for ( i = j = 0; i < len; i++ ) {
        if ( carry < 11 )
            carry = carry * 10 + number[j++];
        digit = carry / 11;
        carry -= 11 * digit;
        putchar( digit + '0' );
    }

    printf( "\n" );
    fflush( stdout );

    return 0;
}
