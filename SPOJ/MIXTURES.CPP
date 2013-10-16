/*
Alfonso Alfonso Peterssen
22 - 7 - 2007
SPOJ #345 "Mixtures"
*/
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN 100
#define oo 1000000000
#define label( x, y ) ( ( mix[y] - ( x ? mix[x - 1] : 0 ) ) % 100 )

int N, i, j, k, h, a, b;
int C[MAXN][MAXN];
int mix[MAXN];

int main() {

  while ( cin >> N ) {

    for ( i = 0; i < N; i++ ) {
      cin >> mix[i];
      if ( i ) mix[i] += mix[i - 1];
    }

    for ( h = 1; h < N; h++ )
      for ( i = 0; i < N - h; i++ ) {
        j = i + h;
        C[i][j] = oo;
        for ( k = i; k < j; k++ ) {
          a = label( i, k );
          b = label( k + 1, j );
          C[i][j] <?= C[i][k] + C[k + 1][j] + a * b;
        }
      }

    cout << C[0][N - 1] << endl;
  }

  return 0;
}
