/*
Alfonso Alfonso Peterssen
7 - 1 - 2008
USACO 2004 FEB "Distance Queries"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int
    MAXV = 50001,
    MAXLOG = 17;

int V, E, T, i, j;
int u, v, w, dir;
bool mark[MAXV];
int level[MAXV];
int LCA[MAXLOG][MAXV];
int cost[MAXLOG][MAXV];
vector< pair< int, int > > G[MAXV];
queue< int > Q;

int log2( int x ) {
    int res = 1;
    while ( 1 << res <= x ) res++;
    return res - 1;
}

int dist( int u, int v ) {

    if ( level[v] > level[u] )
        swap( u, v );

    int result = 0;
    for ( j = log2( level[u] ); j >= 0; j-- )
        if ( level[u] - ( 1 << j ) >= level[v] ) {
            result += cost[j][u];
            u = LCA[j][u];
        }

    if ( u != v ) {
        for ( j = log2( level[u] ); j >= 0; j-- )
            if ( LCA[j][u] && LCA[j][u] != LCA[j][v] ) {
                result += cost[j][u];
                result += cost[j][v];
                u = LCA[j][u];
                v = LCA[j][v];
            }
        result += cost[0][u];
        result += cost[0][v];
    }

    return result;
}

int main() {

    scanf( "%d %d", &V, &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d %d %c", &u, &v, &w, &dir );
        G[u].push_back( make_pair( v, w ) );
        G[v].push_back( make_pair( u, w ) );
    }

    /* BFS */
    mark[1] = true;
    for ( Q.push( 1 ); !Q.empty(); Q.pop() ) {

        u = Q.front();
        for ( i = 0; i < G[u].size(); i++ )
            if ( !mark[ v = G[u][i].first ] ) {

                Q.push( v );
                mark[v] = true;

                cost[0][v] = G[u][i].second;
                level[v] = level[u] + 1;

                /* LCA */
                int lg = log2( level[v] );

                LCA[0][v] = u;
                for ( j = 1; j <= lg; j++ )
                    if ( LCA[j - 1][v] ) {
                        LCA[j][v] = LCA[j - 1][ LCA[j - 1][v] ];
                        cost[j][v] = cost[j - 1][v] +
                                     cost[j - 1][ LCA[j - 1][v] ];
                    }
            }
    }

    /* Answer the queries */
    for ( scanf( "%d", &T ); T; T-- ) {
        scanf( "%d %d", &u, &v );
        printf( "%d\n", dist( u, v ) );
    }

    return 0;
}

/*
Problem 3: Distance Queries [Brian Dean, 2004]

Farmer John's cows refused to run in his marathon since he chose a
path much too long for their leisurely lifestyle.  He therefore
wants to find a path of a more reasonable length.  The input to
this problem consists of the same input as in "Navigation Nightmare",
followed by a line containing a single integer K, followed by K
"distance queries".  Each distance query is a line of input containing
two integers, giving the numbers of two farms between which FJ is
interested in computing distance (measured in the length of the
roads along the path between the two farms).  Please answer FJ's
distance queries as quickly as possible!

PROBLEM NAME: dquery

INPUT FORMAT:

* Lines 1..1+M: Same format as "Navigation Nightmare"

* Line 2+M: A single integer, K.  1 <= K <= 10,000

* Lines 3+M..2+M+K: Each line corresponds to a distance query and
        contains the indices of two farms.

SAMPLE INPUT (file dquery.in):

7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S
3
1 6
1 4
2 6

INPUT DETAILS:

The same farm layout as in problem 1.

OUTPUT FORMAT:

* Lines 1..K: For each distance query, output on a single line an
        integer giving  the appropriate distance.

SAMPLE OUTPUT (file dquery.out):

13
3
36

OUTPUT DETAILS:

Farms 2 and 6 are 20+3+13=36 apart.
*/
