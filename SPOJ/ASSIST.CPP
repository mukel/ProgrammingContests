/*
Alfonso Alfonso Peterssen
16 - 11 - 2007
SPOJ #1798 "Assistance Required"
*/
#include <cstdio>

const int
  MAXN = 3001,
  MAXP = 40000;

int N, i, j, k, h;
int sol[MAXN];
bool mark[MAXP];

int main () {

  j = 2;
  for ( i = 1; i <= MAXN; i++ ) {

    while ( j < MAXP && mark[j] ) j++;
    sol[i] = j;

    for ( k = j; k < MAXP; ) {
      mark[k] = true;
      for ( h = 0 ; h < j; h++ ) {
        k++;
        while ( k < MAXP && mark[k] ) k++;
      }
    }
  }

  for (;;) {
    scanf( "%d", &N );
    if ( !N ) break;
    printf( "%d\n", sol[N] );
  }

  return 0;
}

