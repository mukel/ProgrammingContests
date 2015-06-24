/*
Alfonso Alfonso Peterssen
3 - 1 - 2008
Croacia 2002 Final2 "TELE"
*/
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 3000;

int N, M, i, j, k, size;
int money[MAXN];
int dp[MAXN][MAXN];
vector< pair< int, int > > G[MAXN];

    int dfs( int x ) {

        /* Base Case -> leaf */
        if ( x >= N - M ) {
            dp[x][0] = 0;
            dp[x][1] = money[x - N + M];
            return 1;
        }

        int i, j, k;
        int p, sons = 0;

        dp[x][0] = 0;
        for ( i = 0; i < G[x].size(); i++ ) {

            sons += ( p = dfs( G[x][i].first ) );

            for ( j = sons; j > 0; j-- )
                for ( k = p; k; k-- )
                    dp[x][j] >?= dp[x][j - k] +
                                 dp[ G[x][i].first ][k] - G[x][i].second;
        }

        return sons;
    }

int main() {

    cin >> N >> M;
    for ( i = 0; i < N - M; i++ ) {
        cin >> size;
        while ( size-- ) {
            cin >> j >> k;
            G[i].push_back( make_pair( --j, k ) );
        }
    }

    for ( i = 0; i < M; i++ )
        cin >> money[i];

    for ( i = 0; i < N; i++ )
        fill( dp[i], dp[i] + M + 1, -( 1 << 30 ) ); // -oo

    dfs( 0 );

    for ( i = M; i; i-- )
        if ( dp[0][i] >= 0 ) break;

    cout << i << endl;

    return 0;
}
