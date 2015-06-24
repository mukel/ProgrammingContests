/*
Alfonso Alfonso Peterssen
4 - 12 - 2007
PSN 2007 #76 "LUBENICA"
*/
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

const int
    MAXV = 100001,
    LOGV = 20,
    oo = 1000000000,
    ROOT = 1;

int V, T, i, j, k, x, y, lg;
bool mark[MAXV];
int level[MAXV];

int min_sol, max_sol;

int LCA[LOGV][MAXV],
    min_cost[LOGV][MAXV],
    max_cost[LOGV][MAXV];

int P[MAXV];
struct edge {
    int v, cost, next;
} ls[ 2 * MAXV ];

queue< int > Q;

    int log2( int x ) {
        int res = 1;
        while ( 1 << res <= x ) res++;
        return res - 1;
    }

int main() {

    scanf( "%d", &V );
    for ( i = 1; i < V; i++ ) {
        scanf( "%d %d %d", &j, &k, &x );
        ls[i] = ( edge ) { k, x, P[j] };
        P[j] = i;
        ls[V + i] = ( edge ) { j, x, P[k] };
        P[k] = V + i;
    }

    /* Preprocess LCA */
    Q.push( ROOT ); mark[ROOT] = true;
    while ( !Q.empty() ) {

        x = Q.front();
        Q.pop();

        for ( i = P[x]; i; i = ls[i].next )
            if ( !mark[ y = ls[i].v ] ) {

                Q.push( y );
                mark[y]= true;

                LCA[0][y] = x;
                level[y] = level[x] + 1;
                min_cost[0][y] = max_cost[0][y] = ls[i].cost;

                lg = log2( level[y] );
                for ( j = 1; j <= lg; j++ )
                    if ( LCA[j - 1][y] ) {

                        LCA[j][y] = LCA[j - 1][ LCA[j - 1][y] ];

                        min_cost[j][y] = min_cost[j - 1][y] <?
                                         min_cost[j - 1][ LCA[j - 1][y] ];

                        max_cost[j][y] = max_cost[j - 1][y] >?
                                         max_cost[j - 1][ LCA[j - 1][y] ];
                    }
        }
    }

    /* Queries */
    for ( scanf( "%d", &T ); T; T-- ) {

        scanf( "%d %d", &j, &k );

        if ( level[k] > level[j] )
            swap( j, k );

        min_sol = oo;
        max_sol = -oo;

        //if ( j == k ) min_sol = max_sol = 0;

        lg = log2( level[j] );
        for ( i = lg; i >= 0; i-- )
            if ( level[j] - ( 1 << i ) >= level[k] ) {
                min_sol <?= min_cost[i][j];
                max_sol >?= max_cost[i][j];
                j = LCA[i][j];
            }

        if ( j != k ) {
            lg = log2( level[j] );
            for ( i = lg; i >= 0; i-- )
                if ( LCA[i][j] && LCA[i][j] != LCA[i][k] ) {
                    min_sol <?= ( min_cost[i][j] <? min_cost[i][k] );
                    max_sol >?= ( max_cost[i][j] >? max_cost[i][k] );
                    j = LCA[i][j];
                    k = LCA[i][k];
                }
            min_sol <?= ( min_cost[0][j] <? min_cost[0][k] );
            max_sol >?= ( max_cost[0][j] >? max_cost[0][k] );
        }

        printf( "%d %d\n", min_sol, max_sol );
    }

    return 0;
}
