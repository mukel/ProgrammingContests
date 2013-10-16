/*
Alfonso Alfonso Peterssen
19 - 11 - 2007
COI 2004 Regional Senior "PILOTI"
*/
#include <iostream>
using namespace std;

const int MAXN = 10000;

int N, i, j, cap, ass;
int dp[2][MAXN + 1];

int main() {

    cin >> N;

    /* DP */
    for ( i = 1; i <= N; i++ ) {
        cin >> cap >> ass;
        for ( j = 0; j <= i; j++ ) {
            dp[ i & 1 ][j] = 1000000000;
            if ( j < i - 1 ) dp[ i & 1 ][j] = dp[ i & 1 ^ 1 ][j + 1] + cap;
            if ( j > 0 )     dp[ i & 1 ][j] <?= dp[ i & 1 ^ 1 ][j - 1] + ass;
        }
    }

    cout << dp[ N & 1 ][0] << endl;

    return 0;
}
