/*
Alfonso Alfonso Peterssen
29 - 8 - 2007
USACO 2005 JAN Bronze "Satellite Photo"
*/
#include <cstdio>

#define problem "d"
#define MAXC 76

int F, C, i, j;
int cant, xmin, ymin, xmax, ymax;
int barns, cows;
char mat[MAXC][MAXC];

  void dfs( int x, int y ) {

    if ( mat[x][y] == '.' )
      return ;

    cant++;
    mat[x][y] = '.';

    ymin <?= y; ymax >?= y;
    xmin <?= x; xmax >?= x;

    if ( x > 0 )     dfs( x - 1, y );
    if ( x < F - 1 ) dfs( x + 1, y );
    if ( y > 0 )     dfs( x, y - 1 );
    if ( y < C - 1 ) dfs( x, y + 1 );
  }

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &F, &C );
  for ( i = 0; i < F; i++ )
    scanf( "%s", &mat[i] );

  for ( i = 0; i < F; i++ )
    for ( j = 0; j < C; j++ )
      if ( mat[i][j] != '.' ) {

        cant = 0;
        xmin = MAXC; xmax = -1;
        ymin = MAXC; ymax = -1;

        dfs( i, j );

        if ( cant == ( xmax - xmin + 1 ) * ( ymax - ymin + 1 ) )
             barns++;
        else cows++;

      }

  printf( "%d\n%d\n", barns, cows );

  return 0;
}

/*
Problem 13: Satellite Photo [Brian Dean, 2004]

Farmer John always wanted a good map of his farm, so he purchased
a satellite photograph of his land which is represented by R (1 <=
R <= 75) rows and C (1 <= C <= 75) columns in the photo.  One part
of a photo looks something like this:

..................
..#####.......##..
..#####......##...
..................
#.......###.....#.
#.....#####.......

In trying to interpret the photo, he figures that every connected
shape is either a barn or a cow.  A "connected shape" is a set of
one or more #'s that are adjacent to each other either vertically
or horizontally. The following would be two distinct "connected
shapes":

....
.#..
..#.
....

FJ claims that a connected shape is a barn if it is a filled-in
rectangle whose four sides are parallel to the x and y axes. In the
first photo above, there are three barns (sizes 2x1, 2x5, and 1x1)
and two cows (you'd be surprised at the size of some of FJ's cows!).
Count the number of barns and cows in his satellite photo.

A cow never completely encircles another cow or barn.

PROBLEM NAME: satel

INPUT FORMAT:

* Line 1: Two space-separated integers: R and C.

* Lines 2..R+1: Line i+1 represents row i of the photograph and
        contains C characters (and no spaces).

SAMPLE INPUT (file satel.in):

5 8
#####..#
#####.##
......#.
.###...#
.###..##

INPUT DETAILS:

The photo consists of 5 lines, each of which is 8 characters long.

OUTPUT FORMAT:

* Line 1: The number of barns in the photo.

* Line 2: The number of cows in the photo.

SAMPLE OUTPUT (file satel.out):

2
2

OUTPUT DETAILS:

The photo has 2 barns (the shapes on the left) and 2 cows (on the right).
*/
