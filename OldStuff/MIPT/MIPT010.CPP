/*
Alfonso Alfonso Peterssen
5 - 2 - 2008
MIPT #010 "New Year congratulations"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV = 1000;

int N, M, E, i, flow;
int u, v;
bool mark[MAXV];
int from[MAXV];
vector< int > G[MAXV];

    bool augment( int node ) {

        if ( mark[node] )
            return false;

        mark[node] = true;

        for ( int i = 0; i < G[node].size(); i++ ) {
            int next = G[node][i];
            if ( from[next] < 0 || augment( from[next] ) ) {
                from[next] = node;
                return true;
            }
        }

        return false;
    }

int main() {

    scanf( "%d %d %d", &N, &M, &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( v );
    }

    fill( from, from + M, -1 );
    for ( i = 0; i < N; i++ ) {
        fill( mark, mark + N, false );
        if ( augment( i ) )
            flow++;
    }

    printf( "%d\n", flow );
    for ( i = 0; i < M; i++ )
        if ( from[i] >= 0 )
            printf( "%d %d\n", from[i] + 1, i + 1 );

    return 0;
}
