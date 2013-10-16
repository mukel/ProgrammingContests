/*
Alfonso Alfonso Peterssen
29 - 8 - 2007
USACO 2005 JAN Silver "Sumsets"
*/
#include <cstdio>

#define problem "d"
#define MAXN 1000001
#define BASE 2
#define MODULO 1000000000

int N, i, j, dp[MAXN];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d", &N );

  dp[0] = 1;
  for ( i = 1; i <= N; i *= BASE )
    for ( j = i; j <= N; j++ ) {
      dp[j] += dp[j - i];
      if ( dp[j] >= MODULO )
        dp[j] -= MODULO;
    }

  printf( "%d\n", dp[N] );

  return 0;
}

/*
Problem 6: Sumsets [Marek Turski, 2002]

Farmer John commanded his cows to search for different sets of
numbers that sum to a given number. The cows use only numbers that
are an integer power of 2.  Here are the possible sets of numbers
that sum to 7:

1) 1+1+1+1+1+1+1
2) 1+1+1+1+1+2
3) 1+1+1+2+2
4) 1+1+1+4
5) 1+2+2+2
6) 1+2+4

Help FJ count all possible representations for a given integer N
(1 <= N <= 1,000,000).

PROBLEM NAME: sumset

INPUT FORMAT:

A single line with a single integer, N.

SAMPLE INPUT (file sumset.in):

7

OUTPUT FORMAT:

The number of ways to represent N as the indicated sum.  Due to the
potential huge size of this number, print only last 9 digits (in base
10 representation).

SAMPLE OUTPUT (file sumset.out):

6
*/
