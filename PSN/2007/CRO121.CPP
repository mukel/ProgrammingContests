/*
Alfonso Alfonso Peterssen
8 - 7 - 2007
PSN 2007 #121 "Quirksome Squares"
Pig Code
*/
#include <fstream>
using namespace std;

#define problem "d"

const char *qs[5] =
  { "00\n01\n81\n",
    "0000\n0001\n2025\n3025\n9801\n",
    "000000\n000001\n088209\n494209\n998001\n",
    "00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n" };

ifstream fin( problem ".in" );
ofstream fout( problem ".out" );

int main() {

  int len;
  while ( fin >> len )
    fout << qs[ len / 2 - 1 ];

  return 0;
}

/*
121þ Quirksome Squares.                                   Croacia 2007
ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ

The  number 3025  has a  remarkable quirk:  if you  split its  decimal
representation in two strings of  equal length (30 and 25)  and square
the sum of the numbers so obtained, you obtain the original number:

The problem is  to determine all  numbers with this  property having a
given even  number of  digits. For  example, 4-digit  numbers run from
0000 to 9999. Note that  leading zeroes should be taken  into account.
This means that 0001  which is equal to    is a quirksome number  of 4
digits. The number  of digits may  be 2,4,6 or  8. Although maxint  is
only 32767 and  numbers of eight  digits are asked  for, a well-versed
programmer can keep his numbers in the range of the integers.  However
efficiency should be given a thought.

Input

The input of your program is  a text file containing no more  than 300
numbers of digits (taken from 2,4,6,8),  each number on a line of  its
own.

Output

The output is a text file consisting of lines containing the quirksome
numbers (ordered  according to  the input  numbers and  for each input
number in increasing order). Warning:  Please note that the number  of
digits in the output is equal to the number in the corresponding input
line : leading zeroes may not be suppressed.

Sample Input
2
2

Sample Output
00
01
81
00
01
81

Specifications
Problem Name:       quirk
Input File Name:     quirk.in
Output File Name:  quirk.out
Time Limit:             0.2 s
*/
