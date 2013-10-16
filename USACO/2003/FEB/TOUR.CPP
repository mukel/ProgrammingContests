/*
Alfonso2 Peterssen
4 - 6 - 2008
USACO FEB03 "Farm Tour"
*/
#include <cstdio>
#include <algorithm>

using std::fill;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )
    
const int
    MAXV = 1000,
    MAXE = 20000,
    oo = 1 << 29;
    
int V, E;
int u, v, w;
int src[MAXE];
int dst[MAXE];
int len[MAXE];
int from[MAXV];
int dist[MAXV];

int augment() {

    fill( from, from + V, -1 );
    fill( dist, dist + V, oo );
    dist[0] = 0;

    REP( i, V )
    REP( j, 2 * E ) {
        int cost = dist[ src[j] ] + len[j];
        if ( cost < dist[ dst[j] ] ) {
            dist[ dst[j] ] = cost;
            from[ dst[j] ] = j;
        }
    }
    
    for ( int i = from[V - 1]; i != -1; i = from[ src[i] ] ) {
        len[i] = oo;
        len[i^1] = -len[i^1];
    }
    
    return dist[V - 1];
}

int main() {

    scanf( "%d %d", &V, &E );
    REP( i, E ) {
        scanf( "%d %d %d", &u, &v, &w );
        u--; v--;
        src[2 * i] = dst[2 * i + 1] = u;
        dst[2 * i] = src[2 * i + 1] = v;
        len[2 * i] = len[2 * i + 1] = w;
    }
    
    printf( "%d\n", augment() + augment() );

    return 0;
}
