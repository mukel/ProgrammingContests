/*
Alfonso Alfonso Peterssen
20 - 7 - 2007
SPOJ #1030 "Triple Fat Ladies"
*/
#include <cstdio>

int T;
long long N;
int end[4] = { 192, 442, 692, 942 };

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {
    scanf( "%lld", &N );
    N--;
    printf( "%lld\n", N / 4 * 1000 + end[N & 3] );
  }

  return 0;
}
