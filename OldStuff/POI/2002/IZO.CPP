/*
Alfonso Alfonso Peterssen
29 - 2 - 2008
POI 2002 Stage II "Insulator"
*/
#include <cstdio>
#include <algorithm>

using std::sort;

const int MAXN = 100000;

int n, i, sol;
int s[MAXN];

int main() {

    scanf( "%d", &n );
    for ( i = 0; i < n; i++ )
        scanf( "%d", s + i );

    sort( s, s + n );

    for ( i = 0; i < n / 2; i++ )
        sol += 2 * s[n - i - 1];

    if ( n & 1 )
        sol += s[n / 2];

    printf( "%d\n", sol );

    return 0;
}
