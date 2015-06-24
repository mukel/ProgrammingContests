/*
Alfonso Alfonso Peterssen
17 - 11 - 2007
USACO 2007 NOV Silver "Cow Hurdles"
*/
#include <cstdio>
#include <cstring>

const int
  MAXV = 301,
  oo = 1000000000;

int V, E, T, i, j, k, h;
int cost[MAXV][MAXV];

int main() {

  scanf( "%d %d %d", &V, &E, &T );
  
    /* Init */
  for ( i = V; i; i-- )
    for ( j = i - 1; j; j-- )
      cost[i][j] = cost[j][i] = oo;
  
  for ( i = 0; i < E; i++ ) {
    scanf( "%d %d %d", &j, &k, &h );
    cost[j][k] <?= h;
  }
  
  /* Floyd -> MAXMIN */
  for ( k = 1; k <= V; k++ )  
  for ( i = 1; i <= V; i++ ) if ( cost[i][j] != oo )
  for ( j = 1; j <= V; j++ )
    cost[i][j] <?= ( cost[i][k] >? cost[k][j] );
  
  /* ... */
  for ( ; T; T-- ) {  
    scanf( "%d %d", &j, &k );
    if ( cost[j][k] == oo )
         printf( "-1\n" );
    else printf( "%d\n", cost[j][k] );
  }

  return 0;
}

/*
Problem 6: Cow Hurdles [Neal Wu, 2007]

Farmer John wants the cows to prepare for the county jumping
competition, so Bessie and the gang are practicing jumping over
hurdles. They are getting tired, though, so they want to be able
to use as little energy as possible to jump over the hurdles.

Obviously, it is not very difficult for a cow to jump over several
very short hurdles, but one tall hurdle can be very stressful. Thus,
the cows are only concerned about the height of the tallest hurdle
they have to jump over.

The cows' practice room has N (1 <= N <= 300) stations, conveniently
labeled 1..N. A set of M (1 <= M <= 25,000) one-way paths connects
pairs of stations; the paths are also conveniently labeled 1..M.
Path i travels from station S_i to station E_i and contains exactly
one hurdle of height H_i (1 <= H_i <= 1,000,000). Cows must jump
hurdles in any path they traverse.

The cows have T (1 <= T <= 40,000) tasks to complete. Task i comprises
two distinct numbers, A_i and B_i (1 <= A_i <= N; 1 <= B_i <= N),
which connote that a cow has to travel from station A_i to station
B_i (by traversing over one or more paths over some route). The
cows want to take a path the minimizes the height of the tallest
hurdle they jump over when traveling from A_i to B_i. Your job is to
write a program that determines the path whose tallest hurdle is
smallest and report that height.

PROBLEM NAME: hurdles

INPUT FORMAT:

* Line 1: Three space-separated integers: N, M, and T

* Lines 2..M+1: Line i+1 contains three space-separated integers: S_i,
        E_i, and H_i

* Lines M+2..M+T+1: Line i+M+1 contains two space-separated integers
        that describe task i: A_i and B_i

SAMPLE INPUT (file hurdles.in):

5 6 3
1 2 12
3 2 8
1 3 5
2 5 3
3 4 4
2 4 8
3 4
1 2
5 1


OUTPUT FORMAT:

* Lines 1..T: Line i contains the result for task i and tells the
        smallest possible maximum height necessary to travel between
        the stations. Output -1 if it is impossible to travel between
        the two stations.

SAMPLE OUTPUT (file hurdles.out):

4
8
-1

OUTPUT DETAILS:

Query #1: The best way is to simply travel on the path from station 3 to
station 4.
Query #2: There is a path from station 1 to station 2, but a better way
would be to travel from station 1 to station 3 and then to station 2.
Query #3: There are no paths that start at station 5, so it is clear that
there is no way to reach station 1 from station 5.
*/
