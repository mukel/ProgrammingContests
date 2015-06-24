/*
Alfonso Alfonso Peterssen
9 - 4 - 2008
TASK: MGRID
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector< char > array;
typedef vector< array > matrix;

const int MAXC = 20000;

int F, C, i, j;
char line[MAXC];
int pre[MAXC];

int factor( matrix &M ) {

    int i, j;

    pre[0] = j = -1;
    for ( i = 1; i < M.size(); i++ ) {
        while ( j >= 0 && M[j + 1] != M[i] )
            j = pre[j];
        if ( M[j + 1] == M[i] ) j++;
        pre[i] = j;
    }

    return M.size() - pre[M.size() - 1] - 1;
}

int main() {
    #warning READ FROM FILES!!!!

    freopen( "mgrid.in", "r", stdin );
    freopen( "mgrid.out", "w", stdout );

    scanf( "%d %d", &F, &C );

    matrix A( F, array( C ) );
    matrix B( C, array( F ) );

    for ( i = 0; i < F; i++ ) {
        scanf( "%s", &line );
        for ( j = 0; j < C; j++ ) {
            A[i][j] = line[j];
            B[j][i] = line[j];
        }
    }

    printf( "%d\n", factor( A ) * factor( B ) );
    fflush( stdout );

    return 0;
}
