/*
Alfonso Alfonso Peterssen
14 - 2 - 2008
Saratov #172 "eXam"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

const int MAXV = 200;

int V, E, i, j;
int u, v;
int color[MAXV];
vector< int > G[MAXV];

    void dfs( int node, int tone ) {
        color[node] = tone;
        for ( int i = 0; i < G[node].size(); i++ ) {
            int next = G[node][i];
            if ( color[next] == -1 )
                dfs( next, tone ^ 1 );
            else if ( color[node] == color[next] ) {
                printf( "no\n" );
                fflush( stdout );
                exit( 0 );
            }
        }
    }

int main() {

    scanf( "%d %d", &V, &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( v );
        G[v].push_back( u );
    }
    
    fill( color, color + V, -1 );
    for ( i = 0; i < V; i++ )
        if ( color[i] < 0 )
            dfs( i, 0 );

    /* Fix line-end */
    printf( "yes\n" );
    printf( "%d\n", count( color, color + V, 0 ) );
    for ( i = 0; i < V; i++ )
        if ( color[i] == 0 )
            printf( "%d ", i + 1 );

    return 0;
}
