/*
Alfonso2 Peterssen
20 - 6 - 2008
BalticOI 2002 "Speed Limits"
*/
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

typedef pair< int, int > par;
typedef pair< double, par > triple;

const double oo = 1e10;

const int
    MAXV = 150,
    MAXS = 501,
    MAXE = 60000;

int V, E, D;
int u, v, l, s;
int first[MAXV];
int next[MAXE];
par from[MAXV][MAXS];
double dist[MAXV][MAXS];
int src[MAXE], dst[MAXE];
int lim[MAXE], len[MAXE];
set< triple > S;

void print( int x, int s ) {
    if ( x == 0 ) { printf( "0" ); return ; }
    print( from[x][s].first, from[x][s].second );
    printf( " %d", x );
}

int main() {

    memset( first, -1, sizeof( first ) );

    scanf( "%d %d %d", &V, &E, &D );
    REP( i, E ) {
        scanf( "%d %d %d %d", &src[i], &dst[i], &lim[i], &len[i] );
        next[i] = first[ src[i] ];
        first[ src[i] ] = i;
    }

    REP( i, V )
        REP( j, MAXS )
            dist[i][j] = oo;

    dist[0][70] = 0.;
    S.insert( triple( 0., par( 0, 70 ) ) );

    /* Dijkstra */
    while ( !S.empty() ) {
        triple top = *(S.begin());
        S.erase( S.begin() );
        u = top.second.first;
        l = top.second.second;
        if ( u == D ) { print( D, l ); printf( "\n" ); return 0; }
        for ( int i = first[u]; i != -1; i = next[i] ) {
            v = dst[i];
            s = lim[i];
            if ( s == 0 ) s = l;
            double cost = len[i] / (double)s;
            if ( top.first + cost < dist[v][s] ) {
                if ( dist[v][s] != oo )
                    S.erase( S.find( triple( dist[v][s], par( v, s ) ) ) );
                dist[v][s] = top.first + cost;
                from[v][s] = top.second;
                S.insert( triple( dist[v][s], par( v, s ) ) );
            }
        }
    }

    return 0;
}
