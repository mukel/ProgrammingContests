/*
Alfonso Alfonso Peterssen
2 - 3 - 2008
POI 2003 Stage III "Sums"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int
    MAXV = 50000,
    oo = ( 1 << 29 );

int n, q, V, E, i, x;
int dist[MAXV];
int edge[MAXV];

struct dist_cmp {
    bool operator () ( const int &i, const int &j ) {
        return dist[i] > dist[j]; // > for priority_queue
    }
};

priority_queue< int, vector< int >, dist_cmp > Q;

int main() {

    scanf( "%d", &n );
    scanf( "%d", &V );
    fill( edge, edge + V, oo );
    edge[0] = 0;
    for ( i = 0; i < n - 1; i++ ) {
        scanf( "%d", &x );
        edge[x % V] <?= x;
    }

    for ( i = 0; i < V; i++ )
        if ( edge[i] != oo ) edge[E++] = edge[i];

    fill( dist, dist + V, oo );
    dist[0] = 0;
    for ( Q.push( 0 ); !Q.empty(); ) {
        int node = Q.top();
        Q.pop();
        for ( i = 0; i < E; i++ ) {
            int next = ( node + edge[i] ) % V;
            int cost = dist[node] + edge[i];
            if ( cost < dist[next] ) {
                dist[next] = cost;
                Q.push( next );
            }
        }
    }

    scanf( "%d", &q );
    while ( q-- ) {
        scanf( "%d", &x );
        printf( x >= dist[x % V] ? "TAK\n" : "NIE\n" );
    }

    return 0;
}
