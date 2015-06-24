/*
Alfonso Alfonso Peterssen
1 - 1 - 2008
USACO 2006 DEC Gold "Wormholes"
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int
    MAXV = 500,
    MAXE = 6000;

int F, V, E, e1, e2;
int i, j, k, cost;
int dist[MAXV];
struct edge {
    int u, v, cost;
} ls[MAXE];

int main() {

    for ( cin >> F; F; F-- ) {

        E = 0;
        cin >> V >> e1 >> e2;
        for ( i = 0; i < e1; i++ ) {
            cin >> j >> k >> cost;
            ls[E++] = ( edge ) { --j, --k, cost };
            ls[E++] = ( edge ) { k, j, cost };
        }

        for ( i = 0; i < e2; i++ ) {
            cin >> j >> k >> cost;
            ls[E++] = ( edge ) { --j, --k, -cost };
        }

        /* Bellman-Ford */
        fill( dist, dist + V, 0 );
        for ( i = 0; i < V; i++ )
            for ( j = 0; j < E; j++ )
                dist[ ls[j].v ] <?= dist[ ls[j].u ] + ls[j].cost;

        for ( j = 0; j < E; j++ )
            if ( dist[ ls[j].v ] > dist[ ls[j].u ] + ls[j].cost )
                break;

        cout << ( ( j == E ) ? "NO" : "YES" ) << endl;
    }

    return 0;
}

/*
Problem 1: Wormholes [J. Kuipers, 2002]

While exploring his many farms, Farmer John has discovered a number
of amazing wormholes. A wormhole is very peculiar because it is a
one-way path that delivers you to its destination at a time that
is BEFORE you entered the wormhole! Each of FJ's farms comprises N
(1 <= N <= 500) fields conveniently numbered 1..N, M (1 <= M <=
2500) paths, and W (1 <= W <= 200) wormholes.

As FJ is an avid time-traveling fan, he wants to do the following:
start at some field, travel through some paths and wormholes, and
return to the starting field a time before his initial departure.
Perhaps he will be able to meet himself :) .

To help FJ find out whether this is possible or not, he will supply
you with complete maps to F (1 <= F <= 5) of his farms.  No paths
will take longer than 10,000 seconds to travel and no wormhole can
bring FJ back in time by more than 10,000 seconds.

PROBLEM NAME: wormhole

INPUT FORMAT:

* Line 1: A single integer, F. F farm descriptions follow.

* Line 1 of each farm: Three space-separated integers respectively: N,
        M, and W

* Lines 2..M+1 of each farm: Three space-separated numbers (S, E, T)
        that describe, respectively: a bidirectional path between S
        and E that requires T seconds to traverse. Two fields might be
        connected by more than one path.

* Lines M+2..M+W+1 of each farm: Three space-separated numbers (S, E,
        T) that describe, respectively: A one way path from S to E
        that also moves the traveler back T seconds.

SAMPLE INPUT (file wormhole.in):

2
3 3 1
1 2 2
1 3 4
2 3 1
3 1 3
3 2 1
1 2 3
2 3 4
3 1 8


INPUT DETAILS:

Two farm maps. The first has three paths and one wormhole, and the
second has two paths and one wormhole.

OUTPUT FORMAT:

* Lines 1..F: For each farm, output "YES" if FJ can achieve his goal,
        otherwise output "NO" (do not include the quotes).

SAMPLE OUTPUT (file wormhole.out):

NO
YES

OUTPUT DETAILS:

For farm 1, FJ cannot travel back in time.
For farm 2, FJ could travel back in time by the cycle 1->2->3->1, arriving
back at his starting location 1 second before he leaves. He could start
from anywhere on the cycle to accomplish this.
*/
