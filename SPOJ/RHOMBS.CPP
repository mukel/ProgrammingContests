/*
Alfonso Alfonso Peterssen
1 - 12 - 2007
SPOJ #118 "Rhombs"
Based on Daniel Solution
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int
    MAXN = 50001,
    mov[3][6][2] =
    {{{0,0},{1,0},{0,1},{0,0},{-1,0},{0,-1}},
    {{1,0},{0,1},{0,0},{-1,0},{0,-1},{0,0}},
    {{1,0},{0,0},{0,1},{-1,0},{0,0},{0,-1}}};

int T, N, i;
int dir[MAXN], cant[MAXN], x[MAXN], y[MAXN];

    int calc( int id ) {

        int i, area = 0;

        for ( i = 1; i <= N; i++ ) {
            x[i] = x[i - 1] + mov[id][ dir[i] ][0] * cant[i];
            y[i] = y[i - 1] + mov[id][ dir[i] ][1] * cant[i];
        }

        for ( i = 0; i < N; i++ )
            area += x[i] * y[i + 1] - y[i] * x[i + 1];

        return abs( area ) / 2;
    }

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        scanf( "%d", &N );
        for ( i = 1; i <= N; i++ ) {
            scanf( "%d %d", &dir[i], &cant[i] );
            dir[i]--;
        }

        printf( "%d %d %d\n", calc( 0 ), calc( 1 ), calc( 2 ) );
    }

    return 0;
}
