/*
Alfonso Alfonso Peterssen
19 - 7 - 2007
SPOJ #1021 "Aibohphobia"
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 6100

int T, N, i, j, k;
short C[MAXN][MAXN];
string st;

int main() {

  for ( cin >> T; T; T-- ) {

    cin >> st;

    N = st.size();
    for ( k = 1; k < N; k++ )
      for ( i = 0; i < N - k; i++ ) {
        j = i + k;
        if ( st[i] == st[j] )
             C[i][j] = C[i + 1][j - 1];
        else C[i][j] = min( C[i + 1][j], C[i][j - 1] ) + 1;
      }

    cout << C[0][N - 1] << endl;
  }

  return 0;
}
