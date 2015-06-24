/*
Alfonso Alfonso Peterssen
21 - 2 - 2008
CNCN 2008 Task 2A "Permut"
Never use reals...
*/
#include <iostream>
#include <cmath>

using namespace std;

const int ALPHA = 256;

string st;
int len, i, j, sol;
int freq[ALPHA];

int comb() {
    double res = 1.0;
    int n = 0, i, j;
    for ( i = 'a'; i <= 'z'; i++ )
        n += freq[i];
    for ( i = 'a'; i <= 'z'; i++ )
        for ( j = freq[i]; j > 1; j-- )
            res = res * n / j, n--;
    for ( ; n > 1; n-- )
        res *= n;
    return ( int )ceil( res );
}

int main() {

    cin >> st;
    len = st.size();

    for ( i = 0; i < len; i++ )
        freq[ st[i] ]++;

    for ( i = 0; i < len; i++ ) {
        for ( j = 'a'; j < st[i]; j++ )
            if ( freq[j] > 0 ) {
               freq[j]--;
               sol += comb();
               freq[j]++;
            }
        freq[ st[i] ]--;
    }

    cout << sol + 1 << endl;

    return 0;
}

