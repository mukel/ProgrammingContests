/*
Alfonso Alfonso Peterssen
9 - 4 - 2008
TASK: TIX
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

int id;
int mat[4][4];
int r[16], c[16];

void swap_in_row( int row, int x, int y ) {

    if ( x > y ) swap( x, y );

    /* Shift Left */
    REP( i, x ) printf( "%d l\n", row + 1 );

    /* Swap */
    printf( "%d r\n4 u\n%d r\n4 d\n%d l\n%d l\n4 u\n%d r\n4 d\n",
            row + 1, row + 1, row + 1 , row + 1, row + 1 );

    /* Shift Right */
    REP( i, x ) printf( "%d r\n", row + 1 );

    swap( c[ mat[row][x] ], c[ mat[row][y] ] );
    swap( mat[row][x], mat[row][y] );
}

void swap_in_col( int col, int x, int y ) {

    if ( x > y ) swap( x, y );

    /* Shift Up */
    REP( i, x ) printf( "%d u\n", col + 1 );

    /* Swap */
    printf( "%d d\n4 l\n%d d\n4 r\n%d u\n%d u\n4 l\n%d d\n4 r\n",
            col + 1, col + 1, col + 1, col + 1, col + 1 );

    /* Shift Down */
    REP( i, x ) printf( "%d d\n", col + 1 );

    swap( r[ mat[x][col] ], r[ mat[y][col] ] );
    swap( mat[x][col], mat[y][col] );
}

void move_in_row( int row, int x, int y ) {
    if ( x < y )
        for ( int i = x; i < y; i++ )
            swap_in_row( row, i, i + 1 );
    if ( x > y )
        for ( int i = x; i > y; i-- )
            swap_in_row( row, i - 1, i );
}

void move_in_col( int col, int x, int y ) {
    if ( x < y )
        for ( int i = x; i < y; i++ )
            swap_in_col( col, i, i + 1 );
    if ( x > y )
        for ( int i = x; i > y; i-- )
            swap_in_col( col, i - 1, i );
}

int main() {

    #warning READ FROM FILES!!!!

/*    freopen( "tix.in", "r", stdin );
    freopen( "tix.out", "w", stdout );
*/

    REP( i, 4 )
    REP( j, 4 ) {
        scanf( "%d", &mat[i][j] );
        mat[i][j]--;
        r[ mat[i][j] ] = i;
        c[ mat[i][j] ] = j;
    }

    REP( i, 4 )
    REP( j, 4 ) {
        move_in_row( r[id], c[id], j );
        move_in_col( c[id], r[id], i );
        id++;
    }

    fflush( stdout );

    return 0;
}
