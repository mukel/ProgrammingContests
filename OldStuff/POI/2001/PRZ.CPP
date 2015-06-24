/*
Alfonso Alfonso Peterssen
4 - 3 - 2008
POI 2001 Stage I "Intervals"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair< int, int > interval;

int n, i, lo, hi;
vector< interval > vec;

int main() {

    scanf( "%d", &n );
    for ( i = 0; i < n; i++ ) {
        scanf( "%d %d", &lo, &hi );
        vec.push_back( make_pair( lo, hi ) );
    }

    sort( vec.begin(), vec.end() );

    lo = vec[0].first;
    hi = vec[0].second;
    for ( i = 1; i < n; i++ ) {
        if ( vec[i].first > hi ) {
            printf( "%d %d\n", lo, hi );
            lo = vec[i].first;
        }
        hi >?= vec[i].second;
    }

    printf( "%d %d\n", lo, hi );

    return 0;
}
