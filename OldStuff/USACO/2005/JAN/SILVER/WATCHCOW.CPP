/*
Alfonso Alfonso Peterssen
29 - 8 - 2007
USACO 2005 JAN Silver "Watchcow"
*/
#include <cstdio>

#define problem "d"
#define MAXV 10001
#define MAXE 50001

int V, E, i, j, k;
int P[MAXV];
bool mark[ 2 * MAXE ];
struct node { int B, next; } ls[ 2 * MAXE ];

  void eulerize( int x ) {

    for ( int i = P[x]; i; i = ls[i].next )
      if ( !mark[i] ) {
        mark[i] = true;
        eulerize( ls[i].B );
      }

    printf( "%d\n", x );

  }

int main() {

  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d", &V, &E );
  for ( i = 1; i <= E; i++ ) {

    scanf( "%d %d", &j, &k );

    ls[i] = ( node ) { k, P[j] };
    P[j] = i;

    ls[E + i] = ( node ) { j, P[k] };
    P[k] = E + i;
  }

  eulerize( 1 );

  return 0;
}

/*
Problem 7: Watchcow [Coaches, 2004]

Bessie's been appointed the new watch-cow for the farm. Every night,
it's her job to walk across the farm and make sure that no evildoers
are doing any evil. She begins at the barn, makes her patrol, and
then returns to the barn when she's done.

If she were a more observant cow, she might be able to just walk
each of M (1 <= M <= 50,000) bidirectional trails numbered 1..M
between N (2 <= N <= 10,000) fields numbered 1..N on the farm once
and be confident that she's seen everything she needs to see.  But
since she isn't, she wants to make sure she walks down each trail
exactly twice.  It's also important that her two trips along each
trail be in opposite directions, so that she doesn't miss the same
thing twice.

A pair of fields might be connected by more than one trail.  Find
a path that Bessie can follow which will meet her requirements.
Such a path is guaranteed to exist.

PROBLEM NAME: watchcow

INPUT FORMAT:

* Line 1: Two integers, N and M.

* Lines 2..M+1: Two integers denoting a pair of fields connected by a
        path.

SAMPLE INPUT (file watchcow.in):

4 5
1 2
1 4
2 3
2 4
3 4

OUTPUT FORMAT:

* Lines 1..2M+1: A list of fields she passes through, one per line,
        beginning and ending with the barn at field 1. If more than
        one solution is possible, output any solution.

SAMPLE OUTPUT (file watchcow.out):

1
2
3
4
2
1
4
3
2
4
1

OUTPUT DETAILS:

Bessie starts at 1 (barn), goes to 2, then 3, etc...
*/
