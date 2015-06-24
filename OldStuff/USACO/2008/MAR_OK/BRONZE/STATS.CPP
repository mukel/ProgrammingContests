/*
Alfonso Alfonso Peterssen
19 - 3 - 2008
USACO MAR08 Bronze "Statistics"
*/
#include <cstdio>
#include <algorithm>

using std::sort;

const int MAXN = 100000;

int n, i, j;
int s[MAXN];
double a, b;

int main() {

    freopen( "stats.in", "r", stdin );
    freopen( "stats.out", "w", stdout );

    scanf( "%d", &n );
    for ( i = 0; i < n; i++ ) {
        scanf( "%d", &s[i] );
        a += s[i];
    }

    sort( s, s + n );
    a /= n;
    b = s[n / 2];
    if ( !(n & 1) ) b = ( b + s[n / 2 - 1] ) /2.;

    printf( "%lf\n%lf\n", a, b );

    fflush( stdout );

    return 0;
}
