/*
Alfonso Alfonso Peterssen
1 - 12 - 2007
SPOJ #1870 "Making Labels"
*/
#include <iostream>
using namespace std;

const int sol[] =
    { -1, 1, 1, 3, 16, 125, 1296, 16807, 262144, 4782969, 100000000 };

int T, N;

int main() {

    while ( ++T ) {
        scanf( "%d", &N );
        if ( !N ) break;
        printf( "Case %d, N = %d, # of different labelings = %d\n", T, N, sol[N] );
    }

    return 0;
}
