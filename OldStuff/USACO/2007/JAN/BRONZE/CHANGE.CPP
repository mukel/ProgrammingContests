/*
Alfonso Alfonso Peterssen
13 - 7 - 2007
USACO 2007 JAN Bronze "Making Change"
*/
#include <fstream>
using namespace std;

#define problem "change"
#define MAXV 1001
#define MAXC 10

int V, C, i, j;
int coin[MAXC], cost[MAXV];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> V >> C;
  for ( i = 0; i < C; i++ )
    fin >> coin[i];
    
  for ( i = 1; i <= V; i++) {
    cost[i] = 1 << 30;
    for ( j = 0; j < C; j++ )
      if ( coin[j] <= i )
        cost[i] <?= cost[ i - coin[j] ] + 1;
  }
        
  fout << cost[V] << endl;

  return 0;
}

/*
Problem 12: Making Change [Traditional, 2007]

Poor Bessie has taken a job in the convenience store located just
over the border in Slobbovia. Slobbovians use different coinages
than the USA; their coin values change day-by-day!

Help Bessie make optimal change for Slobbovian shoppers. You will
need to create C (1 <= C <= 1000) cents of change using N (1 <= N
<= 10) coins of various values. All test cases will be solvable
using the supplied coins.

If 5 coins of values 50, 25, 10, 5, and 1 were available, Bessie
would make optimum change (minimal coins) of 93 cents by using 1 x
50, 1 x 25, 1 x 10, 1 x 5, and 3 x 1 coins (a total of 7 coins).

How hard could it be? The final two test cases will be challenging.

PROBLEM NAME: change

INPUT FORMAT:

* Line 1: Two space-separate integers: C and N

* Lines 2..N+1: Each line contains a single unique integer that is a
        coin value that can be used to create change

SAMPLE INPUT (file change.in):

93 5
25
50
10
1
5


OUTPUT FORMAT:

* Line 1: A single integer that is the minimum number of coins to
        create C cents

SAMPLE OUTPUT (file change.out):

7
*/
