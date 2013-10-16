/*
Alfonso Alfonso Peterssen
22 - 11 - 2007
COI 2001 Final2 "FATBOY"
Sexy LCS
*/
#include <iostream>
#include <cstring>
using namespace std;

const int
    MAXLEN = 101,
    mov[4][3] = {{-1,-1,-1},{-1,0,0},{0,-1,0},{0,0,-1}};

int i, j, k, h;
int len[3];
char st[3][MAXLEN];
int dp[MAXLEN][MAXLEN][MAXLEN];
int from[MAXLEN][MAXLEN][MAXLEN];

    void print( int i, int j, int k ) {
        if ( !i || !j || !k ) return;
        int f = from[i][j][k];
        print( i + mov[f][0], j + mov[f][1], k + mov[f][2] );
        if ( !f ) cout << st[0][i];
    }

int main() {

    for ( i = 0; i < 3; i++ ) {
        cin >> ( st[i] + 1 );
        len[i] = strlen( st[i] + 1 );
    }

    /* DP */
    for ( i = 1; i <= len[0]; i++ )
        for ( j = 1; j <= len[1]; j++ )
            for ( k = 1; k <= len[2]; k++ ) {

                dp[i][j][k] = -1;

                if ( ( st[0][i] == st[1][j] ) && ( st[0][i] == st[2][k] ) )
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                else
                    for ( h = 1; h < 4; h++ ) {

                        int cost = dp[ i + mov[h][0] ]
                                     [ j + mov[h][1] ]
                                     [ k + mov[h][2] ];

                        if ( cost > dp[i][j][k] ) {
                            dp[i][j][k] = cost;
                            from[i][j][k] = h;
                        }
                    }
            }

//    cout << dp[ len[0] ][ len[1] ][ len[2] ] << endl;
    print( len[0], len[1], len[2] ); cout << endl;

    return 0;
}
