/*
Alfonso Alfonso Peterssen
19 - 7 - 2007
SPOJ #1031 "Up Subsequence"
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 100

int T, N, LIS, i, j;
int C[MAXN];
char lis[MAXN + 1];
string st;

  void dfs( int x ) {
    lis[ LIS - C[x] ] = st[x];
    if ( C[x] == 0 ) {
      cout << lis << endl;
      return;
    }
    for ( int i = N; --i > x; )
      if ( st[i] >= st[x] )
        if ( C[i] == C[x] - 1 ) dfs( i );
  }

int main() {

  for ( cin >> T; T; T-- ) {

    cin >> st;

    LIS = 0;
    N = st.size();
    for ( i = N; --i >= 0; ) {
      C[i] = 0;
      for ( j = i + 1; j < N; j++ )
        if ( st[j] >= st[i] ) C[i] >?= C[j] + 1;
      LIS >?= C[i];
    }

    lis[ LIS + 1 ] = '\0';
    for ( i = N; --i >= 0; )
      if ( C[i] == LIS ) dfs( i );
  }

  return 0;
}
