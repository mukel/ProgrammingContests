/*
Alfonso Alfonso Peterssen
28 - 2 - 2008
POI 2002 Stage II "Ski Resort"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int MAXV = 6000;

typedef pair< int, int > edge;

int V, S, E, B, i, j;
int u, v, w;
int start, money, sol;
int dist[MAXV];
vector< edge > G[MAXV];
set< edge > Q;

int main() {

    scanf( "%d %d", &V, &B );
    scanf( "%d", &S );
    for ( i = 0; i < S; i++ ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( make_pair( 0, v ) );
    }

    scanf( "%d", &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d %d", &u, &v, &w );
        u--; v--;
        G[u].push_back( make_pair( w, v ) );
    }

    scanf( "%d %d", &start, &money );
    start--;

    /* Kth Path */
    fill( dist, dist + V, -1 );
    Q.insert( make_pair( 0, start ) );
    while ( !Q.empty() ) {

        int cost = (*Q.begin()).first;
        int node = (*Q.begin()).second;
        Q.erase( Q.begin() );

        dist[node] = cost;
        if ( node < B )
            sol = cost;

        for ( i = 0; i < G[node].size(); i++ ) {
            int next = G[node][i].second;
            int newcost = G[node][i].first + cost;
            if ( newcost <= money && newcost > dist[next] )
                Q.insert( make_pair( newcost, next ) );
        }
    }

    printf( "%d\n", money - sol );

    return 0;
}
