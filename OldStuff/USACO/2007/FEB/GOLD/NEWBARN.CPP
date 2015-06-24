/*
Alfonso Alfonso Peterssen
24 - 12 - 2007
USACO FEB07 Gold "Construyendo Un Nuevo Establo"
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int
    oo = 1000000000,
    mov[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int N, i, j, k, cost, places;
int x1, x2, y1, y2;

void find_median( vector< int > ls, int &lo, int &hi ) {
    sort( ls.begin(), ls.end() );
    lo = ls[ ( ls.size() - 1 ) / 2 ];
    hi = ls[ ls.size() / 2 ];
}

int main() {

    cin >> N;

    vector< int > x( N ), y( N );

    for ( i = 0; i < N; i++ )
        cin >> x[i] >> y[i];

    find_median( x, x1, x2 );
    find_median( y, y1, y2 );

    places = ( x2 - x1 + 1 ) * ( y2 - y1 + 1 );

    for ( i = 0; i < N; i++ ) {
        cost += abs( x[i] - x1 ) + abs( y[i] - y1 );
        if ( x[i] >= x1 && x[i] <= x2 &&
             y[i] >= y1 && y[i] <= y2 )
             places--;
    }

    if ( places == 0 ) {
        cost = oo;
        for ( i = 0; i < 4; i++ ) {
            int candy = 0;
            for ( j = 0; j < N; j++ )
                candy += abs( x1 + mov[i][0] - x[j] ) +
                         abs( y1 + mov[i][1] - y[j] );
            if ( candy == cost )
                places++;
            else if ( candy < cost ) {
                cost = candy;
                places = 1;
            }
        }
    }

    cout << cost << " " << places << endl;

    return 0;
}
