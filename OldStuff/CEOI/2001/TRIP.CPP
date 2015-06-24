/*
Alfonso2 Peterssen
21 - 7 - 2008
CEOI 2001 "Round Trip"
O( V^2 ) but can be O( E )
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
    for ( int i = (n) - 1; i >= 0; i-- )

const int MAXV = 1000;

int V, E, P, sol;
int src, snk;
int u, v;
int discover_time;
int path[MAXV];
int from[MAXV];
int low[MAXV];
int dfsnum[MAXV];
int G[MAXV][MAXV];
bool mark[MAXV];

void dfs( int x, int father ) {
    dfsnum[x] = low[x] = ++discover_time;
    REP( y, V ) if ( y != father && G[x][y] )
        if ( !dfsnum[y] ) {
            dfs( y, x );
            low[x] <?= low[y];
            if ( low[y] > dfsnum[x] )
                G[x][y] = G[y][x] = 2;
        } else
            low[x] <?= dfsnum[y];
}

bool augment( int x ) {
    if ( x == snk ) return 1;
    if ( mark[x] )  return 0;
    mark[x] = true;
    REP( y, V )
        if ( G[x][y] && augment( y ) ) {
            from[y] = x;
            return 1;
        }
    return 0;
}

void reflow() {
    P = sol = 0;
    for ( int i = snk; i != src; i = from[i] ) {
        /* Count Bridges */
        if ( G[ from[i] ][i] == 2 ) sol++;
        G[ from[i] ][i]--;
        G[i][ from[i] ]++;
        path[P++] = i;
    }
    path[P++] = src;
}

int main() {

    scanf( "%d %d", &src, &snk );
    src--; snk--;
    scanf( "%d %d", &V, &E );
    REP( i, E ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u][v] = G[v][u] = 1;
    }

    dfs( src, -1 );
    if ( !dfsnum[snk] ) {
        printf( "-1\n" );
        return 0;
    }

    memset( mark, 0, sizeof( mark ) );
    augment( src ); reflow();
    printf( "%d\n", sol );
    REPD( i, P )
        printf( "%d ", path[i] + 1 );
    printf( "\n" );

    memset( mark, 0, sizeof( mark ) );
    augment( src ); reflow();
    REP( i, P )
        printf( "%d ", path[i] + 1 );
    printf( "\n" );

    return 0;
}
