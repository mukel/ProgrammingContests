/*
Alfonso Alfonso Peterssen
11 - 2 - 2008
Saratov #127 "Telephone directory"
*/
#include <cstdio>

const int MAXN = 8000;

int N, K, i, sol;
int freq[10];
char ls[MAXN][10];

int main() {

    scanf( "%d %d", &K, &N );
    for ( i = 0; i < N; i++ )
        scanf( "%s", &ls[i] );

    for ( i = 0; i < N; i++ )
        freq[ ls[i][0] - '0' ]++;

    for ( i = 0; i < 10; i++ )
        sol += ( freq[i] + K - 1 ) / K;
        
    printf( "%d\n", sol + 2 );

    return 0;
}
