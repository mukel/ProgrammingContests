/*
Alfonso2 Peterssen
18 - 4 - 2008
TASK: RED
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int
    MAXV = 15,
    MAXE = 20,
    oo = 2000000000;

int V, E, i, j;
int u, v, w;
int discover_time;
int len[MAXV];
int low[MAXV];
int dfsnum[MAXV];
bool exist_bridges;
int cost, sol;
bool active[MAXE];
int edge_cost[MAXE];
struct edge {
    int v, id;
} G[MAXV][MAXE];

void dfs( int node ) {

    dfsnum[node] = low[node] = ++discover_time;
    
    for ( int i = 0; i < len[node]; i++ ) {
        if ( !active[ G[node][i].id ] )
            continue;
        int next = G[node][i].v;
        if ( !dfsnum[next] ) {
            active[ G[node][i].id ] = false;
            dfs( next );
            if ( low[next] > dfsnum[node] )
                exist_bridges = true;
            low[node] <?= low[next];
        } else
            low[node] <?= dfsnum[next];
    }
}

int main() {

    #warning READ FROM FILES!!!
    freopen( "red.in", "r", stdin );
    freopen( "red.out", "w", stdout );

    scanf( "%d %d", &V, &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d %d", &u, &v, &w );
        u--; v--;
        edge_cost[i] = w;
        G[u][ len[u]++ ] = (edge){ v, i };
        G[v][ len[v]++ ] = (edge){ u, i };
    }
    
    sol = oo;
    for ( i = 0; i < ( 1 << E ); i++ ) {

        if ( __builtin_popcount( i ) < V )
            continue;
            
        cost = 0;
        for ( j = 0; j < E; j++ )
            if ( i & ( 1 << j ) ) {
                cost += edge_cost[j];
                active[j] = true;
            }
            
        if ( cost >= sol ) {
            fill( active, active + E, false );
            continue;
        }

        exist_bridges = false;
        discover_time = 0;

        fill( dfsnum, dfsnum + V, 0 );
        
        dfs( 0 );
        if ( discover_time < V ) {
            fill( active, active + E, false );
            continue;
        }
        if ( !exist_bridges )
            sol = cost;
        fill( active, active + E, false );
    }

    if ( sol == oo )
         printf( "-1\n" );
    else printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
