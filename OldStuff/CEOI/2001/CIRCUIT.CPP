/*
Alfonso2 Peterssen
7 - 6 - 2008
CEOI 2002 Day 1 "Printed Circuit"
Simple MST
*/
#include <cstdio>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

#define ID( x, y ) ( (x) * C + (y) )

const int MAXN = 10000;

int F, C;
int sol, cant;
int P[MAXN];
int x[MAXN];
int y[MAXN];
int d[MAXN];

int FIND( int x ) {
    return ( x != P[x] ) ? P[x] = FIND( P[x] ) : x;
}

bool UNION( int x, int y ) {
    int u = FIND( x );
    int v = FIND( y );
    if ( u != v ) P[u] = v;
    return u != v;
}

int main() {

    scanf( "%d %d", &F, &C );
    REP( i, F * C ) P[i] = i;

    REP( i, F )
    REP( j, C ) {
        int x;
        scanf( "%d", &x );
        if ( x == 1 || x == 3 )
            UNION( ID( i, j ), ID( i + 1, j ) );
        if ( x == 2 || x == 3 )
            UNION( ID( i, j ), ID( i, j + 1 ) );
    }

    REP( i, F - 1 )
    REP( j, C )
        if ( UNION( ID( i, j ), ID( i + 1, j ) ) ) {
            sol += 1;
            x[cant] = i + 1;
            y[cant] = j + 1;
            d[cant] = 1;
            cant++;
        }

    REP( i, F )
    REP( j, C - 1 )
        if ( UNION( ID( i, j ), ID( i, j + 1 ) ) ) {
            sol += 2;
            x[cant] = i + 1;
            y[cant] = j + 1;
            d[cant] = 2;
            cant++;
        }

    printf( "%d %d\n", cant, sol );
    REP( i, cant )
        printf( "%d %d %d\n", x[i], y[i], d[i] );

    return 0;
}
