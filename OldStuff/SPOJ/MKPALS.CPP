/*
Alfonso Alfonso Peterssen
28 - 12 - 2007
SPOJ #1866 "Making Pals"
*/
#include <iostream>
#include <utility>

using namespace std;

const int MAXLEN = 10;

int T, len, i, j, k;
string st;
pair< int, int > sol;

    bool palindrome( const string &st, int lo, int hi ) {
        int len = hi - lo + 1;
        for ( int i = 0; i < len; i++ )
            if ( st[lo + i] != st[hi - i] )
                return false;
        return true;
    }

int main() {

    while ( ++T && ( cin >> st ) ) {

        len = st.size();

        sol = make_pair( len - 1, 2 * len - 1 );
        for ( i = 0; i < len; i = j ) {
            for ( j = i + 1; j < len && palindrome( st, i, j ); j++ );
            pair< int, int > tmp = make_pair( i + len - j, -( len + abs( i - len + j ) ) );
            if ( tmp < sol ) sol = tmp;
        }

        cout << "Case " << T
             << ", sequence = " << st
             << ", cost = " << sol.first
             << ", length = " << -sol.second
             << endl;
    }

    return 0;
}
