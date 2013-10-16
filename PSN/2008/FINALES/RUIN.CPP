/*
Alfonso2 Peterssen
21 - 4 - 2008
TASK: RUIN
*/
#include <cstdio>

const int MAXN = 5000;

int N, i, j, sol;
int x, y, dx, dy;
int X[MAXN];
int Y[MAXN];
bool mark[MAXN + 1][MAXN + 1];

bool used( int x, int y ) {
    if ( x < 0 || x > MAXN ||
         y < 0 || y > MAXN )
         return false;
    return mark[x][y];
}

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d", &X[i], &Y[i] );
        mark[ X[i] ][ Y[i] ] = true;
    }

    for ( i = 0; i < N; i++ )
        for ( j = i + 1; j < N; j++ ) {
            x = X[i];
            y = Y[i];
            dx = X[i] - X[j];
            dy = Y[i] - Y[j];
            if ( used( x - dx + dy, y - dy - dx ) &&
                 used( x + dy, y - dx ) )
                     sol >?= dx * dx + dy * dy;
        }

    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
