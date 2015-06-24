/*
Alfonso Alfonso Peterssen
29 - 11 - 2007
SPOJ #867 "Perfect Cubes"
*/
#include <cstdio>

const int MAXN = 101;

int i, j, k, x;
int cube[MAXN];
int croot[MAXN * MAXN * MAXN];

int main() {

    /* Init */
    for ( i = 2; i < MAXN; i++ ) {
        croot[i*i*i] = i;
        cube[i] = i*i*i;
    }

    /* Solve */
    for ( i = 6; i < MAXN; i++ )
        for ( j = 2; j < MAXN; j++)
            for ( k = j + 1; k < MAXN; k++ ) {
                x = cube[i] - cube[j] - cube[k];
                if ( x < 2 ) break;
                if ( croot[x] && croot[x] > k )
                    printf( "Cube = %d, Triple = (%d,%d,%d)\n", i, j, k, croot[x] );
            }

    return 0;
}
