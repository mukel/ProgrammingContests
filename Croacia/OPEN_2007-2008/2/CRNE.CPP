/*
Alfonso Alfonso Peterssen
24 - 11 - 2007
COCI 2007 Contest 2 "CRNE"
*/
#include <cstdio>

int cuts, x, sol;

int main() {

    scanf( "%d", &cuts );

    x = cuts / 2 + 1;

    sol = x * x;
    if ( cuts & 1 ) sol += x;

    printf( "%d\n", sol );

    return 0;
}
