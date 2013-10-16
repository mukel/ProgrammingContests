/*
Alfonso Alfonso Peterssen
19 - 3 - 2008
USACO MAR08 Bronze "Lake Making"
*/
#include <cstdio>

const int MAXC = 200;

#define REP( i, n ) \
    for ( i = 0; i < (n); i++ )

int f, c, n, e, sol;
int x, y, d, i, j, k;
int mat[MAXC][MAXC];

int main() {

    freopen( "makelake.in", "r", stdin );
    freopen( "makelake.out", "w", stdout );

    scanf( "%d %d %d %d", &f, &c, &e, &n );
    REP( i, f )
    REP( j, c )
        scanf( "%d", &mat[i][j] );

    REP( i, n ) {
        scanf( "%d %d %d", &x, &y, &d );
        x--; y--;
        int value = -1000000000;
        REP( j, 3 ) REP( k, 3 ) value >?= mat[x + j][y + k];
        REP( j, 3 ) REP( k, 3 ) mat[x + j][y + k] <?= value - d;
    }

    REP( i, f )
    REP( j, c )
        if ( mat[i][j] < e )
            sol += e - mat[i][j];

    printf( "%d\n", sol * 72 * 72 );

    fflush( stdout );

    return 0;
}
