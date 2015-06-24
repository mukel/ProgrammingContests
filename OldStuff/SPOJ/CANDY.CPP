/*
Alfonso Alfonso Peterssen
8 - 1 - 2007
SPOJ #2148 "Candy I"
Just for fun
*/
#include <cstdio>
#include <algorithm>

const int MAXN = 10000;

int N, i, sum, sol;
int candies[MAXN];

int main() {

    for (;;) {

        scanf( "%d", &N );

        if ( N == -1 ) break;

        sum = sol = 0;
        for ( i = 0; i < N; i++ ) {
            scanf( "%d", &candies[i] );
            sum += candies[i];
        }

        if ( sum % N ) printf( "-1\n" );
        else {
            sum /= N;
            for ( i = 0; i < N; i++ )
                if ( candies[i] > sum )
                sol += candies[i] - sum;
            printf( "%d\n", sol );
        }
    }

    return 0;
}
