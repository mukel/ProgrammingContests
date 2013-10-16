/*
Alfonso Alfonso Peterssen
9 - 7 - 2007
PSN 2007 #130 "Divisor Summation"
*/
#include <cstdio>
#define MAXV 500001
int T, i, j;
int sum[MAXV];
int main() {
  for ( i = 1; i < MAXV; i++ )
    for ( j = 2 * i; j < MAXV; j += i ) sum[j] += i;
  for ( scanf( "%d\n", &T ); T; T-- ) {
    scanf( "%d\n", &j );
    printf( "%d\n", sum[j] );
  }
  return 0;
}

/*

130þ Divisor Summation.                                   Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Given  a  natural number  n  (1 <=  n  <= 500000),  please  output the
summation of all its proper divisors.

Definition: A proper divisor of  a natural number is the  divisor that
is  strictly  less  than  the number.  e.g.  number  20  has 5  proper
divisors: 1, 2, 4, 5, 10, and the divisor summation is: 1 + 2 + 4 +  5
+ 10 = 22.

Input description: An integer stating the number of test cases  (equal
to about  200000), and  that many  lines follow,  each containing  one
integer between 1 and 500000 inclusive.

Output description: One  integer each line:  the divisor summation  of
the integer given respectively.

Sample input:
3
2
10
20

Sample output:
1
8
22
*/
