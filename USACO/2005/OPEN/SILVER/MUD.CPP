/*
Alfonso Alfonso Peterssen
30 - 8 - 2007
USACO 2005 OPEN Silver "Muddy roads"
*/
#include <cstdio>
#include <algorithm>
#include <utility> // pair
using namespace std;

#define problem "d"
#define MAXN 10000

int N, L, i, j, last, sol;
pair< int, int > ls[MAXN];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &N, &L );
  for ( i = 0; i < N; i++ )
    scanf( "%d %d", &ls[i].first, &ls[i].second );

  sort( ls, ls + N );

  last = -1;
  for ( i = 0; i < N; i++ ) {

    if ( last >= ls[i].second ) continue;

    ls[i].first >?= last;

    j = ls[i].second - ls[i].first;

    sol += j / L;

    if ( j % L ) {
      sol++;
      last = ls[i].first + ( j / L + 1 ) * L;
    } else last = ls[i].second;

  }

  printf( "%d\n", sol );

  return 0;
}

/*
Problem 9: Muddy roads [Dutch Championships, via Jan Kuipers, 2004]

Farmer John has a problem: the dirt road from his farm to town has
suffered in the recent rainstorms and now contains (1 <= N <= 10,000)
mud pools.

Farmer John has a collection of wooden planks of length L that he
can use to bridge these mud pools. He can overlap planks and the
ends do not need to be anchored on the ground. However, he must
cover each pool completely.

Given the mud pools, help FJ figure out the minimum number of planks
he needs in order to completely cover all the mud pools.

PROBLEM NAME: mud

INPUT FORMAT:

* Line 1: Two space-separated integers: N and L

* Lines 2..N+1: Line i+1 contains two space-separated integers: s_i
        and e_i (0 <= s_i < e_i <= 1,000,000,000) that specify the
        start and end points of a mud pool along the road. The mud
        pools will not overlap.  These numbers specify points, so a
        mud pool from 35 to 39 can be covered by a single board of
        length 4. Mud pools at (3,6) and (6,9) are not considered to
        overlap.

SAMPLE INPUT (file mud.in):

3 3
1 6
13 17
8 12

INPUT DETAILS:

FJ needs to use planks of length 3 to cover 3 mud pools.  The mud pools
cover regions 1 to 6, 8 to 12, and 13 to 17.

OUTPUT FORMAT:

* Line 1: The miminum number of planks FJ needs to use.

SAMPLE OUTPUT (file mud.out):

5

OUTPUT DETAILS:

FJ can cover the mud pools with five planks of length 3 in the
following way:
                   111222..333444555....
                   .MMMMM..MMMM.MMMM....
                   012345678901234567890
*/
