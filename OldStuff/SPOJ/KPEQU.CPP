/*
Alfonso Alfonso Peterssen
3 - 11 - 2007
SPOJ #1434 "Equation"
*/
#include <iostream>
using namespace std;

const int
  MAXN = 10001,
  MAXLEN = 50000;

typedef unsigned long long int64;

int N, P, i, j, e;
bool mark[MAXN];
int prime[MAXN];

struct big_int /* buggy */ {

  int size;
  unsigned char dig[MAXLEN];

  big_int& operator = ( int x ) {
    size = 0;
    if ( x == 0 ) { size = 1; dig[0] = 0; }
    else for ( ; x; x /= 10 )
      dig[size++] = x % 10;
  }

  big_int& operator *= ( const int x ) {

    int64 t, r = 0;
    for ( int i = 0; i < size; i++ ) {
      t = dig[i] * x + r;
      dig[i] = t % 10;
      r = t / 10;
    }
    for ( ; r; r /= 10 )
      dig[size++] = r % 10;
  }

} sol;

  ostream& operator << ( ostream &out, const big_int &x ) {
    for ( int i = x.size - 1; i >= 0; i-- )
      out << ( char ) ( x.dig[i] + '0' );
    return out;
  }

int main() {

  /* Prime Sieve */
  for ( i = 2; i * i < MAXN; i++ )
    if ( !mark[i] )
      for ( j = i * i; j < MAXN; j += i )
        mark[j] = true;

  for ( i = 2; i < MAXN; i++ )
    if ( !mark[i] )
      prime[P++] = i;

  for (;;) {

    cin >> N;
    if ( !N ) break;

    sol = 1;
    for ( i = 0; i < P && prime[i] <= N; i++ ) {

      e = 0;
      for ( int64 x = prime[i]; x <= N; x *= prime[i] )
        e += N / x;

      sol *= ( 2 * e + 1 );
    }

    cout << sol << endl;
  }

  return 0;
}
