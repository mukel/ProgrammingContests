/*
Alfonso Alfonso Peterssen
17 - 11 - 2007
USACO 2007 NOV "Speed Reading "
*/
#include <cstdio>

int N, P, rest, speed, time, sol;

int main() {

  scanf( "%d %d", &P, &N );
  for ( ; N; N-- ) {
    scanf( "%d %d %d", &speed, &time, &rest );

    int st = speed * time;

    sol = P / st * ( time + rest );

    if ( P && !( P % st ) )
         sol -= rest;
    else sol += ( P % st + speed - 1 ) / speed;

    printf( "%d\n", sol );
  }

  return 0;
}

/*
Problem 12: Speed Reading [Jeffrey Wang, 2007]

All K (1 <= K <= 1,000) of the cows are participating in Farmer
John's annual reading contest. The competition consists of reading
a single book with N (1 <= N <= 100,000) pages as fast as possible
while understanding it.

Cow i has a reading speed S_i (1 <= S_i <= 100) pages per minute,
a maximum consecutive reading time T_i (1 <= T_i <= 100) minutes,
and a minimum rest time R_i (1 <= R_i <= 100) minutes.  The cow can
read at a rate of S_i pages per minute, but only for T_i minutes
at a time. After she stops reading to rest, she must rest for R_i
minutes before commencing reading again.

Determine the number of minutes (rounded up to the nearest full
minute) that it will take for each cow to read the book.

PROBLEM NAME: read

INPUT FORMAT:

* Line 1: Two space-separated integers: N and K

* Lines 2..K+1: Line i+1 contains three space-separated integers: S_i,
        T_i, and R_i

SAMPLE INPUT (file read.in):

10 3
2 4 1
6 1 5
3 3 3

INPUT DETAILS:

The book has 10 pages; 3 cows are competing. The first cow reads
at a rate of 2 pages per minute, can read for at most 4 minutes at
a time, and must rest for 1 minute after reading. The second reads
at a rate of 6 pages per minute, can read for at most 1 minute at
a time, and must rest 5 minutes after reading. The last reads at a
rate of 3 pages per minute, can read for at most 3 minutes at a
time, and must rest for 3 minutes after reading.

OUTPUT FORMAT:

* Lines 1..K: Line i should indicate how many minutes (rounded up to
        the nearest full minute) are required for cow i to read the
        whole book.

SAMPLE OUTPUT (file read.out):

6
7
7

OUTPUT DETAILS:

The first cow can read 8 pages in 4 minutes, rest for 1 minute, and
read the last 2 pages in a minute. The second reads 6 pages in a
minute, rests for 5 minutes, and finishes in the next minute. The
last reads 9 pages in 3 minutes, rests for 3 minutes, and finishes
in the next minute.
*/
