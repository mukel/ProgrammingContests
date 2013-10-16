/*
Alfonso Alfonso Peterssen
11 - 2 - 2008
Saratov #102 "Coprimes"
*/
#include <cstdio>

const int MAXN = 10000;

int N, i, j;
bool mark[MAXN + 1];
int euler[MAXN + 1];

int main() {

    scanf( "%d", &N );

    for ( i = 0; i <= N; i++ )
        euler[i] = i;
    for ( i = 2; i <= N; i++ )
        if ( !mark[i] )
            for ( j = i; j <= N; j += i ) {
                euler[j] = euler[j] / i * ( i - 1 );
                mark[j] = true;
            }

    printf( "%d\n", euler[N] );

    return 0;
}
