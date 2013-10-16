/*
Alfonso Alfonso Peterssen
20 - 11 - 2007
COI 2001 Regional Senior "PALIN"
*/
#include <iostream>
using namespace std;

const int
    MAXLEN = 101,
    oo = 1000000000;

string st;
int len, i, j, k, sz;
int dp[MAXLEN][MAXLEN];

int main() {

    cin >> st;
    len = st.size();

    /* Init */
    for ( i = 0; i < len; i++ )
        dp[i + 1][i] = dp[i][i] = 1;

    /* DP */
    for ( sz = 1; sz < len; sz++ )
        for ( i = 0; i < len - sz; i++ ) {
            j = i + sz;
            if ( st[i] == st[j] && dp[i + 1][j - 1] == 1 )
                dp[i][j] = 1;
            else {
                dp[i][j] = oo;
                for ( k = i; k < j; k++ )
                dp[i][j] <?= dp[i][k] + dp[k + 1][j];
            }
        }

    cout << dp[0][len - 1] << endl;

    return 0;
}
