/*
Alfonso Alfonso Peterssen
1 - 3 - 2008
POI 2003 Stage I "Sequences without Stammers"
Using Thue-Morse Sequence
*/
#include <cstdio>

const int MAXLEN = 1000000;

int n, l, i, j;
char s[MAXLEN + 1];

int main() {

    scanf( "%d", &n );

    if ( n == 3 ) {
        printf( "3\naba\n" );
        return 0;
    }

    s[l++] = 0;
    s[l++] = 1;
    while ( l <= n ) {
        int last = l;
        for ( i = last / 2; i < last && l <= n; i++ ) {
            s[l++] =  s[i];
            s[l++] = !s[i];
        }
    }

    printf( "%d\n", 3 <? n );
    for ( i = 0; i < n; i++ ) {
        j = ( s[i] == s[i + 1] ? 2 : s[i] );
        putchar( j + 'a' );
    }
    
    putchar( '\n' );

    return 0;
}
