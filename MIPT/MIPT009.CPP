/*
Alfonso Alfonso Peterssen
5 - 2 - 2008
MIPT #009 "Fibonacci numbers"
*/
#include <cstdio>

const int
    MAXLEN = 100000,
    BASE = 100000000;

int n, i;
struct bigint {
    int len, digit[MAXLEN];
    void operator += ( const bigint &x ) {
        int r = 0, t;
        len >?= x.len;
        for ( int i = 0; i < len; i++ ) {
            t = digit[i] + x.digit[i] + r;
            digit[i] = t % BASE;
            r = t / BASE;
        }
        for ( ; r; r /= BASE )
            digit[len++] = r % BASE;
    }
} fib[2];

int main() {

    scanf( "%d", &n );

    fib[0].len = 1;
    fib[0].digit[0] = 1;
    
    for ( i = 1; i <= n; i++ )
        fib[i & 1] += fib[!(i & 1)];
        
    printf( "%d", fib[n & 1].digit[ fib[n & 1].len - 1 ] );
    for ( i = fib[n & 1].len - 2; i >= 0; i-- )
        printf( "%08d", fib[n & 1].digit[i] );  // Shift 0s
        
    printf( "\n" );

    return 0;
}
