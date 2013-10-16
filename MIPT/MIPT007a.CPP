/*
Alfonso Alfonso Peterssen
5 - 2 - 2008
MIPT #007 "Space zoo"
Clever O( n^5 )
*/
#include <cstdio>

const int MAXC = 30;

#define FOR( i, s, e ) \
    for ( i = (s); i <= (e); i++ )

int sol = -( 1 << 20 );
int X, Y, Z, i, j, k, p, q, r;
int T[MAXC][MAXC][MAXC];

int main() {

    scanf( "%d %d %d", &X, &Y, &Z );
    FOR( i, 1, Z )
    FOR( j, 1, X )
    FOR( k, 1, Y ) {
        scanf( "%d", &T[i][j][k] );
        T[i][j][k] += ( T[i - 1][j][k] + T[i][j - 1][k] + T[i][j][k - 1] ) -
                      ( T[i - 1][j - 1][k] + T[i - 1][j][k - 1] + T[i][j - 1][k - 1] ) +
                      ( T[i - 1][j - 1][k - 1] );
    }

    FOR( j, 1, X ) FOR( k, 1, Y )
    FOR( q, j, X ) FOR( r, k, Y ) {
        int sum = 0;
        FOR( i, 1, Z ) {
            sum += ( T[i][q][r] ) -
                   ( T[i - 1][q][r] + T[i][q - j][r] + T[i][q][r - k] ) +
                   ( T[i - 1][q - j][r] + T[i - 1][q][r - k] + T[i][q - j][r - k] ) -
                   ( T[i - 1][q - j][r - k] );
            sol >?= sum;
            if ( sum < 0 ) sum = 0;
        }
    }

    printf( "%d\n", sol );

    return 0;
}
