/*
Alfonso Alfonso Peterssen
28 - 12 - 2007
SPOJ #2132 "IPSC Puzzle"
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector< bool > array;
typedef vector< array > matrix;

int T, F, C, i, j, k;
string color;

int main() {

    for ( cin >> T; T; T-- ) {

        cin >> F >> C;

        matrix board1( C, array( F ) ),
               board2( C, array( F ) ),
               board3( C, array( F ) );

        for ( i = 0; i < F; i++ )
            for ( j = 0; j < C; j++ ) {
                cin >> color;
                board1[j][i] = ( color == "BLUE" );
            }

        for ( i = 0; i < F; i++ )
            for ( j = 0; j < C; j++ ) {
                cin >> color;
                board2[j][i] = ( color == "BLUE" );
            }

        for ( i = 0; i < F; i++ )
            if ( board1[0][i] )
                for ( j = 0; j < C; j++ )
                    board1[j][i] = board1[j][i] ^ true;

        sort( board1.begin(), board1.end() );

        for ( i = 0; i < C; i++ ) {

            board3 = board2;
            
            for ( j = 0; j < F; j++ )
                if ( board3[i][j] )
                    for ( k = 0; k < C; k++ )
                        board3[k][j] = board3[k][j] ^ true;

            sort( board3.begin(), board3.end() );

            for ( j = 0; j < C; j++ )
                 if ( !( board1[j] == board3[j] ) )
                    break;

            if ( j == C ) break;
        }

        if ( j == C )
             cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
