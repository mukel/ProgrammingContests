/*
Alfonso Alfonso Peterssen
17 - 7 - 2007
SPOJ #42 "Adding Reversed Numbers"
*/
#include <iostream>
using namespace std;

  int rev( int x ) {
    int r = 0;
    for ( ; x; x /= 10 )
      r = r * 10 + x % 10;
    return r;
  }

int main() {

  int T, A, B;

  for ( cin >> T; T; T-- ) {
    cin >> A >> B;
    cout << rev( rev( A ) + rev( B ) ) << endl;
  }

  return 0;
}
