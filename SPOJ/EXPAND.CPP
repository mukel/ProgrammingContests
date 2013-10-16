/*
Alfonso Alfonso Peterssen
1 - 9 - 2007
SPOJ #702 "Barn Expansion"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define problem "d"
#define MAXN 25000

int T, N, P, i;
bool crap[MAXN], mark[MAXN];

struct point {

  int X, Y, id;

  bool operator < ( const point &p ) const {
    return X < p.X || ( X == p.X && Y < p.Y );
  }

} ls[ 4 * MAXN ];

  void sweep_line() {

    sort( ls, ls + P );

    int i, j = 1;
    mark[ ls[0].id ] = true;

    for ( i = 1; i < P; i++ ) {
      int a = ls[i].id,
          b = ls[i - 1].id;

      if ( a != b &&
         ( ls[i].X == ls[i - 1].X && ls[i].Y == ls[i - 1].Y ) ) {
        crap[a] = true;
        crap[b] = true;
      }

      if ( mark[a] ^= true ) j++;
      else if ( --j || a != b ) crap[a] = true;
    }
  }

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    P = 0;
    memset( crap, false, sizeof( crap ) );
    memset( mark, false, sizeof( mark ) );

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
      int x1, x2, y1, y2;
      scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
      ls[P++] = ( point ) { x1, y1, i };
      ls[P++] = ( point ) { x1, y2, i };
      ls[P++] = ( point ) { x2, y1, i };
      ls[P++] = ( point ) { x2, y2, i };
    }

    sweep_line();

    for ( i = 0; i < P; i++ )
      swap( ls[i].X, ls[i].Y );

    sweep_line();

    printf( "%d\n", count( crap, crap + N, false ) );

  }

  return 0;
}
