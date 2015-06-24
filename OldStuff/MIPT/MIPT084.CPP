/*
Alfonso Alfonso Peterssen
14 - 3 - 2008
MIPT #084 "Farthest Points"
*/
#include <algorithm>
#include <complex>
#include <cmath>

using namespace std;

const int MAXN = 50000;

typedef complex< double > point;

#define NEXT( x ) ( ( (x) + 1 ) % H )

int N, H, limit;
int i, j, k;
double max_dist;
point points[MAXN];
point hull[ 2 * MAXN ];

double cross( const point &a, const point &b ) { return imag( conj(a) * b ); }
double area2( const point &a, const point &b, const point &c ) {
    return cross( b - a, c - a );
}

bool point_cmp( const point &a, const point &b ) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ )
        scanf( "%lf %lf", &real( points[i] ), &imag( points[i] ) );

    sort( points, points + N, point_cmp );

    limit = 1;
    for ( i = 0; i < N; hull[H++] = points[i++] )
        while ( H > limit &&
                area2( hull[H - 2], hull[H - 1], points[i] ) < 0 )
                H--;

    limit = H - 1;
    for ( i = N - 2; i >= 0; hull[H++] = points[i--] )
        while ( H > limit &&
                area2( hull[H - 2], hull[H - 1], points[i] ) < 0 )
                H--;
    H--;

    for ( i = j = 0; i < H; i++ ) {
        max_dist >?= norm( hull[i] - hull[j] );
        while ( cross( hull[ NEXT( i ) ] - hull[i],
                       hull[ NEXT( j ) ] - hull[j] ) > 0 ) {
                           j = NEXT( j );
                           max_dist >?= norm( hull[i] - hull[j] );
                       }
    }

    printf( "%lf\n", sqrt( max_dist ) );
    fflush( stdout );

    return 0;
}
