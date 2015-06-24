/*
Alfonso Alfonso Peterssen
3 - 1 - 2008
USACO 2001 FEB "Triangular Pastures"
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int
    MAXN = 41,
    MAXL = 1600;

int N, i, j, k, s;
int sum, limit, sol;
int ls[MAXN];
bool dp[MAXL][MAXL][2];

int main() {

    cin >> N;
    for ( i = 1; i <= N; i++ ) {
        cin >> ls[i];
        sum += ls[i];
    }

    dp[0][0][s] = true;
    for ( i = 1; i <= N; i++ ) {
        s ^= 1;
        limit += ls[i];
        for ( j = 0; j < limit; j++ )
            for ( k = 0; k < limit; k++ ) {
                bool &r = dp[j][k][s];
                r = dp[j][k][s ^ 1];
                if ( j >= ls[i] ) r |= dp[ j - ls[i] ][k][s ^ 1];
                if ( k >= ls[i] ) r |= dp[j][ k - ls[i] ][s ^ 1];
            }
    }

    for ( i = 1; i < limit; i++ )
        for ( j = 1; j < limit; j++ )
            if ( dp[i][j][s] ) {
                k = sum - i - j;
                if ( i + j <= k || i + k <= j || j + k <= i )
                    continue;
                long double p = sum / 2.0;
                long double area = sqrtl( p * (p - i) * (p - j) * (p - k) );
                sol >?= ( int ) ( 100.0 * area );
            }

    if ( sol == 0 ) sol = -1;
    cout << sol << endl;

    return 0;
}

/*

PROBLEM 5: Triangular Pastures [Dean, 2001]

Like everyone, cows enjoy variety.  Their current fancy is new shapes for
pastures.  The old rectangular shapes are out of favor; new geometries are
the favorite.

I. M. Hei, the lead cow pasture architect, is in charge of creating a
triangular pasture surrounded by nice white fence rails.  She is supplied
with N (3 <= N <= 40) fence segments (each of integer length Li (1 <= Li
<= 40) and must arrange them into a triangular pasture with the largest
grazing area.  Ms. Hei must use all the rails to create three sides of
a triangle with non-zero area.

Help Ms. Hei convince the rest of the herd that plenty of grazing land will
be available.  Calculate the largest area that may be enclosed with a
supplied set of fence segments.

PROBLEM NAME: pasture

INPUT FORMAT:

* Line 1: A single integer N

* Lines 2..N+1: N lines, each with a single integer representing one
          fence segment's length.  The lengths are not necessarily unique.

SAMPLE INPUT (file pasture.in):

5
1
1
3
3
4

OUTPUT FORMAT:

A single line with the integer that is the truncated integer representation
of the largest possible enclosed area multiplied by 100.  Output -1 if no
triangle of positive area may be constructed.

SAMPLE OUTPUT (file pasture.out):

692

[which is 100x the area of an equilateral triangle with side length 4]
*/
