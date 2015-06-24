/*
Alfonso Alfonso Peterssen
16 - 2 - 2008
Saratov #218 "Unstable Systems"
*/
#include <cstdio>
#include <algorithm>

using std::fill;

const int
    MAXV = 500,
    MAXC = 1000000;

int V, i, j;
int lo, hi, limit;
bool mark[MAXV];
int from[MAXV];
int sol[MAXV];
int G[MAXV][MAXV];

    bool augment( int node ) {

        if ( mark[node] )
            return false;

        mark[node] = true;
        for ( int i = 0; i < V; i++ )
            if ( G[node][i] <= limit &&
               ( from[i] < 0 || augment( from[i] ) ) ) {
                from[i] = node;
                return true;
            }

         return false;
    }

    bool find_match() {

        fill( from, from + V, -1 );
        for ( int i = 0; i < V; i++ ) {
            fill( mark, mark + V, false );
            if ( !augment( i ) )
                return false;
        }

        for ( int i = 0; i < V; i++ )
            sol[ from[i] ] = i;

        return true;
    }

int main() {

    lo = +MAXC;
    hi = -MAXC;

    scanf( "%d", &V );
    for ( i = 0; i < V; i++ )
        for ( j = 0; j < V; j++ ) {
            scanf( "%d", &G[i][j] );
            lo <?= G[i][j];
            hi >?= G[i][j];
    }
    
    while ( lo <= hi ) {
        limit = ( lo + hi ) / 2;
        if ( find_match() )
             hi = limit - 1;
        else lo = limit + 1;
    }

    printf( "%d\n", hi + 1 );
    for ( i = 0; i < V; i++ )
        printf( "%d %d\n", i + 1, sol[i] + 1 );

    return 0;
}
