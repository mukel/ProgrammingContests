/*
Alfonso Alfonso Peterssen
3 - 1 - 2008
USACO 2001 FEB "Rebuilding Roads"
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV = 150;

int V, P, i, j, k, sol;
int dp[MAXV][MAXV + 1];
bool mark[MAXV];
vector< int > G[MAXV];

    int dfs( int x ) {

        mark[x] = true;
        dp[x][1] = 0;

        /* Leaf */
        if ( G[x].size() == 1 && x != 0 )
            return 1;

        int i, j, k, sons = 1;

        for ( i = 0; i < G[x].size(); i++ )
            if ( !mark[ G[x][i] ] )
                dp[x][1]++;

        for ( i = 0; i < G[x].size(); i++ ) {
            if ( mark[ G[x][i] ] ) continue;
            sons += dfs( G[x][i] );
            for ( j = sons; j > 1; j-- )
                for ( k = 1; k < j; k++ )
                    dp[x][j] <?= dp[x][j - k] + dp[ G[x][i] ][k] - 1;
        }

        return sons;
    }

int main() {

    cin >> V >> P;
    for ( i = 0; i < V - 1; i++ ) {
        cin >> j >> k;
        j--; k--;
        G[j].push_back( k );
        G[k].push_back( j );
    }

    /* Init */
    for ( i = 0; i < V; i++ )
        fill( dp[i], dp[i] + V + 1, ( 1 << 20 ) ); // oo

    dfs( 0 );

    sol = dp[0][P];
    for ( i = 1; i < V; i++ )
        sol <?= dp[i][P] + 1; // disconnect

    cout << sol << endl;

    return 0;
}

/*
PROBLEM 4: Rebuilding Roads [Romanian Training Camp, 2001]

The cows have reconstructed Farmer John's farm, with its N barns (1 <= N
<= 150) numbered 1 through N after the terrible earthquake last May. The
cows didn't have time to rebuild any extra roads, so now there is exactly
one way to get from any given barn to any other barn.  Thus, the farm
transportation system can be represented as a tree.

Farmer John wants to know how much damage another earthquake could do.  He
wants to know the minimum number of roads whose destruction would isolate
a subtree of exactly P (1 <= P <= N) barns from the rest of the barns.

PROBLEM NAME: roads

INPUT FORMAT:

* Line 1: Two integers, N and P

* Lines 2..N: N-1 lines, each with two integers I and J.  Node I is
          node J's parent in the tree of roads.

SAMPLE INPUT (file roads.in):

11 6
1 2
1 3
1 4
1 5
2 6
2 7
2 8
4 9
4 10
4 11

OUTPUT FORMAT:

A single line containing the integer that is the minimum number of roads
that need to be destroyed for a subtree of P nodes to be isolated.

SAMPLE OUTPUT (file roads.out):

2

[A subtree with nodes (1, 2, 3, 6, 7, 8) will become isolated if roads 1-4
and 1-5 are destroyed.]
*/
