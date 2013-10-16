/*
Alfonso Alfonso Peterssen
11 - 6 - 2008
IOI 2002 "Bus Terminals"
*/
#include <cstdio>
#include <algorithm>

using std::sort;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXV = 500;

int V, diam;
int X[MAXV];
int Y[MAXV];
int idx[MAXV];
int D[MAXV][MAXV];
int src, hi;

bool comp( const int &i, const int &j ) {
    return D[src][i] > D[src][j]; // reverse
}

int main() {

    scanf( "%d", &V );
    REP( i, V ) {
        scanf( "%d %d", &X[i], &Y[i] );
        idx[i] = i;
    }

    REP( i, V )
    REP( j, i )
        D[i][j] = D[j][i] = abs( X[i] - X[j] ) + abs( Y[i] - Y[j] );

    diam = 1000000000;
    REP( i, V ) {
        src = i;
        sort( idx, idx + V, comp );
        REP( j, i )
            for ( int k = hi = 0; k < V; k++ )
                if ( D[ idx[k] ][j] > D[ idx[hi] ][j] ) {
                    diam <?= D[ idx[k] ][i] + D[ idx[hi] ][j] + D[i][j];
                    hi = k;
                }
    }

    printf( "%d\n", diam );

    return 0;
}
