/*
Alfonso Alfonso Peterssen
28 - 10 - 2007
SPOJ #1804 "Genetic Code"
*/
#include <cstdio>

const int MAXN = 5001;

int N, i, j, sz;
int seq[MAXN ], sol[MAXN ];

int main() {

  /* Gen -> O( n ) */
  seq[ sz++ ] = 0;
  seq[ sz++ ] = 1;
  for ( ; sz < MAXN; ) {

    int last_sz = sz;

    for ( j = last_sz / 2; j < last_sz && sz < MAXN; j++ )
      if ( seq[j] == 0 ) {
        seq[ sz++ ] = 0;
        seq[ sz++ ] = 1;
      } else {
        seq[ sz++ ] = 1;
        seq[ sz++ ] = 0;
      }
  }

  /* Transform */
  for ( i = 0; i < MAXN - 1; i++ )
    if ( seq[i] == seq[i + 1] )
         sol[i] = 2;
    else sol[i] = seq[i];

  for (;;) {

    scanf( "%d", &N );
    if ( !N ) break;

    for ( i = 0; i < N; i++ )
      printf( "%c", sol[i] + 'N' );

    printf( "\n" );
  }

  return 0;
}
