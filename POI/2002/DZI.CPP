/*
Alfonso Alfonso Peterssen
POI 2002 Stage I "Parcel"
29 - 2 - 2008
O( n^2 )
Clever I/O
*/
#include <cstdio>

const int MAXC = 2000;

int n, i, j, k, sol;
int height[MAXC];
int last[MAXC], next[MAXC];
char mat[MAXC][2 * MAXC + 1];

int main() {

    scanf( "%d\n", &n );
    for ( i = 0; i < n; i++ ) {
        gets( mat[i] );
        for ( j = 0; j < n; j++ )
            mat[i][j] = mat[i][j << 1] - '0';
    }

    for ( i = 0; i < n; i++ ) {

        for ( j = 0; j < n; j++ )
            height[j]++;

        for ( j = 0; j < n; j++ )
            if ( mat[i][j] )
                height[j] = 0;

        for ( j = n - 1; j >= 0; j-- ) {
            for ( k = j + 1;
                  k < n && height[k] >= height[j];
                  k = next[k] );
            next[j] = k;
        }

        for ( j = 0; j < n; j++ ) {
            for ( k = j - 1;
                  k >= 0 && height[k] >= height[j];
                  k = last[k] );
            last[j] = k;
        }

        for ( j = 0; j < n; j++ )
            sol >?= height[j] * ( next[j] - last[j] - 1 );
    }

    printf( "%d\n", sol );

    return 0;
}
