/*
Alfonso2 Peterssen
8 - 6 - 2008
IOI 2002 "Median Strength"
Using STL::nth_element
*/
#include "device.h"
#include <algorithm>

using namespace std;

const int MAXN = 1500;

int N;
int a, b, c;
int order[MAXN];

bool compare( const int &i, const int &j ) {
    return i == j ? 0 : Med3( i, j, order[N] ) == i;
}

int main() {

    N = GetN();

    for ( int i = 0; i < N; i++ )
        order[i] = i + 1;

    a = N - 1;
    b = N - 2;
    c = N - 3;
    for ( int i = 0; i < N - 2; i++ ) {
        int med = Med3( order[a], order[b], order[c] );
        if ( med == order[a] ) swap( order[i], order[a] );
        if ( med == order[b] ) swap( order[i], order[b] );
        if ( med == order[c] ) swap( order[i], order[c] );
    }

    N -= 2;
    random_shuffle( order, order + N );
    nth_element( order, order + N / 2, order + N, compare );
    Answer( order[N / 2] );

    return 0;
}
