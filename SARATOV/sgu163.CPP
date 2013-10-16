/*
Alfonso Alfonso Peterssen
14 - 2 - 2008
Saratov #163 "Wise King"
*/
#include <cstdio>

int P, N, i, j, x, pot, sol;

int main() {

    scanf( "%d %d", &N, &P );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d", &x );
        if ( x > 0 || ( x < 0 && !( P & 1 ) ) ) {
            pot = 1;
            for ( j = 0; j < P; j++ )
                pot *= x;
            sol += pot;
        }
    }

    printf( "%d\n", sol );

    return 0;
}
