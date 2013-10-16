/*
Alfonso Alfonso Peterssen
TASK: MUZICARI
*/
#include <cstdio>

const int
    MAXN = 5000,
    MAXM = 500;

int N, M, i, j, k;
bool used[MAXN];
int kind[MAXM], value[MAXM];
int last[MAXN], time[2];

int main() {

    scanf( "%d %d", &N, &M );

    used[0] = true;
    for ( i = 0; i < M; i++ ) {
        scanf( "%d", &value[i] );
        for ( j = N; j - value[i] >= 0; j-- )
            if ( !used[j] && used[j - value[i]] ) {
                last[j] = i;
                used[j] = true;
                k >?= j;
            }
    }

    for ( ; k > 0; k -= value[ last[k] ] )
        kind[ last[k] ] = 1;

    for ( i = 0; i < M; i++ ) {
        printf( ( i == M - 1 ) ? "%d\n" : "%d ", time[ kind[i] ] );
        time[ kind[i] ] += value[i];
    }

    return 0;
}
