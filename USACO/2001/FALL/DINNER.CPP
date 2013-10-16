/*
Alfonso Alfonso Peterssen
25 - 12 - 2007
USACO 2001 Fall "Dinner Time"
*/
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int N, i, j, k;
vector< int > order, pos, sol;

int main() {

    cin >> N;
    pos.resize( N + 1 );
    for ( i = 0; i < N; i++ ) {
        cin >> j;
        pos[j] = i;
        order.push_back( j );
    }

    sol = order;
    for ( i = 0; i < sol.size(); i++ )
        if ( pos[ order[i] ] < pos[ order[i] - 1 ] &&
             abs( sol[i] - order[ pos[ order[i] - 1 ] ]  ) < 2 )
             swap( sol[i], sol[ pos[ order[i] - 1 ] ] );

    copy( sol.begin(), sol.end(),
          ostream_iterator< int > ( cout, "\n" ) );

    return 0;
}

/*
PROBLEM 3: Dinner Time [Burch, 2001]

Farmer John has N (3 <= N <= 50000) cows, each branded with a unique serial
number in the range 1..N.  Each night, they line up for dinner by forming
a line (queue) with the cows in a relatively random order.  Any given
ordering can be expressed as an N digit number in base N.

Farmer John doesn't like random ordering.  He wants the cows to line up in
a way such that the number that represents the ordering is minimized.  The
cows, however, don't like do be told exactly what to do all the time.

FJ and the cows have reached a compromise:  the cows will line up and then
rearrange themselves into a certain new order that minimizes the ordering's
representation.  The trick is that each serial number in the new ordering
can differ by no more than 1 from the serial number that used to occupy
that slot.

If 8 cows lined up like this:   8 5 7 3 6 4 2 1
Then the new ordering would be: 7 4 8 2 6 5 3 1
because:
        * No slot in the second list contains a digit that differs from
          the digit above by more than 1 (sometimes the difference is 0)
        * This is the smallest number that can be obtained using the rules.

Your job is to tell FJ the new ordering of cows so he can ensure they
are lined up properly.

PROBLEM NAME: dinner

INPUT FORMAT:

* Line 1: One line with a single integer: N

* Lines 2..N+1: Each line contains a single integer that is the serial
          number of a cow in the respective slot.  The left-hand cow
          is given first.

SAMPLE INPUT (file dinner.in):

8
8
5
7
3
6
4
2
1

OUTPUT FORMAT:

N lines, each with a single integer that tells which cow belongs in the
respective slot.  The first output line should contain the serial
number of the cow in the left-hand slot (and so on).

SAMPLE OUTPUT (file dinner.out):

7
4
8
2
6
5
3
1
*/
