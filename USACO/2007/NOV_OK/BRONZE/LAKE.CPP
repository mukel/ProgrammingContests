/*
Alfonso Alfonso Peterssen
17 - 11 - 2007
USACO 2007 NOV Bronze "Avoid The Lakes"
*/
#include <cstdio>

const int
  MAXF = 200,
  mov[4][2] = {{-1, 0},{0,-1},{0,1},{1,0}};

int F, C, N, i, j, k, cant, sol;
bool mark[MAXF][MAXF];

  void dfs( int x, int y ) {
    cant++;
    mark[x][y] = false;
    for ( int i = 0; i < 4; i++ ) {
      int nx = x + mov[i][0],
          ny = y + mov[i][1];
      if ( mark[nx][ny] ) dfs( nx, ny );
    }
  }

int main() {

  scanf( "%d %d %d", &F, &C, &N );
  for ( ; N; N-- ) {
    scanf( "%d %d", &j, &k );
    mark[j][k] = true;
  }

  for ( i = 1; i <= F; i++ )
    for ( j = 1; j <= C; j++ )
      if ( mark[i][j] ) {
        cant = 0;
        dfs( i, j );
        sol >?= cant;
      }

  printf( "%d\n", sol );

  return 0;
}

/*
Problem 13: Avoid The Lakes [Jeffrey Wang, 2007]

Farmer John's farm was flooded in the most recent storm, a fact
only aggravated by the information that his cows are deathly afraid
of water. His insurance agency will only repay him, however, an
amount depending on the size of the largest "lake" on his farm.

The farm is represented as a rectangular grid with N (1 <= N <=
100) rows and M (1 <= M <= 100) columns. Each cell in the grid is
either dry or submerged, and exactly K (1 <= K <= N*M) of the cells
are submerged. As one would expect, a lake has a central cell to
which other cells connect by sharing a long edge (not a corner).
Any cell that shares a long edge with the central cell or shares a
long edge with any connected cell becomes a connected cell and is
part of the lake.

PROBLEM NAME: lake

INPUT FORMAT:

* Line 1: Three space-separated integers: N, M, and K

* Lines 2..K+1: Line i+1 describes one submerged location with two
        space separated integers that are its row and column: R and C

SAMPLE INPUT (file lake.in):

3 4 5
3 2
2 2
3 1
2 3
1 1

INPUT DETAILS:

The farm is a grid with three rows and four columns; five of the cells
are submerged. They are located in the positions (row 3, column 2);
(row 2, column 2); (row 3, column 1); (row 2, column 3); (row 1,
column 1):
              # . . .
              . # # .
              # # . .

OUTPUT FORMAT:

* Line 1: The number of cells that the largest lake contains.

SAMPLE OUTPUT (file lake.out):

4

OUTPUT DETAILS:

The largest lake consists of the input's first four cells.
*/
