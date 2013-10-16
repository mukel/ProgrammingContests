/*
Alfonso2 Peterssen
8 - 5 - 2008
Baltic 1995 TASK: RECT
*/
#include <cstdio>

int K, X, Y, sol;
long long x1, x2, y1, y2;

int main() {

    scanf( "%d %d %d", &K, &X, &Y );

    x1 = 0; y1 = 0;
    x2 = 0; y2 = 1;
    do {
        if ( sol % 4 == 0 ) x2 += K * ( y2 - y1 ); // right
        if ( sol % 4 == 1 ) y2 += K * ( x2 - x1 ); // up
        if ( sol % 4 == 2 ) x1 -= K * ( y2 - y1 ); // left
        if ( sol % 4 == 3 ) y1 -= K * ( x2 - x1 ); // down
        sol++;
    } while ( x1 > X || x2 < X ||
              y1 > Y || y2 < Y );

    printf( "%d\n", sol );

    return 0;
}
