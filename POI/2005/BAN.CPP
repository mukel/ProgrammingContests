/*
Alfonso Alfonso Peterssen
8 - 4 - 2008
POI 2005 Stage II "Bank Notes"
O( n * money ) -> DP speedup
*/
#include <cstdio>

const int
    MAXN = 201,
    MAXM = 20001,
    oo = 666666666;

int N, S, money, coins;
int h, i, j, k;
int lo, hi;
int V[MAXN];
int C[MAXN];
int sol[MAXN];
int next[MAXM];
int value[MAXM];
int dp[MAXN][MAXM];
int from[MAXN][MAXM];

int main() {

    scanf( "%d", &N );
    for ( i = 1; i <= N; i++ )
        scanf( "%d", &V[i] );
    for ( i = 1; i <= N; i++ )
        scanf( "%d", &C[i] );
    scanf( "%d", &money );

    for ( i = 1; i <= money; i++ )
        dp[0][i] = oo;

    for ( i = 1; i <= N; i++ )
        for ( j = 0; j < V[i]; j++ ) {

            S = coins = 0;
            for ( k = j; k <= money; k += V[i] ) {
                value[S++] = dp[i - 1][k] - coins;
                dp[i][k] = oo;
                coins++;
            }

            for ( k = S - 1; k >= 0; k-- ) {
                for ( h = k + 1;
                      h < S &&
                      value[h] > value[k];
                      h = next[h] );
                next[k] = h;
            }

            for ( lo = hi = 0; hi < S; hi++ ) {

                if ( hi - lo > C[i] )
                    lo++;
                while ( next[lo] <= hi )
                    lo = next[lo];

                  dp[i][ hi * V[i] + j ] = value[lo] + hi;
                from[i][ hi * V[i] + j ] = hi - lo;
            }
        }

    printf( "%d\n", dp[N][money] );

    for ( i = N; i > 0; i-- ) {
        sol[i] = from[i][money];
        money -= V[i] * sol[i];
    }

    for ( i = 1; i <= N; i++ )
        printf( i < N ? "%d " : "%d\n", sol[i] );

    fflush( stdout );

    return 0;
}
