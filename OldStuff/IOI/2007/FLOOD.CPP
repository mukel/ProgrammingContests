/*
Alfonso2 Peterssen
9 - 5 - 2008
IOI 2007 Task "Flood"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair< int, int > par;

const int MAXN = 100000;
const par EMPTY = par( 0, 0 );

#define POSSIBLE( p, d ) \
    (! ( G[p][d] == EMPTY || \
       ( mark[ G[p][d].second ] != 0 && \
         mark[ G[p][d].second ] != pass ) ) )

int N, W;
int u, v, i;
int pass;
int idx[MAXN];
int mark[2 *MAXN];
par points[MAXN];
par G[MAXN][4];

bool point_cmp( const int &i, const int &j ) {
    return points[i] < points[j];
}

int angle( int i, int j ) {
    // 0right, 1up, 2left, 3down
    int xi = points[i].first; int yi = points[i].second;
    int xj = points[j].first; int yj = points[j].second;
    if ( yi == yj ) return ( xi > xj ) * 2 + 0;
    if ( xi == xj ) return ( yi > yj ) * 2 + 1;
}

void spiderman_thing( int start, int dir ) {
    pass++;
    int now = start;
    if ( !POSSIBLE( now, dir ) ) return ;
    do {
        dir = ( dir + 3 ) % 4;
        while ( !POSSIBLE( now, dir ) )
            dir = ( dir + 1 ) % 4;
        int wall = G[now][dir].second;
        if ( mark[wall] == pass )
             mark[wall] = -1;
        else mark[wall] = pass;
        now = G[now][dir].first;
    } while ( now != start );
}

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d", &u, &v );
        points[i] = par( u, v );
        idx[i] = i;
    }

    scanf( "%d", &W );
    for ( i = 1; i <= W; i++ ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u][ angle( u, v ) ] = par( v, i );
        G[v][ angle( v, u ) ] = par( u, i );
    }

    sort( idx, idx + N, point_cmp );
    for ( i = 0; i < N; i++ )
        spiderman_thing( idx[i], 0 ), // left
        spiderman_thing( idx[i], 1 ); // up

    int sol = count( mark, mark + W + 1, -1 );
    printf( "%d\n", sol );
    for ( i = 1; i <= W; i++ )
        if ( mark[i] == -1 )
            printf( "%d\n", i );

    return 0;
}
