/*
Alfonso Alfonso Peterssen
25 - 12 - 2007
USACO 2001 Fall ( Orange ) "Hungry Cows"
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

int N, i, j;
int dp[MAXN];
struct interval {
    int start, end;
    bool operator < ( const interval &i ) const {
        return end != i.end ? end < i.end : start < i.start;
    }
} ls[MAXN];

int main() {

    cin >> N;
    for ( i = 0; i < N; i++ )
        cin >> ls[i].start >> ls[i].end;

    sort( ls, ls + N ) ;

    /* Easy!!! */
    for ( i = 0; i < N; i++ ) {
        for ( j = 0; j < i; j++ )
            if ( ls[j].end < ls[i].start )
                dp[i] >?= dp[j];
        dp[i] += ls[i].end - ls[i].start + 1;
    }

    cout << *max_element( dp, dp + N ) << endl;

    return 0;
}

/*
PROBLEM 7: Hungry Cows [Brian Dean, 2001]

The cows are lined up at their feed trough, which has individualized
feeding buckets numbered sequentially from 1 through N (1 <= N <= 2000).
Each night a lucky cow gets to eat from a number of buckets according to
Farmer John's rules.

Farmer John posts a list of no more than B bucket-sequences (a bucket
sequence is a pair of integers (a pair like start-end where 1 <= start <=
end <= N and the sequence includes buckets start through end, e.g., 1-3,
7-8, 3-4). FJ's rules allow the cow to choose as many of the intervals as
she wishes, as long as no bucket is mentioned more than once in the total
set of chosen intervals.

Of course, cows are like anyone else and want as much feed as they can get.
Given a set of bucket-sequences, help the lucky cow find the best sequence
which yields the greatest amount of feed.

In the example above, bucket-sequences 1-3 and 3-4 overlap; the wise cow
chooses the set of {1-3, 7-8} for a lavish dinner of five buckets.

PROBLEM NAME: hunger

INPUT FORMAT:

* Line 1: One integer B (1 <= B <= 1000)

* Lines 2..B+1: Each line contains a two integer bucket sequence with
          the smaller bucket number first

SAMPLE INPUT (file hunger.in):

3
1 3
7 8
3 4

OUTPUT FORMAT:

A single line with a single integer that is the greatest number of feed
buckets the lucky cow can eat.

SAMPLE OUTPUT (file hunger.out):

5
*/
