/*
Alfonso Alfonso Peterssen
13 - 7 - 2007
USACO 2007 JAN Bronze "Qualified Primes"
*/
#include <fstream>
using namespace std;

#define problem "qprime"
#define MAXB 4000001

int A, B, D, i, j, sol;
bool mark[MAXB];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> A >> B >> D;

  mark[1] = true;
  for ( i = 2; i * i <= B; i++ )
    if ( !mark[i] )
      for ( j = i * i; j <= B; j += i )
        mark[j] = true;

  for ( i = A; i <= B; i++ )
    if ( !mark[i] ) {
      for ( j = i; j && ( j % 10 != D ); j /= 10 );
      if ( j ) sol++;
    }

  fout << sol << endl;

  return 0;
}

/*
Problem 11: Qualified Primes [Kolstad/Ho, 2007]

Farmer John has begun branding the cows with sequential prime
numbers. Bessie has noticed this and is curious about the occurrence
of various digits in those brands.

Help Bessie determine the number of primes in the inclusive range
A..B (1 <= A <= B <= 4,000,000; B <= A + 1,000,000; one test case
has B <= A + 2,000,000 ) that contain a supplied digit D.

A prime is a positive integer with exactly two divisors (1 and
itself). The first primes are 2, 3, 5, 7, 11, 13, 17, 19, 23, and,
29.

PROBLEM NAME: qprime

INPUT FORMAT:

* Line 1: Three space-separated integers: A, B, and D

SAMPLE INPUT (file qprime.in):

10 15 3


INPUT DETAILS:

How many primes in the range 10..15 contain the digit 3?

OUTPUT FORMAT:

* Line 1: The count of primes in the range that contain the digit D.

SAMPLE OUTPUT (file qprime.out):

1

OUTPUT DETAILS:

Just 13 in this range contains a '3'.
*/
