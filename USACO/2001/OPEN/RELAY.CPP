/*
Alfonso Alfonso Peterssen
25 - 12 - 2007
USACO 2001 Open "Cow Relays"
*/
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAXV = 800;

int K, V, E, i, j, x, sol;
int paths[MAXV];
int cost[MAXV][MAXV]; // unique edges
vector< int > G[MAXV];

typedef pair< int, int > edge;
priority_queue< edge, vector< edge >, greater< edge > > Q;

int main() {

    cin >> K >> V >> E;
    for ( i = 0; i < E; i++ ) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back( v );
        G[v].push_back( u );
        cost[u][v] = cost[v][u] = w;
    }

    /* Find kth-path */
    Q.push( edge( 0, 0 ) );
    while ( !Q.empty() ) {

        edge e = Q.top();
        Q.pop();

        x = e.second;
        if ( paths[x] >= K ) continue;
        paths[x]++;
        if ( x == V - 1 ) {
            sol += e.first;
            continue;
        }

        for ( i = 0; i < G[x].size(); i++ )
            Q.push( edge( e.first + cost[x][ G[x][i] ], G[x][i] ) );
    }

    cout << sol << endl;

    return 0;
}

/*
PROBLEM 1: Cow Relays [Brian Dean, 2001]

Farmer John has formed a relay team for a race by choosing K (2 <= K <=
40) of his cows.  The race is run on FJ's farm which has N (4 <= N <
800) fields numbered 1..N and M (1 <= M <= 4000) unique bidirectional
pathways that connect pairs of different fields.  You will be given the
time it takes a cow to traverse each pathway.

The first cow begins the race in field #1 and runs to the finish line
in field #N. As soon as the first cow finishes, the next cow then starts
from field #1 and runs to field #N and so on.  For this race, no two
cows can follow precisely the same route (a route is a sequence of
fields).

Write a program which computes the minimum possible time required for
FJ's relay team.  It is guaranteed that some minimum possible time
exists.  Any cows can revisit a path in her trip to the other barn if
that turns out to be required for a "best" solution.  As soon as a cow
enters field #N, her relay leg is finished.

PROBLEM NAME: relay

INPUT FORMAT:

* Line 1: One line with three integers: K, N, and M

* Lines 2..M+1: Each line contains three integers describing a path:
         the starting field, the ending field, and the integer time
         to traverse the path (in the range 1..9500).

SAMPLE INPUT (file relay.in):

4 5 8
1 2 1
1 3 2
1 4 2
2 3 2
2 5 3
3 4 3
3 5 4
4 5 6

OUTPUT FORMAT:

One line with a single integer that is the minimum possible time to run
a relay.

SAMPLE OUTPUT (file relay.out):

23

[Namely: Cow 1: 1->2->5         4
        Cow 2: 1->3->5         6
        Cow 3: 1->2->1->2->5   6
        Cow 4: 1->2->3->5      7]
*/
