/*
Alfonso2 Peterssen
23 - 6 - 2008
USACO OPEN02 Gold "Secret Milk Pipes"
O( E * ack + V lg V )
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int
    MAXLOG = 12,
    MAXV = 2000,
    MAXE = 20000,
    oo = 1 << 29;

int V, E;
int sol, diff;
int u, v, w;
int P[MAXV];
bool mark[MAXV];
int depth[MAXV];
int LCA[MAXLOG][MAXV];
int dist[MAXLOG][MAXV];
struct edge {
    int u, v, w;
    bool operator < ( const edge &e ) const { return w < e.w; }
} edges[MAXE];
vector< edge > G[MAXV];

int FIND( int x ) {
    if ( P[x] != x ) P[x] = FIND( P[x] );
    return P[x];
}

void UNION( int x, int y ) {
    x = FIND( x );
    y = FIND( y );
    P[x] = y;
}

int log2( int x ) {
    return 31 - __builtin_clz( x );
}

void dfs( int x ) {

    mark[x] = true;
    REP( i, G[x].size() ) {
        int y = G[x][i].v;
        if ( mark[y] ) continue;

        LCA[0][y] = x;
        dist[0][y] = G[x][i].w;
        depth[y] = depth[x] + 1;

        int lg = log2( depth[y] );
        for ( int j = 1; j <= lg; j++ ) {
            LCA[j][y] = LCA[j - 1][ LCA[j - 1][y] ];
            dist[j][y] = dist[j - 1][y] >? dist[j - 1][ LCA[j - 1][y] ];
        }

        dfs( y );
    }
}

int max_dist( int u, int v ) {

    if ( depth[v] > depth[u] )
        swap( u, v );

    int res = 0;

    int lg = log2( depth[u] );
    for ( int i = lg; i >= 0; i-- )
        if ( depth[u] - ( 1 << i ) >= depth[v] ) {
            res >?= dist[i][u];
            u = LCA[i][u];
        }

    if ( u != v ) {

        int lg = log2( depth[u] );

        for ( int i = lg; i >= 0; i-- )
            if ( LCA[i][u] != LCA[i][v] ) {
                res >?= dist[i][u];
                res >?= dist[i][v];
                u = LCA[i][u];
                v = LCA[i][v];
            }

        res >?= dist[0][u];
        res >?= dist[0][v];
    }

    return res;
}

int main() {

    scanf( "%d %d", &V, &E );
    REP( i, E ) {
        scanf( "%d %d %d", &u, &v, &w );
        u--; v--;
        edges[i] = (edge){ u, v, w };
    }

    REP( i, V ) P[i] = i;

    /* Find MST */
    sort( edges, edges + E );
    REP( i, E ) {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if ( FIND( u ) != FIND( v ) ) {
            UNION( u, v );
            G[u].push_back( (edge){ u, v, w } );
            G[v].push_back( (edge){ v, u, w } );
            sol += w;
        }
    }

    depth[0] = 1;
    dfs( 0 );

    REP( i, V ) P[i] = i;

    diff = oo;
    REP( i, E ) {
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if ( FIND( u ) != FIND( v ) )
            UNION( u, v );
        else
            diff <?= w - max_dist( u, v );
    }

    printf( "%d\n", sol + diff );

    return 0;
}
