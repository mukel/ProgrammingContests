/*
Alfonso Alfonso Peterssen
19 - 3 - 2008
USACO FEB08 Silver "Meteor Shower"
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXC = 301;
const int mov[5][2] =
    {{-1,0},{0,-1},{0,1},{1,0},{0,0}};

int n, i, j, sol;
int x, y, t, nx, ny;
int mat[MAXC][MAXC];
int hit[MAXC][MAXC];
struct point { int x, y; };
queue< point > Q;

bool ok( int x, int y ) {
    return ( x >= 0 && x < MAXC && y >= 0 && y < MAXC );
}

int main() {

    memset( hit, 63, sizeof( hit ) );
    memset( mat, 63, sizeof( mat ) );

    scanf( "%d", &n );
    while ( n-- ) {
        scanf( "%d %d %d", &x, &y, &t );
        for ( i = 0; i < 5; i++ ) {
            nx = x + mov[i][0];
            ny = y + mov[i][1];
            if ( ok( nx, ny ) )
                hit[nx][ny] <?= t;
        }
    }

    sol = -1;
    mat[0][0] = 0;
    Q.push( ( point ) { 0, 0 } );
    for ( ; !Q.empty(); Q.pop() ) {
        x = Q.front().x;
        y = Q.front().y;
        if ( hit[x][y] > 100000 ) {
            sol = mat[x][y];
            break;
        }
        for ( i = 0; i < 4; i++ ) {
            nx = x + mov[i][0];
            ny = y + mov[i][1];
            if ( !ok( nx, ny ) ) continue;
            t = mat[x][y] + 1;
            if ( t >= ( hit[nx][ny] <? mat[nx][ny] ) )
                continue;
            Q.push( ( point ) { nx, ny } );
            mat[nx][ny] = t;
        }
    }

    printf( "%d\n", sol );

    fflush( stdout );

    return 0;
}
