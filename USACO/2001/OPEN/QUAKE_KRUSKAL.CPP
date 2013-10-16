/*
Alfonso Alfonso Peterssen
31 - 12 - 2007
USACO 2001 Open "Earthquake"
Using Kruskal
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int
    MAXV = 400,
    MAXE = 10000;

const double EPSILON = 1e-5;

int V, E, F, i, j, k, c, t;
double lo, hi, mid;
int P[MAXV], ls[MAXE];
struct edge {
    int u, v, c, t;
    double cost;
} edges[MAXE];

    bool comp( const int &i, const int &j ) {
        return edges[i].cost < edges[j].cost;
    }

    int find( int x ) {
        if ( x != P[x] ) P[x] = find( P[x] );
        return P[x];
    }

    void join( int x, int y ) {
        P[ find( x ) ] = find( y );
    }

    bool ok( double value ) {

        int i, mst_edges = 0;
        double mst_cost = 0.0;

        /* Init disjoint sets */
        for ( i = 0; i < V; i++ )
            P[i] = i;

        for ( i = 0; i < E; i++ )
            edges[i].cost = edges[i].t * value + edges[i].c;

        /* Kruskal */
        sort( ls, ls + E, comp );
        for ( i = 0; i < E; i++ ) {
            int u = edges[ ls[i] ].u,
                v = edges[ ls[i] ].v;
            if ( find( u ) != find( v ) ) {
                join( u, v );
                mst_edges++;
                mst_cost += edges[ ls[i] ].cost;
            }
            if ( mst_edges == V - 1 )
                return mst_cost < F;
        }
    }

int main() {

    cin >> V >> E >> F;
    for ( i = 0; i < E; i++ ) {
        cin >> j >> k >> c >> t;
        edges[i] = ( edge ) { --j, --k, c, t, 0.0 };
        ls[i] = i;
    }

    /* BS */
    lo = 0; hi = 1e9;
    while ( hi - lo > EPSILON ) {
        mid = ( lo + hi ) / 2.0;
        if ( ok( mid ) )
             lo = mid;
        else hi = mid;
    }

    cout.precision( 4 );
    cout << fixed << hi << endl;

    return 0;
}

/*
PROBLEM 2: Earthquake [Chandrasekaran, 1977; Tvarozek, 2001]

An earthquake has destroyed Farmer John's entire farm.  Being a resolute
fellow, he decides to rebuild it. After rebuilding all N fields (1 <=
N <= 400), he realizes he must also connect the fields with roads.  When
complete, there must be some way to traverse from any field to any other
field.

After studying the terrain, FJ has concluded that M (1 <= M <= 10,000)
two-way roads can possibly be built. Since he is low on money, he would
like to complete the project in the cheapest way possible.

As luck would have it, the cows have formed an engineering consulting
firm that specializes in rebuilding farm roads destroyed in earthquakes.
The cows also have a keen business sense and have no interest in taking
on jobs for which they do not make a handsome profit.

The cows are concerned about the profit potential.  They have negotiated
a fee F (1 <= F <= 2,000,000,000) which they are paid to rebuild the
roads.  They are given a table of possible roads, the time (in hours)
to build each road (1 <= t <= 2,000,000,000), and the cost to build the
road (1 <= c <= 2,000,000,000).  The table might contain more than one
road connecting the same pair of fields.  It will always be possible to
connect all the fields given the input data though it might not be
profitable.

Determine the highest profit rate the cows can make in rebuilding the
farm's roads.

PROBLEM NAME: quake

INPUT FORMAT:

* Line 1: Three integers, N, M, and F

* Lines 2...M+1: Each line contains four space-separated integers: i,
         j, c, and t respectively denoting two fields the road
         connects, the cost, and the time requirements to build the
         road.

SAMPLE INPUT (file quake.in):

5 5 100
1 2 20 5
1 3 20 5
1 4 20 5
1 5 20 5
2 3 23 1

OUTPUT FORMAT:

A single line containing one number -- printed to four decimal places
-- which is the maximum profit per hour the cows can achieve.  If the
profit is not positive, print 0.0000 .

SAMPLE OUTPUT (file quake.out):

1.0625

[The cows choose to construct the last four roads, with a total cost of
83 and a time of 16.  Their fee is 100, so they make a profit of 100-83
over a period of 16 time units: 17/16 = 1.0625.]
*/
