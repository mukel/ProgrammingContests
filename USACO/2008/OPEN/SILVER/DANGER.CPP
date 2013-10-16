/*
Alfonso2 Peterssen
29 - 5 - 2008
USACO OPEN08 Silver "Peligro Claro y Presente"
*/
#include <cstdio>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int
    MAXV = 100,
    MAXP = 10000;

int V, P, sol;
int dist[MAXV][MAXV];
int path[MAXP];

int main() {

    freopen( "danger.in", "r", stdin );
    freopen( "danger.out", "w", stdout );

    scanf( "%d %d", &V, &P );
    REP( i, P )
        scanf( "%d", &path[i] );

    REP( i, V )
    REP( j, V )
        scanf( "%d", &dist[i][j] );

    REP( k, V )
    REP( i, V )
    REP( j, V )
        dist[i][j] <?= dist[i][k] + dist[k][j];

    REP( i, P - 1 )
        sol += dist[ path[i] - 1 ][ path[i + 1] - 1 ];

    printf( "%d\n", sol );

    return 0;
}
