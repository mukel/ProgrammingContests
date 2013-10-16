/*
Alfonso Alfonso Peterssen
24 - 11 - 2007
SPOJ # "Tin Cutter"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define valid( x, y ) \
    ( ( x ) >= 0 && ( x ) <= max_x && \
      ( y ) >= 0 && ( y ) <= max_y )

const int
    MAXN = 200,
    mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int N, i, j, sol;
int max_x, max_y;
int x[MAXN], y[MAXN];
int nx[MAXN], ny[MAXN];
int ls[MAXN];
bool mark[ 3 * MAXN ][ 3 * MAXN ];

    bool by_X( const int &i, const int &j ) {
        return x[i] < x[j];
    }

    bool by_Y( const int &i, const int &j ) {
        return y[i] < y[j];
    }

    void dfs( int x, int y ) {

        mark[x][y] = true;

        for ( int i = 0; i < 4; i++ ) {

            int a = x + mov[i][0],
                b = y + mov[i][1];

            if ( valid( a, b ) && !mark[a][b] )
                dfs( a, b );

            if ( sol ) {
                a += mov[i][0],
                b += mov[i][1];
                if ( valid( a, b ) && !mark[a][b] )
                    dfs( a, b );
            }
        }
    }

int main() {

    for (;;) {

        scanf( "%d", &N );
        if ( !N ) break;

        /* Init */
        max_x = 0;
        max_y = 0;
        memset( mark, 0, sizeof( mark ) );

        for ( i = 0; i < 2 * N; i++ ) {
            scanf( "%d %d", &x[i], &y[i] );
            ls[i] = i;
        }

        /* Compress X */
        sort( ls, ls + 2 * N, by_X );
        for ( i = 0; i < 2 * N; i = j ) {
            max_x += 2;
            nx[ ls[i] ] = max_x;
            for ( j = i + 1; j < 2 * N && x[ ls[j] ] == x[ ls[i] ]; j++ )
                nx[ ls[j] ] = max_x;
        }

        /* Compress Y */
        sort( ls, ls + 2 * N, by_Y );
        for ( i = 0; i < 2 * N; i = j ) {
            max_y += 2;
            ny[ ls[i] ] = max_y;
            for ( j = i + 1; j < 2 * N && y[ ls[j] ] == y[ ls[i] ]; j++ )
                ny[ ls[j] ] = max_y;
        }

        for ( i = 0; i < 2 * N; i += 2 ) {

            if ( nx[i] == nx[i + 1] ) {

                int lo = ( ny[i] <? ny[i + 1] ),
                    hi = ( ny[i] >? ny[i + 1] );

                for ( j = lo; j <= hi; j++ )
                    mark[ nx[i] ][ j ] = 1;
            }

            if ( ny[i] == ny[i + 1] ) {

                int lo = ( nx[i] <? nx[i + 1] ),
                    hi = ( nx[i] >? nx[i + 1] );

                for ( j = lo; j <= hi; j++ )
                    mark[j][ ny[i] ] = 1;
            }
        }

        /* Solve */
        sol = 0;
        max_x++; max_y++;
        for ( i = 0; i <= max_x; i++ )
            for ( j = 0; j <= max_y; j++ )
                if ( !mark[i][j] ) {
                    dfs( i, j );
                    sol++;
                }

        printf( "%d\n", sol - 1 );
    }

    return 0;
}
