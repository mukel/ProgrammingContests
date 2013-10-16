/*
Alfonso Alfonso Peterssen
31 - 12 - 2007
USACO 2007 DEC Gold "Sightseeing Cows"
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int
    MAXV = 1000,
    MAXE = 5000;

const double EPSILON = 1e-4;

int V, E, i, j, k, t;
int fun[MAXV];
double lo, hi, mid;
double dist[MAXV];
struct edge {
    int u, v, t;
    double cost;
} ls[MAXE];

    bool bellman_ford( double value ) {

        fill( dist, dist + V, 0.0 );

        int i, j;
        for ( i = 0; i < E; i++ )
            ls[i].cost = ls[i].t * value - fun[ ls[i].v ];

        for ( i = 0; i <= V; i++ ) {
            bool chng = false;
            for ( j = 0; j < E; j++ ) {
                double new_cost = dist[ ls[j].u ] + ls[j].cost;
                if ( new_cost < dist[ ls[j].v ] ) {
                    dist[ ls[j].v ] = new_cost;
                    chng = true;
                }
            }
            if ( !chng )
                return false;
        }

        return true;
    }

int main() {

    cin >> V >> E;
    for ( i = 0; i < V; i++ )
        cin >> fun[i];

    for ( i = 0; i < E; i++ ) {
        cin >> j >> k >> t;
        ls[i] = ( edge ) { --j, --k, t, 0.0 };
    }

    /* BS */
    lo = 0; hi = 1e6;
    while ( hi - lo > EPSILON ) {
        mid = ( lo + hi ) / 2.0;
        if ( bellman_ford( mid ) )
             lo = mid;
        else hi = mid;
    }

    if ( hi < EPSILON )
        cout << 0 << endl;
    else {
        cout.precision( 2 );
        cout << fixed << hi << endl;
    }

    return 0;
}

/*
Problem 1: Sightseeing Cows [Reid Barton, 2007]

Farmer John has decided to reward his cows for their hard work by
taking them on a tour of the big city! The cows must decide how
best to spend their free time.

Fortunately, they have a detailed city map showing the L (2 <= L
<= 1000) major landmarks (conveniently numbered 1.. L) and the P
(2 <= P <= 5000) unidirectional cow paths that join them. Farmer
John will drive the cows to a starting landmark of their choice,
from which they will walk along the cow paths to a series of other
landmarks, ending back at their starting landmark where Farmer John
will pick them up and take them back to the  farm. Because space
in the city is at a premium, the cow paths are very narrow and so
travel along each cow path is only allowed in one fixed direction.

While the cows may spend as much time as they like in the city,
they do tend to get bored easily. Visiting each new landmark is
fun, but walking between them takes time. The cows know the exact
fun values F_i (1 <= F_i <= 1000) for each landmark i.

The cows also know about the cowpaths. Cowpath i connects landmark
L1_i to L2_i (in the direction L1_i -> L2_i) and requires time T_i
(1 <= T_i <= 1000) to traverse.

In order to have the best possible day off, the cows want to maximize
the average fun value per unit time of their trip.  Of course, the
landmarks are only fun the first time they are visited; the cows
may pass through the landmark more than once, but they do not
perceive its fun value again. Furthermore, Farmer John is making
the cows visit at least two landmarks, so that they get some exercise
during their day off.

Help the cows find the maximum fun value per unit time that they
can achieve.

PROBLEM NAME: sightsee

INPUT FORMAT:

* Line 1: Two space-separated integers: L and P

* Lines 2..L+1: Line i+1 contains a single one integer: F_i

* Lines L+2..L+P+1: Line L+i+1 describes cow path i with three
        space-separated integers: L1_i, L2_i, and T_i

SAMPLE INPUT (file sightsee.in):

5 7
30
10
10
5
10
1 2 3
2 3 2
3 4 5
3 5 2
4 5 5
5 1 3
5 2 2


OUTPUT FORMAT:

* Line 1: A single number given to two decimal places (do not perform
        explicit rounding), the maximum possible average fun per unit
        time, or 0 if the cows cannot plan any trip at all in
        accordance with the above rules.

SAMPLE OUTPUT (file sightsee.out):

6.00

OUTPUT DETAILS:

The trip 1 -> 2 -> 3 -> 5 -> 1 has a total fun value of 60 and a
length of 10 units for an average fun per unit time of 6. The trip
2 -> 3 -> 5 -> 2 only has an average fun per unit time of 30/6 =
5, and any trip involving landmark 4 has an average fun per unit
time of less than 4.
*/
