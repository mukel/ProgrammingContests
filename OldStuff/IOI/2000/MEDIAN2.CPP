/*
Alfonso2 Peterssen
8 - 6 - 2008
IOI 2002 "Median Strength"
QuickSort Style
*/
#include "device.h"
#include <algorithm>

using std::swap;
using std::random_shuffle;

const int MAXN = 1500;

int N;
int a, b, c;
int order[MAXN];

bool compare( const int &i, const int &j ) {
    return i == j ? 0 : Med3( i, j, order[N] ) == i;
}

int qselect( int lo, int hi, int kth ) {

    while ( lo < hi ) {

        int i = lo;
        int j = hi - 1;
        while ( i <= j ) {
            while ( compare( order[i], order[hi] ) ) i++;
            while ( compare( order[hi], order[j] ) ) j--;
            if ( i <= j ) {
                swap( order[i], order[j] );
                i++; j--;
            }
        }

        j++;
        swap( order[j], order[hi] );
        if ( j == kth ) break;
        if ( j > kth )
             hi = j - 1;
        else lo = j + 1;
    }

    return order[kth];
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
    Answer( qselect( 0, N - 1, N / 2 ) );

    return 0;
}
