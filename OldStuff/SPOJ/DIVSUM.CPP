/*
Alfonso Alfonso Peterssen
17 - 7 - 2007
SPOJ #74 "Divisor Summation"
*/
#include <cstdio>
#define MAXV 500001
int T, i, j;
int sum[MAXV];
int main() {
  for ( i = 1; i + i < MAXV; i++ )
    for ( j = i + i; j < MAXV; j += i ) sum[j] += i;
  for ( scanf( "%d", &T ); T; T-- ) {
    scanf( "%d", &j );
    printf( "%d\n", sum[j] );
  }
  return 0;
}
