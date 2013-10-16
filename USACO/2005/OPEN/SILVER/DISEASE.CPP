/*
Alfonso Alfonso Peterssen
23 - 5 - 2007
USACO 2005 OPEN Silver "Disease Manangement"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXN 1000

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int N, D, M, i, j, k, tup, sol;
int cow[MAXN];

  void comb( int i, int cant ) {
    if ( cant == M ) {
      int sum = 0;
      for ( i = 0; i < N; i++ )
        if ( ( cow[i] & tup ) == cow[i] ) sum++;
      sol >?= sum;
      return;
    }
    for ( ;i < D - M + cant + 1; i++ ) {
      tup |= 1 << i;
      comb( i + 1, cant + 1 );
      tup ^= 1 << i;
    }
  }

int main() {

  fin >> N >> D >> M;

  for ( i = 0; i < N; i++ )
    for ( fin >> j; j > 0; j-- ) {
      fin >> k;
      cow[i] |= 1 << ( k - 1 );
    }

  comb( 0, 0 );

  fout << sol << endl;

  return 0;
}


/*
Problem 8: Disease Manangement [Coaches, 2004]

Alas!  A set of D (1 <= D <= 15) diseases (numbered 1..D) is running through
the farm.  Farmer John would like to milk as many of his N (1 <= N <= 1,000)
cows as possible.  If the milked cows carry more than K (1 <= K <= D)
different diseases among them, then the milk will be too contaminated and
will have to be discarded in its entirety.  Please help determine the
largest number of cows FJ can milk without having to discard the milk.

PROBLEM NAME: disease

INPUT FORMAT:

* Line 1: Three space-separated integers: N, D, and K

* Lines 2..N+1: Line i+1 describes the diseases of cow i with a list
        of 1 or more space-separated integers. The first integer, d_i,
        is the count of cow i's diseases; the next d_i integers
        enumerate the actual diseases. Of course, the list is empty if
        d_i is 0.

SAMPLE INPUT (file disease.in):

6 3 2
0
1 1
1 2
1 3
2 2 1
2 2 1

OUTPUT FORMAT:

* Line 1: M, the maximum number of cows which can be milked.

SAMPLE OUTPUT (file disease.out):

5

OUTPUT DETAILS:

If FJ milks cows 1, 2, 3, 5, and 6, then the milk will have only two
diseases (#1 and #2), which is no greater than K (2).
*/
