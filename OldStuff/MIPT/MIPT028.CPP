/*
Alfonso2 Peterssen
18 - 7 - 2008
MIPT #028 "Circle Game"
*/
#include <cstdio>

#define REP( i, n ) \
    for ( register int i = 0, __e = (n); i < __e; i++ )

const int MAXK = 30;

int K, M;
int next[MAXK];
int last[MAXK];

bool valid( int m ) {
    m--;

    REP( i, 2 * K ) {
        next[i] = i + 1;
        last[i] = i - 1;
    }
    next[2 * K - 1] = 0;
    last[0] = 2 * K - 1;

    int kid = 0;
    REP( i, K ) {
        REP( j, m % ( 2 * K - i ) )
            kid = next[kid];
        if ( kid < K )
            return 0;
        next[ last[kid] ] = next[kid];
        last[ next[kid] ] = last[kid];
        kid = next[kid];
    }

    return 1;
}

int main() {

    scanf( "%d", &K );
    for ( M = K + 1; !valid( M ); M++ );
    printf( "%d\n", M );

    return 0;
}
