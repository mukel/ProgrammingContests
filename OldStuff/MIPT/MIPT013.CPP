/*
Alfonso Alfonso Peterssen
7 - 2 - 2008
MIPT #013 "Boxes"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 500;

int N, i, j, flow;
int from[MAXN];
bool mark[MAXN];
int ls[MAXN][3];

    bool augment( int node ) {

        if ( mark[node] )
            return false;

        mark[node] = true;

        int i, j;
        for ( i = 0; i < N; i++ ) {
            for ( j = 0; j < 3; j++ )
                if ( ls[i][j] >= ls[node][j] )
                    break;
            if ( j == 3 && ( from[i] < 0 || augment( from[ i ] ) ) ) {
                from[i] = node;
                return true;
            }
        }

        return false;
    }

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        for ( j = 0; j < 3; j++ )
            scanf( "%d", &ls[i][j] );
        sort( ls[i], ls[i] + 3 );
    }

    fill( from, from + N, -1 );
    for ( i = 0; i < N; i++ ) {
        fill( mark, mark + N, false );
        if ( augment( i ) )
            flow++;
    }

    printf( "%d\n", N - flow );

    return 0;
}
