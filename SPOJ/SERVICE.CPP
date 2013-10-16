/*
Alfonso Alfonso Peterssen
29 - 9 - 2007
SPOJ #703 "Mobile Service"
*/
#include <cstdio>
#include <cstring>

#define MAXL 200
#define oo 1000000000

int T, N, L, i, j, k, sol;
int job, last, now, next;
int C[MAXL][MAXL];
int dp[2][MAXL][MAXL];

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    scanf( "%d %d", &L, &N );
    for ( i = 0; i < L; i++ )
      for ( j = 0; j < L; j++ )
        scanf( "%d", &C[i][j] );

    memset( dp, 127, sizeof( dp ) );

    scanf( "%d", &job ); job--;
    for ( j = 0; j < 3; j++ )
      for ( k = 0; k < 3; k++ )
        if ( j != k )
          dp[0][j][k] = C[ 3 - j - k ][job];

    for ( i = 0; i < N - 1; i++ ) {

      last = job;
      scanf( "%d", &job ); job--;

      now = i & 1;
      next = ( i + 1 ) & 1;

      for ( j = 0; j < L; j++ )
        for ( k = 0; k < L; k++ ) {

          int value = dp[now][j][k];

          if ( k != job && last != job ) dp[next][last][k] <?= value + C[j][job];
          if ( j != job && last != job ) dp[next][j][last] <?= value + C[k][job];
          if ( j != job && k != job )    dp[next][j][k]    <?= value + C[last][job];

          dp[now][j][k] = oo;
        }
    }

    sol = oo;
    for ( j = 0; j < L; j++ )
      for ( k = 0; k < L; k++ )
        sol <?= dp[( N - 1 ) & 1][j][k];

    printf( "%d\n", sol );
  }

  return 0;
}
