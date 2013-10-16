/*
Alfonso Alfonso Peterssen
5 - 1 - 2007
SPOJ #2148 "Candy III"
Just for fun
*/
#include <cstdio>

int T, N, i;
long long candies, sum;

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        sum = 0;

        scanf( "%d", &N );
        for ( i = 0; i < N; i++ ) {
            scanf( "%lld", &candies );
            sum = ( sum + candies % N ) % N;
        }
        
        printf( sum ? "NO\n" : "YES\n" );
    }

    return 0;
}
