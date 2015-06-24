/*
Alfonso Alfonso Peterssen
9 - 9 - 2007
SPOJ #1435 "Vertex Cover"
Hoy es el cumpleaños de Abel -> mi amigo...
O( V lg V ) -> podria ser O( E ) con una lista
*/
#include <cstdio>
#include <set>
using namespace std;

#define MAXV 100000

int V, i, j, k, sol;
int degree[MAXV];
int P[MAXV];
struct node { int B, next; } ls[ 2 * MAXV ];

set< int > S;
set< int >::iterator it[MAXV];

int main() {

  scanf( "%d", &V );
  for ( i = 1; i < V; i++ ) {

    scanf( "%d %d", &j, &k );

    degree[--j]++, degree[--k]++;

    ls[i] = ( node ) { k, P[j] };
    P[j] = i;

    ls[V + i - 1] = ( node ) { j, P[k] };
    P[k] = V + i - 1;
  }

  for ( i = V - 1; i >= 0; i-- )
    if ( degree[i] == 1 ) {
      S.insert( i );
      it[i] = S.begin();
    }

  while ( S.size() > 0 ) {

    i = *( S.begin() );

    for ( j = P[i]; j; j = ls[j].next )
      if ( degree[ ls[j].B ] > 0 ) break;

    i = ls[j].B;

    sol++;

    if ( degree[i] == 1 )
      S.erase( it[i] );

    degree[i] = -1;

    for ( j = P[i]; j; j = ls[j].next ) {

      k = ls[j].B;
      degree[k]--;

      if ( degree[k] == 0 )
      S.erase( it[k] );

      if ( degree[k] == 1 ) {
        S.insert( k );
        it[k] = S.find( k );
      }

    }
  }

  printf( "%d\n", sol );

  return 0;
}
