/*
Alfonso Alfonso Peterssen
1 - 12 - 2007
SPOJ #300 "Cable TV Network"
*/
#include <cstdio>
#include <queue>
using namespace std;

const int
    MAXV = 101,
    oo = 1000000000;

int T, V, E, S, i, j, k;
int flow, sol;
int from[MAXV];
int cap[MAXV][MAXV],
    tmp_cap[MAXV][MAXV];
int P[MAXV];
struct edge {
    int v, next;
} ls[MAXV * MAXV];

    void connect( int i, int j ) {
        cap[i][j] = 1;
        ls[++S] = ( edge ) { j, P[i] };
        P[i] = S;
    }

    bool augment( int src, int snk ) {

        queue< int > Q;
        memset( from, 0, sizeof( from ) );
        from[src] = -1;

        int i, x, y;

        /* BFS */
        Q.push( src );
        while ( !Q.empty() && !from[snk] ) {

            x = Q.front();
            Q.pop();

            for ( i = P[x]; i; i = ls[i].next )
                if ( !from[ y = ls[i].v ] && tmp_cap[x][y] > 0 ) {
                    from[y] = x;
                    if ( y == snk ) break;
                    Q.push( y );
                }
        }

        if ( !from[snk] ) return false;

        /* Reflow */
        for ( i = snk; i != src; i = from[i] )
             tmp_cap[ from[i] ][i]--, tmp_cap[i][ from[i] ]++;

        return true;
    }

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        /* Init */
        S = 0;
        memset( P, 0, sizeof( P ) );
        memset( cap, 0, sizeof( cap ) );

        scanf( "%d %d", &V, &E );
        for ( i = 0; i < E; i++ ) {
            scanf( " (%d,%d)", &j, &k );
            j++; k++;
            connect( j + V, k );
            connect( k + V, j );
        }

        for ( i = 1; i <= V; i++ )
            connect( i, i + V );

        /* Solve */
        sol = oo;
        for ( i = 1; i <= V; i++ )
            for ( j = 1; j <= i; j++ ) {

                /* Reset */
                memcpy( tmp_cap, cap, sizeof( cap ) );

                flow = 0;
                while ( flow < sol && augment( i + V, j ) )
                    flow++;

                if ( flow == V - 1 ) flow = V;
                sol <?= flow;
            }

        if ( sol == oo ) sol = 0;

        printf( "%d\n", sol );
    }

    return 0;
}
