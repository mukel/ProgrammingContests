/*
Alfonso Alfonso Peterssen
31 - 12 - 2007
USACO 2007 DEC Silver "Charm Bracelet"
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXM = 15000;

int N, M, i, j, w, d;
int dp[MAXM];

int main() {

    cin >> N >> M;
    for ( i = 0; i < N; i++ ) {
        cin >> w >> d;
        for ( j = M; j >= w; j-- )
            dp[j] >?= dp[j - w] + d;
    }

    cout << dp[M] << endl;

    return 0;
}

/*
Problem 6: Charm Bracelet [Kolstad/Cox, 2006]

Bessie has gone to the mall's jewelry store and spies a charm
bracelet. Of course, she'd like to fill it with the best charms
possible from the N (1 <= N <= 3,402) available charms. Each charm
i in the supplied list has a weight W_i (1 <= W_i <= 400), a
'desirability' factor D_i (1 <= D_i <= 100), and can be used at
most once.  Bessie can only support a charm bracelet whose weight
is no more than M (1 <= M <= 12,880).

Given that weight limit as a constraint and a list of the charms
with their weights and desirability rating, deduce the maximum
possible sum of ratings.

PROBLEM NAME: charm

INPUT FORMAT:

* Line 1: Two space-separated integers: N and M

* Lines 2..N+1: Line i+1 describes charm i with two space-separated
        integers: W_i and D_i

SAMPLE INPUT (file charm.in):

4 6
1 4
2 6
3 12
2 7

INPUT DETAILS:

Four potential charms; maximum weight 6

OUTPUT FORMAT:

* Line 1: A single integer that is the greatest sum of charm
        desirabilities that can be achieved given the weight
        constraints

SAMPLE OUTPUT (file charm.out):

23

OUTPUT DETAILS:

Without the second possible charm, the 4+12+7=23 is the highest
value for weight 1+2+3 <= 6
*/
