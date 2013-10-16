/*
Alfonso2 Peterssen
13 - 5 - 2008
Saratov #222 "Little Rooks"
*/
#include <cstdio>

int N, K;
long long sol, factK;

int main() {

    scanf( "%d %d", &N, &K );

    if ( K > N ) {
        printf( "0\n" );
        return 0;
    }

    factK = 1;
    for ( int i = 1; i <= K; i++ )
        factK = factK * i;

    sol = 1;
    for ( int i = N - K + 1; i <= N; i++ )
        sol *= i;
        
    printf( "%I64d\n", sol * sol / factK );

    return 0;
}
