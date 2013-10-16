/*
Alfonso Alfonso Peterssen
9 - 7 - 2007
PSN 2007 #122 "The Next Palindrome"
*/
#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

#define problem "d"
#define set_reverse( x, y ) ( x = y, reverse( x.begin(), x.end() ) )

int len;
string num, rgt, lft, tmp;

  void PLUS( string &st ) {
    int i, r = 1, t;
    for ( i = st.size(); --i >= 0; ) {
      t = st[i] - '0' + r;
      st[i] = '0' + t % 10 ;
      r = t / 10;
    }
    if ( r )
      st = '1' + st;
  }

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  while ( fin >> num ) {

    PLUS( num );
    len = ( num.size() + 1 ) / 2;

    rgt = num.substr( 0, len );
    lft = num.substr( len, len );

    set_reverse( tmp, rgt );
    if ( tmp < lft ) PLUS( rgt );

    set_reverse( tmp, rgt );
    if ( num.size() & 1 ) tmp.erase( 0, 1 );
    fout << rgt + tmp << endl;
  }

  return 0;
}

/*
122þ The Next Palindrome.                                 Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

A positive integer is called a palindrome if its representation in the
decimal system is the same when read from left to right and from right
to left.  For a  given positive  integer K  of not  more than  1000000
digits, write the  value of the  smallest palindrome larger  than K to
output. Numbers are always displayed without leading zeros.

Input

A single integer K is given in the first line.

Output

Output the smallest palindrome larger than K.

Sample Input 1:

808

Sample Output 1:

818

Sample Input 2:

2133

Sample Output 2:

2222


Warning: large Input/Output data.

Specifications
Problem Name:       palin
Input File Name:     palin.in
Output File Name:  palin.out
Time Limit:             0.25 s
*/
