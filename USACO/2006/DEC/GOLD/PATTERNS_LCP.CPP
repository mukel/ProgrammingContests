/*
Alfonso Alfonso Peterssen
1 - 1 - 2008
USACO 2006 DEC Gold "Milk Patterns"
O( n lg^2 n ) -> to build the suffix array
*/
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAXL = 100000;

int len, r, offset, i, j, k, sol;
int st[MAXL];
int sa[MAXL], pos[MAXL], t[MAXL];
int lcp[MAXL];
multiset< int > S;

    bool comp( const int &i, const int &j ) {
        if ( pos[i] != pos[j] ) return pos[i] < pos[j];
        if ( i + offset >= len ) return 1;
        if ( j + offset >= len ) return 0;
        return pos[i + offset] < pos[j + offset];
    }

int main() {

    cin >> len >> r;
    for ( i = 0; i < len; i++ )
        cin >> st[i];

    for ( i = 0; i < len; i++ ) {
        sa[i] = i;
        pos[i] = st[i];
    }

    /* Build Suffix Array */
    for ( offset = 0; t[len - 1] != len - 1;
          offset ? offset *= 2 : offset++ ) {
        sort( sa, sa + len, comp );
        for ( i = 0; i < len - 1; i++ )
            t[i + 1] = t[i] + comp( sa[i], sa[i + 1] );
        for ( i = 0; i < len; i++ )
            pos[ sa[i] ] = t[i];
    }

    /* Build LCP */
    for ( i = k = 0; i < len; i++ ) {
        if ( pos[i] == len - 1 ) continue;
        for ( j = sa[ pos[i] + 1 ];
              i + k < len && j + k < len && st[i + k] == st[j + k];
              k++ );
        lcp[ pos[i] ] = k;
        if ( k > 0 ) k--;
    }

    /* Find min */
    r--;
    for ( i = 0; i < r; i++ )
        S.insert( lcp[i] );

    sol = *S.begin();
    for ( i = r; i < len - 1; i++ ) {
        S.insert( lcp[i] );
        S.erase( S.find( lcp[i - r] ) );
        sol >?= *S.begin();
    }

    cout << sol << endl;

    return 0;
}

/*
Problem 3: Milk Patterns [Coaches, 2004]

Farmer John has noticed that the quality of milk given by his cows
varies from day to day. On further investigation, he discovered
that although he can't predict the quality of milk from one day to
the next, there are some regular patterns in the daily milk quality.

To perform a rigorous study, he has invented a complex classification
scheme by which each milk sample is recorded as an integer between
0 and 1,000,000 inclusive, and has recorded data from a single cow
over N (1 <= N <= 20,000) days. He wishes to find the longest
pattern of samples which repeats identically at least K (2 <= K <= N) times.
This may include overlapping patterns -- 1 2 3 2 3 2 3 1 repeats 2
3 2 3 twice, for example.

Help Farmer John by finding the longest repeating subsequence in
the sequence of samples. It is guaranteed that at least one subsequence
is repeated at least K times.

PROBLEM NAME: patterns

INPUT FORMAT:

* Line 1: Two space-separated integers: N and K

* Lines 2..N+1: N integers, one per line, the quality of the milk on
        day i appears on the ith line.

SAMPLE INPUT (file patterns.in):

8 2
1
2
3
2
3
2
3
1


OUTPUT FORMAT:

* Line 1: One integer, the length of the longest pattern which occurs
        at least K times

SAMPLE OUTPUT (file patterns.out):

4
*/
