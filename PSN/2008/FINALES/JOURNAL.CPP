/*
Alfonso Alfonso Peterssen
1 - 5 - 2008
TASK: JOURNAL
*/
#include <cstdio>
#include <vector>

using namespace std;

const int MAXV = 100000;

int V, E;
int i, j, u, v;
int rank[MAXV];
bool mark[MAXV];
vector< int > order;
vector< int > G[MAXV];

void dfs( int node ) {
    mark[node] = true;
    for ( int i = 0; i < G[node].size(); i++ )
        if ( !mark[ G[node][i] ] )
            dfs( G[node][i] );
    order.push_back( node );
}

int main() {

    scanf( "%d %d", &V, &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( v );
    }

    for ( i = 0; i < V; i++ )
        if ( !mark[i] )
            dfs( i );

    for ( i = V - 1; i >= 0; i-- ) {
        u = order[i];
        printf( "%d\n", u + 1 );
        for ( j = 0; j < G[u].size(); j++ )
            rank[ G[u][j] ] >?= rank[u] + 1;
    }

    printf( "%d\n", ( int )rank[ order[0] ] != V - 1 );
    fflush( stdout );

    return 0;
}
