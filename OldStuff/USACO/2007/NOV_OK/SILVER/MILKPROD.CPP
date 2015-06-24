/*
Alfonso Alfonso Peterssen
17 - 11 - 2007
USACO 2007 NOV Silver "Milking Time"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXM = 1000;

int N, M, R, i, j, k, sol;
int dp[MAXM];
struct interval {
  int start, end, cost;
  bool operator < ( const interval &x ) const {
    return end < x.end;
  }
} ls[MAXM];

int main() {

  scanf( "%d %d %d", &N, &M, &R );
  for ( i = 0; i < M; i++ ) {
    int s, e, c;
    scanf( "%d %d %d", &s, &e, &c );
    ls[i] = ( interval ) { s, e + R, c };
  }

  sort( ls, ls + M );

  for ( i = 0; i < M; i++ ) {
    for ( j = 0; j < i; j++ )
      if ( ls[j].end <= ls[i].start )
        dp[i] >?= dp[j];
    dp[i] += ls[i].cost;
  }

  printf( "%d\n", *max_element( dp, dp + M ) );

  return 0;
}

/*
Problem 7: Milking Time [Jeffrey Wang, 2007]

Bessie is such a hard-working cow. In fact, she is so focused on
maximizing her productivity that she decides to schedule her next
N (1 <= N <= 1,000,000) hours (conveniently labeled 0..N-1) so that
she produces as much milk as possible.

Farmer John has a list of M (1 <= M <= 1,000) possibly overlapping
intervals in which he is available for milking. Each interval i has
a starting hour (0 <= starting_hour_i < N), an ending hour
(starting_hour_i < ending_hour_i <= N), and a corresponding efficiency
(1 <= efficiency_i <= 1,000,000) which indicates how many gallons
of milk that he can get out of Bessie in that interval. Farmer John
starts and stops milking at the beginning of the starting hour and
ending hour, respectively. When being milked, Bessie must be milked
through an entire interval.

Even Bessie has her limitations, though. After being milked during
any interval, she must rest R (1 <= R <= N) hours before she can
start milking again. Given Farmer Johns list of intervals, determine
the maximum amount of milk that Bessie can produce in the N hours.

PROBLEM NAME: milkprod

INPUT FORMAT:

* Line 1: Three space-separated integers: N, M, and R

* Lines 2..M+1: Line i+1 describes FJ's ith milking interval with
        three space-separated integers: starting_hour_i,
        ending_hour_i, and efficiency_i

SAMPLE INPUT (file milkprod.in):

12 4 2
1 2 8
10 12 19
3 6 24
7 10 31

INPUT DETAILS:

Bessie wants to schedule the next 12 hours; Farmer John has four
intervals in which he can milk her; Bessie must rest 2 hours after
every milking. The first interval lasts from hour 1 to hour 2, the
second from hour 10 to hour 12, the third from hour 3 to hour 6,
and the fourth from hour 7 to hour 10. Farmer John can get 8, 19,
24, and 31 gallons of milk, respectively, from Bessie in those
intervals.

OUTPUT FORMAT:

* Line 1: The maximum number of gallons of milk that Bessie can
        product in the N hours

SAMPLE OUTPUT (file milkprod.out):

43

OUTPUT DETAILS:

If Bessie uses the first interval, she cannot use the third because
she needs 2 hours of rest. If she uses the second, she cannot use
the fourth.  Lastly, if she uses the third, she cannot use the
fourth. The best situation is choosing the second and third intervals,
producing 43 gallons of milk.
*/
