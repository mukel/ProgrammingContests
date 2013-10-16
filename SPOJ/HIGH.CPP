/*
Alfonso Alfonso Peterssen
19 - 10 - 2007
SPOJ #104 "Highways"
*/
#include <cstdio>
#include <cstring>
#include <cmath>

const int MAXV = 12;
const double EPSILON = 1e-8;

typedef long double real;

int T, V, E, i, j, k;
real det;
real mat[MAXV][MAXV];

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    scanf( "%d %d", &V, &E );

    /* Init */
    memset( mat, 0, sizeof( mat ) );

    for ( i = 0; i < E; i++ ) {
      scanf( "%d %d", &j, &k );
      j--, k--;
      mat[j][j]++; mat[k][k]++;
      mat[j][k] = mat[k][j] = -1;
    }

    V--; // Delete last row and column

    /* Find Determinant */
    det = 1;
    for ( i = 0; i < V; i++ ) {
      det *= mat[i][i];
      if ( mat[i][i] < EPSILON ) break;
      for( j = i + 1; j < V; j++ )
        for( k = V - 1; k >= i; k-- )
          mat[j][k] -= mat[i][k] * mat[j][i] / mat[i][i];
    }

    double sol = det + EPSILON;
    printf( "%.0lf\n", sol );
  }

  return 0;
}
