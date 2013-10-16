/*
Alfonso Alfonso Peterssen
TASK: CADENA
*/
#include <cstdio>
#include <cstring>

const int
    MAXN = 200000,
    MAXLEN = 80;

int N, i, j;
int pos, last, sol_count;
int sol[MAXN];
char words[MAXN][MAXLEN];
int len[MAXN], next[MAXN];
int lcp[MAXN], cant[MAXN];

int LCP( int a, int b ) {
    int i = 0;
    while ( words[a][i] == words[b][i] ) i++;
    return i;
}

int main() {

    #warning READ FROM FILES!!!!

//    freopen( "cadena.in", "r", stdin );
//    freopen( "cadena.out", "w", stdout );

    while ( scanf( "%s", &words[N] ) && words[N][0] != '.' )
        len[N] = strlen( words[N] ), N++;

    for ( i = N - 1; i >= 0; i-- ) {
        lcp[i] = LCP( i, i + 1 );
        for ( j = i + 1; j < N && lcp[j] >= lcp[i]; j = next[j] );
        next[i] = j;
    }

    for ( i = 0; i < N; i++ ) {
        cant[i]++;
        if ( lcp[i] < len[i] )
             cant[i + 1]--;
        else cant[ next[i] + 1 ]--;
        if ( i )
            cant[i] += cant[i - 1];
        if ( cant[i] > cant[pos] )
            pos = i;
    }

    last = pos;
    sol[sol_count++] = pos;
    for ( i = pos - 1; i >= 0; i-- )
        if ( LCP( i, last ) == len[i] ) {
            last = i;
            sol[sol_count++] = i;
        }

    for ( i = sol_count - 1; i >= 0; i-- )
        printf( "%s\n", words[ sol[i] ] );

    fflush( stdout );

    return 0;
}
