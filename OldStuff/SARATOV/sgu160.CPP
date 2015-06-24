/*
Alfonso Alfonso Peterssen
14 - 2 - 2008
Saratov #160 "Magic Multiplying Machine"
Que hago programando el 14 de febrero?...
*/
#include <cstdio>

const int MAXM = 1000;

int N, M, i, j, k, x;
int used[2][MAXM];
int from[2][MAXM];

    void print( int score ) {
        if ( used[0][score] < 1 )
            return ;
        print( from[0][score] );
        printf( "%d ", used[0][score] );
    }

int main() {

    scanf( "%d %d", &N, &M );

    used[0][1] = used[1][1] = -1;
    for ( i = 1; i <= N; i++ ) {
        scanf( "%d", &x );
        for ( j = 0; j < M; j++ )
            if ( used[0][j] ) {
                int score = ( x * j ) % M;
                if ( used[1][score] ) continue;
                used[1][score] = i;
                from[1][score] = j;
            }
        for ( j = 0; j < M; j++ ) {
            k = ( used[0][j] != 0 );
            used[k][j] = used[k^1][j];
            from[k][j] = from[k^1][j];
        }
    }

    for ( j = M - 1; !used[0][j]; j-- );

    printf( "%d\n", j );
    /* Check line-end */
    print( j );

    return 0;
}
