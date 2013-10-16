/*
PROG: paint2
LANG: C++
ID: a2peter1
*/
#include <cstdio>

const int MAXN = 200;

int N, K, i, j, sol;
int cows[MAXN][MAXN];
int fil[MAXN], col[MAXN],
    diag1[ 2 * MAXN ], diag2[ 2 * MAXN ];

int main() {

  freopen( "paint2.in", "r", stdin );
  freopen( "paint2.out", "w", stdout );

  scanf( "%d %d", &N, &K );
  for ( i = 0; i < K; i++ ) {
    int x, y;
    scanf( "%d %d", &x, &y );
    fil[x]++;
    col[y]++;
    diag1[x + y]++;
    diag2[x - y + N]++;
    cows[x][y]++;
  }

  for ( i = N; i; i-- )
    for ( j = N; j; j-- )
      if ( fil[i] + col[j] +
           diag1[i + j] + diag2[i - j + N] -
           3 * cows[i][j] == K )
           sol++;

  printf( "%d\n", sol );

  return 0;
}
