/*
Alfonso Alfonso Peterssen
9 - 7 - 2007
PSN 2007 #129 "Raising Rabbits"
*/
#include <iostream>
using namespace std;

int T, N, M;

  int fib( int n ) {
    long long a = 1, b = 0, c = 1, d = 0, t;
    for ( ; n; n /= 2 ) {
      if ( n & 1 ) {
        t = ( a * c ) % M;
        a = ( a * d + b * c + t ) % M;
        b = ( b * d + t ) % M;
      }
      t = ( c * c ) % M;
      c = ( 2 * ( c * d ) + t ) % M;
      d = ( d * d + t ) % M;
    }
    return b;
  }

int main() {

  for ( cin >> T; T; T-- ) {
    cin >> N >> M;
    M = ( 1 << M );
    cout << fib( N + 1 ) << endl;
  }

  return 0;
}

/*
129þ Raising Rabbits.                                     Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

Rabbits  are  incredible  animals.  One  of  their  more   interesting
characteristics  is  related with  their  reproduction. If  we  keep a
couple  of  adult  rabbits  in  optimal  conditions  of  life,  it  is
scientifically  proved that,  each month,  that couple  is capable  of
procreating a new couple of  young rabbits. You should know  that only
the adult couples  may procreate and  that the time  taken by a  young
couple of rabbits to  grow (that is, to  become adult) is of  1 month.
For the  convenience of  this task,  we will  be dealing with immortal
rabbits.

Farmer Luis  (FL) is  a great  admirer of  rabbits. FL  bought in  the
market 1 couple of adult rabbits (alive, of course) and know wants  to
raise as  many rabbits  as he  can. Unfortunately,  there is  a little
problem, FL has boxes where he can only put exactly 2^M (1 <= M <= 20)
couples of rabbits (neither more nor  less). FL can use as many  boxes
as he wishes as long as he fulfils the condition above. FL would  like
to know how many couples of rabbits he will not be able to put  inside
boxes if he  raises rabbits for  N (1 <=  N <= 2147483647)  months and
then tries to ‘box’ them (put  them inside boxes). You should help  FL
with these calculations. You must consider that FL starts with 1 adult
couple of rabbits the 1st month, and that couples of rabbits reproduce
and grow as stated in the 1st paragraph.

Input description:

Line 1: C  (1 <= C  <= 100), the  number of calculations  your program
will be requested to do

Lines 2-C+1: two integers N and M (in that order)

Output description:

Lines 1-C: on each  lines print S, which  is the number of  rabbits FL
will not be able to ‘box’ for calculation # i

Sample input:
1
5 2

Sample output:
0


Output explanation:
	1	2	3	4	5
Adults 	1	1	2	3	5
Young	0	1	1	2	3

After  growing couples  of rabbits  during 5  months, FL  has 5  adult
couples and 3 young couples (8  couples in total). FL has boxes  where
can put 2^2 = 4 couples of rabbits, so he can use 2 boxes to ‘box’ all
the  8 couples.  If FL  had instead  grown couples  of rabbits  for 4
months, he would  have 5 couples  in total; thus  1 couple would  have
remained un-‘boxed’ (the answer would have been 1).
*/
