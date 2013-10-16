/*
Alfonso Alfonso Peterssen
4 - 11 - 2007
COCI 2007 Contest 1 "SREDNJI"
*/
#include <cstdio>

const int MAXN = 100000;

int N, B, i, j, sum, pos, sol;
int ls[MAXN];
int cant[ 2 * MAXN ];

int main() {

  scanf( "%d %d", &N, &B );
  for ( i = 0; i < N; i++ ) {
    scanf( "%d", &j );
    if ( j < B ) ls[i] = -1;
    else if ( j > B ) ls[i] = 1;
    else if ( j == B ) {
      ls[i] = 0;
      pos = i;
    }
  }

  for ( i = pos; i < N; i++ ) {
    sum += ls[i];
    cant[ sum + N ]++;
  }

  sum = 0;
  for ( i = pos; i >= 0; i-- ) {
    sum += ls[i];
    sol += cant[ -sum + N ];
  }

  printf( "%d\n", sol );

  return 0;
}
