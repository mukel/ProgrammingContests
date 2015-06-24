/*
Alfonso Alfonso Peterssen
11 - 2 - 2008
Saratov #105 "Div 3"
*/
#include <cstdio>

int main() {

    int n;
    scanf( "%d", &n );
    printf( "%d\n", n / 3 * 2 + ( n % 3 == 2 ) );

    return 0;
}
