/*
Alfonso Alfonso Peterssen
28 - 12 - 2007
SPOJ #2038 "Rectangle Tiling"
*/
#include <cstdio>
#include <cstring>

const int MAXN = 1001;

int T, F, C, i, j;
int pre[MAXN];
char vertical[MAXN][MAXN],
     horizontal[MAXN][MAXN];

    int factor( const char st[][MAXN], int len ) {

        int i, j = pre[0] = -1;
        for ( i = 1; i < len; i++ ) {
            while ( j >= 0 && strcmp( st[j + 1], st[i] ) )
                j = pre[j];
            if ( strcmp( st[j + 1], st[i] ) == 0 ) j++;
            pre[i] = j;
        }

        i = len - j - 1;
        return ( len % i == 0 ) ? i : len;
    }

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        scanf( "%d %d", &F, &C );

        for ( i = 0; i < F; i++ )
            scanf( "%s", &vertical[i] );

        F = factor( vertical, F );

        for ( i = 0; i < C; i++ ) {
            for ( j = 0; j < F; j++ )
                horizontal[i][j] = vertical[j][i];
            horizontal[i][j] = '\0';
        }
                
        C = factor( horizontal, C );

        printf( "%d\n", F * C );
    }

    return 0;
}
