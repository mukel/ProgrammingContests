/*
Alfonso Alfonso Peterssen
25 - 12 - 2007
USACO 2001 Fall "Cow Dominoes"
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int N, i, j, k, r;
vector< int > dom, sol;

int main() {

    cin >> N;
    for ( i = 0; i < N; i++ ) {
        cin >> j >> k;
        dom.push_back( j + k );
    }

    sort( dom.begin(), dom.end() );

    for ( i = 0; i < dom.size(); i++ ) {
        sol.push_back( ( dom[i] + r ) % 10 );
        r = ( dom[i] + r ) / 10;
    }

    for ( ; r > 0; r /= 10 )
        sol.push_back( r % 10 );

    copy( sol.rbegin(), sol.rend(),
          ostream_iterator< int >( cout ) );

    cout << endl;

    return 0;
}

/*
PROBLEM 1: Cow Dominoes [Korean training problem submitted by Joseph Lim]

The cows are playing dominoes with N (1 <= N <= 40) domino tiles.  Each
domino has two numbers in the range 0..9 arranged one on top of the other,
like this:

                             +---+
                             | 5 |
                             +---+
                             | 2 |
                             +---+

The figure below depicts three dominoes arranged side-by-side along with
two base 10 integers that represent the arrangement:

       +---+ +---+ +---+
       | 5 | | 3 | | 4 |   5 * 100 + 3 * 10 + 4 * 1 = 534
       +---+ +---+ +---+
       | 2 | | 4 | | 1 |   2 * 100 + 4 * 10 + 1 * 1 = 241
       +---+ +---+ +---+

Of course, any domino can be rotated 180 degrees, swapping the top and
bottom numbers:

                    +---+      +---+
                    | 5 |      | 2 |
                    +---+  ->  +---+
                    | 2 |      | 5 |
                    +---+      +---+

The particular game the cows are playing requires laying down the N
dominoes (choosing the order and the rotation) so that the sum of the two
base 10 representations is maximized.  For the example above, the maximum
sum is 775. Your job is to calculate that maximum sum.

PROBLEM NAME: cowdom

INPUT FORMAT:

* Line 1: One line with a single integer: N

* Lines 2..N+1: Each line contains two integers describing a domino.

SAMPLE INPUT (file cowdom.in):

3
1 4
2 5
3 4

OUTPUT FORMAT:

One line with a single integer that is the maximum possible sum of the base
10 representations of the dominoes laid out side-by-side.

SAMPLE OUTPUT (file cowdom.out):

775
*/
