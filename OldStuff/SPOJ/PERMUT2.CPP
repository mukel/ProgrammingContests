/*
Alfonso Alfonso Peterssen
17 - 7 - 2007
SPOJ #379 "Ambiguous Permutations"
*/
#include <cstdio>

#define MAXN 100000

int N, i;
int seq[MAXN], pos[MAXN];

int main() {

  scanf( "%d", &N );
  while ( N ) {

    for ( i = 0; i < N; i++ ) {
      scanf( "%d", &seq[i] );
      pos[ --seq[i] ] = i;
    }

    for ( i = 0; i < N; i++ )
      if ( pos[i] != seq[i] ) break;

    if ( i < N ) printf( "not " );
    printf( "ambiguous\n" );

    scanf( "%d", &N );
  }

  return 0;
}
