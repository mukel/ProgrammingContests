/*
Alfonso2 Peterssen
29 - 5 - 2008
USACO OPEN08 Silver "Potencia de Palabra"
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::fill;

/* fors++  */
#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
    for ( int i = (n) - 1; i >= 0; i-- )
#define FOR( i, s, e ) \
    for ( int i = s; i <= (e); i++ )

const int
    MAXN = 1000,
    MAXM = 100,
    MAXLEN = 1002;

int N, M;
int sz[MAXM];
char words[MAXN][MAXLEN];
char goods[MAXM][MAXLEN];
int next[MAXLEN][0x100];

int quality( int idx ) {

    /* Preprocess */
    int len = strlen( words[idx] );
    REP( i, len )
        if ( words[idx][i] < 'a' )
            words[idx][i] += 'a' - 'A';

    FOR( i, 1, len ) {
        FOR( j, 'a', 'z' )
            next[i][j] = next[i - 1][j];
        next[i][ words[idx][i - 1] ] = i - 1;
    }

    int cant = 0;
    REP( i, M ) {
        int pos = len;
        REPD( j, sz[i] ) {
            pos = next[pos][ goods[i][j] ];
            if ( pos == -1 )
                break;
        }
        if ( pos != -1 )
            cant++;
    }

    return cant;
}

int main() {

    freopen( "wordpow.in", "r", stdin );
    freopen( "wordpow.out", "w", stdout );

    scanf( "%d %d", &N, &M );
    REP( i, N )
        scanf( "%s", &words[i] );

    REP( i, M ) {
        scanf( "%s", &goods[i] );
        sz[i] = strlen( goods[i] );
        REP( j, sz[i] )
            if ( goods[i][j] < 'a' )
                goods[i][j] += 'a' - 'A';
    }

    fill( next[0], next[0] + 0x100, -1 );
    REP( i, N )
        printf( "%d\n", quality( i ) );

    return 0;
}
