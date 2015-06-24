/*
Alfonso Alfonso Peterssen
13 - 7 - 2007
PSN 2007 #128 "Marbles"
Simple -> Comb( N - 1, K - 1 )
*/
#include <iostream>
using namespace std;

/* Remembering the old Pascal */
typedef long long int64;

int T, N, i;
int64 sol, den, gcd;

  int64 GCD( int64 a, int64 b ) {
    while ( a && b ) if ( a %= b ) b %= a;
    return a + b;
  }

int main() {

  for ( cin >> T; T; T-- ) {
    cin >> N >> i;

    sol = den = 1;
    for( i >?= N - i + 1; i < N; i++ ) {

      sol *= i / ( gcd = GCD( i, N ) );
      den *= ( N - i ) / gcd;

      sol /= ( gcd = GCD( sol, den ) );
      den /= gcd;
    }

    cout << sol << endl;
  }

  return 0;
}

/*
128þ Marbles.                                             Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Dovier dreams he is in a  shop with an infinite amount of  marbles. He
is  allowed to  select n  marbles. There  are marbles  of k  different
colors. From each color there are also infinitely many marbles. Dovier
wants to have at least one marble of each color, but still there are a
lot  of possibilities  for his  selection. In  his effort  to make  a
decision he wakes up.  Now he asks you  how many possibilites for  his
selection he would have had. Assume that marbles of equal color  can't
be distinguished, and the order of the marbles is irrelevant.

Input description:

The first line of input contains a number T <= 100 that indicates  the
number of test cases  to follow. Each test  case consists of one  line
containing n and k,  where n is the  number of marbles Dovier  selects
and k is the number of different colors of the marbles. You can assume
that 1<=k<=n<=1000000.

Output description:

For each test case print the number of possibilities that Dovier would
have had. You can  assume that this number  fits into a signed  64 bit
integer.

Sample Input:
2
10 10
30 7

Sample Output:
1
475020
*/
