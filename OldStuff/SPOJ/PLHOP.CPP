/*
Alfonso2 Peterssen
3 - 7 - 2008
SPOJ #698 "Plane Hopping"
*/
#include <cstdio>
#include <cstring>

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

typedef long long int64;

const int
    MAXV = 200,
    MAXLOG = 32;

const int64 oo = (int64)1e17;

int T, V, L;
int next, last;
int64 best[MAXV];
int64 dist[2][MAXV];
int64 D[MAXLOG][MAXV][MAXV];

int main() {

    scanf( "%d", &T );
    while ( T-- ) {

        scanf( "%d %d", &L, &V );
        REP( i, V )
        REP( j, V )
            scanf( "%d", &D[0][i][j] );

        for ( int d = 1; ( 1 << d ) < L + V; d++ ) {

            REP( i, V )
            REP( j, V )
                D[d][i][j] = oo;

            REP( k, V )
            REP( i, V )
            REP( j, V )
                D[d][i][j] <?= D[d - 1][i][k] + D[d - 1][k][j];
        }

        REP( i, V ) {

            REP( k, V )
                best[k] = oo;

            // in radom graphs 5 should be enough
            REP( j, 5 <? V ) {

                next = 0; last = 1;
                REP( k, V ) dist[next][k] = oo;
                dist[next][i] = 0;

                int len = L + j;
                for ( int d = 0; ( 1 << d ) <= len; d++ )
                    if ( len & ( 1 << d ) ) {
                        last = next;
                        next = 1 - next;
                        REP( k, V )
                            dist[next][k] = oo;
                        REP( a, V )
                        REP( b, V )
                            dist[next][a] <?= dist[last][b] + D[d][b][a];
                    }

                REP( a, V )
                    best[a] <?= dist[next][a];
            }

            REP( j, V )
                printf( "%I64d ", best[j] );
            printf( "\n" );
        }
    }

    return 0;
}
