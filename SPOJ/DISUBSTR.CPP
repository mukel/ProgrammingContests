/*
Alfonso Alfonso Peterssen
18 - 10 - 2007
SPOJ #694 "Distinct Substrings"
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXLEN = 2000;

int T, len, i, j, sol;
int sfx[MAXLEN];
char st[MAXLEN];

  bool cmp( const int &i, const int &j ) {
    return strcmp( st + i, st + j ) < 0;
  }

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    scanf( "%s", &st );
    len = strlen( st );

    for ( i = 0; i < len; i++ )
      sfx[i] = i;

    sort( sfx, sfx + len, cmp );

    sol = len * ( len + 1 ) / 2;
    for ( i = 0; i < len - 1; i++ ) {
      for ( j = 0;
            st[ sfx[i] + j ] == st[ sfx[i + 1] + j ];
            j++ );
      sol -= j;
    }

    printf( "%d\n", sol );
  }

  return 0;
}
