/*
Alfonso Alfonso Peterssen
17 - 7 - 2007
SPOJ #11 "Factorial"
*/
#include <iostream>
using namespace std;
int T, N, zeros;
int main() {
  for ( cin >> T; T; T-- ) {
    zeros = 0;
    for ( cin >> N; N; zeros += N /= 5 );
    cout << zeros << endl;
  }
  return 0;
}
