/*
Alfonso Alfonso Peterssen
22 - 9 - 2007
USACO 2006 NOV "Bad Hair Day"
*/
#include <fstream>
using namespace std;

#define problem "d"
#define MAXN 80001
#define oo 1000000001

int N, i, j;
long long sol;
int seq[MAXN], next[MAXN];

ifstream fin ( problem ".in" );
ofstream fout ( problem ".out" );

int main() {

  fin >> N;
  for ( i = 0; i < N; i++ )
    fin >> seq[i];

  seq[N] = oo;
  for ( i = N - 1; i >= 0; i-- ) {

    j = i + 1;
    while ( seq[j] < seq[i] )
      j = next[j];

    sol += j - i - 1;
    next[i] = j;
  }

  fout << sol << endl;

  return 0;
}

/*
Problem 6: Bad Hair Day [Brian Dean, 2006]

Some of Farmer John's N cows (1 <= N <= 80,000) are having a bad
hair day! Since each cow is self-conscious about her messy hairstyle,
FJ wants to count the number of other cows that can see the top of
other cows' heads.

Each cow i has a specified height h[i] (1 <= h[i] <= 1,000,000,000)
and is standing in a line of cows all facing east (to the right in
our diagrams). Therefore, cow i can see the tops of the heads of
cows in front of her (namely cows i+1, i+2, and so on), for as long
as these cows are strictly shorter than cow i.

Consider this example:

        =
=       =
=   -   =           Cows facing right -->
=   =   =
= - = = =
= = = = = =
1 2 3 4 5 6

Cow#1 can see the hairstyle of cows #2, 3, 4
Cow#2 can see no cow's hairstyle
Cow#3 can see the hairstyle of cow #4
Cow#4 can see no cow's hairstyle
Cow#5 can see the hairstyle of cow 6
Cow#6 can see no cows at all!

Let c[i] denote the number of cows whose hairstyle is visible from
cow i; please compute the sum of c[1] through c[N]. For this example,
the desired is answer 3 + 0 + 1 + 0 + 1 + 0 = 5.

TIME LIMIT: 0.5 seconds

PROBLEM NAME: badhair

INPUT FORMAT:

* Line 1: The number of cows, N.

* Lines 2..N+1: Line i+1 contains a single integer that is the height
        of cow i.

SAMPLE INPUT (file badhair.in):

6
10
3
7
4
12
2


INPUT DETAILS:

Six cows stand in a line; heights are 10, 3, 7, 4, 12, 2.

OUTPUT FORMAT:

* Line 1: A single integer that is the sum of c[1] through c[N].

SAMPLE OUTPUT (file badhair.out):

5
*/
