/*
Alfonso Alfonso Peterssen
25 - 12 - 2007
USACO 2001 Fall "Cowese"
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int
    MAXN = 20000,
    oo = 1000000000;

int N, i, j, k, len, max_prefix;
int sol1, sol2, x, y;
int sorted[MAXN], lcp[MAXN];
string st[MAXN];

    bool comp( const int &i, const int &j ) {
        return st[i] < st[j];
    }

    void update( int value, int &x, int &y ) {
        if ( value < x ) {
            y = x;
            x = value;
        } else if ( value != x )
            y <?= value;
    }


int main() {

    cin >> N;
    for ( i = 0; i < N; i++ ) {
        cin >> st[i];
        sorted[i] = i;
    }

    sort( sorted, sorted + N, comp );

    /* Build LCP */
    for ( i = 0; i < N - 1; i++ ) {

        string& x = st[ sorted[i] ],
                y = st[ sorted[i + 1] ];

        len = x.size() <? y.size();
        for ( j = 0; j < len; j++ )
            if ( x[j] != y[j] ) break;

        max_prefix >?= j;
        lcp[i] = j;
    }

    /* Solve */
    sol1 = sol2 = oo;
    for ( i = 0; i < N - 1; i = j + 1 ) {
        x = y = oo;
        for ( j = i; j < N - 1; j++ ) {
            if ( lcp[j] < max_prefix ) break;
            update( sorted[j], x, y );
            update( sorted[j + 1], x, y );
        }
        if ( x < sol1 )
            sol1 = x, sol2 = y;
    }

    cout << st[sol1] << endl;
    cout << st[sol2] << endl;

    return 0;
}

/*
PROBLEM 4: Cowese [Dan Adkins, 2001]

It is a little known fact that the cows love word games.  They have their
own cow crossword puzzles, cow word-find grids, and all sorts of other cow
word games.

The cows need some computer assistance, though, in order to design certain
word games.  They have lists of N distinct words (2 <= N <= 20,000) no
longer than 100 characters, all of which are lower-case and contain only
the letters 'a'..'z'.

They need to find two words in the list that share the longest prefix
(i.e., the first C characters of the words match and C is the longest
length for all possible pairs of words).  The input datasets are guaranteed
to have at least one pair of words with a shared prefix.

If more than two word pairs share prefixes of the same maximal size, the
cows want to see the pair whose first word is closest to the beginning of
the supplied list and whose other maximal-prefix word is closest to the
beginning of the list.

PROBLEM NAME: prefix

INPUT FORMAT:

* Line 1: One line with a single integer: N

* Lines 2..N+1: Each line contains a single word.

SAMPLE INPUT (file prefix.in):

9
noon
is
lunch
for
most
noone
waits
until
two

OUTPUT FORMAT:

Two lines, each with a single word.

SAMPLE OUTPUT (file prefix.out):

noon
noone
*/
