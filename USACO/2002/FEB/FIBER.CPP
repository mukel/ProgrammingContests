/*
Alfonso Alfonso Peterssen
26 - 21 - 2007
USACO 2002 FEB "Fiber Communications"
Simple Simulation -> O( n * m )
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000;

int N, M, i, j, k;
int cant, sol;
int mark[ 2 * MAXN ];
vector< int > ls[MAXN];

    int update( int lo, int hi, int amount ) {
        int edges = 0;
        for ( int i = lo; i < hi; i++ ) {
            mark[i] += amount;
            if ( mark[i] == 0 && amount == -1 ) edges--;
            if ( mark[i] == 1 && amount == 1 ) edges++;
        }
        return edges;
    }

int main() {

    cin >> N >> M;
    for ( i = 0; i < M; i++ ) {
        cin >> j >> k;
        j--; k--;
        ls[j].push_back( k );
        ls[k].push_back( j );
    }

    /* Init */
    for ( i = 0; i < N; i++ )
        for ( j = 0; j < ls[i].size(); j++ )
            if ( ( k = ls[i][j] ) > i )
                cant += update( i, k, 1 );

    /* Solve */
    sol = cant;
    for ( i = 0; i < N; i++ ) {
        for ( j = 0; j < ls[i].size(); j++ )
            if ( ( k = ls[i][j] ) > i ) {
                cant += update( i, k, -1 );
                cant += update( k, i + N, 1 );
            } else {
                cant += update( i, k + N, -1 );
                cant += update( k + N, i + N, 1 );
            }
        sol <?= cant;
    }

    cout << sol << endl;

    return 0;
}

/*
PROBLEM 1: Fiber Communications [Reid Barton, 2001]

Farmer John wants to connect his N (1 <= N <= 1,000) barns (numbered 1..N)
with a new fiber-optic network.  However, the barns are located in a circle
around the edge of a large pond, so he can only connect pairs of adjacent
barns. The circular configuration means that barn N is adjacent to barn 1.

FJ doesn't need to connect all the barns, though, since only certain pairs
of cows wish to communicate with each other.  He wants to construct as few
connections as possible while still enabling all of these pairs to
communicate through the network.  Given the list of barns that wish to
communicate with each other, determine the minimum number of lines that
must be laid.  To communicate from barn 1 to barn 3, lines must be laid
from barn 1 to barn 2 and also from barn 2 to barn 3.

PROBLEM NAME: fiber

INPUT FORMAT:

* Line 1: Two integers, N and P (the number of communication pairs, 1 <= P
  <= 10,000)

* Lines 2..P+1: two integers describing a pair of barns between which
  communication is desired.  No pair is duplicated in the list.

SAMPLE INPUT (file fiber.in):

5 2
1 3
4 5

OUTPUT FORMAT:

One line with a single integer which is the minimum number of direct
connections FJ needs to make.

SAMPLE OUTPUT (file fiber.out):

3

[Which connect barn pairs 1-2, 2-3, and 4-5.]
*/
