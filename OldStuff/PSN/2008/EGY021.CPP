/*
Alfonso Alfonso Peterssen
TASK: POINTS
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

typedef pair< int, int > par;

int n, i, j, k, sol;
int dx, dy, gcd;
int x[MAXN], y[MAXN];
par ls[MAXN];

int my_gcd( int a, int b ) {
    while ( a && b ) if ( a %= b ) b %= a;
    return a + b;
}

int main() {

    while ( scanf( "%d %d", &x[n], &y[n] ) )
        n++;

    for ( i = 0; i < n; i++ ) {
        for ( j = 0; j < n; j++ ) {
            dx = x[j] - x[i];
            dy = y[j] - y[i];
            gcd = my_gcd( dx, dy );
            if ( gcd )
                dx /= gcd, dy /= gcd;
            ls[j] = make_pair( dx, dy );
        }
        sort( ls, ls + n );
        for ( j = 0; j < n; j = k ) {
            for ( k = j + 1; k < n && ls[k] == ls[j]; k++ );
            sol >?= k - j + 1;
        }
    }

    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
