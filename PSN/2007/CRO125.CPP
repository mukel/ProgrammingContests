/*
Alfonso Alfonso Peterssen
9 - 7 - 2007
PSN 2007 #125 "Very Easy Problem" ( Domino IV )
He aqui la recurrencia original:
  dp[i] = dp[i - 1] + dp[i - 2] + 2 * S[i - 2] + A[i - 2];
  S[i] = S[i - 1] + dp[i];
  A[i] = A[i - 2] + dp[i];
El enredo de abajo es solo para ahorrar memoria.
*/
#include <iostream>
using namespace std;

#define MODULO 1234567

int N, i, j, j1;
int dp[2], S[2], A[2];

int main() {

  cin >> N;

  /* Efficient Memory Usage */
  dp[0] = S[0] = A[0] = 1;
  for ( i = 1; i <= N; i++ ) {
    j = i & 1;
    j1 = ( i - 1 ) & 1;
    dp[j] = ( dp[j] + dp[j1] + 2 * S[j] + A[j] ) % MODULO;
    S[j] = ( S[j1] + dp[j] ) % MODULO;
    A[j] = ( A[j] + dp[j] ) % MODULO;
  }

  cout << dp[j] << endl;

  return 0;
}

/*
125þ Very Easy Problem.                                   Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Given  a  board of  size  4xN, we  wish  to arrange  inside  of it  2N
dominoes. Write a program that given an integer N writes all different
ways this can be done.

Input description:
A single line with an integer N (0 <= N <= 10 000 000).

Output description:
One single line with the number described above modulo 1234567.

Sample Input (standard input):
2

Sample Output (standard output):
5

Output explanation:
For a 2xN board there are 5 different configurations, as shown in the figure.
*/
