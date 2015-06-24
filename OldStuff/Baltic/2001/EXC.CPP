/*
Alfonso2 Peterssen
19 - 6 - 2008
BalticOI 2001 "Excursion"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXV = 20000;

int V, E;
int SCC;
int u, v;
int discover_time;
int scomp[MAXV];
int low[MAXV], dfsnum[MAXV];
bool mark[MAXV], used[MAXV], deleted[MAXV];
vector< int > G[MAXV], H[MAXV], C[MAXV];
vector< int > order;
stack< int > S;

int NOT( int x ) {
    return x < V ? x + V : x - V;
}

void dfs( int x ) {

    low[x] = dfsnum[x] = ++discover_time;
    S.push( x );

    REP( i, G[x].size() ) {
        int y = G[x][i];
        if ( !dfsnum[y] ) {
            dfs( y );
            low[x] <?= low[y];
        } else
            if ( !deleted[y] )
                low[x] <?= dfsnum[y];
    }

    if ( low[x] == dfsnum[x] ) {
        while ( !deleted[x] ) {
            deleted[ S.top() ] = true;
            scomp[ S.top() ] = SCC;
            S.pop();
        }
        SCC++;
    }
}

void topsort( int x ) {
    mark[x] = true;
    REP( i, H[x].size() ) {
        int y = H[x][i];
        if ( !mark[y] ) topsort( y );
    }
    order.push_back( x );
}

int main() {

    scanf( "%d %d", &E, &V );
    REP( i, E ) {
        scanf( "%d %d", &u, &v );
        if ( u < 0 ) u = -u + V;
        if ( v < 0 ) v = -v + V;
        u--; v--;
        G[ NOT( u ) ].push_back( v );
        G[ NOT( v ) ].push_back( u );
    }

    REP( i, 2 * V )
        if ( !dfsnum[i] )
            dfs( i );

    REP( i, V )
        if ( scomp[i] == scomp[ NOT( i ) ] ) {
            printf( "NO\n" );
            return 0;
        }

    REP( i, 2 * V )
        REP( j, G[i].size() )
            H[ scomp[i] ].push_back( scomp[ G[i][j] ] );

    REP( i, SCC )
        if ( !mark[i] )
            topsort( i );

    fill( mark, mark + SCC, false );

    REP( i, 2 * V )
        C[ scomp[i] ].push_back( i );

    REP( i, SCC )
        if ( !mark[ order[i] ] )
            REP( j, C[ order[i] ].size() ) {
                u = C[ order[i] ][j];
                used[u] = true;
                mark[ scomp[ NOT(u) ]  ] = true;
            }

    printf( "%d\n", count( used, used + V, true ) );
    REP( i, V )
        if ( used[i] )
            printf( "%d ", i + 1 );

    return 0;
}
