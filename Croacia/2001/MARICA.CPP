/*
Alfonso Alfonso Peterssen
21 - 11 - 2007
COI 2001 Final2 "MARICA"
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int
    MAXV = 1001,
    oo = 1000000000;

int V, E, i, j, k, sol;
bool mark[MAXV];
int cost[MAXV][MAXV];
int dist[MAXV], from[MAXV];
int blocked[MAXV][MAXV];
int sz[MAXV], ls[MAXV][MAXV];
typedef struct { int u, v; } edge;
vector< edge > edges;

    void dijkstra() {

        fill( mark, mark + V + 1, false );
        fill( dist, dist + V + 1, oo );
        dist[1] = 0;

        int i, j, k;
        for ( i = 0; i < V; i++ ) {

            k = 0;
            for ( j = 1; j <= V; j++ )
                if ( !mark[j] && dist[j] < dist[k] )
                    k = j;

            mark[k] = true;

            for ( j = 0; j < sz[k]; j++ ) {
                int x = ls[k][j];
                if ( blocked[k][x] ) continue;
                if ( !mark[x] && dist[k] + cost[k][x] < dist[x] ) {
                    dist[x] = dist[k] + cost[k][x];
                    from[x] = k;
                }
            }
        }
    }

int main() {

    cin >> V >> E;
    for ( i = 0; i < E; i++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = cost[v][u] = w;
        ls[u][ sz[u]++ ] = v;
        ls[v][ sz[v]++ ] = u;
    }

    /* Init */
    dijkstra();
    for ( i = V; i != 1; i = from[i] )
        edges.push_back( ( edge ) { i, from[i] } );

    /* Solve */
    for ( i = 0; i < edges.size(); i++ ) {
        int u = edges[i].u, v = edges[i].v;
        blocked[u][v] = blocked[v][u] = 1;
        dijkstra();
        blocked[u][v] = blocked[v][u] = 0;
        sol >?= dist[V];
    }

    cout << sol << endl;

    return 0;
}
