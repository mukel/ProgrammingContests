/*
Alfonso2 Peterssen
15 - 5 - 2008
Saratov #239 "Minesweeper"
*/
#include <cstdio>

const int MAXN = 2000;

int N, i, sol;
int last, cent, next;
int mines[MAXN];

int main() {

    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ )
        scanf( "%d", &mines[i] );

    last = cent = next = 0;
    cent = 0;
    for ( i = 1; i <= N; i++ ) {
        next = mines[i] - cent - last;
        if ( next < 0 || next > 1 ) // Ooops
            break;
        last = cent;
        cent = next;
    }

    if ( i > N && next == 0 )
        sol++;

    last = cent = next = 0;
    cent = 1;
    for ( i = 1; i <= N; i++ ) {
        next = mines[i] - cent - last;
        if ( next < 0 || next > 1 ) // Ooops
            break;
        last = cent;
        cent = next;
    }

    if ( i > N && next == 0 )
        sol++;

    printf( "%d\n", sol );

    return 0;
}
