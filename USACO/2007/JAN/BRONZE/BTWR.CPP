/*
Alfonso Alfonso Peterssen
13 - 7 - 2007
USACO 2007 JAN Bronze "The Bale Tower"
*/
#include <fstream>
using namespace std;

#define problem "btwr"
#define MAXN 20

int N, i, j, k, sol;
struct bale {
  int W, B;
  bool operator < ( const bale &x ) const {
    return W < x.W && B < x.B;
  }
} ls[MAXN];

  int dfs( int x ) {
    int i, res = 0;
    for ( int i = 0; i < N; i++ )
      if ( ls[i] < ls[x] ) res >?= dfs( i );
    return res + 1;      
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ )
    fin >> ls[i].W >> ls[i].B;
    
  for ( i = 0; i < N; i++ )
    sol >?= dfs( i );
  
  fout << sol << endl;
  
  return 0;
}

/*
Problem 13: The Bale Tower [Rob Kolstad, 2007]

Always bored with cud-chewing, the cows have invented a new game.
One cow retrieves a set of N (3 <= N <= 20) hay bales from the shed
each of which is one unit high. Each bale also has some unique width
and unique breadth.

A second cow tries to choose a set of bales to make the tallest
stack of bales in which each bale can be placed only on a bale whose
own width and breadth are smaller than the width and breadth of the
bale below. Bales can not be rotated to interchange the width and
breadth.

Help the cows determine the highest achievable tower that can be
legally built form a set of bales.

PROBLEM NAME: btwr

INPUT FORMAT:

* Line 1: A single integer, N

* Lines 2..N+1: Each line describes a bale with two space-separated
        integers,respectively the width and breadth

SAMPLE INPUT (file btwr.in):

6
6 9
10 12
9 11
8 10
7 8
5 3


INPUT DETAILS:

Six bales of various widths and breadths

OUTPUT FORMAT:

* Line 1: The height of the tallest possible tower that can legally be
        built from the bales.

SAMPLE OUTPUT (file btwr.out):

5

OUTPUT DETAILS:

These bales can be stacked for a total height of 5:
10 12
9 11
8 10
6 9
5 3
[another stacking exists, too]
*/