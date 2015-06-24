/*
Alfonso2 Peterssen
22 - 6 - 2008
PolishOI 2001 "Peaceful Commission"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXV = 40000;

int V, E;
int SCC;
int u, v;
int discover_time;
int low[MAXV];
int dfsnum[MAXV];
int scomp[MAXV];
bool mark[MAXV];
bool used[MAXV];
bool deleted[MAXV];
vector< int > G[MAXV], C[MAXV];
vector< int > order;
stack< int > S;

int NOT( int x ) {
    return x < V ? x + V : x - V;
}

void dfs( int x ) {

    dfsnum[x] = low[x] = ++discover_time;
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

    if ( dfsnum[x] == low[x] ) {
        while ( !deleted[x] ) {
            deleted[ S.top() ] = true;
            scomp[ S.top() ] = SCC;
            S.pop();
        }
        order.push_back( SCC );
        SCC++;
    }
}

int main() {

    scanf( "%d %d", &V, &E );
    V = V * 2;
    REP( i, E ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        /* They can't be together */
        u = NOT( u );
        v = NOT( v );
        G[ NOT(u) ].push_back( v );
        G[ NOT(v) ].push_back( u );
    }

    REP( i, V ) {
        if ( !(i & 1) )
            continue;
        /* There is someone */
        u = i;
        v = i - 1;
        G[ NOT(u) ].push_back( v );
        G[ NOT(v) ].push_back( u );
        /* And only one */
        u = NOT( i );
        v = NOT( i - 1 );
        G[ NOT(u) ].push_back( v );
        G[ NOT(v) ].push_back( u );
    }

    REP( i, 2 * V )
        if ( !dfsnum[i] )
            dfs( i );

    REP( i, V )
        if ( scomp[i] == scomp[ NOT(i) ] ) {
            printf( "NIE\n" );
            return 0;
        }

    REP( i, 2 * V )
        C[ scomp[i] ].push_back( i );

    REP( i, SCC )
        if ( !mark[ order[i] ] )
            REP( j, C[ order[i] ].size() ) {
                int x = C[ order[i] ][j];
                used[x] = true;
                mark[ scomp[ NOT(x) ] ] = true;
            }

    REP( i, V )
        if ( used[i] )
            printf( "%d\n", i + 1 );

    return 0;
}
