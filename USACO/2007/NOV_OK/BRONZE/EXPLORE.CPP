/*
Alfonso Alfonso Peterssen
17 - 11 - 2007
USACO 2007 NOV Bronze "Exploration"
*/
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 50000;

int N, T, i, last, dist, sol;
int ls[MAXN];

  bool by_abs( const int &a, const int &b ) {
    return abs( a ) < abs( b );
  }

int main() {

  scanf( "%d %d", &T, &N );
  for ( i = 0; i < N; i++ )
    scanf( "%d", &ls[i] );

  sort( ls, ls + N, by_abs );

  last = 0;
  for ( sol = 0; sol < N; sol++ ) {
    if ( dist + abs( last - ls[sol] ) > T ) break;
    dist += abs( last - ls[sol] );
    last = ls[sol];
  }

  printf( "%d\n", sol );

  return 0;
}

/*
Problem 11: Exploration [Jeffrey Wang, 2007]

Bessie is traveling on a road teeming with interesting landmarks.
The road is labeled just like a number line, and Bessie starts at
the "origin" (x = 0). A total of N (1 <= N <= 50,000) landmarks are
located at points x_1, x_2, ..., x_N  (-100,000 <= x_i <= 100,000).
Bessie wants to visit as many landmarks as possible before sundown,
which occurs in T (1 <= T <= 1,000,000,000) minutes. She travels 1
distance unit in 1 minute.

Bessie will visit the landmarks in a particular order. Since the
landmarks closer to the origin are more important to Farmer John,
she always heads for the unvisited landmark closest to the origin.
No two landmarks will be the same distance away from the origin.

Help Bessie determine the maximum number of landmarks she can visit
before the day ends.

PROBLEM NAME: explore

INPUT FORMAT:

* Line 1: Two space-separated integers: T and N

* Lines 2..N+1: Line i+1 contains a single integer that is the
        location of the ith landmark: x_i

SAMPLE INPUT (file explore.in):

25 5
10
-3
8
-7
1

INPUT DETAILS:

Bessie has 25 minutes before sundown, and there are 5 landmarks
located at positions 10, -3, 8, -7, and 1.

OUTPUT FORMAT:

* Line 1: The maximum number of landmarks Bessie can visit.

SAMPLE OUTPUT (file explore.out):

4

OUTPUT DETAILS:

Bessie sequentially visits the landmarks at locations 1, -3, -7,
and 8, after which she has traveled a total of 24 minutes.  She
cannot visit the next intended landmark at position 10, since this
would extend her total travel time to 26 minutes.
*/
