/*
Alfonso Alfonso Peterssen
16 - 2 - 2008
Saratov #226 "Colored graph"
*/
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int MAXV = 200;

#define REP( i, n ) \
    for ( i = 0; i < (n); i++ )

typedef pair< int, int > node;

int V, E, i, sol;
int u, v, c, nu, nc;
int dist[MAXV][3];
vector< node > G[MAXV];
queue< node > Q;

int main() {

    scanf( "%d %d", &V, &E );
    REP( i, E ) {
        scanf( "%d %d %d", &u, &v, &c );
        u--; v--; c--;
        G[u].push_back( make_pair( v, c ) );
    }

    REP( i, 3 )
        Q.push( make_pair( 0, i ) );

    /* BFS */
    while ( !Q.empty() ) {
        u = Q.front().first;
        c = Q.front().second;
        Q.pop();
        REP( i, G[u].size() ) {
            nu = G[u][i].first;
            nc = G[u][i].second;
            if ( nc == c ) continue;
            if ( dist[nu][nc] == 0 ||
                 dist[nu][nc] > dist[u][c] + 1 ) {
                dist[nu][nc] = dist[u][c] + 1;
                Q.push( make_pair( nu, nc ) );
            }
        }
    }

    sol = 1 << 29;
    REP( i, 3 )
        if ( dist[V - 1][i] > 0 )
            sol <?= dist[V - 1][i];

    if ( sol == ( 1 << 29 ) )
        sol = -1;

    printf( "%d\n", sol );

    return 0;
}
