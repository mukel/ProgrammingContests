/*
Alfonso Alfonso Peterssen
5 - 2 - 2008
MIPT #006 "Three squares"
*/
#include <cstdio>
#include <algorithm>

using std::count;

const int MAXN = 10001;

int N, i, j, k;
int sqr[MAXN];
bool mark[MAXN];

int main() {

    scanf( "%d", &N );
    
    N++;
    for ( i = 0; ( sqr[i] = i * i ) < N; i++ );

    for ( i = 0; sqr[i] < N; i++ )
        for ( j = i; sqr[i] + sqr[j] < N; j++ )
            for ( k = j; sqr[i] + sqr[j] + sqr[k] < N; k++ )
                mark[ sqr[i] + sqr[j] + sqr[k] ] = true;

    printf( "%d\n",
        count( mark, mark + N, false ) );

    return 0;
}
