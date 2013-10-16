/*
Alfonso Alfonso Peterssen
1 - 12 - 2007
SPOJ #377 "Taxi"
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 401;

int T, E, N, M, i, j, k;
int speed, limit, flow;
int x[ 2 * MAXN ], y[ 2 * MAXN ];
bool mark[MAXN];
int from[MAXN], P[MAXN];
struct edge {
    int v, next;
} ls[ MAXN * MAXN ];

    bool augment( int x ) {

        if ( mark[x] ) return false;

        int i, j;
        mark[x] = true;
        for ( i = P[x]; i; i = ls[i].next )
            if ( !from[ j = ls[i].v ] || augment( from[j] ) ) {
                from[j] = x;
                return true;
            }

        return false;
    }

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        /* Init */
        E = flow = 0;
        memset( P, 0, sizeof( P ) );
        memset( from, 0, sizeof( from ) );

        scanf( "%d %d %d %d", &N, &M, &speed, &limit );

        for ( i = 0; i < N + M; i++ )
            scanf( "%d %d", &x[i], &y[i] );

        /* Build Net */
        for ( i = 0; i < N; i++ )
            for ( j = 0; j < M; j++ ) {

                int dist = abs( x[i] - x[j + N] ) +
                           abs( y[i] - y[j + N] );

                if ( ( long long )dist * 200 /* Block Size */ <= limit * speed ) {
                    ls[++E] =( edge ) { i + 1, P[j + 1] };
                    P[j + 1] = E;
                }
            }

        /* Bipartite Matching */
        for ( i = 1; i <= M && flow < ( N <? M ); i++ ) {
            memset( mark, 0, sizeof( mark ) );
            if ( augment( i ) ) flow++;
        }

        printf( "%d\n", flow );
    }

    return 0;
}
