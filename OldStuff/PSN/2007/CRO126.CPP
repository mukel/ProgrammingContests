/*
Alfonso Alfonso Peterssen
2 - 8 - 2007
PSN 2007 #129 "Count on Canton"
*/
#include <iostream>
#include <cmath>
using namespace std;

int T, N, sq, t;

int main() {

  for ( cin >> T ; T; T-- ) {

    cin >> N;

    sq = trunc( sqrt( 8 * N ) - 1 ) / 2;
    t = N - sq * ( sq + 1 ) / 2;

    cout << "TERM " << N << " IS ";
    if ( sq & 1 )
         cout << t << "/" << sq - t + 2 << endl;
    else cout << sq - t + 2 << "/" << t << endl;
  }

  return 0;
}

/*
126þ Count on Canton.                                     Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

One  of the  famous proofs  of modern  mathematics is  Georg Cantor's
demonstration  that the  set of  rational numbers  is enumerable.  The
proof works by  using an explicit  enumeration of rational  numbers as
shown in the diagram below.

1/1 1/2 1/3 1/4 1/5...
2/1 2/2 2/3 2/4
3/1 3/2 3/3
4/1 4/2
5/1

In the above diagram, the first  term is 1/1, the second term  is 1/2,
the third term is 2/1, the fourth term is 3/1, the fifth term is  2/2,
and so on.

Input description:

The input  starts with  a line  containing a  single integer  1<= t <=
100000,  the number  of test  cases. t  test cases  follow. Then,  it
contains a single number per line.

Output description:

You are to  write a program  that will read  a list of  numbers in the
range from 1 to 10^7 and will print for each number the  corresponding
term in Cantor's enumeration as given below.

Sample Input:
33
14
7

Sample Output:
TERM 3 IS 2/1
TERM 14 IS 2/4
TERM 7 IS ¼
*/
