/*
Alfonso Alfonso Peterssen
15 - 2 - 2008
Saratov #179 "Brackets light"
*/
#include <cstdio>
#include <cstring>

const int MAXLEN = 10000;

int len, i, from, x, y, a, b;
char st[MAXLEN + 1];

int main() {

    scanf( "%s", &st );
    len = strlen( st );

    for ( i = 0; i < len; i++ )
        if ( st[i] == '(' ) {
            if ( x < y ) {
                from = i;
                a = len / 2 - x;
                b = len / 2 - y;
            }
            y++;
        }
        else x++;

    if ( from == 0 )
        printf( "No solution\n" );
    else {
        st[from] = ')'; a--;
        for ( i = 0; i < b; i++ ) st[++from] = '(';
        for ( i = 0; i < a; i++ ) st[++from] = ')';
        printf( "%s", st );
    }

    return 0;
}
