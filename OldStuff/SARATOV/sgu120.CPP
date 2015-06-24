/*
Alfonso2 Peterssen
13 - 5 - 2008
Saratov #120 "Archipelago"
*/
#include <cstdio>
#include <algorithm>
#define _NO_OLDNAMES 1 // Shit
#include <cmath>

using std::swap;

const double PI = acos( -1 );

int N, n1, n2;
double x1, y1, x2, y2;
double beta, ganma, radius;
double centerX, centerY;

void rotate( double x0, double y0, double &x, double &y, double delta ) {
    double a = x - x0;
    double b = y - y0;
    delta += atan2( b, a );
    x =  hypot( a, b ) * cos( delta ) + x0;
    y =  hypot( a, b ) * sin( delta ) + y0;
}

int main() {

    scanf( "%d %d %d", &N, &n1, &n2 );
    scanf( "%lf %lf", &x1, &y1 );
    scanf( "%lf %lf", &x2, &y2 );

    if ( n1 > n2 ) {
        swap( n1, n2 );
        swap( x1, x2 );
        swap( y1, y2 );
    }

    beta = 2 * PI / N * ( n2 - n1 );
    if ( beta > PI )
        beta = 2 * PI - beta;

    radius = hypot( x2 - x1, y2 - y1 ) / 2. / sin( beta / 2. );

    centerX = x1 + radius;
    centerY = y1;

    ganma = atan2( y2 - y1, x2 - x1 );
    if ( n2 - n1 > N / 2 )
         ganma += ( PI - beta ) / 2.;
    else ganma -= ( PI - beta ) / 2.;

    rotate( x1, y1, centerX, centerY, ganma );
    for ( int i = 1; i <= N; i++ ) {
        double a = x1;
        double b = y1;
        rotate( centerX, centerY, a, b, ( n1 - i ) * ( 2 * PI / N ) );
        printf( "%lf %lf\n", a, b );
    }

    return 0;
}
