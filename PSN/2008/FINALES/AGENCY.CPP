/*
Alfonso2 Peterssen
29 - 4 - 2008
TASK:  AGENCY
*/
#include <cstdio>

const int MAXN = 100000;

int N, i, sum;
int seq[MAXN];
int deg[MAXN];
int sol[MAXN];

bool greedy( int start ) {

    for ( int i = 0; i < N; i++ )
        deg[i] = seq[i];

    int cant = 0;
    int j = start;
    deg[j]--;
    sol[cant++] = j;

    for (;;) {
        while ( j > 0     && deg[j - 1] ) { deg[--j]--;  sol[cant++] = j; }
        if    ( j < N - 1 && deg[j + 1] ) { deg[++j]--;  sol[cant++] = j; }
        if ( ( j == 0     || !deg[j - 1] ) &&
             ( j == N - 1 || !deg[j + 1] ) )
             break;
    }

    return ( cant == sum );
}

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d", &seq[i] );
        sum += seq[i];
    }

    for ( i = 0; !greedy( i ); i++ );

    for ( i = 0; i < sum; i++ )
        printf( "%d\n", sol[i] + 1 );
    fflush( stdout );

    return 0;
}
