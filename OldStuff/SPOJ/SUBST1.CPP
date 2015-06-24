/*
Alfonso Alfonso Peterssen
18 - 10 - 2007
SPOJ #705 "New Distinct Substrings"
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>

const int MAXLEN = 60000;

int T, len, i, j;
long long sol;
char st[MAXLEN];
int sfx[MAXLEN];

  int idx_cmp( const void *p1, const void *p2 ) {
   return strcmp( st + *(int *)p1, st + *(int *)p2 );
  }

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    scanf( "%s", &st );
    len = strlen( st );

    for ( i = 0; i < len; i++ )
      sfx[i] = i;

    qsort( sfx, len, sizeof( int ), idx_cmp );

    sol = len;
    sol = sol * ( sol + 1 ) / 2;
    for ( i = 0; i < len - 1; i++ ) {
      for( j = 0; st[ sfx[i] + j ] == st[ sfx[i + 1] + j ]; j++ );
      sol -= j;
    }

    printf( "%lld\n", sol );
  }

  return 0;
}
