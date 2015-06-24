/*
Alfonso Alfonso Peterssen
V.I.Lenin
Task: SUDOKU
Lang: C++
*/
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <algorithm>
using namespace std;

typedef bitset< 10 > moves;
#define used( i, j ) ( fil[i] | col[j] | box[ i / 3 ][ j / 3 ] )

int i, j, cant;
char sudo[9][9];
moves fil[9], col[9], box[3][3];
struct thing {
    int x, y;
    bool operator < ( const thing &t ) const {
        return used( x, y ).count() > used( t.x, t.y ).count();
    }
} ls[81];

    void comb( int cant ) {

        if ( cant == 0 ) {

            for ( int i = 0; i < 9; i++ )
                for ( int j = 0; j < 9; j++ )
                    printf( "%d", sudo[i][j] );

            fflush( stdout );
            exit( 0 );
        }

        //sort( ls, ls + cant );
        swap( ls[0], ls[ min_element( ls, ls + cant ) - ls ] );

        int x = ls[0].x,
            y = ls[0].y;

        moves mark = used( x, y );

        if ( mark.count() == 9 )
            return ; // shit

        swap( ls[0], ls[cant - 1] );

        for ( int i = 1; i < 10; i++ )
            if ( !mark[i] ) {
                fil[x][i] = true;
                col[y][i] = true;
                box[x / 3][y / 3][i] = true;

                sudo[x][y] = i;
                comb( cant - 1 );

                fil[x][i] = false;
                col[y][i] = false;
                box[x / 3][y / 3][i] = false;
            }
    }

int main() {

    freopen( "sudoku.in", "r", stdin );
    freopen( "sudoku.out", "w", stdout );

    scanf( "%s", &sudo );
    for ( i = 0; i < 9; i++ )
        for ( j = 0; j < 9; j++ )
            if ( sudo[i][j] != '.' )
                 sudo[i][j] -= '0';
            else sudo[i][j] = 0;

    /* Init */
    for ( i = 0; i < 9; i++ )
        for ( j = 0; j < 9; j++ ) {
            if ( sudo[i][j] ) {
                fil[i][ sudo[i][j] ] = true;
                col[j][ sudo[i][j] ] = true;
                box[ i / 3 ][ j / 3 ][ sudo[i][j] ] = true;
            } else ls[cant++] = ( thing ) { i, j };
        }

    /* Solve */
    comb( cant );

    return 0;
}
