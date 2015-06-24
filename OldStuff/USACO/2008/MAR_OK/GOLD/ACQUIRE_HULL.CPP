/*
Alfonso Alfonso Peterssen
24 - 3 - 2008
USACO MAR08 Gold "Acquire"
*/
#include <cstdio>
#include <algorithm>
#include <complex>

using namespace std;

const int MAXN = 50000;

typedef long long int64;
typedef complex< int64 > point;

int N, M, i, j;
int x, y, lo, hi;
int64 dp;
point points[MAXN];
point hull[MAXN];

int64 gety( point &p, int64 x )
    { return real( p ) * x + imag( p ); }
    
int64 cross( const point &a, const point &b )
    { return imag( conj( a ) * b ); }
    
bool point_cmp( const point &a, const point &b )
    { return real( a ) < real( b ); }

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d", &x, &y );
        points[i] = point( x, y );
    }

    sort( points, points + N, point_cmp );
    
    for ( i = 0; i < N; i++ ) {
        while ( M > 0 &&
                imag( points[i] ) >= imag( points[M - 1] ) )
                M--;
        points[M++] = points[i];
    }
    
    for ( i = 0; i < M; i++ ) {

        int64 x = real( points[i] );
        point p = point( imag( points[i] ), dp );
        
        while ( lo + 1 < hi &&
                cross( hull[hi - 1] - hull[hi - 2], p - hull[hi - 2] ) >= 0 )
                hi--;
            
        hull[hi++] = p;
        while ( lo + 1 < hi &&
                gety( hull[lo],     x ) >=
                gety( hull[lo + 1], x ) )
                lo++;
            
        dp = gety( hull[lo], x );
    }

    printf( "%I64d\n", dp );

    return 0;
}
