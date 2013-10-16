/*
Alfonso Alfonso Peterssen
28 - 11 - 2007
SPOJ #1723 "Bee Maja"
I take this from prefield.com
*/
#include <iostream>
#include <cmath>
using namespace std;

struct point {
  int x, y;
  point( int x, int y ) : x(x), y(y) { }
};

    point maja( int x ) {

        if ( x == 0 ) return point( 0,0 );

        int n = ( int )( ceil( ( -1.0 + sqrt( 1.0 + 4.0 / 3.0 * x ) ) / 2.0 ) );

        int a = 3 * n * ( n - 1 ),
            d = ( int )( ceil( ( 1.0 * x - a ) / n - 1.0 ) );

        int k = x - a - n * d;

        switch ( d ) {
            case 0 : return point( n - k, k );
            case 1 : return point( -k, n );
            case 2 : return point( -n, n - k );
            case 3 : return point( -n + k, -k );
            case 4 : return point( k, -n );
            case 5 : return point( n, -n + k );
        }
    }

int main() {

    int N;
    while ( cin >> N ) {
        point sol = maja( N - 1 );
        cout << sol.x << " " << sol.y << endl;
    }

    return 0;
}
