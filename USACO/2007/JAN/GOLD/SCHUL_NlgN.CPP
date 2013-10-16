/*
Alfonso2 Peterssen
6 - 5 - 2008
TASK: SCHUL
O( n lg n )
*/
#include <cstdio>
#include <algorithm>

using std::sort;

const int MAXN = 50000;

int N, P, T, cant;
int lo, hi, i, j;
int ans[MAXN];
double left[MAXN];
double right[MAXN];
struct point {
    int x, y;
    bool operator < ( const point &p ) const {
        return y * p.x < p.y * x;
    }
};
point hull[MAXN];
point test[MAXN];

int cross( const point &a, const point &b, const point &c ) {
    return ( b.x - a.x ) * ( c.y - a.y ) -
           ( c.x - a.x ) * ( b.y - a.y );
}

double eval( point p, double value ) {
    return p.y - p.x * value;
}

void hull_add( int x, int y ) {
    point p = (point) { x, y };
    while ( hi - lo > 1 &&
            cross( hull[hi - 2], hull[hi - 1], p ) >= 0 )
            hi--;
    hull[hi++] = p;
}

double hull_query( double value ) {
    while ( hi - lo > 1 &&
            eval( hull[lo]    , value ) <=
            eval( hull[lo + 1], value ) )
            lo++;
    return eval( hull[lo], value );
}

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d", &test[i].y, &test[i].x );
        T += test[i].x;
        P += test[i].y;
    }

    sort( test, test + N );

    lo = hi = 0;
    for ( i = 0; i < N - 1; i++ ) {
        hull_add( test[i].x, test[i].y );
        P -= test[i].y;
        T -= test[i].x;
        left[i] = hull_query( (double) P / T  );
    }

    P = T = 0;

    lo = hi = 0;
    for ( i = N - 1; i > 0; i-- ) {
        hull_add( -test[i].x, -test[i].y );
        P += test[i].y;
        T += test[i].x;
        right[i] = -hull_query( (double) P / T );
    }
    
    for ( i = 0; i < N - 1; i++ )
        if ( left[i] > right[i + 1] )
            ans[cant++] = i + 1;
    
    printf( "%d\n", cant );
    for ( i = 0; i < cant; i++ )
        printf( "%d\n", ans[i] );

    return 0;
}
