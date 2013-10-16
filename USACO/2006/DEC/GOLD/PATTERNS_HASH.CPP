/*
Alfonso Alfonso Peterssen
2 - 1 - 2008
USACO 2006 DEC Gold "Milk Patterns"
O( n lg n ) -> Average
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int
    MAXL = 20001,
    BASE = 29,
    TABLE_SIZE = 100003;

int len, r, i;
int lo, hi, mid;
int st[MAXL];

/* hash_table */
int t_sz;
int first[TABLE_SIZE];
struct node {
    int pos, cant, next;
} ls[MAXL + 1];

    bool repeated( int size ) {

        t_sz = 0;
        fill( first, first + TABLE_SIZE, 0 );

        int i, j;
        int hash = 0, pot = 1;

        for ( i = 0; i < size; i++ ) {
            pot = ( pot * BASE ) % TABLE_SIZE;
            hash = ( hash * BASE + st[i] ) % TABLE_SIZE;
        }

        ls[++t_sz] = ( node ) { 0, 1, 0 };
        first[hash] = t_sz;

        for ( i = 1; i < len - size + 1; i++ ) {

            /* Rehash */
            hash = hash * BASE - st[i - 1] * pot + st[i + size - 1];
            if ( ( hash %= TABLE_SIZE ) < 0 )
                hash += TABLE_SIZE;

            for ( j = first[hash]; j; j = ls[j].next )
                if ( memcmp( st + i, st + ls[j].pos,
                             size * sizeof( int ) ) == 0 ) {
                    if ( ++ls[j].cant >= r )
                        return 1;
                    break;
                }

            if ( !j ) {
                ls[++t_sz] = ( node ) { i, 1, first[hash] };
                first[hash] = t_sz;
            }
        }

        return false;
    }

int main() {

    cin >> len >> r;
    for ( i = 0; i < len; i++ )
        cin >> st[i];

    lo = 0; hi = len - r + 1;
    while ( lo <= hi ) {
        mid = ( lo + hi ) / 2;
        if ( repeated( mid ) )
             lo = mid + 1;
        else hi = mid - 1;
    }

    cout << lo - 1 << endl;

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
