/*
Alfonso Alfonso Peterssen
4 - 3 - 2008
Saratov #114 "Telecasting station"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 20000;

int n, i, l, r, sol;
double value, best;
struct city {
    double dist; int factor;
    bool operator < ( const city &t ) const { return dist < t.dist; }
} ls[MAXN];

int main() {

    scanf( "%d", &n );
    for ( i = 0; i < n; i++ )
        scanf( "%lf %d", &ls[i].dist, &ls[i].factor );

    sort( ls, ls + n );

    for ( i = 0; i < n; i++ ) {
        value += ( ls[i].dist - ls[0].dist ) * ls[i].factor;
        r += ls[i].factor;
    }

    best = value;
    l += ls[0].factor;
    r -= ls[0].factor;
    for ( i = 1; i < n; i++ ) {
        value += l * ( ls[i].dist - ls[i - 1].dist );
        value -= r * ( ls[i].dist - ls[i - 1].dist );
        l += ls[i].factor;
        r -= ls[i].factor;
        if ( value < best ) {
            best = value;
            sol = i;
        }
    }

//    printf( "%lf\n", best );
    printf( "%lf\n", ls[sol].dist );

    return 0;
}
