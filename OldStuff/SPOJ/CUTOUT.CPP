/*
Alfonso Alfonso Peterssen
19 - 10 - 2007
SPOJ #67 "Cutting out"
*/
#include <cstdio>
#include <list>

using namespace std;

int T, N, C, i, j, sol;
int x1, y1, x2, y2;
int a, b, c, d;

struct rect {
  int x1, y1, x2, y2;
  int area() { return ( x2 - x1 ) * ( y2 - y1 ); }
};

list< rect > ls;
list< rect >::iterator it, tmp;

int main() {

  for ( scanf( "%d", &T ); T ; T-- ) {

    scanf( "%d %d", &C, &N );

    /* Init */
    sol = 0;
    ls.clear();
    ls.push_back( ( rect ) { 0, 0, C, C } );

    for ( i = 0; i < N; i++ ) {

      scanf( "%d %d %d %d", &a, &c, &b, &d );

      it = ls.begin();
      for ( j = ls.size(); j; j-- ) {
        x1 = (*it).x1; x2 = (*it).x2;
        y1 = (*it).y1; y2 = (*it).y2;
        tmp = it++;
        if ( a < x2 && c > x1 && b < y2 && d > y1 ) {
          ls.erase( tmp );
          if ( a > x1 ) ls.push_back( ( rect ) { x1, y1, a, y2 } );
          if ( c < x2 ) ls.push_back( ( rect ) { c, y1, x2, y2 } );
          if ( b > y1 ) ls.push_back( ( rect ) { x1, y1, x2, b } );
          if ( d < y2 ) ls.push_back( ( rect ) { x1, d, x2, y2 } );
        }
      }
    }

    for ( it = ls.begin(); it != ls.end(); it++ )
        sol >?= (*it).area();

    printf( "%d\n", sol );
  }

  return 0;
}
