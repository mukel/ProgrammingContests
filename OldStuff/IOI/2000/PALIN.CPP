/*
Alfonso2 Peterssen
8 - 6 - 2008
IOI 2000 "Palindrome"
*/
#include <cstdio>
int N, i, j, dp[2][6000];
char st[6000];
int main() {
  scanf( "%d%s", &N, &st );
  for ( i = N - 1; i >= 0; i-- )
  for ( j = N - 1; j >= 0; j-- )
    if ( st[i] == st[N - j - 1] )
         dp[i&1][j] = dp[i&1^1][j + 1] + 1;
    else dp[i&1][j] = dp[i&1^1][j] >? dp[i&1][j + 1];
  printf( "%d\n", N - dp[0][0] );
  return 0;
}
