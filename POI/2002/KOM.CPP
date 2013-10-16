/*
Alfonso Alfonso Peterssen
28 - 2 - 2008
POI 2002 Stage I "Byteasar the Travelling Salesman"
*/
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int
    MAXV = 30000,
    MAXLOG = 16;

int V, P, i, j, sol;
int last, next;
int u, v;
int level[MAXV];
int LCA[MAXLOG][MAXV];
vector< int > G[MAXV];
queue< int > Q;

int log2( int x ) {
    return 31 - __builtin_clz( x );
}

int dist( int u, int v ) {

    int i, sum = 0;

    if ( level[v] > level[u] )
        swap( u, v );

    for ( i = log2( level[u] ); i >= 0; i-- )
        if ( level[u] - ( 1 << i ) >= level[v] ) {
            u = LCA[i][u];
            sum += ( 1 << i );
        }

    if ( u != v ) {
        for ( i = log2( level[u] ); i >= 0; i-- )
            if ( LCA[i][u] != LCA[i][v] ) {
                u = LCA[i][u];
                v = LCA[i][v];
                sum += 2 * ( 1 << i );
            }
        sum += 2;
    }

    return sum;
}

int main() {

    scanf( "%d", &V );
    for ( i = 0; i < V - 1; i++ ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( v );
        G[v].push_back( u );
    }

    /* BFS */
    level[0] = 1;
    for ( Q.push( 0 ); !Q.empty(); Q.pop() ) {
        u = Q.front();
        for ( i = 0; i < G[u].size(); i++ ) {
            v = G[u][i];
            if ( level[v] ) continue;
            Q.push( v );
            level[v] = level[u] + 1;
            LCA[0][v] = u;
            int lg = log2( level[v] );
            for ( j = 1; j <= lg; j++ )
                LCA[j][v] = LCA[j - 1][ LCA[j - 1][v] ];
        }
    }

    scanf( "%d", &P );
    scanf( "%d", &last ); last--;
    for ( i = 1; i < P; i++ ) {
        scanf( "%d", &next );
        next--;
        sol += dist( last, next );
        last = next;
    }

    printf( "%d\n", sol );

    return 0;
}
