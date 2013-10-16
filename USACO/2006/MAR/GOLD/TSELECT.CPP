/*
Alfonso Alfonso Peterssen
4 - 1 - 2007
USACO 2006 MAR Gold "Milk Team Select"
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV = 600;

int V, S, i, j;
int milk[MAXV];
int dp[2][MAXV][MAXV];
vector< int > G[MAXV];

    int dfs( int x ) {

        dp[0][x][0] = 0;
        dp[1][x][0] = milk[x];

        int i, j, k, sons = 0;

        for ( i = 0; i < G[x].size(); i++ ) {

            int y = G[x][i];
            sons += dfs( y );

            for ( j = sons; j >= 0; j-- )
                for ( k = 0; k <= j; k++ ) {
                    dp[0][x][j] >?= dp[0][x][j - k] +
                                    max( dp[0][y][k], dp[1][y][k] );

                    dp[1][x][j] >?= dp[1][x][j - k] + dp[0][y][k];

                    if ( k < j )
                        dp[1][x][j] >?= dp[1][x][j - k - 1] + dp[1][y][k];
                }
        }

        return sons + 1;
    }

int main() {

    cin >> V >> S;
    for ( i = 1; i <= V; i++ ) {
        cin >> milk[i] >> j;
        G[j].push_back( i );
    }

    /* Init */
    for ( i = 0; i <= V; i++ ) {
        fill( dp[0][i], dp[0][i] + V, -( 1 << 29 ) );
        fill( dp[1][i], dp[1][i] + V, -( 1 << 29 ) );
    }

    dfs( 0 );

    for ( i = V - 1; i >= 0; i-- )
        if ( dp[0][0][i] >= S )
            break;

    cout << i << endl;

    return 0;
}

/*
Problem 2: Milk Team Select [Percy Liang, 2002]

Farmer John's N (1 <= N <= 500) cows are trying to select the
milking team for the world-famous Multistate Milking Match-up (MMM)
competition. As you probably know, any team that produces at least
X (1 <= X <= 1,000,000) gallons of milk is a winner.

Each cow has the potential of contributing between -10,000 and
10,000 gallons of milk. (Sadly, some cows have a tendency to knock
over jugs containing milk produced by other cows.)

The MMM prides itself on promoting family values. FJ's cows have
no doubt that they can produce X gallons of milk and win the contest,
but to support the contest's spirit, they want to send a team with
as many parent-child relationships as possible (while still producing
at least X gallons of milk). Not surprisingly, all the cows on FJ's
farm are female.

Given the family tree of FJ's cows and the amount of milk that each
would contribute, compute the maximum number of parent-child
relationships that can exist in a winning team. Note that a set of
cows with a grandmother-mother-daughter combination has two
parent-child relationships (grandmother-mother, mother-daughter).

PROBLEM NAME: tselect

INPUT FORMAT:

* Line 1: Two space-separated integers, N and X.

* Lines 2..N+1: Line i+1 contains two space-separated integers
        describing cow i. The first integer is the number of gallons
        of milk cow i would contribute. The second integer (range
        1..N) is the index of the cow's mother. If the cow's mother is
        unknown, the second number is 0. The family information has no
        cycles: no cow is her own mother, grandmother, etc.

SAMPLE INPUT (file tselect.in):

5 8
-1 0
3 1
5 1
-3 3
2 0

INPUT DETAILS:

There are 5 cows. Cow 1 can produce -1 gallons and has two daughters, cow
2 and 3, who can produce 3 and 5 gallons, respectively. Cow 3 has a
daughter (cow 4) who can produce -3 gallons. Then there's cow 5, who can
produce 2 gallons.

OUTPUT FORMAT:

* Line 1: The maximum number of parent-child relationships possible on
        a winning team. Print -1 if no team can win.

SAMPLE OUTPUT (file tselect.out):

2

OUTPUT DETAILS:

The best team consists of cows 1, 2, 3, and 5. Together they produce
(-1)+3+5+2 = 9 >= 8 gallons and have 2 parent-child relationships
(1--2 and 1--3). Note that a team with cows 2, 3, and 5 would be
able to produce more milk (10 gallons), but would have fewer
parent-child relationships (0).
*/
