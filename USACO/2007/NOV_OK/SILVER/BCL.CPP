/*
Alfonso Alfonso Peterssen
17 - 11 - 2007
USACO 2007 NOV Silver "Best Cow Line"
O( n^2 ) -> Brutusky Forzusky
*/
#include <cstdio>

const int MAXN = 2010;

int N, len, i, j, k;
char st[MAXN], sol[MAXN];

int main() {

  scanf( "%d", &N );
  for ( i = 0; i < N; i++ )
    scanf( "%s", st + i );

  i = 0; j = N - 1;
  for ( len = 0; len < N; len++ ) {
    for ( k = 0; k < j - i; k++ )
      if ( st[i + k] != st[j - k] ) break;
    if ( st[i + k] < st[j - k] )
         sol[len] = st[i], i++;
    else sol[len] = st[j], j--;
  }

  for ( i = 0; i < len; i++ ) {
    printf( "%c", sol[i] );
    if ( i % 80 == 79 ) printf( "\n" );
  }

  return 0;
}

/*
Problem 8: Best Cow Line [Christos Tzamos, 2007]

FJ is about to take his N (1 <= N <= 2,000) cows to the annual
"Farmer of the Year" competition. In this contest every farmer
arranges his cows in a line and herds them past the judges.

The contest organizers adopted a new registration scheme this year:
simply register the initial letter of every cow in the order they
will appear (i.e., If FJ takes Bessie, Sylvia, and Dora in that
order he just registers BSD). After the registration phase ends,
every group is judged in increasing lexicographic order according
to the string of the initials of the cows' names.

FJ is very busy this year and has to hurry back to his farm, so he
wants to be judged as early as possible. He decides to rearrange
his cows, who have already lined up, before registering them.

FJ marks a location for a new line of the competing cows. He then
proceeds to marshal the cows from the old line to the new one by
repeatedly sending either the first or last cow in the (remainder
of the) original line to the end of the new line. When he's finished,
FJ takes his cows for registration in this new order.

Given the initial order of his cows, determine the least lexicographic
string of initials he can make this way.

PROBLEM NAME: bcl

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains a single initial ('A'..'Z') of the
        cow in the ith position in the original line

SAMPLE INPUT (file bcl.in):

6
A
C
D
B
C
B

INPUT DETAILS:

FJ has 6 cows in this order: ACDBCB

OUTPUT FORMAT:

The least lexicographic string he can make. Every line (except perhaps
the last one) contains the initials of 80 cows ('A'..'Z') in the new
line.

SAMPLE OUTPUT (file bcl.out):

ABCBCD

OUTPUT DETAILS:

  Step   Original     New
   #1     ACDBCB
   #2      CDBCB     A
   #3      CDBC      AB
   #4      CDB       ABC
   #5      CD        ABCB
   #6       D        ABCBC
   #7                ABCBCD
*/
