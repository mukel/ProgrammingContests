/*
Alfonso2 Peterssen
21 - 4 - 2008
TASK: SEQUENCE
O( n )
*/
#include <cstdio>

const int MAXN = 100010;

#define DEBUG false

int N, M, sol;
int i, j, x;
int cant;
bool used[MAXN];
int len[MAXN];
bool zero;

int main() {

    #warning READ FROM FILES!!!
    freopen( "sequence.in", "r", stdin );
    freopen( "sequence.out", "w", stdout );

    scanf( "%d %d", &N, &M );
    for ( i = 0; i < M; i++ ) {
        scanf( "%d", &x );
        if ( x == 0 )
             zero = true;
        else used[x] = true;
    }

    for ( i = 0; i <= N;  ) {
        for ( j = i; j <= N && used[j]; j++ );
        cant = j - i;
        for ( j = i; j <= N && used[j]; j++ )
            len[j] = cant;
        i = j + 1;
    }

    if ( DEBUG ) {
        for ( i = 0; i <= N; i++ )
            printf( "%d ", len[i] );
        printf( "\n" );
    }

    sol = zero;
    for ( i = 0; i <= N; i++ ) {
        sol >?= len[i];
        if ( zero ) {
             if ( i + 1 <= N && !used[i + 1] )
                 sol >?= len[i] + len[i + 2] + 1;
        }
    }

    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
