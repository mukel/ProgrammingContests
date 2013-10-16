/*
Alfonso Alfonso Peterssen
22 - 11 - 2007
COI 2001 Olympiad "WORDS"
*/
#include <cstring>
#include <iostream>
using namespace std;

const int MAXN = 16;

int N, i, j, k, sol;
string st[MAXN];
int len[MAXN];
int dp[1 << MAXN][MAXN];

int main() {

    cin >> N;
    for ( i = 0; i < N; i++ ) {
        cin >> st[i];
        sol >?= st[i].size();
        dp[ 1 << i ][i] = st[i].size();
    }

    /* DP */
    for ( i = 0; i < 1 << N; i++ )
        for ( j = 0; j < N; j++ )
            if ( i & ( 1 << j ) )
                for ( k = 0; k < N; k++ )
                    if ( k != j && ( i & ( 1 << k ) ) )
                        if ( st[j][ st[j].size() - 1 ] == st[k][0] ) {
                            dp[i][j] >?= dp[ i ^ ( 1 << j ) ][k] + st[j].size();
                            sol >?= dp[i][j];
                        }

    cout << sol << endl;

    return 0;
}
