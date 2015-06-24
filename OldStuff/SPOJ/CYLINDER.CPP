/*
Alfonso Alfonso Peterssen
24 - 11 - 2007
SPOJ #1681 "Cylinder"
Gracias a Manuel Candales
*/
#include <cmath>
#include <iostream>
using namespace std;

    double sqr( double x ) {
        return x * x;
    }

int main() {

    cout.precision( 3 );

    double A, B;
    while ( cin >> A >> B, A, B )
        cout << fixed
             << ( ( sqr( ( ( double )A / 2 ) <? ( B / ( 2 * ( M_PI + 1 ) ) ) ) * A * M_PI ) >?
                ( sqr( A / M_PI / 2 ) * ( B - 2 * ( A / M_PI / 2 ) ) * M_PI ) )
             << endl;

    return 0;
}
