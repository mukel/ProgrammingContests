/*
Alfonso Alfonso Peterssen
10 - 11 - 2007
SPOJ #1881 "Instruction Decoder"
*/
#include <cstdio>

int N, i, x, sol;
char op[4];

int main() {

  for (;;) {

    sol = 16;

    scanf( "%d", &N );
    if ( N == 0 ) break;

    for ( i = 0; i < N; i++ ){
      scanf( "%s %d", &op, &x );
      if ( op[0] == 'M' )
        for ( ; sol && !( x & 1 ); sol--, x >>= 1 );
    }

    printf( "%d\n", 1 << sol );
  }

  return 0;
}
