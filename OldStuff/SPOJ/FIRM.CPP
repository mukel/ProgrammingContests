/*
Alfonso Alfonso Peterssen
26 - 10 - 2007
SPOJ #1421 "Goods"
*/
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int MAXN = 5000;

int N, i, j, k, days;
int next[MAXN];
int cycle[MAXN], pos[MAXN];
bool mark[MAXN];

struct OP { int A, B; };
queue< OP > Q;

  void print_swaps( queue< OP > &Q ) {
    printf( "%d", Q.size() );
    while ( !Q.empty() ) {
      OP x = Q.front();
      printf( " %d-%d", x.A + 1, x.B + 1 );
      Q.pop();
    }
    printf( "\n" );
  }

int main() {

  scanf( "%d", &N );
  for ( i = 0; i < N; i++ ) {
    scanf( "%d", &j ); j--;
    next[i] = j;
    pos[j] = i;
  }

  /* Count days */
  for ( i = 0; i < N; i++ )
    if ( !mark[i] ) {

      k = 0;
      for ( j = i; !mark[j]; j = next[j], k++ )
        mark[j] = true;

      if ( k == 2 ) days >?= 1;
      if ( k > 2 )  days >?= 2;
    }

  printf( "%d\n", days );

  /* Bump cycles, solve 2-cycles */
  for ( int d = 0; d < days; d++ ) {

    memset( mark, 0, sizeof( mark ) );

    for ( i = 0; i < N; i++ )
      if ( !mark[i] && i != next[i] ) {

        k = 0;
        for ( j = i; !mark[j]; j = next[j], k++ ) {
          cycle[k] = j;
          mark[j] = true;
        }

        for ( j = 0; j < k / 2; j++ ) {

          int a = cycle[j],
              b = cycle[k - j - 1];

          Q.push( ( OP ) { a, b } );

          next[ pos[a] ] = b;
          next[ pos[b] ] = a;

          swap( pos[a], pos[b] );
        }

      }
      
    print_swaps( Q );    
  }

  return 0;
}
