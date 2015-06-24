/*
Alfonso Alfonso Peterssen
21 - 2 - 2008
CNC 2008 Task 1A "Imagen"
Fucking Fast I/O
*/
#include <cstdio>

const int
    MAXC = 20000,
    oo = 1 << 30;

int f, c, i, j;
int x1, y1, x2, y2;
char line[MAXC];

int main() {

    x1 = y1 = +oo;
    x2 = y2 = -oo;
    scanf( "%d%d\n", &f, &c );
    for ( i = 0; i < f; i++ ) {
        gets( line );
        for ( j = 0; j < c; j++ )
            if ( line[j] == '1' ) {
                x1 <?= j; x2 >?= j + 1;
                y1 <?= i; y2 >?= i + 1;
                break;
            }
        for ( j = c - 1; j >= 0; j-- )
            if ( line[j] == '1' ) {
                x1 <?= j; x2 >?= j + 1;
                y1 <?= i; y2 >?= i + 1;
                break;
            }
    }

    if ( x1 == oo )
         printf( "0\n" );
    else printf( "%d\n", 2 * ( x2 - x1 + y2 - y1 ) );

    return 0;
}
