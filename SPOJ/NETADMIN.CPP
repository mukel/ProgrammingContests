/*
Alfonso Alfonso Peterssen
8 - 12 - 2007
SPOJ #287 "Smart Network Administrator"
*/
#include <cstdio>
#include <queue>
using namespace std;

const int
    MAXV = 501,
    MAXE = 250001,
    snk = 1; /* Admin's House */

int T, V, E, H, i, j, k;
int lo, hi, mid;
int house[MAXV];
int P[MAXV], from[MAXV];
struct edge {
    int u, v, cap, next;
} ls[ 2 * MAXE ];

    bool augment( int src ) {

        int i, x, y;

        queue< int > Q;
        memset( from, 0, sizeof( from ) );
        from[src] = -1;

        /* BFS */
        Q.push( src );
        while ( !Q.empty() && !from[snk] ) {

            x = Q.front();
            Q.pop();

            for ( i = P[x]; i; i = ls[i].next )
                if ( !from[ y = ls[i].v ] && ls[i].cap > 0 ) {
                    from[y] = i; /* save the edge */
                    if ( y == snk ) break;
                    Q.push( y );
                }
        }

        if ( !from[snk] ) return false;

        /* Reflow */
        for ( i = snk; i != src; i = ls[ from[i] ].u ) {
            x = from[i];
            ls[x].cap--;
            ( x > E ) ? ls[x - E].cap++ : ls[x + E].cap++;
        }

        return true;
    }

    bool ok( int colors ) {

        int i;
        for ( i = 1; i <= 2 * E; i++ )
            ls[i].cap = colors;

        for ( i = 0; i < H; i++ )
            if ( !augment( house[i] ) )
                return false;

        return true;
    }

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        /* Init */
        memset( P, 0, sizeof( P ) );

        scanf( "%d %d %d", &V, &E, &H );
        for ( i = 0; i < H; i++ )
            scanf( "%d", &house[i] );

        for ( i = 1; i <= E; i++ ) {
            scanf( "%d %d", &j, &k );
            ls[i] = ( edge ) { j, k, 0, P[j] };
            P[j] = i;
            ls[E + i] = ( edge ) { k, j, 0, P[k] };
            P[k] = E + i;
        }

        /* BS */
        lo = 1, hi = H;
        while ( lo <= hi ) {
            mid = ( lo + hi ) / 2;
            if ( ok( mid ) )
                 hi = mid - 1;
            else lo = mid + 1;
        }

        printf( "%d\n", hi + 1 );
    }

    return 0;
}
