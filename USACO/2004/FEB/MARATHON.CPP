/*
Alfonso Alfonso Peterssen
7 - 1 - 2008
USACo 2004 FEB "Cow Marathon"
*/
#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

const int MAXV = 50001;

int V, E, i, diameter;
int u, v, w, dir;
bool mark[MAXV];
vector< pair< int, int > > G[MAXV];

int dfs( int x ) {

    int i, max_path = 0;

    mark[x] = true;
    for ( i = 0; i < G[x].size(); i++ )
        if ( !mark[ G[x][i].first ] ) {
            int tmp = dfs( G[x][i].first ) + G[x][i].second;
            diameter >?= max_path + tmp;
            max_path >?= tmp;
        }

    return max_path;
}

int main() {

    scanf( "%d %d", &V, &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d %d %c", &u, &v, &w, &dir );
        G[u].push_back( make_pair( v, w ) );
        G[v].push_back( make_pair( u, w ) );
    }

    dfs( 1 );

    printf( "%d\n", diameter );

    return 0;
}

/*
Problem 2: Cow Marathon [Brian Dean, 2004]

After hearing about the epidemic of obesity in the USA, Farmer John
wants his cows to get more exercise, so he has committed to create
a bovine marathon for his cows to run.  The marathon route will
include a pair of farms and a path comprised of a sequence of roads
between them. Since FJ wants the cows to get as much exercise as
possible he wants to find the two farms on his map that are the
farthest apart from each other (distance being measured in terms
of total length of road on the path between the two farms).  Help
him determine the distances between this farthest pair of farms.

PROBLEM NAME: marathon

INPUT FORMAT:

* Lines 1.....: Same input format as "Navigation Nightmare".

SAMPLE INPUT (file marathon.in):

7 6
1 6 13 E
6 3 9 E
3 5 7 S
4 1 3 N
2 4 20 W
4 7 2 S

INPUT DETAILS:

The same farm layout as in problem 1.

OUTPUT FORMAT:

* Line 1: An integer giving the distance between the farthest pair of
        farms.

SAMPLE OUTPUT (file marathon.out):

52

OUTPUT DETAILS:

The longest marathon runs from farm 2 via roads 4, 1, 6 and 3
to farm 5 and is of length 20+3+13+9+7=52.
*/
