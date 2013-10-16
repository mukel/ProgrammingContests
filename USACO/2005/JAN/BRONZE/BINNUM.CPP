/*
Alfonso Alfonso Peterssen
date
USACO JAN 2005 "Binary Numbers"
*/
#include <fstream>
using namespace std;

#define problem "d"

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

  void print( long long x ) {
    if ( !x ) return ;
    print( x / 2 );
    fout << ( x & 1 );
  }

int main() {

  long long N;

  fin >> N;

  if ( N )
       print( N );
  else fout << 0;

  fout << endl;

  return 0;
}

/*
Problem 11: Binary Numbers [Traditional, 2004]

Given a positive integer A (0 <= A <= 2,110,000,000), print its binary
(base two) representation (without extra leading zeroes, of course). Do not
use automatic conversion routines or automatic binary printing routines.

PROBLEM NAME: binnum

INPUT FORMAT:

* Line 1: An integer

SAMPLE INPUT (file binnum.in):

277309

OUTPUT FORMAT:

* Line 1: The binary representation of the input integer

SAMPLE OUTPUT (file binnum.out):

1000011101100111101
*/
