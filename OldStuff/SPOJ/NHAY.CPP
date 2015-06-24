/*
Alfonso Alfonso Peterssen
21 - 7 - 2007
SPOJ #32 "A Needle in the Haystack"
*/
#include <cstdio>

int P, i, j, *pre;
char ch, *pat;

int main() {

  while ( scanf( "%d", &P ) != EOF ) {

    pat = new char[P + 2];
    pre = new int[P + 2];

    scanf( "%s\n", pat + 1 );

    /* Preprocess */
    pre[1] = j = 0;
    for ( i = 2; i <= P; i++ ) {

      while ( j && pat[j + 1] != pat[i] )
        j = pre[j];

      if ( pat[j + 1] == pat[i] ) j++;

      pre[i] = j;
    }

    /* Search */
    j = 0;
    for ( i = 1;; i++ ) {

      scanf( "%c", &ch );

      if ( ch == '\n' ) break;

      while ( j && pat[j + 1] != ch )
        j = pre[j];

      if ( pat[j + 1] == ch ) j++;

     if ( j == P ) {
        printf( "%d\n", i - P + 1 );
        j = pre[j];
      }
    }

    printf( "\n" );

    delete [] pat;
    delete [] pre;
  }

  return 0;
}
