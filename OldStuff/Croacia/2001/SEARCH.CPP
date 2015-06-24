/*
Alfonso Alfonso Peterssen
22 - 11 - 2007
COI 2001 Olympiad "SEARCH"
*/
#include <cstdio>

const int
    MAXF = 60,
    mov[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

int F, C, P, i, j, k, way;
char op[4];
char mat[MAXF][MAXF];
int mark[MAXF][MAXF];

/* BFS */
int now, last;
int sz[2];
int qX[2][MAXF * MAXF],
    qY[2][MAXF * MAXF];

    bool valid( int x, int y ) {
        return ( x >= 0 && x < F ) &&
               ( y >= 0 && y < C ) && mat[x][y] != 'X';
    }

int main() {

    scanf( "%d %d", &F, &C );

    for ( i = 0; i < F; i++ ) {

        scanf( "%s", mat[i] );

        for ( j = 0; j < C; j++ )
            if ( mat[i][j] == '*' ) {
                /* Push the source */
                now = 0, last = 1;
                qX[now][ sz[now] ] = i;
                qY[now][ sz[now] ] = j;
                sz[now]++;
            }
    }

    /* BFS */
    for ( scanf( "%d", &P ); P; P-- ) {

        scanf( "%s", &op );

        if ( op[0] == 'N' ) way = 0;
        if ( op[0] == 'S' ) way = 1;
        if ( op[0] == 'E' ) way = 2;
        if ( op[0] == 'W' ) way = 3;

        now ^= 1;
        last ^= 1;
        sz[now] = 0;

        for ( i = 0; i < sz[last]; i++ ) {

            int x = qX[last][i],
                y = qY[last][i];

            for ( j = 1; ; j++ ) {

                int nx = x + j * mov[way][0],
                    ny = y + j * mov[way][1];

                if ( !valid( nx, ny ) ) break;

                if ( mark[nx][ny] != P ) {
                    /* Push */
                    qX[now][ sz[now] ] = nx;
                    qY[now][ sz[now] ] = ny;
                    mark[nx][ny] = P;
                    sz[now]++;
                }
            }
        }
    }

    /* Output */
    for ( i = 0; i < F; i++ ) {

        for ( j = 0; j < C; j++ )
            if ( mark[i][j] == 1 )
                 printf( "*" );
            else printf( ( mat[i][j] == 'X' ) ? "X" : "." );

        printf( "\n" );
    }

    return 0;
}
