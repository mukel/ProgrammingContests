/*
Alfonso Alfonso Peterssen
25 - 12 - 2007
USACO 2001 Fall ( Orange ) "Dictionary Numbers"
Just for fun
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const char* number[] =
    { "zero", "one", "two", "three", "four",
      "five" ,"six" , "seven", "eight", "nine" };

int A, B, i, j, k;
vector< pair< string, int > > ls;

int main() {

    cin >> A >> B;

    for ( i = A; i <= B; i++ ) {
        string word;
        for ( j = i; j; j /= 10 )
            word = number[ j % 10 ] + word;
        ls.push_back( make_pair( word, i ) );
    }

    sort( ls.begin(), ls.end() );

    cout << ls[0].second << " " <<
            ls[ ls.size() - 1 ].second << endl;

    return 0;
}

/*
PROBLEM 6: Dictionary Numbers [Piele, 2001]

The number 79 becomes "seven nine" when translated digit by digit into a
string of words. Likewise 80 becomes "eight zero"

When sorted as numbers, 79 comes before 80. But as a translated string,
the number "eight zero" comes before "seven nine" in dictionary order.

Write a program that reads two whole numbers M and N (1 <= M < N <= 999)
and finds the first and last numbers in dictionary order of the numbers
in the range M..N inclusive

PROBLEM NAME: dictnum

INPUT FORMAT:

A single line with two integers: M and N

SAMPLE INPUT (file dictnum.in):

7 20

OUTPUT FORMAT:

A single line with two space-separated integers that are the first and last
numbers when the numbers are sorted in dictionary sequence.


SAMPLE OUTPUT (file dictnum.out):

8 20
*/
