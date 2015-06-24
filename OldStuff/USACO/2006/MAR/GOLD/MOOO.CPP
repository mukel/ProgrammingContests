/*
Alfonso Alfonso Peterssen
4 - 1 - 2007
USACO 2006 MAR Gold "Mooo"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 50000;

int N, i;
int height[MAXN], volume[MAXN];
int next[MAXN];
long long sum[MAXN];

    void solve() {
        int i, j;
        for ( i = 0; i < N; i++ ) {
            for ( j = i - 1;
                  j >= 0 && height[j] <= height[i];
                  j = next[j] );
            next[i] = j;
            if ( j >= 0 )
                sum[j] += volume[i];
        }
    }

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ )
        scanf( "%d %d", &height[i], &volume[i] );

    solve();
    reverse( sum, sum + N );
    reverse( height, height + N );
    reverse( volume, volume + N );
    solve();

    printf( "%lld\n", *max_element( sum, sum + N ) );

    return 0;
}

/*
Problem 3: Mooo [Brian Dean, 2005]

Farmer John's N (1 <= N <= 50,000) cows are standing in a very
straight row and mooing. Each cow has a unique height h in the range
1..2,000,000,000 nanometers (FJ really is a stickler for precision).
Each cow moos at some volume v in the range 1..10,000. This "moo"
travels across the row of cows in both directions (except for the
end cows, obviously). Curiously, it is heard only by the closest
cow in each direction whose height is strictly larger than that of
the mooing cow (so each moo will be heard by 0, 1 or 2 other cows,
depending on whether or not taller cows exist to the mooing cow's
right or left).

The total moo volume heard by given cow is the sum of all the moo
volumes v for all cows whose mooing reaches the cow. Since some
(presumably taller) cows might be subjected to a very large moo
volume, FJ wants to buy earmuffs for the cow whose hearing is most
threatened. Please compute the loudest moo volume heard by any cow.

PROBLEM NAME: mooo

INPUT FORMAT:

* Line 1: A single integer, N.

* Lines 2..N+1: Line i+1 contains two space-separated integers, h and
        v, for the cow standing at location i.

SAMPLE INPUT (file mooo.in):

3
4 2
3 5
6 10

INPUT DETAILS:

Three cows: the first one has height 4 and moos with volume 2, etc.

OUTPUT FORMAT:

* Line 1: The loudest moo volume heard by any single cow.

SAMPLE OUTPUT (file mooo.out):

7

OUTPUT DETAILS:

The third cow hears both the first and second cows moo 2+5=7.  Though the
third cow moos with volume 10, no one hears her.
*/
