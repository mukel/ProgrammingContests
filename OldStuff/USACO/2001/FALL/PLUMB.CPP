/*
Alfonso Alfonso Peterssen
25 - 12 - 2007
USACO 2001 Fall "Cow Plumbing"
*/
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

const int MAXD = 100000;

typedef pair< int, int > pipe;

int D, P, i, j, k;
int dp[MAXD + 1];
vector< pipe > pipes;

int main() {

    cin >> D >> P;
    for ( i = 0; i < P; i++ ) {
        cin >> j >> k;
        pipes.push_back( pipe( k, j ) );
    }

    sort( pipes.begin(), pipes.end(),
          greater< pipe >()  );

    /* DP */
    dp[0] = INT_MAX;
    for ( i = 0; i < pipes.size(); i++ ) {
        if ( dp[D] != 0 ) break;
        for ( j = D; j >= pipes[i].second; j-- )
            if ( dp[j] == 0 && dp[j - pipes[i].second] > 0 )
                dp[j] = pipes[i].first;
    }

    cout << dp[D] << endl;

    return 0;
}

/*
PROBLEM 2: Cow Plumbing [Kolstad, 2001]

The cows want to move water from the pond to the barn, a distance of D (7
<= D <= 100,000).  They have a set of P (1 <= P <= 350) pipes, each with
positive integer length Li and positive integer capacity Ci (both numbers
fit in 24 bits).

The pipes can be connected in series into a run: the connected pipes have
the capacity that is the least of all pipes' individual capacities.  A run
must reach precisely D units (i.e., the sum of the Li's for the pipes in
a run must be D).

Find the maximum amount of water that can be moved from the pond to the
barn in one single run of pipe.

PROBLEM NAME: plumb

INPUT FORMAT:

* Line 1: One line with two integers: D and P

* Lines 2..P+1: Each line contains two integers describing a pipe: Li
          and Ci

SAMPLE INPUT (file plumb.in):

7 6
4 5
3 6
2 7
1 4
6 7
1 5

OUTPUT FORMAT:

One line with a single integer that is the maximum possible legal flow.

SAMPLE OUTPUT (file plumb.out):

5
*/
