/*
Alfonso Alfonso Peterssen
28 - 2 - 2007
USACO 2002 FEB "BUY LOW, BUY LOWER"
*/
#include <iostream>
using namespace std;

const int MAXN = 5000;

int N, i, j, len, cant;
int ls[MAXN];
int dp[MAXN], ways[MAXN];

int main() {

    cin >> N;
    for ( i = 0; i < N; i++ ) {

        cin >> ls[i];

        for ( j = 0; j < i; j++ )
            if ( ls[j] > ls[i] )
                dp[i] >?= dp[j] + 1;

        len >?= dp[i];

        for ( j = i - 1; j >= 0; j-- ) {
            if ( ls[j] == ls[i] && dp[j] == dp[i] )
                break;
            if ( ls[j] > ls[i] && dp[j] + 1 == dp[i] )
                 ways[i] += ways[j];
        }

        if ( j < 0 && dp[i] == 0 )
            ways[i] = 1;
    }

    for ( i = 0; i < N; i++ )
        if ( dp[i] == len )
            cant += ways[i];

    cout << len + 1 << " "
         << cant    << endl;

    return 0;
}

/*
PROBLEM 9: BUY LOW, BUY LOWER [Piele, 1990?]

The advice to "buy low" is half the formula to success in the bovine stock
market.  To be considered a great investor you must also follow this
problems' advice:

                    "Buy low; buy lower"

Each time you buy a stock, you must purchase it at a lower price than the
previous time you bought it. The more times you buy at a lower price than
before, the better! Your goal is to see how many times you can continue
purchasing at ever lower prices.

You will be given the daily selling prices of a stock (positive 16-bit
integers) over a period of time.  You can choose to buy stock on any of
the days. Each time you choose to buy, the price must be strictly lower
than the previous time you bought stock.  Write a program which identifies
which days you should buy stock in order to maximize the number of times
you buy.

Here is a list of stock prices:

 Day   1  2  3  4  5  6  7  8  9 10 11 12
Price 68 69 54 64 68 64 70 67 78 62 98 87

The best investor (by this problem, anyway) can buy at most four times if
each purchase is lower then the previous purchase. One four day sequence
(there might be others) of acceptable buys is:

Day    2  5  6 10
Price 69 68 64 62

PROBLEM NAME: buylow

INPUT FORMAT:

* Line 1: N (1 <= N <= 5000), the number of days for which stock prices
          are given

* Lines 2..etc: A series of N space-separated integers, ten per line except
          the final line which might have fewer integers.

SAMPLE INPUT (file buylow.in):

12
68 69 54 64 68 64 70 67 78 62
98 87

OUTPUT FORMAT:

Two integers on a single line:
   * The length of the longest sequence of decreasing prices
   * The number of sequences that have this length (guaranteed to fit in 31 bits)

In counting the number of solutions, two potential solutions are considered
the same (and would only count as one solution) if they repeat the same
string of decreasing prices, that is, if they "look the same" when the
successive prices are compared. Thus, two different sequence of "buy" days
could produce the same string of decreasing prices and be counted as only
a single solution.

SAMPLE OUTPUT (file buylow.out):

4 2
*/
