/*
Alfonso Alfonso Peterssen
4 - 11 - 2007
COCI 2007 Contest 1 "CETVRTA"
*/
#include <cstdlib>
#include <iostream>
using namespace std;

int i, j, k, l;
int x[3], y[3];

int main() {

  for ( i = 0; i < 3; i++ )
    cin >> x[i] >> y[i];

  for ( i = 1; i < 3; i++ )
    for ( j = 0; j < i; j++ )
      if ( x[i] == x[j] )
        for ( k = 1; k < 3; k++ )
          for ( l = 0; l < k; l++ )
            if ( y[k] == y[l] ) {
              cout << x[3 - i - j] << " " << y[3 - k - l] << endl;
              /* Suicide */
              return 0;
            }
}
