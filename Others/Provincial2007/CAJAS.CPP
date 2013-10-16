/*
Alfonso Alfonso Peterssen
V.I.Lenin
Task: CAJAS
Lang: C++
*/
#include <cstdio>
#include <algorithm> // abs()

const int MAXBOXES = 2500;

int F, C, N, i, j, k, cant, col, movs;
int ls[MAXBOXES];

int main() {

    freopen( "cajas.in", "r", stdin );
    freopen( "cajas.out", "w", stdout );
    
    scanf( "%d %d", &C, &F );
    
    for ( i = 0; i < F; i++ )
        for ( j = 0; j < C; j++ ) {
            scanf( "%d", &k );
            if ( k ) ls[N++] = j;
        }
        
    movs = 1000000000; // oo
    for ( i = 0; i < C; i++ ) {

        cant = 0;
        for ( j = 0; j < N; j++ )
            cant += abs( ls[j] - i );
            
        if ( cant < movs ) {
             movs = cant;
             col = i + 1;
        }
    }
    
    printf( "%d\n", col );

    return 0;
}
