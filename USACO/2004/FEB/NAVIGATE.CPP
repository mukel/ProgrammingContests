/*
Alfonso Alfonso Peterssen
7 - 1 - 2008
USACO 2004 FEB "Navigation Nightmare"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int
    MAXV = 50001,
    MAXLOG = 17;

const int mov[4][2] =
    {{0,1},{1,0},{0,-1},{-1,0}}; // NESW

int V, E, T, i, j;
int u, v, w, id, dir;
bool mark[MAXV];
int level[MAXV];
int x[MAXV], y[MAXV];
int LCA[MAXLOG][MAXV];
int max_edge[MAXLOG][MAXV];

struct edge {
    int node, cost, id, dir;
};

vector< edge > G[MAXV];
queue< int > Q;

int log2( int x ) {
    int res = 1;
    while ( 1 << res <= x ) res++;
    return res - 1;
}

int find_max_edge( int u, int v ) {

    if ( level[v] > level[u] )
        swap( u, v );

    int result = 0;

    for ( j = log2( level[u] ); j >= 0; j-- )
        if ( level[u] - ( 1 << j ) >= level[v] ) {
            result >?= max_edge[j][u];
            u = LCA[j][u];
        }

    if ( u != v ) {
        for ( j = log2( level[u] ); j >= 0; j-- )
            if ( LCA[j][u] && LCA[j][u] != LCA[j][v] ) {
                result >?= max_edge[j][u];
                result >?= max_edge[j][v];
                u = LCA[j][u];
                v = LCA[j][v];
            }
        result >?= max_edge[0][u];
        result >?= max_edge[0][v];
    }

    return result;
}

int main() {

    scanf( "%d %d", &V, &E );
    for ( i = 1; i <= E; i++ ) {
        scanf( "%d %d %d %c", &u, &v, &w, &dir );
        if ( dir == 'N' ) dir = 0;
        if ( dir == 'E' ) dir = 1;
        if ( dir == 'S' ) dir = 2;
        if ( dir == 'W' ) dir = 3;
        G[u].push_back( ( edge ){ v, w, i, dir } );
        G[v].push_back( ( edge ){ u, w, i, ( dir + 2 ) % 4 } );
    }

    /* BFS */
    mark[1] = true;
    for ( Q.push( 1 ); !Q.empty(); Q.pop() ) {
        u = Q.front();
        for ( i = 0; i < G[u].size(); i++ )
            if ( !mark[ v = G[u][i].node ] ) {

                Q.push( v );
                mark[v] = true;
                level[v] = level[u] + 1;

                dir = G[u][i].dir;
                x[v] = x[u] + mov[dir][0] * G[u][i].cost;
                y[v] = y[u] + mov[dir][1] * G[u][i].cost;

                /* Build LCA */
                int lg = log2( level[v] );

                LCA[0][v] = u;
                max_edge[0][v] = G[u][i].id;
                for ( j = 1; j <= lg; j++ )
                    if ( LCA[j - 1][v] ) {
                        LCA[j][v] = LCA[j - 1][ LCA[j - 1][v] ];
                        max_edge[j][v] = max( max_edge[j - 1][ LCA[j - 1][v] ],
                                              max_edge[j - 1][v] );
                    }
            }
    }

    /* Answer the queries */
    for ( scanf( "%d", &T ); T; T-- ) {

        scanf( "%d %d %d", &u, &v, &id );

        int sol = -1;
        if ( find_max_edge( u, v ) <= id )
             sol = abs( x[u] - x[v] ) + abs( y[u] - y[v] );

        printf( "%d\n", sol );
    }

    return 0;
}

/*
Problem 1: Navigation Nightmare [Brian Dean, 2004]

Farmer John's pastoral neighborhood has N farms (2 <= N <= 40,000),
usually numbered/labeled 1..N.  A series of M (1 <= M < 40,000) vertical
and horizontal roads each of varying lengths (1 <= length <= 1000)
connect the farms.  A map of these farms might look something like
the illustration below in which farms are labeled F1..F7 for clarity
and lengths between connected farms are shown as (n):

           F1 --- (13) ---- F6 --- (9) ----- F3
            |                                 |
           (3)                                |
            |                                (7)
           F4 --- (20) -------- F2            |
            |                                 |
           (2)                               F5
            |
           F7

Being an ASCII diagram, it is not precisely to scale, of course.

Each farm can connect directly to at most four other farms via roads that
lead exactly north, south, east, and/or west.  Moreover, farms are only
located at the endpoints of roads, and some farm can be found at every
endpoint of every road.  No two roads cross, and precisely one path
(sequence of roads) links every pair of farms.

FJ lost his paper copy of the farm map and he wants to reconstruct it
from backup information on his computer.  This data contains lines
like the following, one for every road:

   There is a road of length 10 running north from Farm #23 to Farm #17
   There is a road of length 7 running east from Farm #1 to Farm #17
   ...

As FJ is retrieving this data, he is occasionally interrupted by
questions such as the following that he receives from his navigationally-
challenged neighbor, farmer Bob:

    What is the Manhattan distance between farms #1 and #23?

FJ answers Bob, when he can (sometimes he doesn't yet have enough
data yet).  In the example above, the answer would be 17, since Bob
wants to know the "Manhattan" distance between the pair of farms.
The Manhattan distance between two points (x1,y1) and (x2,y2) is
just |x1-x2| + |y1-y2| (which is the distance a taxicab in a large
city must travel over city streets in a perfect grid to connect two
x,y points).

When Bob asks about a particular pair of farms, FJ might not yet
have enough information to deduce the distance between them; in
this case, FJ apologizes profusely and replies with "-1".

PROBLEM NAME: navigate

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..M+1: Each line contains four space-separated entities, F1,
        F2, L, and D that describe a road. F1 and F2 are numbers of
        two farms connected by a road, L is its length, and D is a
        character that is either 'N', 'E', 'S', or 'W' giving the
        direction of the road from F1 to F2.

* Line M+2: A single integer, K (1 <= K <= 10,000), the number of FB's
        queries

* Lines M+3..M+K+2: Each line corresponds to a query from Farmer Bob
        and contains three space-separated integers: F1, F2, and I. F1
        and F2 are numbers of the two farms in the query and I is the
        index (1 <= I <= M) in the data after which Bob asks the
        query. Data index 1 is on line 2 of the input data, and so on.

SAMPLE INPUT (file navigate.in):

7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S
3
1 6 1
1 4 3
2 6 6

INPUT DETAILS:

This is the farm layout drawn above.

OUTPUT FORMAT:

* Lines 1..K: One integer per line, the response to each of Bob's
        queries.  Each line should contain either a distance
        measurement or -1, if it is impossible to determine the
        appropriate distance.

SAMPLE OUTPUT (file navigate.out):

13
-1
10

OUTPUT DETAILS:

At time 1, FJ knows the distance between 1 and 6 is 13.
At time 3, the distance between 1 and 4 is still unknown.
At the end, location 6 is 3 units north and 7 units west of location 2, so the distance
is 10.
*/
