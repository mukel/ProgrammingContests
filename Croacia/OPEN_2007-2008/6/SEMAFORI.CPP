/*
Alfonso2 Peterssen
12 - 4 - 2008
TASK: SEMAFORI
*/
#include <cstdio>

const int MAXN = 1000;

int N, L, i, j, k;
int delay;
int D[MAXN];
int R[MAXN];
int G[MAXN];

int main() {

    scanf( "%d %d", &N, &L );
    for ( i = 0; i < N; i++ )
        scanf( "%d %d %d", &D[i], &R[i], &G[i] );
        
    for ( i = 0; i < L; i++ ) {
        for ( j = 0; j < N; j++ )
            if ( D[j] == i ) {
                int mod = delay % ( R[j] + G[j] );
                if ( mod < R[j] )
                    delay += R[j] - mod;
            }
        delay++;
    }
    
    printf( "%d\n", delay );

    return 0;
}


