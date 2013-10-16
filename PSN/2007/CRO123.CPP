/*
Alfonso Alfonso Peterssen
8 - 7 - 2007
PSN 2007 #123 "Prince and Princess"
Hay un error en los JD,
la longitud de las secuencias son P y Q,
no P + 1 y Q + 1 como dice en el texto.
*/
#include <cstdio>
#include <cstring> // memset()

#define problem "d"

#define MAXN 62501

int T, N, P, Q, S, len, i, j;
int id[MAXN], seq[MAXN], lis[MAXN];

int main() {
  freopen( problem ".in", "r", stdin );
  freopen( problem ".out", "w", stdout );

  scanf( "%d\n", &T );
  for ( ; T; T-- ) {

    memset( id, 0, sizeof( id ) );
    
    scanf( "%d %d %d\n", &N, &P, &Q );
    
    for ( i = 0; i < P; i++ )
      scanf( "%d", &j ), id[j] = i + 1;
      
    len = 0;
    for ( i = 0; i < Q; i++ ) {
      scanf( "%d", &seq[i] );
      if ( id[j] ) seq[ len++ ] = id[j];
    }

    /* LIS */
    S = 0;
    for ( i = 0; i < k; i++ ) {
      int d = 0, h = S + 1, mid;
      
      /* BS */
      do {
        mid = ( d + h ) / 2;
        if ( seq[i] >= lis[mid] ) d = mid + 1;
        else h = mid;
      } while ( d < h );
      
      lis[h] = seq[i];
      if ( h == S + 1 ) S++;
      
    }
    
    printf( "%d\n", S );
  }
  
  return 0;
}

/*

123þ Prince and Princess.                                 Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

In an n x n chessboard, Prince and Princess plays a game. The  squares
in the chessboard are numbered 1, 2, 3 ... n*n, as shown below:

Prince stands in square 1, make p jumps and finally reach square  n*n.
He enters a square at  most once. So if we  use xp to denote the  p-th
square he enters, then x1, x2,  ... xp+1 are all different. Note  that
x1 = 1  and xp+1 =  n*n. Princess does  the similar thing  - stands in
square 1, make q jumps and finally  reach square n*n. We use y1, y2  ,
... yq+1 to denote the sequence, and all q+1 numbers are different.

Figure 2 belows show a 3x3  square, a possible route for Prince  and a
different route for Princess.

The Prince moves along the sequence: 1 --> 7 --> 5 --> 4 --> 8 -->  3
--> 9 (Black arrows), while the Princess moves along this sequence:  1
--> 4 --> 3 --> 5  --> 6 --> 2 --> 8  --> 9 (White arrow). The King  -
- their father, has just  come. "Why move separately? You  are brother
and sister!"  said the  King, "Ignore  some jumps  and make  sure that
you're always together."

For  example, if  the Prince  ignores his  2nd, 3rd,  6th jump,  he'll
follow the route:  1 --> 4  --> 8 -->  9. If the  Princess ignores her
3rd, 4th, 5th, 6th jump, she'll follow the same route: 1 --> 4 -->  8
--> 9,  (The common  route is  shown in  figure 3)  thus satisfies the
King, shown above. The King wants  to know the longest route they  can
move together, could you tell him?

Input

The first line of the input contains a single integer t(1 <= t <= 10),
the  number of  test cases  followed. For  each case,  the first  line
contains three integers n, p, q(2 <= n  <= 250, 1 <= p, q < n*n).  The
second line contains p+1 different integers in the range [1..n*n], the
sequence of the Prince. The third line contains q+1 different integers
in the range [1..n*n], the sequence of the Princess.

Output

For each test case,  print the case number  and the length of  longest
route. Look at the output for sample input for details.

Sample Input                           Output for Sample Input
1
3 6 7
1 7 5 4 8 3 9
1 4 3 5 6 2 8 9

Specifications
Problem Name:       prince
Input File Name:     prince.in
Output File Name:  prince.out
Time Limit:             0.35 s
*/
