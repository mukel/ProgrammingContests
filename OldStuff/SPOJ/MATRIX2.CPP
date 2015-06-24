/*
Alfonso Alfonso Peterssen
30 - 9 - 2007
SPOJ #912 "Submatrix of submatrix"
*/
#include <cstdio>

#define MAXN 1001
#define oo 1000000000
#define sum( x1, y1, x2, y2 ) \
  ( T[x2][y2] - T[x1 -1][y2] - T[x2][y1 - 1] + T[x1 - 1][y1 - 1] )

int TC, N, M, A, B, C, D, i, j, k, diff, sol;
int bigX, bigY, smallX, smallY;
int T[MAXN][MAXN];
int min_box[MAXN][MAXN];
int min_left[MAXN], min_right[MAXN];
int big[MAXN][MAXN],
    small[MAXN][MAXN];

int main() {

  for ( scanf( "%d", &TC ); TC; TC-- ) {

    /* The order could be wrong */
    scanf( "%d %d %d %d %d %d", &N, &M, &A, &B, &C, &D );
    for ( i = 1; i <= N; i++ ) {
      scanf( "%d", &T[i][1] );
      for ( j = 2; j <= M; j++ )
        T[i][j] = ( T[i][j - 1] * 71 + 17 ) % 100 + 1;
    }

    for ( i = 1; i <= N; i++ )
      for ( j = 1; j <= M; j++ )
        T[i][j] += T[i - 1][j] + T[i][j - 1] - T[i - 1][j - 1];

    for ( i = 1; i <= N - A + 1; i++ )
      for ( j = 1; j <= M - B + 1; j++ )
        big[i][j] = sum( i, j, i + A - 1, j + B - 1 );

    for ( i = 1; i <= N - C + 1; i++ )
      for ( j = 1; j <= M - D + 1; j++ )
        small[i][j] = sum( i, j, i + C - 1, j + D - 1 );

    diff = B - D - 1;
    for ( i = 2; i < N; i++ )
      for ( j = diff + 1; j <= M; j += diff ) {

        min_left[j] = min_right[j] = small[i][j];

        for ( k = j + 1; k < j + diff && k <= M; k++ )
          min_right[k] = min_right[k - 1] <? small[i][k];

        for ( k = j - 1; k > j - diff; k-- )
          min_left[k] = min_left[k + 1] <? small[i][k];

        for ( k = j - diff + 1; k <= j; k++ )
          min_box[i][k] = min_left[k] <? min_right[k + diff - 1];
      }

    diff = A - C - 1;
    for ( j = 2; j < M; j++ )
      for ( i = diff + 1; i <= N; i += diff ) {

        min_left[i] = min_right[i] = min_box[i][j];

        for ( k = i + 1; k < i + diff && k <= N; k++ )
          min_right[k] = min_right[k - 1] <? min_box[k][j];

        for ( k = i - 1; k > i - diff; k-- )
          min_left[k] = min_left[k + 1] <? min_box[k][j];

        for ( k = i - diff + 1; k <= i; k++ )
          min_box[k][j] = min_left[k] <? min_right[k + diff - 1];
      }

    sol = -oo;
    for ( i = 1; i <= N - A + 1; i++ )
      for ( j = 1; j <= M - B + 1; j++ )
        sol >?= big[i][j] - min_box[i + 1][j + 1];

    printf( "%d\n", sol );
  }

  return 0;
}
