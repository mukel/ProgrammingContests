/*
Alfonso Alfonso Peterssen
18 - 10 - 2007
SPOJ #687 "Repeats"
*/
#include <cstdio>

const int MAXN = 50000;

int T, len, sol, i, j, k;
char st[MAXN];

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    scanf( "%d\n", &len );
    for ( i = 0; i < len; i++ )
      scanf( "%c\n", &st[i] );

    sol = 1;
    for ( i = 1; i <= len / 2; i++ ) {

      if ( len / i <= sol ) break;

      k = 0;
      for ( j = i; j < len; j++ )
        if ( st[j] != st[j - i] ) {

          sol >?= ( j - k ) / i;
          k = j - i + 1;
        }

      sol >?= ( len - k ) / i;
    }

    printf( "%d\n", sol );
  }

  return 0;
}
