/*
Alfonso Alfonso Peterssen
31 - 8 - 2007
SPOJ #1716 "Can you answer these queries III"

Preprocessing: O( n )
Update: O( lg n )
Query: O( lg^2 n )

Para la suma hace falta el ABI,
no se puede hacer utilizando el mismo arbol porque
aunque la complejidad es la misma, se va por tiempo.
*/
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 70001
#define oo 1000000000

int N, Q, BASE, i, j, k;
int op, sum, sol, left, right;

struct node {

  int start, end,
      sum,
      right, value, left;

} tree[ 3 * MAXN ];

struct {

  int T[MAXN];

  //inline int lobit( int x ) { return x & -x; }
  #define lobit( x ) ( x & -x )

  void update( int x, int amount ) {
    for ( ; x <= N; x += lobit( x ) )
      T[x] += amount;
  }

  int sum( int x ) {
    int res = 0;
    for ( ; x; x -= lobit( x ) )
      res += T[x];
    return res;
  }

} ABI;

  int log2( int x ) {
    int lg = 1;
    while ( 1 << lg < x ) lg++;
    return lg - 1;
  }

  int query_sum( int lo, int hi ) {
    return ABI.sum( hi ) - ABI.sum( lo - 1 );
  }

  void find_value( int x, int lo, int hi ) {

    if ( tree[x].start == lo && tree[x].end == hi ) {
      left = tree[x].right;
      right = tree[x].left;
      sol = tree[x].value;
      return ;
    }

    int y = ( x << 1 );
    int z = y | 1;

    int lleft = 0, lright = 0, lvalue = 0,
        rleft = 0, rright = 0, rvalue = 0,
        lstart = 0, lend = 0,
        rstart = 0, rend = 0;

    if ( tree[ y ].end >= lo ) {

      lstart = lo;
      lend = min( hi, tree[ y ].end );
      find_value( y, lstart, lend );

      lleft = left;
      lright = right;
      lvalue = sol;
    }

    if ( tree[ z ].start <= hi ) {

      rstart = max( lo, tree[ z ].start );
      rend = hi;
      find_value( z, rstart, rend );

      rleft = left;
      rright = right;
      rvalue = sol;
    }

    if ( lstart )
         left = max( lleft, query_sum( lstart, lend ) + rleft );
    else left = rleft;

    if ( rstart )
         right = max( rright, query_sum( rstart, rend ) + lright );
    else right = lright;

    if ( lstart ) {
      if ( rstart )
        sol = max( max( lvalue, rvalue ) , lright + rleft );
      else sol = lvalue;
    } else sol = rvalue;

  }

  int query_value( int lo, int hi ) {
    find_value( 1, lo, hi );
    return sol;
  }

  void setup( int x ) {

    int y = ( x << 1 );
    int z = y | 1;

    tree[x].start = tree[ y ].start;
    tree[x].end = tree[ z ].end;

    tree[x].sum = tree[y].sum + tree[z].sum;

    tree[x].left = max( tree[ z ].left,
                        tree[ z ].sum + tree[ y ].left );

    tree[x].right = max( tree[ y ].right,
                         tree[ y ].sum + tree[ z ].right );

    tree[x].value = max( max( tree[ y ].value,
                              tree[ z ].value ),
                         tree[ y ].left + tree[ z ].right );
  }

  void update( int x, int val ) {

    /* ABI Stuff */
    int v = ABI.sum( x ) - ABI.sum( x - 1 );
    ABI.update( x, val - v );

    tree[BASE + x] = ( node ) { x, x, val, val, val, val };

    x += BASE;
    while ( x >>= 1 )
      setup( x );
  }

int main() {

  scanf( "%d", &N );

  int lg = log2( N ) + 1;
  BASE = ( 1 << lg ) -  1;

  for ( i = 1; i <= N; i++ ) {
    scanf( "%d", &j );
    ABI.update( i, j );
    tree[BASE + i] = ( node ) { i, i, j, j, j, j };
  }

  for ( i = BASE + N + 1; i <= BASE * 2 + 1; i++ )
    tree[i] = ( node ) { i, i, -oo, -oo, -oo, -oo };

  for ( i = BASE; i; i-- )
    setup( i );

  /* ... */
  for ( scanf( "%d", &Q ); Q; Q-- ) {

    scanf( "%d %d %d", &op, &j, &k );

    if ( op )
         printf( "%d\n", query_value( j, k ) );
    else
      if ( k != tree[BASE + j].value )
        update( j, k );
  }

  return 0;
}
