/*
Alfonso Alfonso Peterssen
TASK: LEKTIRA
*/
#include <iostream>
#include <algorithm>

using namespace std;

int i, j, len;
string st, sol;

    void check( int i, int j ) {

        string a = st.substr( 0, i );
        string b = st.substr( i, j - i + 1 );
        string c = st.substr( j + 1, len - j + 1 );
        
        //cout << "try: " << a << " " << b << " " << c << endl;

        reverse( a.begin(), a.end() );
        reverse( b.begin(), b.end() );
        reverse( c.begin(), c.end() );
        
        if ( sol == "" || a + b + c < sol )
            sol = a + b + c;
    }

int main() {

    cin >> st;
    len = st.size();
    
    for ( i = 1; i < len - 1; i++ )
    for ( j = i; j < len - 1; j++ )
        check( i, j );
        
    cout << sol << endl;

    return 0;
}
