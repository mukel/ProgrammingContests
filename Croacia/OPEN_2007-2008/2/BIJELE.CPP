/*
Alfonso Alfonso Peterssen
24 - 11 - 2007
COCI 2007 Contest 2 "BIJELE"
*/
#include <cstdio>

int main() {

    int target[6] = { 1, 1, 2, 2, 2, 8 };

    for ( int i = 0; i < 6; i++ ) {
        int cant;
        scanf( "%d", &cant );
        printf( "%d", target[i] - cant );
        printf( ( i == 5 ) ? "\n" : " " );
    }

    return 0;
}
