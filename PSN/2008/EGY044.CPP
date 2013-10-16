/*
Alfonso Alfonso Peterssen
TASK: ADIT
*/
#include <cstdio>

const int MAXN = 10001;

int N, i, j;
int dp[MAXN];
int from[MAXN];

void print( int x ) {
    if ( !x ) return ;
    print( from[x] ); printf( "%d ", x );
}

int main() {

    #warning READ FROM FILES!!!!!
    //freopen( "adit.in", "r", stdin );
    //freopen( "adit.out", "w", stdout );

    scanf( "%d", &N );

    dp[1] = 1;
    for ( i = 1; i <= N; i++ )
        for ( j = i; j > 0; j = from[j] )
            if ( i + j <= N &&
                 ( dp[i] + 1 < dp[i + j] || dp[i + j] == 0 ) ) {
                dp[i + j] = dp[i] + 1;
                from[i + j] = i;
            }

    printf( "%d\n", dp[N] );
    print( N );

    fflush( stdout );

    return 0;
}
