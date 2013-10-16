/*
Alfonso Alfonso Peterssen
17 - 7 - 2007
SPOJ #302 "Count on Cantor"
*/
#include <iostream>
#include <cmath>
using namespace std;

int T, N, sq, t;

int main() {

  for ( cin >> T ; T; T-- ) {

    cin >> N;

    sq = trunc( sqrt( 8 * N ) - 1 ) / 2;
    t = N - sq * ( sq + 1 ) / 2;

    cout << "TERM " << N << " IS ";
    if ( sq & 1 )
         cout << t << "/" << sq - t + 2 << endl;
    else cout << sq - t + 2 << "/" << t << endl;
  }

  return 0;
}
