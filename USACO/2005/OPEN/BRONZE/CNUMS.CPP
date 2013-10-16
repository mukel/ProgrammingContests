/*
Alfonso Alfonso Peterssen
30 - 8 - 2007
USACO 2005 OPEN Bronze "Countable Numbers"
*/
#include <cstdio>

#define problem "d"

int start, end, sol;

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &start, &end );

  for ( ; start <= end; start++ )
    if ( __builtin_popcount( start ) <= 4 )
         sol++;
    /* Oh, yes */
    else start |= ( start & -start ) - 1;

  printf( "%d\n", sol );

  return 0;
}

/*
Problem 11: Countable Numbers [Woburn Competition, ICPSC, 1999]

Cow hooves have no fingers to speak of, so they count in binary
instead of decimal. Of course, with only four hooves, they can't
count so very high in normal binary.

They've devised a clever counting method, though.  They stand on
one to four of their legs after putting marks in the dirt. The marks
represent binary 0's; their leg locations represent binary 1's.
This means that they can represent numbers whose binary representation
has four or fewer 1's.

Given a range of positive integers (both the start number and stop
number are in the range 1..15,000,000), determine how many numbers
in that range the cows can represent with four or fewer one bits.

PROBLEM NAME: cnums

INPUT FORMAT:

* Line 1: Two space-separated numbers: the beginning and end of a
        range to be checked

SAMPLE INPUT (file cnums.in):

100 105

OUTPUT FORMAT:

* Line 1: The count of numbers in the range that can be represented by
        four or fewer 1's using binary arithmetic.

SAMPLE OUTPUT (file cnums.out):

5

OUTPUT DETAILS:

Num Binary  Number of 1's  Representable by cows?
100 1100100    3            Yes
101 1100101    4            Yes
102 1100110    4            Yes
103 1100111    5             No
104 1101000    3            Yes
105 1101001    4            Yes
*/
