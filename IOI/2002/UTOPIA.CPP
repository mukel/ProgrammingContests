/*
Alfonso2 Peterssen
11 - 6 - 2008
IOI 2002 "Utopia Divided"
*/
#include <cstdio>
#include <algorithm>

using std::sort;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

const int
    MAXN = 10000,
    region[4][2] = {{+1,+1},{-1,+1},{-1,-1},{+1,-1}};

int N, x;
int seq[2 * MAXN];
int reg[2 * MAXN];
int sol[2 * MAXN];

#define sign( x ) \
    ( (x+N)%2 ? +S[N-1] : -S[N-1] )

void process( int *X, int *S, int *out ) {

    sort( X, X + N );

    int lo = 0;
    int hi = N - 1;
    for ( int i = N - 1; i > 0; i-- )
        if ( sign( hi ) == S[i - 1] )
             out[i] = X[lo] * sign( lo ), lo++;
        else out[i] = X[hi] * sign( hi ), hi--;

    out[0] = X[lo] * sign( lo );
}

int main() {

    scanf( "%d", &N );
    REP( i, 2 * N )
        scanf( "%d", &seq[i] );
    REP( i, N ) {
        scanf( "%d", &x );
        x--;
        reg[i]     = region[x][0];
        reg[i + N] = region[x][1];
    }

    process( seq    , reg    , sol );
    process( seq + N, reg + N, sol + N );

    REP( i, N )
        printf( "%+d %+d\n", sol[i], sol[i + N] );

    return 0;
}
