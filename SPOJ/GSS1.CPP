/*
Alfonso Alfonso Peterssen
23 - 8 - 2007
SPOJ #1043 "Can you answer these queries"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 50001
#define MAXLOG 16

#define sum( i, j ) ( sum[j] - sum[(i) - 1] )

int N, Q, i, j, k;
int sum[MAXN];
struct node {
  int right, value, left;
} T[MAXLOG][MAXN];

  int log2( int x ) {
    int lg = 1;
    while ( 1 << lg < x ) lg++;
    return lg - 1;
  }

  int query_right( int a, int b ) {

    int start = a, end = b,
        sol = sum( a, b );

    do {

      int lg = log2( end - start + 1 );
      sol >?= T[lg][start].right + sum( a, start - 1 );
      start += 1 << lg;

    } while ( start < end );

    return sol;
  }

  int query_left( int a, int b ) {

    int start = a, end = b,
        sol = sum( a, b );

    do {

      int lg = log2( end - start + 1 );
      sol >?= T[lg][end].left + sum( end + 1, b );
      end -= 1 << lg;

    } while ( start < end );

    return sol;
  }

  int query_value( int a, int b ) {

    if ( a == b )
      return T[0][a].value;

    int lg = log2( b - a + 1 ),
        mid = ( a + b ) / 2;

    return max( max( T[lg][a].value,
                     T[lg][ b - ( 1 << lg ) + 1 ].value ),
                query_left( a, mid ) + query_right( mid + 1, b ) );
  }

int main() {

  scanf( "%d", &N );
  for ( i = 1; i <= N; i++ ) {
    scanf( "%d", &j );
    sum[i] = sum[i - 1] + j;
    T[0][i] = ( node ) { j, j, j };
  }

  int lg = log2( N );
  for ( i = 1; i <= lg; i++ )
    for ( j = 1; j + ( 1 << i ) - 1 <= N ; j++ ) {

      k = j + ( 1 << i ) - 1;
      int mid = ( j + k ) / 2;

      T[i][j].right = max( T[i - 1][j].right,
                           T[i - 1][mid + 1].right + sum( j, mid ) );

      T[i][k].left =  max( T[i - 1][k].left,
                           T[i - 1][mid].left + sum( mid + 1, k ) );

      T[i][j].value = max( max( T[i - 1][j].value,
                                T[i - 1][mid + 1].value ),
                           T[i - 1][mid].left + T[i - 1][mid + 1].right );
  }

  scanf( "%d", &Q );
  for ( ; Q; Q-- ) {
    scanf( "%d %d", &j, &k );
    printf( "%d\n", query_value( j, k ) );
  }

  return 0;
}
