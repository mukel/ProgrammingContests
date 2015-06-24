/*
Alfonso Alfonso Peterssen
17 - 11 - 2007
SPOJ #364 "Prime Path"
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXP = 10000;

int T, src, tgt, i, j;
int len[MAXP];
bool mark[MAXP];

int main(void) {

  /* Prime Sieve */
  mark[0] = mark[1] = true;
  for ( i = 2; i * i < MAXP; i++ )
    if ( !mark[i] )
      for ( j = i * i; j < MAXP; j += i )
        mark[j] = true;

  for ( scanf( "%d", &T ); T; T-- ) {

    queue< int > Q;

    scanf( "%d %d", &src, &tgt );

    memset( len, 0, sizeof( len ) );
    len[src] = 1;

    for ( Q.push( src ); !Q.empty() && !len[tgt]; Q.pop() ) {

      int x = Q.front();

      int pot = 10;
      for ( i = 0; i < 4; pot *= 10, i++ )
        for ( int dig = 0; dig < 10; dig++ ) {

          int y = ( x / pot ) * pot + ( dig * ( pot / 10 ) ) + x % ( pot / 10 );

          if ( y > 1000 && !len[y] && !mark[y] ) {
            len[y] = len[x] + 1;
            Q.push( y );
          }
        }
    }

    printf( "%d\n", len[tgt] - 1 );
  }
  return 0;
}
