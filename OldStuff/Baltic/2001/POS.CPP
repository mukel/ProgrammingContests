/*
Alfonso2 Peterssen
10 - 6 - 2008
BalticOI 2001 "Postman"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair< int, int > par;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int
    MAXV = 1000,
    MAXE = 100000;

int V, E;
int u, v;
int used[MAXE];
vector< par > G[MAXV];

void eulerize( int u ) {
    REP( i, G[u].size() ) {
        int id = G[u][i].second;
        if ( !used[id] ) {
            used[id] = true;
            eulerize( G[u][i].first );
        }
    }
    printf( "%d ", u + 1 );
}

int main() {

    scanf( "%d %d", &V, &E ) ;
    REP( i, V )
        scanf( "%*d" ); // reads nothing
    REP( i, E ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( par( v, i ) );
        G[v].push_back( par( u, i ) );
    }

    printf( "%d\n", E ); eulerize( 0 ); printf( "\n" );

    return 0;
}
