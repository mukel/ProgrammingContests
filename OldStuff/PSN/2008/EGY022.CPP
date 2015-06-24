/*
Alfonso Alfonso Peterssen
TASK: SMATRIX
*/
#include <cstdio>

const int MAXC = 2000;

int f, c, i, j, k, sol;
int mat[MAXC][MAXC];
int next[MAXC];
int last[MAXC];
int height[MAXC];

int main() {

    scanf( "%d %d", &f, &c );
    for ( i = 0; i < f; i++ )
        for ( j = 0; j < c; j++ )
            scanf( "%d", &mat[i][j] );

    for ( i = 0; i < f; i++ ) {

        for ( j = 0; j < c; j++ ) {
            if ( mat[i][j] == 0 )
                 height[j] = 0;
            else height[j]++;
        }

        /* next */
        for ( j = c - 1; j >= 0; j-- ) {
            for ( k = j + 1;
                  k < c && height[k] >= height[j];
                  k = next[k] );
            next[j] = k;
        }

        /* last */
        for ( j = 0; j < c; j++ ) {
            for ( k = j - 1;
                  k >= 0 && height[k] >= height[j];
                  k = last[k] );
            last[j] = k;
        }

        for ( j = 0; j < c; j++ )
            sol >?= height[j] * ( next[j] - last[j] - 1 );
    }

    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
