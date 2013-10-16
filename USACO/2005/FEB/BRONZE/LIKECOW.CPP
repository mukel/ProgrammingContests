/*
Alfonso Alfonso Peterssen
28 - 8 - 2007
USACO 2005 FEB Bronze "Cow Similarity"
*/
#include <cstdio>

#define problem "d"
#define MAXN 50

int N, i, j, k, h;
int cowa, cowb, diff, min_diff;
char cow[MAXN][5][8];

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d", &N );
  for ( i = 0; i < N; i++ )
    for ( j = 0; j < 5; j++ )
      scanf( "%s", &cow[i][j] );

  min_diff = 1000000;
  for ( i = 0; i < N; i++ )
    for ( j = i + 1; j < N; j++ ) {

      diff = 0;
      for ( k = 0; k < 5; k++ )
        for ( h = 0; h < 7; h++ )
          if ( cow[i][k][h] != cow[j][k][h] )
            diff++;

      if ( diff < min_diff ) {
        min_diff = diff;
        cowa = i + 1;
        cowb = j + 1;
      }

    }

  printf( "%d %d\n", cowa, cowb );

  return 0;
}

/*
Problem 12: Cow Similarity [Mathijs Vogelzang, 2005]

Farmer John has N (2 <= N <= 50) different cows numbered 1..N and
wants to know which two appear most similar to each other. He has
made 5x7 digital photographs of each of his cows and wants you to
write a program to compare them.

The 5x7 photos show the black and white spot pattern of a cow. Below
are the photos of two different cows ('X' represents a black part;
'.' represents a white part):

      Cow 1         Cow 2
     ..X....       ...X...
     .XXX...       ..XX...
     .XX....       .XX....
     .....X.       .XX..X.
     .X...X.       .X...X.

To compare these two cows, every spot in corresponding squares is
checked.  Each spot that is the same gets one 'similarity point'.
The two cows above score 30 'similarity points' because only five
of the corresponding squares are different (see '#' below):

         ++##+++
         +#+++++
         +++++++
         +##++++
         +++++++

Given a set of cows, find the two that are most similar and print
their two ID numbers in ascending order. It is guaranteed that only
one pair of cows has the highest similarity score.

PROBLEM NAME: likecow

INPUT FORMAT:

* Line 1: N, the number of cows

* Lines 2..N*5+1: The digital photographs of the cows, with cow i
        appearing on line i*5+1 to line i*5+5.  See the sample below.

SAMPLE INPUT (file likecow.in):

3
..X....
.XXX...
.XX....
.....X.
.X...X.
...X...
..XX...
.XX....
.XX..X.
.X...X.
XX.....
X......
XX...XX
XXXX.XX
XXX..XX

INPUT DETAILS:

The two sample cows, plus one extra cow

OUTPUT FORMAT:

* Line 1: The two cows having the maximum similarity score, in
        ascending order

SAMPLE OUTPUT (file likecow.out):

1 2

OUTPUT DETAILS:

The third cow has a similarity of score of 16 and 19 with cow 1 and
2 respectively, both lower than the similarity score of 30 between
cow 1 and 2
*/
