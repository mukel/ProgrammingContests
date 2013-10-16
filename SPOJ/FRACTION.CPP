/*
Alfonso Alfonso Peterssen
30 - 11 - 2007
SPOJ #403 "Sort fractions"
*/
#include <cstdio>

const int MAXFRAC = 7600459;

typedef short int int16;

int T, N, Q, count, pos;
struct fraction {
    int16 num, den;
} ls[MAXFRAC];

    void find( int16 a, int16 b, int16 c, int16 d ) {
        if ( a + c > N || b + d > N ) return;
        find( a, b, a + c, b + d );
        ls[count++] = ( fraction ) { a + c, b + d };
        find( a + c, b + d, c, d );
    }

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        scanf( "%d %d", &N, &Q );

        count = 0;
        ls[count++] = ( fraction ) { 0, 1 };
        find( 0, 1, 1, 1 );
        ls[count++] = ( fraction ) { 1, 1 };

        for ( ; Q; Q-- ) {
            scanf( "%d", &pos ); pos--;
            printf( "%d/%d\n", ls[pos].num, ls[pos].den ) ;
        }
    }

    return 0;
}
