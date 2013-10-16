/*
Alfonso Alfonso Peterssen
5 - 4 - 2008
Baltic 2002 Task "Bicriterial routing"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXV = 100;

struct edge {
    int u, a, b;
    bool operator < ( const edge &e ) const {
        return b != e.b ? b > e.b : a > e.a;
    }
};

int V, E, src, dst, sol;
int u, v, a, b;
int cost[MAXV];
vector< edge > G[MAXV];
priority_queue< edge > Q;

int main() {

    scanf( "%d %d", &V, &E );
    scanf( "%d %d", &src, &dst );
    src--; dst--;
    for ( int i = 0; i < E; i++ ) {
        scanf( "%d %d %d %d", &u, &v, &a, &b );
        u--; v--;
        G[u].push_back( (edge){ v, a, b } );
        G[v].push_back( (edge){ u, a, b } );
    }

    fill( cost, cost + V, 1 << 29 );

    Q.push( (edge){ src, 0, 0 } );

    while ( !Q.empty() ) {

        u = Q.top().u;
        a = Q.top().a;
        b = Q.top().b;
        Q.pop();

        if ( a >= cost[u] ) continue;
        cost[u] = a;

        if ( u == dst ) {
            sol++;
            continue;
        }

        for ( int i = 0; i < G[u].size();i++ ) {
            edge e = G[u][i];
            if ( e.a + a < cost[ e.u ] )
                Q.push( (edge){ e.u, e.a + a, e.b + b } );
        }
    }

    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
