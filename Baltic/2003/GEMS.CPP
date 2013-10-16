/*
Alfonso2 Peterssen
19 - 6 - 2008
BalticOI 2003 "Gems"
Only three colors needed
*/
#include <cstdio>
#include <vector>

using std::vector;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXV = 10000;

int V;
int u, v;
int dp[MAXV][3];
bool mark[MAXV];
vector< int > G[MAXV];

int dfs( int x ) {

    dp[x][0] = 1;
    dp[x][1] = 2;
    dp[x][2] = 3;

    mark[x] = true;
    REP( i, G[x].size() ) {
        int y = G[x][i];
        if ( mark[y] ) continue;
        dfs( y );
        dp[x][0] += dp[y][1] <? dp[y][2];
        dp[x][1] += dp[y][0] <? dp[y][2];
        dp[x][2] += dp[y][0] <? dp[y][1];
    }

    return dp[x][0] <? dp[x][1] <? dp[x][2];
}

int main() {

    scanf( "%d", &V );
    REP( i, V - 1 ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( v );
        G[v].push_back( u );
    }

    printf( "%d\n", dfs( 0 ) );

    return 0;
}
