/*
Alfonso Alfonso Peterssen
24 - 8 - 2007
SPOJ #263 "Period"
*/
#include <cstdio>

#define MAXP 1000001

int T, P, tc, i, j;
int pre[MAXP];
char pat[MAXP];

int main() {

  scanf( "%d", &T );
  for ( tc = 1; tc <= T; tc++ ) {

    scanf( "%d", &P );
    scanf( "%s", &pat[1] );
    
    printf( "Test case #%d\n", tc );

    j = 0;
    for ( i = 2; i <= P; i++ ) {

      while ( j && pat[j + 1] != pat[i] )
        j = pre[j];

      if ( pat[j + 1] == pat[i] ) j++;

      pre[i] = j;
      
      if ( j && ( i % ( i - j ) == 0 ) )
        printf( "%d %d\n", i, i / ( i - j ) );
    }
    
    printf( "\n" );

  }

  return 0;
}
