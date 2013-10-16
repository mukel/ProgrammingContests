/*
Alfonso Alfonso Peterssen
1 - 3 - 2008
POI 2000 Stage I "Skiers"
*/
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXV = 10000;

int V, i, j, k, flow;
int source, sink;
bool mark[MAXV];
vector< int > G[MAXV];
queue< int > Q;

int main() {

    scanf( "%d", &V );
    for ( i = 0; i < V - 1; i++ )
        for ( scanf( "%d", &k ); k; k-- ) {
            scanf( "%d", &j );
            G[i + V].push_back( j - 1 );
        }

    for ( i = 0; i < V; i++ )
        G[i].push_back( i + V );

    source = V; sink = V - 1;
    for ( Q.push( source ); !Q.empty(); Q.pop() ) {
        int node = Q.front();
        for ( int i = 0; i < G[node].size(); i++ ) {
            int next = G[node][i];
            if ( mark[next] ) continue;
            if ( next == sink ) { flow++; continue; }
            mark[next] = true;
            Q.push( next );
        }
    }

    printf( "%d\n", flow );

    return 0;
}
