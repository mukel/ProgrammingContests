/*
Alfonso2 Peterssen
18 - 7 - 2008
MIPT #022 "Regular expression I"
*/
#include <cstdio>
#include <cstring>

#define FOR( i, s, e ) \
    for ( int i = (s); i <= (e); i++ )

const int MAXN = 2000;

int lenA, lenB;
char A[MAXN];
char B[MAXN];
int dp[MAXN][MAXN];

int main() {

    gets( A + 1 ); lenA = strlen( A + 1 );
    gets( B + 1 ); lenB = strlen( B + 1 );

    dp[0][0] = 1;
    if ( B[1] == '*' ) dp[0][1] = 1; // * is empty

    FOR( i, 1, lenA )
    FOR( j, 1, lenB ) {
        if ( B[j] == A[i] )
            dp[i][j] = dp[i - 1][j - 1];
        if ( B[j] == '*' )
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }

    printf( "%d\n", dp[lenA][lenB] );

    return 0;
}
