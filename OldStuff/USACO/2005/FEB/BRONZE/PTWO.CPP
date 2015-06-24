/*
Alfonso Alfonso Peterssen
28 - 7 - 2007
USACO 2005 FEB Bronze "Powers of Two"
*/
#include <cstdio>

#define problem "d"
#define MAXLEN 100

int N, len, i, j, r, t;
int num[MAXLEN];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d", &N );

  num[ len++ ] = 1;
  for ( i = 0; i < N; i++ ) {

    r = 0;
    for ( j = 0; j < len; j++ ) {
      t = num[j] * 2 + r;
      num[j] = t % 10;
      r = t / 10;
    }

    if ( r )
      num[ len++ ] = r;
  }

  for ( i = len; i; i-- )
    printf( "%d", num[i - 1] );

  printf( "\n" );

  return 0;
}

/*
Problem 11: Powers of Two [Traditional, 2005]

Given an integer N (0 <= N <= 265), print exactly value of 2 to the Nth
power (with no leading zeroes or spaces, of course).

PROBLEM NAME: ptwo

INPUT FORMAT:

* Line 1: The integer N

SAMPLE INPUT (file ptwo.in):

100

OUTPUT FORMAT:

* Line 1: A single line that contains 2 to the Nth power.

SAMPLE OUTPUT (file ptwo.out):

1267650600228229401496703205376
*/
