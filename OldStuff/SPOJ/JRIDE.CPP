/*
Alfonso Alfonso Peterssen
18 - 7 - 2007
SPOJ #408 "Jill Rides Again"
*/
#include <cstdio>

#define MAXN 100000
#define oo 2000000000

int T, N, t, i, j;
int sum, start, end, sol;
int val[MAXN];

int main() {

  scanf( "%d", &T );
  for ( t = 1; t <= T; t++ ) {

    scanf( "%d", &N );
    for ( i = 1; i < N; i++ )
      scanf( "%d", &val[i] );

    j = 1;
    sum = 0; sol = -oo;
    start = 0; end = -1;

    for ( i = 1; i < N; i++ ) {
      sum += val[i];
      if ( sum < 0 ) {
        sum = 0;
        j = i + 1;
      }
      else
      if ( sum > sol ||
         ( ( sum == sol && ( i - j > end - start ) ) ) ) {
        sol = sum;
        start = j;
        end = i;
      }
    }

    if ( sol > 0 )
         printf( "The nicest part of route %d is between stops %d and %d\n", t, start, end + 1 );
    else printf( "Route %d has no nice parts\n", t );

  }

  return 0;
}
