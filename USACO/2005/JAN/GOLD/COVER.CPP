/*
Alfonso Alfonso Peterssen
29 - 8 - 2007
USACO 2005 JAN Gold "Muddy Fields"
*/
#include <cstdio>
#include <cstring> // memset

#define problem "d"
#define MAXV 1251
#define MAXF 51

int F, C, H, V, i, j, flow;
char mat[MAXF][MAXF];
bool mark[MAXV];
int cap[MAXV][MAXV], prev[MAXV];
int vidx[MAXF][MAXF], hidx[MAXF][MAXF];

  bool augment( int x ) {

    if ( mark[x] ) return false;

    mark[x] = true;
    for ( int i = 1; i <= H; i++ )
      if ( cap[x][i] && ( !prev[i] || augment( prev[i] ) ) ) {
        prev[i] = x;
        return true;
      }

    return false;
  }

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &F, &C );
  for ( i = 0; i < F; i++ )
    scanf( "%s", &mat[i] );

  for ( i = 0; i < F; i++ )
    for ( j = 0; j < C; j++ )
      if ( mat[i][j] == '*' ) {

        if ( i == 0 || mat[i - 1][j] == '.' )
             vidx[i][j] = ++V;
        else vidx[i][j] = vidx[i - 1][j];

        if ( j == 0 || mat[i][j - 1] == '.' )
             hidx[i][j] = ++H;
        else hidx[i][j] = hidx[i][j - 1];

        cap[ vidx[i][j] ][ hidx[i][j] ] = 1;
      }

  for ( i = 1; i <= V; i++ ) {
    memset( mark, false, sizeof( mark ) );
    if ( augment( i ) ) flow++;
  }

  printf( "%d\n", flow );

  return 0;
}

/*
Problem 1: Muddy Fields [Alex Schwendner, 2004]

Rain has pummeled the cows' field, a rectangular grid of R rows and
C columns (1 <= R <= 50, 1 <= C <= 50). While good for the grass,
the rain makes some patches of bare earth quite muddy. The
cows, being meticulous grazers, don't want to get their hooves dirty
while they eat.

To prevent those muddy hooves, Farmer John will place a number of
wooden boards over the muddy parts of the cows' field.  Each of the
boards is 1 unit wide, and can be any length long.  Each board must
be aligned parallel to one of the sides of the field.

Farmer John wishes to minimize the number of boards needed to cover
the muddy spots, some of which might require more than one board
to cover.  The boards may not cover any grass and deprive the cows
of grazing area but they can overlap each other.

Compute the minimum number of boards FJ requires to cover all the mud in
the field.

PROBLEM NAME: cover

INPUT FORMAT:

* Line 1: Two space-separated integers: R and C

* Lines 2..R+1: Each line contains a string of C characters, with '*'
        representing a muddy patch, and '.' representing a grassy
        patch. No spaces are present.

SAMPLE INPUT (file cover.in):

4 4
*.*.
.***
***.
..*.

OUTPUT FORMAT:

* Line 1: A single integer representing the number of boards FJ needs.

SAMPLE OUTPUT (file cover.out):

4

OUTPUT DETAILS:

Boards 1, 2, 3 and 4 are placed as follows:
1.2.
.333
444.
..2.
Board 2 overlaps boards 3 and 4.
*/
