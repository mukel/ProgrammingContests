/*
Alfonso2 Peterssen
18 - 7 - 2008
MIPT # "Bridges"
*/
#include <cstdio>
#include <cstring>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXN = 3000;
const int mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int N, diff;
char board[MAXN][MAXN];
char mark[MAXN][MAXN];

void DFS( int x, int y, int id ) {
    mark[x][y] = id;
    REP( i, 4 ) {
        int nx = x + mov[i][0];
        int ny = y + mov[i][1];
        if ( nx < 0 || nx >= N ||
             ny < 0 || ny >= N )
             continue;
        if ( board[nx][ny] == board[x][y] && !mark[nx][ny] )
            DFS( nx, ny, id );
    }
}

int GetR() {

    memset( mark, 0, sizeof( mark ) );
    for ( int i = 1; i < N; i += 2 ) {
        DFS( i, 0, 1 );
        DFS( i, N - 1, 2 );
    }

    int cant = 0;
    REP( i, N )
        REP( j, N )
            if ( board[i][j] == '.' ) {
                int mask = 0;
                REP( k, 4 ) {
                    int nx = i + mov[k][0];
                    int ny = j + mov[k][1];
                    if ( ny < 0 ) mask |= 1;
                    if ( ny >= N ) mask |= 2;
                    if ( nx < 0 || nx >= N ||
                         ny < 0 || ny >= N )
                         continue;
                    mask |= mark[nx][ny];
                }
                if ( mask == 3 )
                    cant++;
            }

    return cant;
}

int GetB() {

    memset( mark, 0, sizeof( mark ) );
    for ( int i = 1; i < N; i += 2 ) {
        DFS( 0, i, 1 );
        DFS( N - 1, i, 2 );
    }

    int cant = 0;
    REP( i, N )
        REP( j, N )
            if ( board[i][j] == '.' ) {
                int mask = 0;
                REP( k, 4 ) {
                    int nx = i + mov[k][0];
                    int ny = j + mov[k][1];
                    if ( nx < 0 ) mask |= 1;
                    if ( nx >= N ) mask |= 2;
                    if ( nx < 0 || nx >= N ||
                         ny < 0 || ny >= N )
                         continue;
                    mask |= mark[nx][ny];
                }
                if ( mask == 3 )
                    cant++;
            }

    return cant;
}

int main() {

    scanf( "%d", &N );
    REP( i, N ) {
        scanf( "%s", &board[i] );
        REP( j, N )
            if ( board[i][j] == 'B' )
                diff++;
            else
            if ( board[i][j] == 'R' )
                diff--;
    }

    if ( !diff ) // Red's turn
         printf( "%d\n", ( GetR() > 0 ) ? 1 : ( ( GetB() > 1 ) ? 2 : 0 ) );
    else printf( "%d\n", ( GetB() > 0 ) ? 1 : ( ( GetR() > 1 ) ? 2 : 0 ) );

    return 0;
}
