/*
Alfonso Alfonso Peterssen
1 - 9 - 2007
SPOJ #688 "Toy Cars"
*/
#include <cstdio>
#include <set>
using namespace std;

#define MAXQ 500001
#define MAXC 500001
#define oo 1000000000

typedef pair< int, int > pii;

int T, C, F, Q, i, cant, sol;
bool mark[MAXC];
int car[MAXQ];
int pos[MAXC], next[MAXC];

int main() {

  for ( scanf( "%d", &T ); T; T-- ) {

    multiset< pii, greater< pii > > heap;

    sol = cant = 0;
    memset( pos, 0, sizeof( pos ) );
    memset( mark, false, sizeof( mark ) );

    scanf( "%d %d %d", &C, &F, &Q );
    for ( i = 0; i < Q; i++ )
      scanf( "%d", &car[i] );

    for ( i = Q - 1; i >= 0; i-- ) {

      if ( pos[ car[i] ] )
           next[i] = pos[ car[i] ];
      else next[i] = oo;

      pos[ car[i] ] = i;
    }

    for ( i = 0; i < Q; i++ )
      if ( !mark[ car[i] ] ) {

        sol++;
        mark[ car[i] ] = true;

        pos[ car[i] ] = next[i];
        heap.insert( make_pair( next[i], car[i] ) );

        if ( heap.size() > F ) {

          typeof( heap.begin() ) it = heap.begin();

          if ( it->first == next[i] ) it++;

          if ( it != heap.end() ) {
            mark[ it->second ] = false;
            heap.erase( it );
          }
        }

      } else {
        heap.erase( heap.find( make_pair( pos[ car[i] ], car[i] ) ) );
        heap.insert( make_pair( next[i], car[i] ) );
        pos[ car[i] ] = next[i];
      }

    printf( "%d\n", sol );

  }

  return 0;
}
