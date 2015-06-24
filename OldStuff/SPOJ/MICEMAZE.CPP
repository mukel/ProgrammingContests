/*
Alfonso Alfonso Peterssen
28 - 10 - 2007
SPOJ #1845 "Mice and Maze"
*/
#include <cstdio>

const int
  MAXV = 101,
  oo = 1000000000;

int V, E, S, T, i, j, k, sol;
int mat[MAXV][MAXV];

int main() {

  scanf( "%d %d %d %d", &V, &S, &T, &E );

  for ( i = 1; i <= V; i++ )
    for ( j = i + 1; j <= V; j++ )
      mat[i][j] = mat[j][i] = oo;

  for ( i = 0; i < E; i++ ) {
    int u, v, w;
    scanf( "%d %d %d", &u, &v, &w );
    mat[u][v] <?= w;
  }

  /* Floyd-Warshall */
  for ( k = 1; k <= V; k++ )
  for ( i = 1; i <= V; i++ )
  for ( j = 1; j <= V; j++ )
    mat[i][j] <?= mat[i][k] + mat[k][j];

  for ( i = 1; i <= V; i++ )
    if ( mat[i][S] <= T ) sol++;

  printf( "%d\n", sol );

  return 0;
}
