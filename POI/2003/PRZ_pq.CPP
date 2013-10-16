/*
Alfonso Alfonso Peterssen
1 - 3 - 2008
POI 2003 Stage I "Smugglers"
Using STL::priority_queue
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXV = 5000;

typedef pair< int, int > par;

int V, E, i, sol;
int u, v, w;
int tax[MAXV];
int D1[MAXV], D2[MAXV];
vector< par > G1[MAXV], G2[MAXV];

void dijkstra( vector< par > G[], int dist[] ) {
    priority_queue< par, vector< par >, greater< par > > Q;
    fill( dist, dist + V, ( 1 << 29 ) ); // oo
    dist[0] = 0;
    Q.push( make_pair( 0, 0 ) );
    while ( !Q.empty() ) {
        int cost = Q.top().first;
        int node = Q.top().second;
        Q.pop();
        for ( int i = 0; i < G[node].size(); i++ ) {
            int next = G[node][i].first;
            int newcost = G[node][i].second + cost;
            if ( newcost < dist[next] ) {
                dist[next] = newcost;
                Q.push( make_pair( newcost, next ) );
            }
        }
    }
}

int main() {

    scanf( "%d", &V );
    for ( i = 0; i < V; i++ )
        scanf( "%d", &tax[i] );

    scanf( "%d", &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d %d", &u, &v, &w );
        u--; v--;
        G1[u].push_back( make_pair( v, w ) );
        G2[v].push_back( make_pair( u, w ) );
    }

    dijkstra( G1, D1 );
    dijkstra( G2, D2 );

    sol = tax[0] / 2;
    for ( i = 0; i < V; i++ )
        sol <?= D1[i] + D2[i] + tax[i] / 2;

    printf( "%d\n", sol );

    return 0;
}
