/*
Alfonso Alfonso Peterssen
21 - 10 - 2007
SPOJ #1709 "Swamp Things"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 1000;

int T, N, i, j, k, sol;
int X[MAXN], Y[MAXN];
int ls[MAXN];

  int cross( int o, int c, int m ) {
    return ( X[c] - X[o] ) * ( Y[m] - Y[o] ) -
           ( X[m] - X[o] ) * ( Y[c] - Y[o] );
  }

  bool cmp( const int &i, const int &j ) {
    return cross( ls[0], i, j ) < 0;
  }

int main() {

  while ( ++T ) {

    scanf( "%d", &N );
    if ( !N ) break;

    for ( i = 0; i < N; i++ )
      scanf( "%d %d", &X[i], &Y[i] );

    for ( i = 0; i < N; i++ ) {
      ls[i] = i;
      if ( Y[i] < Y[j] || ( Y[i] == Y[j] && X[i] < X[j] ) )
        j = i;
    }

    swap( X[0], X[j] );
    swap( Y[0], Y[j] );

    sol = 0;
    for ( i = 0; i < N; i++ ) {

      swap( ls[0], ls[i] );
      sort( ls + 1, ls + N, cmp );

      for ( k = 1; k < N; k = j + 1 ) {

        for ( j = k; j < N - 1; j++ )
          if ( cross( ls[0], ls[j], ls[j + 1] ) != 0 )
            break;

        sol >?= j - k + 2;
      }
    }

    if ( sol < 4 ) sol = 0;
    printf( "Photo %d: %d points eliminated\n", T, sol );
  }

  return 0;
}
