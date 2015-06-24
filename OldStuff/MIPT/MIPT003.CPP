/*
Alfonso2 Peterssen
17 - 7 - 2008
MIPT #003 "Contest Table"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
    for ( int i = (n) - 1; i >= 0; i-- )

const int MAXV = 200;

int V;
char line[2 * MAXV];
int SCC;
int discover_time;
int low[MAXV];
int dfsnum[MAXV];
bool deleted[MAXV];
int comp[MAXV];
bool mark[MAXV];
bool used[MAXV];
stack< int > S;
vector< int > order;
vector< int > sol;
vector< int > G[MAXV];

void dfs( int x ) {

    S.push( x );
    dfsnum[x] = low[x] = ++discover_time;
    
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
            comp[S.top()] = SCC;
            deleted[S.top()] = true;
            S.pop();
        }
        order.push_back( SCC );
        SCC++;
    }
}

void print_comp( int x, int id ) {
    used[x] = true;
    REP( i, G[x].size() ) {
        int y = G[x][i];
        if ( !used[y] && comp[y] == id )
            print_comp( y, id );
    }
    sol.push_back( x + 1 );
}

int main() {

    scanf( "%d", &V );
    REP( i, V ) {
        scanf( "%s", &line );
        REP( j, i )
            if ( line[j] == '+' )
                 G[i].push_back( j );
            else G[j].push_back( i );
    }
    
    REP( i, V )
        if ( !dfsnum[i] )
            dfs( i );

    REP( i, SCC ) {
        int c = order[i];
        REP( j, V )
            if ( !used[j] && comp[j] == c )
                print_comp( j, c );
    }
    
    REPD( i, V )
        printf( "%d ", sol[i] );
    printf( "\n" );
            
    return 0;
}
