/*
Alfonso Alfonso Peterssen
4 - 3 - 2008
POI 2001 Stage I "Antiprime Numbers"
*/
#include <cstdio>

const int MAXP = 8;
const int prime[MAXP] =
    { 2, 3, 5, 7, 11, 13, 17, 19 };

int n, sol, max_div;

void comb( long long value, int div, int p ) {
    if ( p >= MAXP ) {
    if ( div > max_div || ( div == max_div && value < sol ) ) {
        max_div = div;
        sol = value;
    } return ; }
    int i = 1;
    while ( value <= n ) {
        comb( value, div * i, p + 1 );
        value *= prime[p];
        i++;
    }
}

int main() {
    scanf( "%d", &n );
    comb( 1, 1, 0 );
    printf( "%d\n", sol );
    return 0;
}
