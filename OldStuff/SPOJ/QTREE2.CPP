/*
Alfonso Alfonso Peterssen
4 - 12 - 2007
SPOJ #913 "Query on a tree II"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int
    MAXV = 10001,
    LOGV = 15;

int T, V, i, j, k, cost, sol;

char op[5];

bool mark[MAXV];
int level[MAXV];

int LCA[LOGV][MAXV];
int dist[LOGV][MAXV];

int P[MAXV];
struct edge {
    int v, cost, next;
} ls[ 2 * MAXV ];

    int log2( int x ) {
        int res = 1;
        while ( 1 << res <= x ) res++;
        return res - 1;
    }

    void dfs( int x ) {

        int i, j, y, lg;

        mark[x] = true;
        for ( i = P[x]; i; i = ls[i].next )
            if ( !mark[ y = ls[i].v ] ) {

                LCA[0][y] = x;
                dist[0][y] = ls[i].cost;
                level[y] = level[x] + 1;

                lg = log2( level[y] );
                for ( j = 1; j <= lg; j++ )
                    if ( LCA[j - 1][y] ) {
                        LCA[j][y] = LCA[j - 1][ LCA[j - 1][y] ];
                        dist[j][y] = dist[j - 1][y] +
                                     dist[j - 1][ LCA[j - 1][y] ];
                    }

                dfs( y );
            }
    }

    int query_lca( int j, int k ) {

        int lg, i;

        if ( level[k] > level[j] )
            swap( j, k );

        lg = log2( level[j] );
        for ( i = lg; i >= 0; i-- )
            if ( level[j] - ( 1 << i ) >= level[k] )
                j = LCA[i][j];

        if ( j == k ) return j;

        if ( j != k ) {
            lg = log2( level[j] );
            for ( i = lg; i >= 0; i-- )
                if ( LCA[i][j] && LCA[i][j] != LCA[i][k] ) {
                    j = LCA[i][j];
                    k = LCA[i][k];
                }
        }

        return LCA[0][j];
    }

    int query_dist( int j, int k, bool nodes = false ) {

        /* Find # of nodes or distance beteween j and k */

        int i, lg, res = 0;

        if ( level[k] > level[j] )
            swap( j, k );

        lg = log2( level[j] );
        for ( i = lg; i >= 0; i-- )
            if ( level[j] - ( 1 << i ) >= level[k] ) {
                res += ( nodes ) ? ( 1 << i ) : dist[i][j];
                j = LCA[i][j];
            }

        return res;
    }

    int query_kth( int j, int k, int kth ) {

        if ( kth == 1 ) return j;

        int i, lg, lca, d1, d2, lvl;

        lca = query_lca( j, k );
        d1 = query_dist( j, lca, true ),
        d2 = query_dist( k, lca, true );
        
        if ( kth == d1 + d2 + 1 ) return k;
        
        if ( kth > d1 + 1 ) {
            swap( j, k );
            kth = d1 + d2 + 1 - kth;
        } else kth--;

        lvl = level[j] - kth;
        lg = log2( level[j] );
        for ( i = lg; i >= 0; i-- )
            if ( level[j] - ( 1 << i ) >= lvl )
                j = LCA[i][j];

        return j;
    }

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        /* Init */
        memset( mark, 0, sizeof( mark ) );
        memset( LCA, 0, sizeof( LCA ) );
        memset( P, 0, sizeof( P ) );

        scanf( "%d", &V );
        for ( i = 1; i < V; i++ ) {
            scanf( "%d %d %d", &j, &k, &cost );
            ls[i] = ( edge ) { k, cost, P[j] };
            P[j] = i;
            ls[V + i] = ( edge ) { j, cost, P[k] };
            P[k] = V + i;
        }

        /* Preprocess LCA */
        dfs( 1 );

        /* Solve */
        for (;;) {

            scanf( "%s", op );
            if ( op[1] == 'O' ) break; /* DONE */

            scanf( "%d %d", &i, &j );

            if ( op[0] == 'D' ) {
                /* DIST */
                int lca = query_lca( i, j );
                printf( "%d\n", query_dist( i, lca ) + query_dist( j, lca ) );
            } else {
                /* KTH */
                scanf( "%d", &k );
                printf( "%d\n", query_kth( i, j, k ) );
            }
        }

        printf( "\n" );

    }

    return 0;
}
