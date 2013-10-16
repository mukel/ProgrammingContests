/*
Alfonso Alfonso Peterssen
20 - 2 - 2008
CNC 2008 Task 1C "Pantalla"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int MAXF = 200;

int F, C, R, i, j;
int order, x;
int sol[MAXF][MAXF];
struct box {
    int value, x, y;
    bool operator < ( const box &t ) const { return value < t.value; }
};
vector< box > vec;
priority_queue< box > Q;

int main() {

    scanf( "%d %d", &F, &C );
    scanf( "%d", &R );

    for ( i = 0; i < F; i++ ) {
        for ( j = 0; j < C; j++ ) {
            scanf( "%d", &x );
            vec.push_back( ( box ){ x, i, j } );
        }
        if ( i & 1 )
            reverse( vec.end() - C, vec.end() );
    }

    i = 0;
    while ( i < F * C || !Q.empty() ) {
        for ( j = 0; j < R && i < F * C; j++, i++ )
            Q.push( vec[i] );
        sol[ Q.top().x ][ Q.top().y ] = ++order;
        Q.pop();
    }

    for ( i = 0; i < F; i++ )
        for ( j = 0; j < C; j++ ) {
            printf( "%d", sol[i][j] );
            printf( j == C - 1 ? "\n" : " " );
        }

    fflush( stdout );

    return 0;
}


