/*
Alfonso2 Peterssen
17 - 6 - 2008
IOI 2006 "PYRAMID"
*/
#include <cstdio>

#define FOR( i, s, e ) \
    for ( int i = (s); i <= (e); i++ )
#define FORD( i, e, s ) \
    for ( int i = (e); i >= (s); i-- )

const int MAXC = 1001;

int F, C, x1, y1, x2, y2;
int sol;
int T[MAXC][MAXC];
int best[MAXC][MAXC];
int value[MAXC];
int next[MAXC];

int sum( int x1, int y1, int x2, int y2 ) {
    return T[x2][y2] - T[x1][y2] - T[x2][y1] + T[x1][y1];
}

int main() {

    scanf( "%d %d %d %d %d %d", &C, &F, &y1, &x1, &y2, &x2 );
    FOR( i, 1, F )
    FOR( j, 1, C ) {
        scanf( "%d", &T[i][j] );
        T[i][j] += T[i - 1][j] + T[i][j - 1] - T[i - 1][j - 1];
    }

    FOR( i, x2 + 1, F - 1 ) {
        FOR( j, y2, C )
            value[j] = sum( i - x2, j - y2, i, j );
        FORD( j, C, y2 + 1 ) {
            int k = j + 1;
            while ( k <= C && value[k] > value[j] )
                k = next[k];
            next[j] = k;
        }
        int lo = y2 + 1;
        FOR( j, y1, C ) {
            if ( j - lo > y1 - y2 - 1 ) lo++;
            while ( next[lo] < j )
                lo = next[lo];
            best[i][j] = value[lo];
        }
    }

    FOR( i, y1, C ) {
        FOR( j, x2, F )
            value[j] = best[j][i];
        FORD( j, F, x2 + 1 ) {
            int k = j + 1;
            while ( k <= F && value[k] > value[j] )
                k = next[k];
            next[j] = k;
        }
        int lo = x2 + 1;
        FOR( j, x1, F ) {
            if ( j - lo > x1 - x2 - 1 ) lo++;
            while ( next[lo] < j )
                lo = next[lo];
            best[j][i] = value[lo];
        }
    }

    FOR( i, x1, F )
    FOR( j, y1, C )
        sol >?= sum( i - x1, j - y1, i, j ) - best[i][j];

//    printf( "%d\n", sol );
    FOR( i, x1, F )
    FOR( j, y1, C )
        if ( sum( i - x1, j - y1, i, j ) - best[i][j] == sol )
            FOR( a, i - x1 + x2 + 1, i - 1 )
            FOR( b, j - y1 + y2 + 1, j - 1 )
                if ( sum( a - x2, b - y2, a, b ) == best[i][j] ) {
                    printf( "%d %d\n", j - y1 + 1, i - x1 + 1 );
                    printf( "%d %d\n", b - y2 + 1, a - x2 + 1 );
                    fflush( stdout );
                    return 0;
                }

    return 0;
}
