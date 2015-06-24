/*
Alfonso Alfonso Peterssen
11 - 1 - 2008
SPOJ #110 "Fill the Cisterns"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 50000;
const double EPSILON = 1e-4;

int T, N, i, j;
int water, capacity;
double lo, hi, mid;
int base[MAXN];
int start[MAXN], end[MAXN];

    bool ok( double level ) {

        double amount = 0;
        for ( int i = 0; i < N; i++ ) {
            if ( level < start[i] ) continue;
            amount += base[i] * ( min( level, 1.0 * end[i] ) - start[i] );
        }

        return amount < water;
    }

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        /* Init */
        capacity = 0;

        scanf( "%d", &N );
        for ( i = 0; i < N; i++ ) {
            scanf( "%d %d %d %d", &start[i], &end[i], &base[i], &j );
            base[i] *= j;
            capacity += base[i] * end[i];
            end[i] += start[i];
        }

        scanf( "%d", &water );

        if ( water > capacity ) {
            printf( "OVERFLOW\n" );
            continue;
        }

        lo = 0; hi = 1e10;
        while ( hi - lo > EPSILON ) {
            mid = ( lo + hi ) / 2;
            if ( ok( mid ) )
                 lo = mid;
            else hi = mid;
        }

        printf( "%.2lf\n", lo );
    }

    return 0;
}
