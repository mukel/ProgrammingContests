/*
Alfonso Alfonso Peterssen
31 - 3 - 2008
USACO MAR03 Green "Cornfields"
2D_RMQ
*/
#include <cstdio>

const int
    MAXN = 250,
    LOGN = 9,
    oo = 1000000000;

int N, B, Q, a, b, i, j;
int x, y, value;
int RMQmin[LOGN][LOGN][MAXN][MAXN];
int RMQmax[LOGN][LOGN][MAXN][MAXN];

int log2( int x ) {
    return 31 - __builtin_clz( x );
}

int query( int x1, int y1, int x2, int y2 ) {

    int lgx = log2( x2 - x1 + 1 );
    int lgy = log2( y2 - y1 + 1 );

    int lo = RMQmin[lgx][lgy][x1][y1] <?
             RMQmin[lgx][lgy][x2 - ( 1 << lgx ) + 1][y1] <?
             RMQmin[lgx][lgy][x1][y2 - ( 1 << lgy ) + 1] <?
             RMQmin[lgx][lgy][x2 - ( 1 << lgx ) + 1][y2 - ( 1 << lgy ) + 1];

    int hi = RMQmax[lgx][lgy][x1][y1] >?
             RMQmax[lgx][lgy][x2 - ( 1 << lgx ) + 1][y1] >?
             RMQmax[lgx][lgy][x1][y2 - ( 1 << lgy ) + 1] >?
             RMQmax[lgx][lgy][x2 - ( 1 << lgx ) + 1][y2 - ( 1 << lgy ) + 1];

    return hi - lo;
}

int main() {

    scanf( "%d %d %d", &N, &B, &Q );
    for ( i = 0; i < N; i++ )
        for ( j = 0; j < N; j++ ) {
            scanf( "%d", &x );
            RMQmin[0][0][i][j] = x;
            RMQmax[0][0][i][j] = x;
        }

    int lg = log2( B );
    for ( a = 0; a <= lg; a++ )
        for ( b = 0; b <= lg; b++ ) {
            if ( a == 0 && b == 0 )
                continue;
            for ( i = N - ( 1 << a ); i >= 0; i-- )
            for ( j = N - ( 1 << b ); j >= 0; j-- ) {
                value = +oo;
                if ( a ) value <?= RMQmin[a - 1][b][i][j];
                if ( b ) value <?= RMQmin[a][b - 1][i][j];
                if ( a ) value <?= RMQmin[a - 1][b][i + (1 << ( a - 1 ))][j];
                if ( b ) value <?= RMQmin[a][b - 1][i][j + (1 << ( b - 1 ))];
                if ( a && b ) value <?= RMQmin[a - 1][b - 1][i][j];
                if ( a && b ) value <?= RMQmin[a - 1][b - 1][i + (1 << ( a - 1 ))][j + (1 << ( b - 1 ))];
                RMQmin[a][b][i][j] = value;

                value = -oo;
                if ( a ) value >?= RMQmax[a - 1][b][i][j];
                if ( b ) value >?= RMQmax[a][b - 1][i][j];
                if ( a ) value >?= RMQmax[a - 1][b][i + (1 << ( a - 1 ))][j];
                if ( b ) value >?= RMQmax[a][b - 1][i][j + (1 << ( b - 1 ))];
                if ( a && b ) value >?= RMQmax[a - 1][b - 1][i][j];
                if ( a && b ) value >?= RMQmax[a - 1][b - 1][i + (1 << ( a - 1 ))][j + (1 << ( b - 1 ))];
                RMQmax[a][b][i][j] = value;
            }
        }

    while ( Q-- ) {
        scanf( "%d %d", &x, &y );
        x--; y--;
        printf( "%d\n", query( x, y, x + B - 1, y + B - 1 ) );
    }

    fflush( stdout );

    return 0;
}
