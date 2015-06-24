/*
Alfonso2 Peterssen
30 - 5 - 2008
BalkanOI 2004 "Race"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXV = 2001;

int V, E, cant;
int dummy;
int u, v, w;
int x[MAXV];
int y[MAXV];
vector< int > G[MAXV];
int dist[MAXV][MAXV];
int from[MAXV][MAXV];
int sol[10 * MAXV];

struct state {
    int u, v, w;
    bool operator < ( const state &s ) const {
        if ( w != s.w ) return w > s.w;
        return ( u != s.u ) ? u < s.u : v < s.v;
    }
};
set< state > S;

int sqr( int x ) { return x * x; }
int sign( int x ) { return ( x > 0 ) - ( x < 0 ); }

int mydist( int i, int j ) {
    return sqr( x[i] - x[j] ) + sqr( y[i] - y[j] );
}

bool turn_left( int a, int b, int c ) {
    int cp = ( x[b] - x[a] ) * ( y[c] - y[a] ) -
             ( x[c] - x[a] ) * ( y[b] - y[a] );
    if ( cp == 0 ) // move only forward
        return ( sign( x[c] - x[b] ) == sign( x[b] - x[c] ) &&
                 sign( y[c] - y[b] ) == sign( y[b] - y[c] ) );
    return cp > 0;
}

int main() {

    scanf( "%d %d", &V, &E );
    REP( i, V )
        scanf( "%d %d", &x[i], &y[i] );
    REP( i, E ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( v );
        G[v].push_back( u );
    }

    /* Init */
    dummy = V++;
    x[dummy] = x[0]; y[dummy] = y[0];
    REP( i, G[0].size() ) {
        int next = G[0][i];
        G[next].push_back( dummy );
        dist[0][next] = mydist( 0, next );
        S.insert( (state){ 0, next, dist[0][next] } );
    }

    /* Dijkstra */
    for (;;) {

        state top = *S.begin();
        S.erase( S.begin() );
        u = top.u;
        v = top.v;
        w = top.w;

        if ( v == dummy ) {
            // we find a cycle
            while ( u != 0 )   {
                sol[cant++] = u;
                w = u;
                u = from[u][v];
                v = w;
            }
            sol[cant++] = 0;
            printf( "%d\n", cant );
            for ( int i = cant - 1; i >= 0; i-- )
                printf( "%d ", sol[i] + 1 );
            printf( "%d\n" );
            return 0;
        }

        REP( j, G[v].size() ) {

            int next = G[v][j];
            if ( turn_left( u, v, next ) ) {
                int cost = min( w, mydist( v, next ) );
                if ( cost > dist[v][next] ) {

                    if ( dist[v][next] != 0 )
                        S.erase( S.find( (state){ v, next, dist[v][next] } ) );

                    dist[v][next] = cost;
                    S.insert( (state){ v, next, cost } );
                    from[v][next] = u;
                }
            }
        }

    }

    return 0;
}
