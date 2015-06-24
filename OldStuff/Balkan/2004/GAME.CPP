/*
Alfonso2 Peterssen
29 - 5 - 2008
BalkanOI 2004 "Game"
*/
#include <cstdio>
#include <cstring>

#define FOR( i, s, e ) \
    for ( int i = s; i <= (e); i++ )

const int MAXN = 2001;

int N, M;
int A[MAXN], SA[MAXN];
int B[MAXN], SB[MAXN];
int dp[MAXN][MAXN];
int best[MAXN];

int main() {

    scanf( "%d %d", &N, &M );
    FOR( i, 1, N ) scanf( "%d", &A[N - i + 1] );
    FOR( i, 1, M ) scanf( "%d", &B[M - i + 1] );

    FOR ( i, 1, N ) A[i]--, SA[i] = A[i] + SA[i - 1];
    FOR ( i, 1, M ) B[i]--, SB[i] = B[i] + SB[i - 1];

    FOR( i, 1, N ) {
        best[0] = 0;
        FOR( j, 1, M ) {
            if ( i == 1 || j == 1 )
                dp[i][j] = SA[i] * SB[j];
            else {
                dp[i][j] =   dp[i - 1][ best[0] ] + A[i] * ( SB[j] - SB[ best[0] ] );
                dp[i][j] <?= dp[ best[j] ][j - 1] + B[j] * ( SA[i] - SA[ best[j] ] );
            }
            if ( best[0] == 0 ||
                 dp[i - 1][j] - SB[j] * A[i] < dp[i - 1][ best[0] ] - SB[ best[0] ] * A[i] )
                best[0] = j;
            if ( best[j] == 0 ||
                 dp[i][j - 1] - SA[i] * B[j] < dp[ best[j] ][j - 1] - SA[ best[j] ] * B[j] )
                best[j] = i;
        }
    }

    printf( "%d\n", dp[N][M] );

    return 0;
}
