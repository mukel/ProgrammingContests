/*
Alfonso Alfonso Peterssen
4 - 3 - 2008
POI 2001 Stage I "Map"
*/
#include <cstdio>

const int MAXN = 300;

#define FOR( i, s, e ) \
     for ( i = (s); i <= (e); i++ )

int n, r, i, j, x;
int x1, y1, x2, y2;
int T[MAXN][MAXN];

int main() {

    scanf( "%d %d", &n, &r );
    FOR( i, 1, n )
        FOR( j, 1, n ) {
            scanf( "%d", &T[i][j] );
            T[i][j] += T[i - 1][j] + T[i][j - 1] - T[i - 1][j - 1];
        }

    FOR( i, 1, n )
        FOR( j, 1, n ) {
            x1 = ( 1 >? i - r ); y1 = ( 1 >? j - r );
            x2 = ( n <? i + r ); y2 = ( n <? j + r );
            x = T[x2][y2] - T[x1 - 1][y2] - T[x2][y1 - 1] + T[x1 - 1][y1 - 1];
            printf( j < n ? "%d " : "%d\n", x );
        }

    return 0;
}
