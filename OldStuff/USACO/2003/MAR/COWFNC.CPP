/*
Alfonso2 Peterssen
26 - 5 - 2008
USACO MAR03 Gold "Best Cow Fences"
*/
#include <cstdio>

const int MAXN = 100001;
const double EPSILON = 1e-4;

int N, F;
int C[MAXN];
double lo, hi, mid;
double low[MAXN];

bool check( double value ) {
    for ( int i = 1; i <= N; i++ ) {
        double now = C[i] - value * i;
        low[i] = now <? low[i - 1];
        if ( i >= F && now >= low[i - F] )
            return 1;
    }
    return 0;
}

int main() {

	scanf( "%d %d", &N, &F );
    for ( int i = 1; i <= N; i++ ) {
        scanf( "%d", &C[i] );
        C[i] += C[i - 1];
    }

    lo = 0;
    hi = 1e5;
    while ( hi - lo > EPSILON ) {
        mid = ( lo + hi ) / 2.;
        if ( check( mid ) )
             lo = mid;
        else hi = mid;
    }

    printf( "%d\n", (int)( ( lo  + EPSILON ) * 1000. ) );

    return 0;
}
