/*
Alfonso2 Peterssen
10 - 6 - 2008
IOI 2002 "XOR"
This gets 85 points in 20s
*/
#include <cstdio>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 2010;

int N;
int cant;
int x1, y1, x2, y2;
int sol[MAXN][4];
char mat[MAXN][MAXN];

int main() {

    scanf( "%d", &N );
    REP( i, N )
    REP( j, N )
        scanf( "%d", &mat[i + 1][j + 1] );

    REP( i, N + 1 )
    REP( j, N + 1 )
        mat[i][j] ^= mat[i + 1][j] ^ mat[i][j + 1] ^ mat[i + 1][j + 1];

    for ( x1 = y1 = 0; x1 <= N; y1 == N ? y1 = 0, x1++ : y1++ )
        if ( mat[x1][y1] ) {
            for ( x2 = x1 + 1; x2 <= N && !mat[x2][y1]; x2++ );
            for ( y2 = y1 + 1; y2 <= N && !mat[x1][y2]; y2++ );
            mat[x1][y1] = 0;
            mat[x1][y2] = 0;
            mat[x2][y1] = 0;
            mat[x2][y2] ^= 1;
            sol[cant][0] = y1 + 1;
            sol[cant][1] = y2;
            sol[cant][2] = x1 + 1;
            sol[cant][3] = x2;
            cant++;
        }

    printf( "%d\n", cant );
    REP( i, cant ) {
        REP( j, 4 )
            printf( "%d ", sol[i][j] );
        printf( "\n" );
    }

    return 0;
}
