/*
Alfonso2 Peterssen
19 - 6 - 2008
BalkanOI 2004 "TEAM SELECTION"
*/
#include <cstdio>
#include <cstring>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 600000;

int N, sol, x;
int P[3][MAXN];
int T[MAXN];

int lobit( int x ) { return x & -x; }

int query( int x ) {
    int res = 1 << 30;
    for ( ; x > 0; x -= lobit( x ) )
        res <?= T[x];
    return res;
}

void update( int x, int value ) {
    for ( ; x <= N; x += lobit( x ) )
        T[x] <?= value;
}

int main() {

    scanf( "%d", &N );

    REP( i, 3 )
    REP( j, N ) {
        scanf( "%d", &x );
        if ( !i )
             P[i][j] = x;
        else P[i][x] = j + 1;
    }

    memset( T, 63, sizeof( T ) );

    REP( i, N )
        if ( query( P[1][P[0][i]] ) > P[2][P[0][i]] ) {
            update( P[1][P[0][i]], P[2][P[0][i]] );
            sol++;
        }

    printf( "%d\n", sol );

    return 0;
}
