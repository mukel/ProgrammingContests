/*
Alfonso Alfonso Peterssen
4 - 11 - 2007
PSN 2007 #80 "Severina"
*/
#include <cstdio>
#include <cstring>

const int
  MAXN = 300000,
  MAXW = 4000,
  MAXLEN = 100,
  MODULO = 1337377;

int N, W, S, i, j, k, len;
char st[MAXN + 1];
char tmp[MAXLEN + 1];
int dp[MAXN];

struct node {
  bool flag;
  int next[26];
} trie[ MAXW * MAXLEN + 1 ];

int main() {

  scanf( "%s", &st );
  N = strlen( st );

  scanf( "%d", &W );

  for ( i = 0; i < W; i++ ) {

    scanf( "%s", &tmp );
    len = strlen( tmp );

    /* Insert into the trie */
    for ( k = j = 0; j < len; j++ )
      if ( !trie[k].next[ tmp[j] - 'a' ] )
           k = trie[k].next[ tmp[j] - 'a' ] = ++S;
      else k = trie[k].next[ tmp[j] - 'a' ];

    trie[k].flag = true;
  }

  /* Solve */
  for ( i = 0; i < N; i++ )
    for ( k = 0, j = i; j < N; j++ ) {
      k = trie[k].next[ st[j] - 'a' ];
      if ( !k ) break;
      if ( trie[k].flag )
        dp[j] = ( dp[j] + ( i ? dp[i - 1] : 1 ) ) % MODULO;
    }

  printf( "%d\n", dp[N - 1] );

  return 0;
}
