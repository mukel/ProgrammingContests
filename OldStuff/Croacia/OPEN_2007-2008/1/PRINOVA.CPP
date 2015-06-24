/*
Alfonso Alfonso Peterssen
4 - 11 - 2007
COCI 2007 Contest 1 "PRINOVA"
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int
  MAXN = 100,
  oo = 1000000001;

int N, A, B, i, dist, pos, sol;
int ls[MAXN];

  void check( int pos ) {
    if ( pos < A || pos > B )
      return;

    int d = oo;
    for ( int i = 0; i < N; i++ )
      d <?= abs( pos - ls[i] );

    if ( d > dist ) {
      dist = d;
      sol = pos;
    }
  }

int main() {

  cin >> N;
  for ( i = 0; i < N; i++ )
    cin >> ls[i];

  cin >> A >> B;

  sort( ls, ls + N );

  dist = -oo;
  for ( i = 0; i < N - 1; i++ ) {
    pos = ( ls[i] + ls[i + 1] ) / 2;
    if ( pos & 1 ) check( pos );
    else {
      check( pos + 1 );
      check( pos - 1 );
    }
  }

  check( A + !( A & 1 ) );
  check( B - !( B & 1 ) );

  cout << sol << endl;

  return 0;
}
