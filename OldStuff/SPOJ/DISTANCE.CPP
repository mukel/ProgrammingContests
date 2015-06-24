/*
Alfonso Alfonso Peterssen
*/
#include <cstdio>
#include <algorithm>

using std::abs;

const int
    MAXN = 100000,
    MAXD = 6;

#define REP( i, n ) \
    for ( i = 0; i < (n); i++ )

int N, D, i, j, k, sol;
int a, b, dist;
int sum[MAXN];
int vec[MAXN][MAXD];

int main() {

    scanf( "%d %d", &N, &D );
    REP( i, N )
        REP( j, D )
            scanf( "%d", &vec[i][j] );

    REP( i, 1 << ( D - 1 ) ) {

        REP( j, N )
            for ( k = sum[j] = 0; k < D; k++ )
                if ( i & ( 1 << k ) )
                     sum[j] += vec[j][k];
                else sum[j] -= vec[j][k];

        a = b = dist = 0;
        REP( j, N ) if ( sum[j] < sum[a] ) a = j;
        REP( j, N ) if ( sum[j] > sum[b] ) b = j;

        REP( j, D )
            dist += abs( vec[a][j] - vec[b][j] );

        sol >?= dist;
    }

    printf( "%d\n", sol );

    return 0;
}
