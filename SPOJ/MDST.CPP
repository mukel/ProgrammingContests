/*
Alfonso Alfonso Peterssen
9 - 1 - 2008
SPOJ #735 "Minimum Diameter Spanning Tree"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int
    MAXV = 1000,
    oo = 1000000000;

typedef pair< int, int > edge;

int T, V, E, i, j, k;
int u, v, len;
bool mark[MAXV];
int dist[MAXV][MAXV];
int size[MAXV];
int G[MAXV][MAXV];
vector< edge > edges;

    void bfs( int from ) {

        fill( mark, mark + V, false );
        mark[from] = true;

        int i, x, y;
        queue< int > Q;

        for ( Q.push( from ); !Q.empty(); Q.pop() ) {
            x = Q.front();
            for ( int i = 0; i < size[x]; i++ )
                if ( !mark[ y = G[x][i] ] ) {
                    dist[from][y] = dist[from][x] + 1;
                    mark[y] = true;
                    Q.push( y );
                }
        }
    }

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        scanf( "%d", &V );

        /* Init */
        edges.clear();
        fill( size, size + V, 0 );
        for ( i = 0; i < V; i++ )
            fill( dist[i], dist[i] + V, 0 );

        for ( i = 0; i < V; i++ ) {
            scanf( "%d", &u );
            scanf( "%d", &len );
            u--;
            for ( j = 0; j < len; j++ ) {
                scanf( "%d", &v );
                v--;
                G[u][ size[u]++ ] = v;
                G[v][ size[v]++ ] = u;
                edges.push_back( edge( u, v ) );
            }
        }

        /* APSP */
        for ( i = 0; i < V; i++ )
            bfs( i );

        /* MDST */
        int diam = oo;
        E = edges.size();
        vector< int > thetha( E, 0 );
        for ( i = 0; i < E; i++ ) {
            u = edges[i].first;
            v = edges[i].second;
            for ( j = 0; j < V; j++ )
                thetha[i] >?= min( dist[u][j], dist[v][j] );
            diam <?= 2 * thetha[i] + 1;
        }

        int mdst = oo;
        for ( i = 0; i < E; i++ )
            if ( 2 * thetha[i] <= diam ) {

                u = edges[i].first;
                v = edges[i].second;

                vector< edge > ls;
                for ( j = 0; j < V; j++ )
                    ls.push_back( make_pair( dist[u][j], dist[v][j] ) );

                sort( ls.rbegin(), ls.rend() );

                /* Edge */
                for ( j = k = 0; j < V; j++ )
                    if ( ls[j].second > ls[k].second ) {
                        mdst <?= ls[j].first + ls[k].second + 1;
                        k = j;
                    }

                /* Vertex */
                mdst <?= 2 * ls[0].first;
                mdst <?= 2 * ls[k].second;
            }

        if ( mdst == oo )
            mdst = 0;

        printf( "%d\n", mdst );
    }

    return 0;
}
