/*
Alfonso Alfonso Peterssen
24 - 7 - 2007
SPOJ #188 "Rectangles"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 7000

int T, N, i, j, sol;
int P[MAXN];
struct rect {
  int x1, y1, x2, y2;
} ls[MAXN];

  int find( int a ) {
    if ( a != P[a] ) P[a] = find( P[a] );
    return P[a];
  }

  void join( int a, int b ) {
    --sol;
    P[ find( a ) ] = find( b );
  }

  bool intersect( int a, int b ) {
    int dx = min( ls[a].x2, ls[b].x2 ) - max( ls[a].x1, ls[b].x1 );
    int dy = min( ls[a].y2, ls[b].y2 ) - max( ls[a].y1, ls[b].y1 );
    return ( dx >= 0 ) && ( dy >= 0 ) && ( ( dx > 0 ) || ( dy > 0 ) );
  }

int main() {

  for ( scanf( "%d", &T); T; T-- ) {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
      scanf( "%d %d %d %d", &ls[i].x1, &ls[i].y1, &ls[i].x2, &ls[i].y2 );
      P[i] = i;
    }

    sol = N;
    for ( i = 0; i < N; i++ )
      for ( j = i + 1; j < N; j++ )
        if ( find( i ) != find( j ) )
          if ( intersect( i, j ) ) join( i, j );

    printf( "%d\n", sol );
  }

  return 0;
}
