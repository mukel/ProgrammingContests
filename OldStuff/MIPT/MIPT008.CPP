/*
Alfonso Alfonso Peterssen
2 - 2 - 2008
MIPT #003 "Brackets"
*/
#include <iostream>

using namespace std;

int i, cnt;
string st;

int main() {

    cin >> st;
    for ( i = 0; i < st.size(); i++ ) {
        if ( st[i] == '(' )
             cnt++;
        else cnt--;
        if ( cnt < 0 ) break;
    }
    
    cout << ( cnt ? "NO" : "YES" ) << endl;

    return 0;
}
