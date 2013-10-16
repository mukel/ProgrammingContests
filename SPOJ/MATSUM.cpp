/*
Alfonso Alfonso Peterssen
20 - 7 - 2007
SPOJ #1029 "Matrix Summation"
*/
#include <cstdio>
#include <cstring>

#define MAXN 1025

int T, N, x1, y1, x2, y2, value;
char op[10];

struct {

  int T[MAXN][MAXN], SIZE;

  inline int lobit( int x ) { return x & -x; }

  void update( int x ,int y, int amount ) {
    x++; y++;
    for ( ; x <= SIZE; x += lobit( x ) )
      for ( int y1 = y; y1 <= SIZE; y1 += lobit( y1 ) )
        T[x][y1] += amount;
  }

  int sum( int x, int y ) {
    x++; y++;
    int res = 0;
    for ( ; x; x -= lobit( x ) )
      for ( int y1 = y; y1; y1 -= lobit( y1 ) )
        res += T[x][y1];
    return res;
  }

  int operator () ( int x1, int y1, int x2, int y2 ) {
    return sum( x2, y2 ) - sum( x2, y1 - 1 ) -
           sum( x1 - 1, y2 ) + sum( x1 - 1, y1 - 1 );
  }

  void reset( int sz ) {
    SIZE = sz;
    memset( T, 0, sizeof( T ) );
  }

} ABI;

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    scanf( "%d", &N );

    ABI.reset( N );

    while ( true ) {

      scanf( "%s ", &op );

      if ( strcmp( op, "SET" ) == 0 ) {
        scanf( "%d %d %d", &x1, &y1, &value );
        ABI.update( x1, y1, value - ABI( x1, y1, x1, y1 ) );
      }

      if ( strcmp( op, "SUM" ) == 0 ) {
        scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
        printf( "%d\n", ABI( x1, y1, x2, y2 ) );
      }

      if ( strcmp( op, "END" ) == 0 ) break;
    }

  }

  return 0;
}
