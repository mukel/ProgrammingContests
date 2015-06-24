/*
Alfonso Alfonso Peterssen
4 - 11 - 2007
COCI 2007 Contest 1 "CETVRTA"
*/
#include <cstdlib>
#include <iostream>
using namespace std;

int i, j, u, v;
int x[3], y[3];

  int min3( int a, int b, int c ) {
    return a <? b <? c;
  }

  int max3( int a, int b, int c ) {
    return a >? b >? c;
  }

  bool check( int u, int v ) {
    for ( int i = 0; i < 3; i++ )
      if ( u == x[i] && v == y[i] )
        return false;
    return true;
  }

  void solution( int u, int v ) {
    cout << u << " " << v << endl;
    exit( 0 );
  }

int main() {

  for ( i = 0; i < 3; i++ )
    cin >> x[i] >> y[i];

  for ( i = 0; i < 3; i++ )
    for ( j = 0; j < 3; j++ )
      if ( j != i )
        if ( x[i] == x[j] && y[i] == y[j] )
          solution( x[ 3 - i - j ], y[ 3 - i - j ] );

  u = min3( x[0], x[1], x[2] );
  v = min3( y[0], y[1], y[2] );
  if ( check( u, v ) ) solution( u, v );

  u = min3( x[0], x[1], x[2] );
  v = max3( y[0], y[1], y[2] );
  if ( check( u, v ) ) solution( u, v );

  u = max3( x[0], x[1], x[2] );
  v = min3( y[0], y[1], y[2] );
  if ( check( u, v ) ) solution( u, v );

  u = max3( x[0], x[1], x[2] );
  v = max3( y[0], y[1], y[2] );
  if ( check( u, v ) ) solution( u, v );

  return 0;
}
