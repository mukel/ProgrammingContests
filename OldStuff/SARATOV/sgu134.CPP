/*
Alfonso Alfonso Peterssen
11 - 2 - 2008
Saratov #134 "Centroid"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV = 20000;

int V, i, u, v;
int sol, cant;
int hang[MAXV];
bool mark[MAXV];
vector< int > G[MAXV];

    int dfs( int node ) {

        mark[node] = true;
        int i, child, value, cant = 1;
        for ( i = 0; i < G[node].size(); i++ ) {
            child = G[node][i];
            if ( mark[child] ) continue;
            value = dfs( child );
            cant += value;
            hang[node] >?= value;
        }

        hang[node] >?= V - cant;

        return cant;
    }

int main() {

    scanf( "%d", &V );
    for ( i = 0; i < V - 1; i++ ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( v );
        G[v].push_back( u );
    }

    dfs( 0 );

    cant = count( hang, hang + V, sol = *min_element( hang, hang + V ) );

    printf( "%d %d\n", sol, cant );
    for ( i = 0; i < V; i++ )
        if ( hang[i] == sol )
            printf( --cant == 0 ? "%d\n" : "%d ", i + 1 );

    return 0;
}
