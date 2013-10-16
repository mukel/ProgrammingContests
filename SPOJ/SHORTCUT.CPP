/*
Alfonso Alfonso Peterssen
16 - 11 - 2007
SPOJ #84 "Shortcut"
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 250001;

int T, N, i, j, k, sol, start, end;
int sorted[MAXN];
char st[MAXN];
struct point { int X, Y; } ls[MAXN];

  bool by_X( const int &a, const int &b ) {
    if ( ls[a].X != ls[b].X ) return ls[a].X < ls[b].X;
    return ls[a].Y < ls[b].Y;
  }

  void find_shortcut() {

    sort( sorted, sorted + N, by_X );

    for ( i = 0; i < N - 1; i++ )
      if ( ls[ sorted[i] ].X == ls[ sorted[i + 1] ].X ) {

        int dist = ls[ sorted[i + 1] ].Y - ls[ sorted[i] ].Y;

        int a = sorted[i], b = sorted[i + 1];

        if ( a > b ) swap( a, b );

        /* Is a shortcut? */
        if ( a + 1 == b ) continue;

        if ( dist < sol ||
           ( dist == sol && ( a < start || ( ( a == start ) && ( b > end ) ) ) ) ) {
          start = a;
          end = b;
          sol = dist;
        }

      }
  }

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    scanf( "%d", &N );
    scanf( "%s", &st );

    j = k = 0;
    ls[0] = ( point ) { 0, 0 };
    for ( i = 0; i < N; i++ ) {
      if ( st[i] == 'E' ) j++;
      if ( st[i] == 'W' ) j--;
      if ( st[i] == 'N' ) k++;
      if ( st[i] == 'S' ) k--;
      ls[i + 1] = ( point ) { j, k };
    }

    sol = ++N;
    for ( i = 0; i < N; i++ )
      sorted[i] = i;

    find_shortcut();

    for ( i = 0; i < N; i++ )
      swap( ls[i].X, ls[i].Y );

    find_shortcut();

    char way;
    if ( ls[start].X == ls[end].X )
         way = ( ls[start].Y < ls[end].Y ) ? 'E' : 'W';
    else way = ( ls[start].X < ls[end].X ) ? 'N' : 'S';

    printf( "%d %d %d %c\n", sol, start, end, way );
  }

  return 0;
}
