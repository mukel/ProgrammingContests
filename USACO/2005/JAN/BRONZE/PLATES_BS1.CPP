/*
Alfonso Alfonso Peterssen
29 - 8 - 2007
USACO 2005 JAN Bronze "Plate Stacking"
*/
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#define problem "d"

int N, i, j, k, sol;
vector< int > lds;

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;

  for ( i = 0; i < N; i++ ) {

    fin >> k;

    vector< int >::iterator it =
      upper_bound( lds.begin(), lds.end(), k, greater_equal< int >() );

    if ( it == lds.end() )
         lds.push_back( k );
    else *it = k;
  }

  fout << lds.size() << endl;

  return 0;
}

/*
Problem 14: Plate Stacking [Rob Kolstad, 2005]

The cows want to be on TV. They've decided their best chance is to
demonstrate their prowess in stacking plates as high as they possibly
can.  They hope to maximize entertainment value by stacking certain
plates that are thrown from stage left toward stage center.

Of course, plates can only be stacked when a strictly smaller plate
is stacked upon a larger plate. Thus, some plates might be discarded.

Given the sequence of integer of N (1 <= N <= 5,000) plate thrown
from the side of the stage, calculate the height (in plates) of the
tallest possible plate-stacking structure that can be build.  Sizes
are integers in the range 1..1,000,000.

If the plates were thrown on this order:

     7 10 7 8 9 7 8 6 4

Then the tallest possible stack would be 10, 9, 8, 6, 4 whose height is 5.

Solve this problem perfectly to earn an invitation to the Silver division.

PROBLEM NAME: plates

INPUT FORMAT:

* Line 1: A single integer, N

* Lines 2..N+1: Line i+1 describes the i_th plate tossed from the side
        of the stage.

SAMPLE INPUT (file plates.in):

9
7
10
7
8
9
7
8
6
4

OUTPUT FORMAT:

* Line 1: A single line with the maximum height of plates that can be
        stacked.

SAMPLE OUTPUT (file plates.out):

5
*/
