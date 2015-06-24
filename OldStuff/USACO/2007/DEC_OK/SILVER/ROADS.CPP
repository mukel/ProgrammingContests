/*
Alfonso Alfonso Peterssen
31 - 12 - 2007
USACO 2007 DEC Silver "Building Roads"
*/
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXV = 1001;

int V, R, E, i, j, k;
int x[MAXV], y[MAXV];
bool mark[MAXV];
long long cost[MAXV][MAXV];
long long dist[MAXV];
double sol;

long long sqr( long long x ) { return x * x; }

int main() {

    cin >> V >> R;
    for ( i = 1; i <= V; i++ )
        cin >> x[i] >> y[i];

    for ( i = 1; i <= V; i++ )
        for ( j = 1; j < i; j++ )
            cost[i][j] = cost[j][i] =
                sqr( x[i] - x[j] ) + sqr( y[i] - y[j] );

    for ( i = 0; i < R; i++ ) {
        cin >> j >> k;
        cost[j][k] = cost[k][j] = 0;
    }

    /* MST -> Prim */
    fill( dist, dist + V + 1, LONG_LONG_MAX );
    dist[1] = 0;
    for ( i = 0; i < V; i++ ) {

        k = 0;
        for ( j = 1; j <= V; j++ )
            if ( !mark[j] && dist[j] < dist[k] )
                k = j;

        mark[k] = true;
        sol += sqrt( dist[k] );

        for ( j = 1; j <= V; j++ )
            if ( !mark[j] && cost[k][j] < dist[j] )
                dist[j] = cost[k][j];
    }

    cout.precision( 2 );
    cout << fixed << sol << endl;

    return 0;
}

/*
Problem 7: Building Roads  [Richard Ho, 2007]

Farmer John had just acquired several new farms! He wants to connect
the farms with roads so that he can travel from any farm to any
other farm via a sequence of roads; roads already connect some of
the farms.

Each of the N (1 <= N <= 1,000) farms (conveniently numbered 1..N)
is represented by a position (X_i, Y_i) on the plane (0 <= X_i <=
1,000,000; 0 <= Y_i <= 1,000,000).  Given the preexisting M roads
(1 <= M <= 1,000) as pairs of connected farms, help Farmer John
determine the smallest length of additional roads he must build to
connect all his farms.

PROBLEM NAME: roads

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: Two space-separated integers: X_i and Y_i

* Lines N+2..N+M+2: Two space-separated integers: i and j, indicating
        that there is already a road connecting the farm i and farm j.

SAMPLE INPUT (file roads.in):

4 1
1 1
3 1
2 3
4 3
1 4

INPUT DETAILS:

Four farms at locations (1,1), (3,1), (2,3), and (4,3). Farms 1 and 4 are
connected by a road.

OUTPUT FORMAT:

* Line 1: Smallest length of additional roads required to connect all
        farms, printed without rounding to two decimal places. Be sure
        to calculate distances as 64-bit floating point numbers.

SAMPLE OUTPUT (file roads.out):

4.00

OUTPUT DETAILS:

Connect farms 1 and 2 with a road that is 2.00 units long, then connect
farms 3 and 4 with a road that is 2.00 units long. This is the best we can
do, and gives us a total of 4.00 unit lengths.
*/
