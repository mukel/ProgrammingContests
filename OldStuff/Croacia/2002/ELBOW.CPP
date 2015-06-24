/*
Alfonso Alfonso Peterssen
20 - 2 - 2008
Croatia 2002 Regional(Senior) "ELBOW"
*/
#include <cstdio>
#include <cstring>

const int MAXN = 200;

int A, B, C, i, j, k;
bool dp[MAXN][MAXN];
char a[MAXN], b[MAXN], c[2 * MAXN];

    void print( int i, int j ) {
        if ( i == 0 && j == 0 ) return ;
        if ( i != 0 && dp[i - 1][j] ) {
            print( i - 1, j );
            printf( "1" );
        } else
        if ( j != 0 && dp[i][j - 1] ) {
            print( i, j - 1 );
            printf( "2" );
        }
    }

int main() {

    scanf( "%s", a + 1 ); A = strlen( a + 1 );
    scanf( "%s", b + 1 ); B = strlen( b + 1 );
    scanf( "%s", c + 1 ); C = strlen( c + 1 );

    dp[0][0] = true;
    for ( i = 0; i <= A; i++ )
        for ( j = 0; j <= B; j++ ) {
            if ( i + j == 0 ) continue;
            if ( i != 0 && a[i] == c[i + j] )
                dp[i][j] |= dp[i - 1][j];
            if ( j != 0 && b[j] == c[i + j] )
                dp[i][j] |= dp[i][j - 1];
        }

    print( A, B );
    printf( "\n" );
    fflush( stdout );

    return 0;
}
