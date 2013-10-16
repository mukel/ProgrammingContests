/*
Alfonso Alfonso Peterssen
8 - 4 - 2008
USACO DEC06 Gold "Fewcoins"
*/
#include <cstdio>

const int
    MAXN = 100,
    MAXM = 15000,
    oo = 666666666;

int N, T, M, S, coins;
int h, i, j, k;
int lo, hi, sol;
int V[MAXN];
int C[MAXN];
int dp1[MAXM];
int dp2[MAXM];
int next[MAXM];
int value[MAXM];

int main() {

    scanf( "%d %d", &N, &T );
    for ( i = 0; i < N; i++ ) scanf( "%d", &V[i] );
    for ( i = 0; i < N; i++ ) scanf( "%d", &C[i] );

    for ( i = 0; i < N; i++ )
        M >?= V[i] * V[i];

    for ( i = 1; i <= M; i++ )
        dp1[i] = dp2[i] = oo;

    for ( i = 0; i < N; i++ )
        for ( j = 0; j < V[i]; j++ ) {

            S = coins = 0;
            for ( k = j; k <= M; k += V[i] ) {
                value[S++] = dp1[k] - coins;
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
                dp1[ hi * V[i] + j ] = value[lo] + hi;
            }
        }

    for ( i = 0; i < N; i++ )
        for ( j = V[i]; j <= M; j++ )
            dp2[j] <?= dp2[ j - V[i] ] + 1;

    sol = oo;
    for ( i = T; i <= M; i++ )
        sol <?= dp1[i - T] + dp2[i];

    if ( sol == oo )
        sol = -1;

    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
