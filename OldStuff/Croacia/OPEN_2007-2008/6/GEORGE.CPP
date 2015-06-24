/*
Alfonso2 Peterssen
12 - 4 - 2008
TASK: GEORGE
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int
    MAXV = 1000,
    oo = 1000000000;

int V, E, R, delay;
int gtime;
int start, end;
int i, j, k;
int u, v, w;
int dist[MAXV];
bool mark[MAXV];
int route[MAXV];
int cost[MAXV][MAXV];
vector< int > G[MAXV];

int block[MAXV][MAXV];

int main() {

    scanf( "%d %d", &V, &E );
    scanf( "%d %d", &start, &end );
    start--; end--;
    scanf( "%d %d", &delay, &R );
    for ( i = 0; i < R; i++ ) {
        scanf( "%d", &route[i] );
        route[i]--;
    }
    
    for ( i = 0; i < V; i++ ) {
        fill( cost[i], cost[i] + V, oo );
        cost[i][i] = 0;
        fill( block[i], block[i] + V, oo );
    }
    
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d %d", &u, &v, &w );
        u--; v--;
        G[u].push_back( v );
        G[v].push_back( u );
        cost[u][v] <?= cost[v][u] <?= w;
    }
    
    for ( i = 0; i < R - 1; i++ ) {
        u = route[i];
        v = route[i + 1];
        block[u][v] = gtime;
        block[v][u] = gtime;
        gtime += cost[u][v];
    }
    
    /* Dijkstra */
    fill( dist, dist + V, oo );
    dist[start] = 0;
    
    for ( i = 0; i < V; i++ ) {
        k = -1;
        for ( j = 0; j < V; j++ )
            if ( !mark[j] )
            if ( k == -1 || dist[j] < dist[k] )
                k = j;
        mark[k] = true;
        for ( j = 0; j < V; j++ )
            if ( !mark[j] ) {
                /* Update */
                int wait = 0;
                if ( dist[k] + delay >= block[k][j] &&
                     dist[k] + delay < block[k][j] + cost[k][j] )
                     wait = block[k][j] + cost[k][j] - ( dist[k] + delay );
                dist[j] <?= dist[k] + cost[k][j] + wait;
            }
    }
    
    printf( "%d\n", dist[end] );

    return 0;
}


