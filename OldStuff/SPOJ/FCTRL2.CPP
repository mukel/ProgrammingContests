/*
Alfonso Alfonso Peterssen
17 - 7 - 2007
SPOJ #24 "Small factorials"
*/
#include <iostream>
using namespace std;

#define MAXN 101
#define MAXLEN 158

int T, N, i, j, r, t;
int sz[MAXN];
int fact[MAXN][MAXLEN];

int main() {

  fact[0][ ++sz[0] ] = 1;
  for ( i = 1; i < MAXN; i++ ) {

    sz[i] = sz[i - 1];
    for ( j = 1; j <= sz[i]; j++ ) {
      t = fact[i - 1][j] * i + r;
      fact[i][j] = t % 10;
      r = t / 10;
    }

    for ( ; r; r /= 10 )
      fact[i][ ++sz[i] ] = r % 10;
  }

  for ( cin >> T; T; T-- ) {
    cin >> N;
    for ( i = sz[N]; i; i-- ) cout << fact[N][i];
    cout << endl;
  }

  return 0;
}
