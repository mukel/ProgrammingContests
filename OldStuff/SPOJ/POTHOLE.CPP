/*
Alfonso Alfonso Peterssen
4 - 10 - 2007
SPOJ #203 "Potholers"
*/
#include <iostream>
#include <queue>
using namespace std;

const int MAXV = 300;

int T, V, src, snk, flow, i, j, k;
int sz[MAXV];
int ls[MAXV][MAXV];
int cap[MAXV][MAXV];
int prev[MAXV];

  void add( int u, int v, int w ) {
    ls[u][ ++sz[u] ] = v;
    ls[v][ ++sz[v] ] = u;
    cap[u][v] = w;
  }

  bool augment() {
    int i, j, x;
    queue< int > Q;

    Q.push( src );
    memset( prev, 0, sizeof( prev ) );
    prev[src] = -1;

    while ( !Q.empty() && !prev[snk] ) {
      i = Q.front();
      Q.pop();
      for ( j = 1; j <= sz[i]; j++ ) {
        x = ls[i][j];
        if ( !prev[x] && cap[i][x] > 0 ) {
          prev[x] = i;
          if ( x == snk ) break;
          Q.push( x );
        }
      }
    }

    if ( !prev[snk] ) return false;

    for ( ; x != src; x = prev[x] )
      cap[ prev[x] ][x]--, cap[x][ prev[x] ]++;

    return true;
  }

int main() {

  for ( cin >> T; T; T-- ) {

    flow = 0;
    memset( cap, 0, sizeof( cap ) );

    cin >> V;
    for ( i = 1; i < V; i++ ) {
      scanf( "%d", &j );
      for ( ; j; j-- ) {
        scanf( "%d", &k );
        if ( k == V || i == 1 )
             add( i, k, 1 );
        else add( i, k, 1000000000 );
      }
    }

    src = 1;
    snk = V;

    while ( augment() ) flow++;
    cout << flow << endl;
  }

  return 0;
}
