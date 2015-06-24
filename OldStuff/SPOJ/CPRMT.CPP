/*
Alfonso Alfonso Peterssen
31 - 8 - 2007
SPOJ #1728 "Common Permutation"
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXLEN 1001

int i, len;
char ch;
char stA[MAXLEN], stB[MAXLEN];
int frqA[256], frqB[256];

int main() {

  while ( scanf( "%s\n%s", &stA, &stB ) != EOF ) {

    memset( frqA, 0, sizeof( frqA ) );
    memset( frqB, 0, sizeof( frqB ) );

    len = strlen( stA );
    for ( i = 0; i < len; i++ )
      frqA[ stA[i] ]++;

    len = strlen( stB );
    for ( i = 0; i < len; i++ )
      frqB[ stB[i] ]++;

    for ( ch = 'a'; ch <= 'z'; ch++ )
      for ( i = min( frqA[ch], frqB[ch] ); i; i-- )
        printf( "%c", ch );

    printf( "\n" );

  }

  return 0;
}
