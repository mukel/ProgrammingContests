/*
Alfonso Alfonso Peterssen
4 - 8 - 2008
USACO JAN07 Gold "Balanced Lineup"
*/
#include <cstdio>

const int
    MAXN = 50000,
    MAXLOG = 16;

int N, Q;
int i, j, k;
int lg, lo, hi, sol
int LOW[MAXLOG][MAXN];
int UPP[MAXLOG][MAXN];

int log2( int x ) {
    return 31 - __builtin_clz( x );
}

int main() {

    scanf( "%d %d", &N, &Q );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d", &k );
        LOW[0][i] = UPP[0][i] = k;
    }

    lg = log2( N );
    for ( i = 1; i <= lg; i++ )
        for ( j = N - ( 1 << i ); j >= 0; j-- ) {
            LOW[i][j] = LOW[i - 1][j] <? LOW[i - 1][j + ( 1 << ( i - 1 ) )];
            UPP[i][j] = UPP[i - 1][j] >? UPP[i - 1][j + ( 1 << ( i - 1 ) )];
        }

    while ( Q-- ) {
        scanf( "%d %d", &lo, &hi );
        lo--; hi--;
        lg = log2( hi - lo + 1 );
        sol = ( UPP[][lg][lo] <? UPP[lg][hi - ( 1 << lg ) + 1] ) -
              ( LOW[][lg][lo] <? LOW[lg][hi - ( 1 << lg ) + 1] );
        printf( "%d\n", sol );
    }

    fflush( stdout );

    return 0;
}
