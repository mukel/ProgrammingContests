/*
Alfonso2 Peterssen
15 - 6 - 2008
IOI 2005 "Garden"
*/
#include <cstdio>
#include <cstring>

#define FOR( i, s, e ) \
    for ( int i = (s); i <= (e); i++ )

const int MAXC = 300;

int F, C, N, K;
int sol;
int x, y;
int A[MAXC][MAXC];
int B[MAXC][MAXC];
int T[MAXC][MAXC];
int L[MAXC];
int R[MAXC];

int sum( int x1, int y1, int x2, int y2 ) {
    x1--; y1--;
    return T[x2][y2] - T[x1][y2] - T[x2][y1] + T[x1][y1];
}

int solve( int A[][MAXC], int F, int C ) {

    FOR( i, 1, F )
    FOR( j, 1, C )
        T[i][j] = A[i][j] + T[i - 1][j] +
                  T[i][j - 1] - T[i - 1][j  - 1];

    memset( L, 63, sizeof( L ) );
    memset( R, 63, sizeof( R ) );

    FOR( i, 1, F )
    FOR( j, 1, i )
        for ( int lo = 1, hi = 1; lo <= C; lo++ ) {
            while ( hi < C && sum( j, lo, i, hi ) < K ) hi++;
            if ( sum( j, lo, i, hi ) == K ) {
                int per = 2 * ( i - j + 1 ) + 2 * ( hi - lo + 1 );
                L[i] <?= per;
                R[j] <?= per;
            }
        }

    FOR( i, 1, F ) {
        L[i] <?= L[i - 1];
        R[F-i+1] <?= R[F-i+2];
    }

    FOR( i, 1, F - 1 )
        sol <?= L[i] + R[i + 1];
}

int main() {

    scanf( "%d %d", &F, &C );
    scanf( "%d %d", &N, &K );
    FOR( i, 1, N ) {
        scanf( "%d %d", &x, &y );
        A[x][y]++;
        B[y][x]++;
    }

    sol = 1000000;
    solve( A, F, C );
    solve( B, C, F );

    if ( sol == 1000000 )
         printf( "NO\n" );
    else printf( "%d\n", sol );

    return 0;
}

