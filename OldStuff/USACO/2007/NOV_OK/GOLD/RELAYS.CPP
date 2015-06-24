/*
Alfonso Alfonso Peterssen
21 - 2 - 2008
USACO NOV07 Gold "Relays"
*/
#include <cstdio>
#include <cstring>

const int
    MAXNODES = 1001,
    MAXV = 100,
    MAXLOG = 21;

int V, E, N, S, T;
int u, v, w, lg, bit;
int h, i, j, k;
int id[MAXNODES];
int dist[MAXLOG][MAXV][MAXV];
int best[MAXLOG][MAXV];

int main() {

    memset( id, -1, sizeof( id ) );
    memset( dist, 63, sizeof( dist ) );

    scanf( "%d %d", &N, &E );
    scanf( "%d %d", &S, &T );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d %d", &w, &u, &v );
        if ( id[u] < 0 ) id[u] = V++; u = id[u];
        if ( id[v] < 0 ) id[v] = V++; v = id[v];
        dist[0][u][v] <?= w;
        dist[0][v][u] <?= w;
    }

    lg = 31 - __builtin_clz( N );
    for ( h = 1; h <= lg; h++ )
        for ( k = 0; k < V; k++  )
        for ( i = 0; i < V; i++  )
        for ( j = 0; j < V; j++  )
            dist[h][i][j] <?= dist[h - 1][i][k] + dist[h - 1][k][j];


    memset( best, 63, sizeof( best ) );
    best[0][ id[S] ] = 0;
    
    for ( h = 0; h <= lg; h++ )
        if ( N & ( 1 << h ) ) {
            bit++;
            for ( i = 0; i < V; i++ )
                for ( j = 0; j < V; j++ )
                    best[bit][i] <?= best[bit - 1][j] + dist[h][i][j];
        }
    
    printf( "%d\n", best[bit][ id[T] ] );
    
    return 0;
}
