/*
Alfonso Alfonso Peterssen
24 - 11 - 2007
COCI 2007 Contest 2 "PRVA"
*/
#include <iostream>
#include <cstring>
using namespace std;

const int MAXF = 30;

int F, C, i, j;
string mat[MAXF];
string sol, tmp;

    void update() {
        if ( ( tmp.size() >= 2 ) && ( sol == "" || tmp < sol ) )
            sol = tmp;
    }

int main() {

    cin >> F >> C;
    for ( i = 0; i < F; i++ )
        cin >> mat[i];
    
    for ( i = 0; i < F; i++ ) {
        tmp = "";
        for ( j = 0; j < C; j++ )
            if ( mat[i][j] != '#' )
                tmp += mat[i][j];
            else {
                update();
                tmp = "";
            }
        update();
    }

    for ( i = 0; i < C; i++ ) {
        tmp = "";
        for ( j = 0; j < F; j++ )
            if ( mat[j][i] != '#' )
                 tmp += mat[j][i];
            else {
                update();
                tmp = "";
            }
        update();
    }
    
    cout << sol << endl;

    return 0;
}
