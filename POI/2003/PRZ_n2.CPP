/*
Alfonso Alfonso Peterssen
1 - 3 - 2008
POI 2003 Stage I "Smugglers"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV = 5000;

typedef pair< int, int > par;

int V, E, i, sol;
int u, v, w;
int tax[MAXV];
bool mark[MAXV];
int D1[MAXV], D2[MAXV];
vector< par > G1[MAXV], G2[MAXV];

void dijkstra( vector< par > G[], int dist[] ) {
    int i, j, k;
    fill( mark, mark + V, 0 );
    fill( dist, dist + V, ( 1 << 29 ) ); // oo

    dist[0] = 0;
    for ( i = 0; i < V; i++ ) {
        for ( k = -1, j = 0; j < V; j++ )
            if ( !mark[j] && ( k == -1 || dist[j] < dist[k] ) )
                k = j;
        for ( j = 0; j < G[k].size(); j++ )
            dist[ G[k][j].second ] <?= dist[k] + G[k][j].first;
        mark[k] = true;
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
        G1[u].push_back( make_pair( w, v ) );
        G2[v].push_back( make_pair( w, u ) );
    }

    dijkstra( G1, D1 );
    dijkstra( G2, D2 );

    sol = tax[0] / 2;
    for ( i = 0; i < V; i++ )
        sol <?= D1[i] + D2[i] + tax[i] / 2;

    printf( "%d\n", sol );

    return 0;
}
