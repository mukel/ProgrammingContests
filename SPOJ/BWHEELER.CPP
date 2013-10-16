/*
Alfonso Alfonso Peterssen
2 - 11 - 2007
SPOJ #1874 "Burrows Wheeler Precompression"
*/
#include <cstring>
#include <cstdio>

const int MAXLEN = 2000;

int pos, len, i, j, k;
int bk[256], idx[MAXLEN];
char st[MAXLEN], sol[MAXLEN];

int main() {

  for (;;) {

    scanf( "%d", &pos );
    if ( pos == 0 ) break;
    pos--;

    scanf( "%s", &st );
    len = strlen( st );

    memset( bk, 0, sizeof( bk ) );

    for ( i = 0; i < len; i++ )
        idx[i] = bk[ st[i] ]++;

    for ( i = j = 0; i < 256; i++ ) {
      k = bk[i];
      bk[i] = j;
      j += k;
    }

    j = pos;
    for( i = len - 1; i >= 0; i--, j = idx[j] + bk[ st[j] ] )
        sol[i] = st[j];

    sol[len] = '\0';

    printf( "%s\n", sol );
  }

  return 0;
}
