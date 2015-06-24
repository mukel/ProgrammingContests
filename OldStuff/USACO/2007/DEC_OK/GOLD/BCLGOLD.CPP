/*
Alfonso Alfonso Peterssen
20 - 12 - 2007
USACO 2007 DEC Gold "Best Cow Line, Gold"
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXL = 60000;

int len, offset, i, j, k;
int pos[MAXL], sa[MAXL], t[MAXL];
string st;

    bool comp( const int &i, const int &j ) {
        if ( pos[i] != pos[j] ) return pos[i] < pos[j];
        if ( i + offset >= len ) return 1;
        if ( j + offset >= len ) return 0;
        return pos[i + offset] < pos[j + offset];
    }

int main() {

    cin >> len;
    st.resize( len );
    for ( i = 0; i < len; i++ )
        cin >> st[i];

    st += string( st.rbegin(), st.rend() );
    len = st.size();

    /* Init */
    for ( i = 0; i < len; i++ ) {
        sa[i] = i;
        pos[i] = st[i];
    }

    /* Build Suffix Array */
    for ( offset = 0; t[len - 1] != len - 1/*offset < len*/;
          offset ? offset *= 2 : offset++ ) {
        sort( sa, sa + len, comp );
        for ( i = 0; i < len - 1; i++ )
            t[i + 1] = t[i] + comp( sa[i], sa[i + 1] );
        for ( i = 0; i < len; i++ )
            pos[ sa[i] ] = t[i];
    }

    j = 0, k = len / 2 - 1;
    for ( i = 0; i < len / 2; i++ ) {
        if ( pos[j] < pos[ len - k - 1 ] )
             cout << st[j], j++;
        else cout << st[k], k--;
        if ( i % 80 == 79 )
            cout << endl;
    }

    if ( i % 80 ) cout << endl;

  return 0;
}

/*
Problem 3: Best Cow Line, Gold [Christos Tzamos, 2007]

FJ is about to take his N (1 <= N <= 30,000) cows to the annual
"Farmer of the Year" competition. In this contest every farmer
arranges his cows in a line and herds them past the judges.

The contest organizers adopted a new registration scheme this year:
simply register the initial letter of every cow in the order they
will appear (e.g., If FJ takes Bessie, Sylvia, and Dora in that
order, he just registers BSD). After the registration phase ends,
every group is judged in increasing lexicographic order (i.e.,
alphabetical order) according to the string of the initials of the
cows' names.

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

PROBLEM NAME: bclgold

INPUT FORMAT:

* Line 1: A single integer: N

* Lines 2..N+1: Line i+1 contains a single initial ('A'..'Z') of the
        cow in the ith position in the original line

SAMPLE INPUT (file bclgold.in):

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

SAMPLE OUTPUT (file bclgold.out):

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
