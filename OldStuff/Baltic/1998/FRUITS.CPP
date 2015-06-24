/*
Alfonso2 Peterssen
31 - 5 - 2008
BalticOI 1998 "Fruits"
*/
#include <cstdio>
#include <cstring>

/* fors++  */
#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )
#define FORD( i, s, e ) \
    for ( int i = (e); i >= (s); i-- )

const int
    MAXN = 100,
    KG = 1000;

int N;
int fruits[MAXN];
int from[KG + 1];

int main() {

    scanf( "%d", &N );

    memset( from, -1, sizeof( from ) );
    from[0] = -2;
    REP( i, N ) {
        scanf( "%d", &fruits[i] );
        FORD( j, fruits[i], KG ) {
            if ( from[ j - fruits[i] ] != -1 )
                from[j] = i;
        }
    }

    if ( from[KG] == -1 )
        printf( "NO\n" );
    else {
        int pos = KG;
        while ( from[pos] != -2 ) {
            printf( "%d\n", fruits[ from[pos] ] );
            pos -= fruits[ from[pos] ];
        }
    }

    return 0;
}
