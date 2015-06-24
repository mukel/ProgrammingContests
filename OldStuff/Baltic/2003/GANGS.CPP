/*
Alfonso Alfonso Peterssen
12 - 3 - 2008
Baltic 2003 Day 2 "Gangs"
*/
#include <iostream>
#include <vector>

using namespace std;

const int MAXV = 1000;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

int V, E, u, v, sol;
int P[MAXV];
vector< int > G[2][MAXV];

int FIND( int x ) {
    if ( P[x] != x ) P[x] = FIND( P[x] );
    return P[x];
}

void UNION( int x, int y ) {
    P[ FIND( x ) ] = FIND( y );
}

int main() {

    cin >> V >> E;
    REP( i, E ) {
        char ch;
        cin >> ch >> u >> v;
        u--; v--;
        G[ch == 'E'][u].push_back( v );
        G[ch == 'E'][v].push_back( u );
    }

    REP( i, V ) P[i] = i;

     REP( i, V )
        REP( j, G[0][i].size() )
            UNION( i, G[0][i][j] );

    REP( i, V )
        REP( j, G[1][i].size() ) {
            int g1 = G[1][i][j];
            REP( k, G[1][g1].size() ) {
                int g2 = G[1][g1][k];
                UNION( i, g2 );
            }
        }

    REP( i, V )
        if ( P[i] == i ) sol++;

    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
