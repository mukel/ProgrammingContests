/*
Alfonso Alfonso Peterssen
17 - 4 - 2008
TASK: TREASURE
*/
#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>

using namespace std;

const int MAXC = 205;
const int DINAMITE = 28;
const int mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int F, C;
int i, j, k;
int x, y, d;
char mat[MAXC][MAXC];
int cost[MAXC][MAXC][DINAMITE];
struct state {
    int x, y, dinamite;
};
queue< state > Q;

int main() {

    #warning READ FROM FILES!!!
    freopen( "treasure.in", "r", stdin );
    freopen( "treasure.out", "w", stdout );
    
    for (;;) {
        scanf( "%s", &mat[F] );
        if ( mat[F][0] == '-' && mat[F][1] == '-' )
            break;
        F++;
    }

    C = strlen( mat[0] );

    memset( cost, -1, sizeof( cost ) );

    /* get doors */
    for ( i = 0; i < F; i++ )
    for ( j = 0; j < C; j++ ) {
        if ( mat[i][j] == '#' ) {
            Q.push( (state){ i, j, 0 } );
            cost[i][j][0] = 0;
        }
        if ( mat[i][j] >= 'A' && mat[i][j] <= 'Z' ) {
            Q.push( (state){ i, j, mat[i][j] - 'A' + 1 } );
            cost[i][j][ mat[i][j] - 'A' + 1 ] = 0;
        }
    }

    /* BFS */
    while ( !Q.empty() ) {

        x = Q.front().x;
        y = Q.front().y;
        d = Q.front().dinamite;
        Q.pop();

        for ( i = 0; i < 4; i++ ) {
            int nx = x + mov[i][0];
            int ny = y + mov[i][1];

            if ( nx < 0 || nx >= F ||
                 ny < 0 || ny >= C )
                 continue;

            if ( mat[nx][ny] == '#' )
                continue;

            if ( mat[nx][ny] >= 'A' && mat[nx][ny] <= 'Z' )
                continue;

            if ( mat[nx][ny] == '*' )
                continue;

            /* rock */
            if ( mat[nx][ny] >= '1' && mat[nx][ny] <= '9' ) {
                /* hand kill */
                int nc = cost[x][y][d] + mat[nx][ny] - '0';
                if ( cost[nx][ny][d] == -1 || nc < cost[nx][ny][d] ) {
                    cost[nx][ny][d] = nc;
                    Q.push( (state){ nx, ny, d } );
                }

                /* use dinamite */
                if ( d > 0 ) {
                    int nc = cost[x][y][d];
                    if ( cost[nx][ny][d - 1] == -1 || nc < cost[nx][ny][d - 1] ) {
                        cost[nx][ny][d - 1] = nc;
                        Q.push( (state){ nx, ny, d - 1 } );
                    }
                }
            }

            /* hallway & treasure */
            if ( mat[nx][ny] == '.' ||
                 mat[nx][ny] == '$' ) {
                int nc = cost[x][y][d];
                if ( cost[nx][ny][d] == -1 || nc < cost[nx][ny][d] ) {
                    cost[nx][ny][d] = nc;
                    Q.push( (state){ nx, ny, d } );
                }
            }

        }
    }

    for ( i = 0; i < F; i++ )
    for ( j = 0; j < C; j++ )
        if ( mat[i][j] == '$' ) {
            int val = 1000000000;
            for ( k = 0; k < DINAMITE; k++ )
                if ( cost[i][j][k] != -1 )
                    val <?= cost[i][j][k];
            if ( val != 1000000000 )
                 printf( "%d\n", val );
            else printf( "IMPOSSIBLE\n" );
            fflush( stdout );
            exit( 0 );
        }

    return 0;
}
