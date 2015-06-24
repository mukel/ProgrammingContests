/*
Alfonso2 Peterssen
18 - 6 - 2008
BalkanOI 2003 "Spaceship"
*/
#include <cstdio>

const int
    MAXN = 42,
    MAXNS = 450,
    MAXLEN = 60;

int S, N;
int dp[MAXN][MAXNS][MAXLEN];

/* from infoarena.ro */
void add( int A[], int B[] ) {
    int i, t = 0;
    for ( i = 1; i <= A[0] || i <= B[0] || t; i++, t /= 10 )
          A[i] = ( t += A[i] + B[i] ) % 10;
    A[0] = i - 1;
}

int main() {

    scanf( "%d %d", &S, &N );

    dp[0][0][0] = dp[0][0][1] = 1;
    for ( int i = 1; i <= N + 1; i++ )
        for ( int j = i; j <= i * S; j++ ) {
            add( dp[i][j], dp[i][j - 1] );
            add( dp[i][j], dp[i - 1][j - 1] );
        }

    for ( int i = dp[N+1][N*S+1][0]; i > 0; i-- )
        printf( "%d", dp[N+1][N*S+1][i] );
    printf( "\n" );

    return 0;
}
