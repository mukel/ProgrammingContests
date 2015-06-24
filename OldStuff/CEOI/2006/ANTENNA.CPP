/*
Alfonso2 Peterssen
3 - 5 - 2008
TASK: ANTENNA
*/
#include <cstdio>
#include <algorithm>
#include <cmath>

using std::sort;

const int MAXN = 500;
const double EPSILON = 1e-5;

int N, K, E;
double lo, hi, mid;
double solx, soly;
int x[MAXN];
int y[MAXN];
double dist[MAXN][MAXN];
struct event {
    double angle;
    int kind;
    bool operator < ( const event &e ) const {
        if ( angle != e.angle ) return angle < e.angle;
        return kind < e.kind;
    }
} events[2 * MAXN];

bool exist( double radius ) {

    for ( int i = 0; i < N; i++ ) {

        E = 0;
        for ( int j = 0; j < N; j++ )
            if ( j != i && dist[i][j] <= 2 * radius + EPSILON ) {
                double a = atan2( y[j] - y[i], x[j] - x[i] );
                double b = acos( dist[i][j] / ( 2 * radius ) );
                events[E++] = ( event ){ a - b, +1 };
                events[E++] = ( event ){ a + b, -1 };
            }

        sort( events, events + E );

        int inside = 1;
        for ( int j = 0; j < E; j++ ) {
            inside += events[j].kind;
            if ( inside >= K ) {
                solx = x[i] + cos( events[j].angle ) * radius;
                soly = y[i] + sin( events[j].angle ) * radius;
                return true;
            }
        }

    }

    return false;
}

int main() {

    scanf( "%d %d", &N, &K );
    for ( int i = 0; i < N; i++ )
        scanf( "%d %d", &x[i], &y[i] );

    for ( int i = 0; i < N; i++ )
        for ( int j = 0; j < N; j++ )
            dist[i][j] = hypot( x[i] - x[j], y[i] - y[j] );

    lo = 0.0;
    hi = 10000.0 * sqrt( 2. );
    while ( hi - lo > EPSILON ) {
        mid = ( lo + hi ) / 2;
        if ( exist( mid ) )
             hi = mid;
        else lo = mid;
    }

    exist( hi );

    printf( "%lf\n%lf %lf\n", hi, solx, soly );
    fflush( stdout );

    return 0;
}
