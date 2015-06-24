/*
Alfonso Alfonso Peterssen
10 - 11 - 2007
COCI 2007 Contest 1 "ZAPIS"
*/
#include <cstdio>

const int
  MAXN = 201,
  MODULO = 100000;

const char* bracket[3] = { "()", "[]", "{}" };

int N, i, j, k, b, sz;
char st[MAXN];
long long dp[MAXN][MAXN];

int main() {

  scanf( "%d", &N );
  scanf( "%s", &st );

  /* Init */
  for ( i = 0; i < N; i++ )
    dp[i + 1][i] = 1;

  /* DP */
  for ( sz = 1; sz < N; sz += 2 )
    for ( i = 0; i < N - sz; i++ )
      for ( j = i + sz, k = i + 1; k <= j; k += 2 )
        for ( b = 0; b < 3; b++ )
          if ( ( st[i] == '?' || st[i] == bracket[b][0] ) &&
               ( st[k] == '?' || st[k] == bracket[b][1] ) ) {
            dp[i][j] += dp[i + 1][k - 1] * dp[k + 1][j];
            if ( dp[i][j] >= MODULO )
              dp[i][j] = MODULO + dp[i][j] % MODULO;
          }

  int sol = dp[0][N - 1];
  printf( ( sol < MODULO ) ? "%d\n" : "%05d\n", sol % MODULO );

  return 0;
}
