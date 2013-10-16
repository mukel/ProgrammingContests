/*
Alfonso Alfonso Peterssen
3 - 3 - 2008
SPOJ #262 "Connections"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int
    MAXV = 100,
    MAXK = 100;

typedef pair< int, int > par;

int t, V, E, Q, i, j;
int u, v, w;
vector< int > dist[MAXV][MAXV];
vector< par > G[MAXV];

    void process( int source ) {
        priority_queue< par, vector< par >, greater< par > > Q;
        Q.push( make_pair( 0, source ) );
        while ( !Q.empty() ) {
            int cost = Q.top().first;
            int node = Q.top().second;
            Q.pop();
            if ( dist[source][node].size() > MAXK )
                continue;
            dist[source][node].push_back( cost );
            for ( int i = 0; i < G[node].size(); i++ ) {
                int next = G[node][i].second;
                int newcost = G[node][i].first + cost;
                Q.push( make_pair( newcost, next ) );
            }
        }
    }

int main() {

    scanf( "%d", &t );
    while ( t-- ) {

        scanf( "%d %d", &V, &E );

        for ( i = 0; i < V; i++ ) {
            G[i].clear();
            for ( j = 0; j < V; j++ )
                dist[i][j].clear();
        }

        for ( i = 0; i < E; i++ ) {
            scanf( "%d %d %d", &u, &v, &w );
            u--; v--;
            G[u].push_back( make_pair( w, v ) );
        }

        for ( i = 0; i < V; i++ )
            process( i );

        scanf( "%d", &Q );
        while ( Q-- ) {
            scanf( "%d %d %d", &u, &v, &w );
            u--; v--;
            if ( u != v ) w--;
            if ( w >= dist[u][v].size() )
                printf( "-1\n" );
            else printf( "%d\n", dist[u][v][w] );
        }
        printf( "\n" );
    }

    return 0;
}
