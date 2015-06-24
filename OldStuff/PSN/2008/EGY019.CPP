/*
Alfonso Alfonso Peterssen
5 - 3 - 2008
PSN 2008 #19 "Suburbios"
*/
#include <cstdio>
#include <cmath>

int n, k, i;
double digits;

int main() {
    scanf( "%d %d", &n, &k );
    for ( i = k + 1; i <= n; i++ )
        sol += log10( i );
    for ( i = 2; i <= n - k; i++ )
        sol -= log10( i );
    printf( "%.0lf\n", ceil( sol + 1e-8 ) );
    return 0;
}
