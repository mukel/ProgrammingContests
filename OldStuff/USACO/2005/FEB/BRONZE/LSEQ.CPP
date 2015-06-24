/*
Alfonso Alfonso Peterssen
28 - 8 - 2007
USACO 2005 FEB Bronze "Linear Sequences"
*/
#include <cstdio>

#define problem "d"
#define MAXS 100

int S, i, j, k, sol;
int ls[MAXS];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d", &S );
  for ( i = 0; i < S; i++ )
    scanf( "%d", &ls[i] );

  for ( i = 0; i < S; i++ )
    for ( j = i + 1; j < S; j++ )
      for ( k = j + 1; k < S; k++ )
        if ( ls[k] - ls[j] == ls[j] - ls[i] )
          sol++;

  printf( "%d\n", sol );

  return 0;
}

/*
Problem 13: Linear Sequences [Traditional, 2005]

A linear sequence is an ordered triple (s1,s2,s3) where the difference
s2-s1 is the same as the difference s3-s2.  Examples include: (1,2,3),
(2,4,6), and (14,21,28).

Given a sorted set of S (3 <= S <= 30) unique integers in the range
1..100, count the number of linear sequences formed by all the
possible triples.

PROBLEM NAME: lseq

INPUT FORMAT:

* Line 1: A single integer, S

* Line 2: S space-separated integers

SAMPLE INPUT (file lseq.in):

7
1 2 3 4 6 8 9

OUTPUT FORMAT:

* Line 1 : A single integer that is the number of linear subsequences.
         The integer is guaranteed to fit into a signed 32-bit
        integer.

SAMPLE OUTPUT (file lseq.out):

5

OUTPUT DETAILS:

These are the sequences:
1 2 3
2 3 4
2 4 6
3 6 9
4 6 8
*/
