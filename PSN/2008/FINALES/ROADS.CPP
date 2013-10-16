/*
Alfonso2 Peterssen
19 - 4 - 2008
TASK: ROADS
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int
    MAXV = 1000,
    MAXE = 100000;

typedef pair< int, int > par;

int V, E, BCC, sol;
int i, j, u, v;
int bcomp[MAXV];
vector< par > G[MAXV];
stack< int > S;
bool used[MAXE];
int discover_time;
int dfsnum[MAXV];
int low[MAXV];
int cant[MAXV];

void dfs( int node ) {

    S.push( node );
    dfsnum[node] = low[node] = ++discover_time;
    
    for ( int i = 0; i < G[node].size(); i++ ) {
        if ( used[ G[node][i].second ] )
            continue;
        int next = G[node][i].first;
        if ( !dfsnum[next] ) {
            used[ G[node][i].second ] = true;
            dfs( next );
            low[node] <?= low[next];
        } else
            low[node] <?= dfsnum[next];
    }
    
    if ( dfsnum[node] == low[node] ) {
        while ( S.top() != node ) {
            bcomp[ S.top() ] = BCC;
            S.pop();
        }
        bcomp[ S.top() ] = BCC;
        S.pop();
        BCC++;
    }
}

int main() {

    #warning READ FROM FILES!!!

    freopen( "roads.in", "r", stdin );
    freopen( "roads.out", "w", stdout );

    scanf( "%d %d", &V, &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( par( v, i ) );
        G[v].push_back( par( u, i ) );
    }
    
    dfs( 0 );
    
    if ( BCC <= 1 ) {
        printf( "0\n" );
        fflush( stdout );
        exit( 0 );
    }
    
    for ( i = 0; i < V; i++ )
        for ( j = 0; j < G[i].size(); j++ )
            if ( bcomp[ G[i][j].first ] != bcomp[i] ) {
                cant[ bcomp[i] ]++;
                cant[ bcomp[ G[i][j].first ] ]++;
            }

    for ( i = 0; i < BCC; i++ ) {
        cant[i] /= 2;
        if ( cant[i] <= 1 )
            sol++;
    }
    
    printf( "%d\n", ( sol + 1 ) / 2 );
    fflush( stdout );

    return 0;
}
