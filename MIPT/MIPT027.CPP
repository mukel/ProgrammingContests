/*
Alfonso2 Peterssen
18 - 7 - 2008
MIPT #027 "Odd number"
*/
#include <cstdio>
#include <bitset>

using namespace std;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int MAXX = 1000001;

int N, x;
bitset< MAXX > odd;

int main() {

    scanf( "%d", &N );
    REP( i, N ) {
        scanf( "%d", &x );
        odd.flip( x );
    }
    
    REP( i, MAXX )
        if ( odd[i] ) {
            printf( "%d\n", i );
            break;
        }

    return 0;
}
