/*
Alfonso Alfonso Peterssen
24 - 6 - 2007
PSN 2007 #38 "Balanced Lineup"
*/
#include <cstdio>
using namespace std;

#define problem "d"

#define MAXN 50000
#define MAXLOG 16

int N, Q, i, j;
int t_min[MAXLOG][MAXN],
    t_max[MAXLOG][MAXN];

  inline int lg( int x ) {
    int res = 1;
    while ( 1 << res < x ) res++;
    return res - 1;
  }

  int min_query( int a, int b ) {
    int l = lg( b - a + 1 );
    return min( t_min[l][a], t_min[l][ b - ( 1 << l ) + 1 ] );
  }

  int max_query( int a, int b ) {
    int l = lg( b - a + 1 );
    return max( t_max[l][a], t_max[l][ b - ( 1 << l ) + 1 ] );
  }

int main() {
  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d %d\n", &N, &Q );
  for ( i = 0; i < N; i++ ) {
    scanf( "%d\n", &j );
    t_max[0][i] = t_min[0][i] = j;
  }

  /* Preprocess */
  int l = lg( N );
  for ( i = 1; i <= l; i++ )
    for ( j = 0; j + ( 1 << i ) <= N; j++ ) {
      int p = ( 1 << ( i - 1 ) );
      t_min[i][j] = min( t_min[i - 1][j], t_min[i - 1][j + p] );
      t_max[i][j] = max( t_max[i - 1][j], t_max[i - 1][j + p] );
    }

  for ( ; Q; Q-- ) {
    scanf( "%d %d\n", &i, &j );
    i--, j--;
    printf( "%d\n", max_query( i, j ) - min_query( i, j ) );
  }

  return 0;
}

/*
38þ Balanced Lineup.                                      Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

For the daily milking, Farmer John's N cows (1 <= N <= 50,000)
always line up in the same order. One day Farmer John decides to
organize a game of Ultimate Frisbee with some of the cows. To keep
things simple, he will take a contiguous range of cows from the
milking lineup to play the game. However, for all the cows to have
fun they should not differ too much in height.

Farmer John has made a list of Q (1 <= Q <= 200,000) potential
groups of cows and their heights (1 <= height <= 1,000,000). For
each group, he wants your help to determine the difference in height
between the shortest and the tallest cow in the group.

PROBLEM NAME: lineup

INPUT FORMAT:

- Line 1: Two space-separated integers, N and Q.

- Lines 2..N+1: Line i+1 contains a single integer that is the height
        of cow i

- Lines N+2..N+Q+1: Two integers A and B (1 <= A <= B <= N),
        representing the range of cows from A to B inclusive.

SAMPLE INPUT (file lineup.in):

6 3
1
7
3
4
2
5
1 5
4 6
2 2


OUTPUT FORMAT:

- Lines 1..Q: Each line contains a single integer that is a response
        to a reply and indicates the difference in height between the
        tallest and shortest cow in the range.

SAMPLE OUTPUT (file lineup.out):

6
3
0
*/
