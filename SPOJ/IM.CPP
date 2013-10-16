/*
Alfonso Alfonso Peterssen
26 - 11 - 2007
SPOJ #962 "Intergalactic Map"
*/
#include <cstdio>
#include <queue>
using namespace std;

const int
    MAXV = 40012,
    MAXE = 60012,
    snk = 2;

int T, V, E, i, j, k;
int P[MAXV];
int from[MAXV];
struct edge {
    int u, v, cap, next;
} ls[ 2 * MAXE ];

    bool augment( int src ) {

        queue< int > Q;
        memset( from, 0, sizeof( from ) );

        int i, x, y;

        /* BFS */
        Q.push( src );
        while ( !Q.empty() && !from[snk] ) {

            x = Q.front(); Q.pop();

            for ( i = P[x]; i; i = ls[i].next )
                if ( !from[ y = ls[i].v ] && ls[i].cap > 0 ) {
                    from[y] = i; // save the edge
                    if ( y == snk ) break;
                    Q.push( y );
                }
        }

        if ( !from[snk] ) return false;

        /* Reflow */
        for ( i = snk; i != src; i = ls[ from[i] ].u ) {
            j = from[i];
            ls[j].cap--;
            ( j > E ) ? ls[j - E].cap++ : ls[j + E].cap++;
        }

        return true;
    }

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        /* Init */
        memset( P, 0, sizeof( P ) );

        scanf( "%d %d", &V, &E );

        for ( i = 1; i <= E; i++ ) {

            scanf( "%d %d", &j, &k );

            ls[i] = ( edge ) { j, k, 1, P[j] };
            P[j] = i;

            ls[E + i] = ( edge ) { k, j, 1, P[k] };
            P[k] = E + i;
        }

        /* Find 2 Disjoint Paths */
        if ( augment( 1 ) && augment( 3 ) )
             printf( "YES\n" );
        else printf( "NO\n" );
    }

    return 0;
}
