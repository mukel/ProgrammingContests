/*
Alfonso Alfonso Peterssen
17 - 3 - 2008
USACO MAR08 Gold "Cow Jogging"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXV = 1000;

typedef pair< int, int > par;

int V, E, K, i;
int u, v, w;
int cant[MAXV];
vector< par > G[MAXV];
priority_queue< par, vector< par >, greater< par > > Q;

int main() {

    scanf( "%d %d %d", &V, &E, &K );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d %d", &u, &v, &w );
        u--; v--;
        G[u].push_back( make_pair( w, v ) );
    }

    Q.push( make_pair( 0, V - 1 ) );
    while ( !Q.empty() ) {
        int cost = Q.top().first;
        int node = Q.top().second;
        Q.pop();
        cant[node]++;
        if ( node == 0 )
            printf( "%d\n", cost );
        for ( i = 0; i < G[node].size(); i++ ) {
            int next = G[node][i].second;
            if ( cant[next] >= K ) continue;
            Q.push( make_pair( G[node][i].first + cost, next ) );
        }
    }

    for ( i = cant[0]; i < K; i++ )
        printf( "-1\n" );

    fflush( stdout );

    return 0;
}
