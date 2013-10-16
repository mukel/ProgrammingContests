/*
Alfonso Alfonso Peterssen
11 - 2 - 2008
Saratov #123 "The sum"
*/
#include <cstdio>

int n, i;
int fib[50];

int main() {

    scanf( "%d", &n );
    
    fib[1] = 1;
    for ( i = 2; i <= n + 2; i++ )
        fib[i] = fib[i - 1] + fib[i - 2];

    printf( "%d\n", fib[n + 2] - 1 );

    return 0;
}
