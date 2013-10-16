/*
Alfonso2 Peterssen
9 - 7 - 2008
SPOJ #1329 "Matrix"
*/
#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR( i, s, e ) \
    for ( int i = (s); i <= (e); i++ )

const int
    MAXC = 300;

int F, C, lo, hi;
long long sol;
int S[MAXC][MAXC];
int T[MAXC];
int value[MAXC];
int order[MAXC];

inline int lobit( int x ) { return x & -x; }

int query( int x ) {
    int sum = 0;
    for ( x++; x > 0; x -= lobit( x ) )
        sum += T[x];
    return sum;
}

void update( int x ) {
    for ( x++; x <= C + 6; x += lobit( x ) )
        T[x]++;
}

int main() {

    scanf( "%d %d", &F, &C );
    FOR( i, 1, F )
    FOR( j, 1, C ) {
        scanf( "%d", &S[i][j] );
        S[i][j] += S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1];
    }
    scanf( "%d %d", &lo, &hi );

    FOR( i, 1, F )
    FOR( j, 1, i ) {
        fill( T, T + C + 6, 0 );
        FOR( k, 0, C )
            order[k] = value[k] = S[i][k] - S[j - 1][k];
        sort( order, order + C + 1 );
        FOR( k, 0, C ) {
            sol += query( upper_bound( order, order + C + 1, value[k] - lo ) - order - 1 ) - // <=
                   query( lower_bound( order, order + C + 1, value[k] - hi ) - order - 1 );  // <
            update( lower_bound( order, order + C + 1, value[k] ) - order );
        }
    }

    printf( "%lld\n", sol );

    return 0;
}
