/*
Alfonso Alfonso Peterssen
28 - 2 - 2008
SPOJ #677 "A place for the brewery"
*/
#include <cstdio>

const int MAXN = 10000;

int t, n, i, middle;
int beer[MAXN], dist[MAXN + 1];
long long l, r, value, sol;

    int last( int a, int b ) {
        return ( a >= b ) ? dist[a] - dist[b] : dist[a] + dist[n] - dist[b];
    }

    int next( int a, int b ) {
        return ( a <= b ) ? dist[b] - dist[a] : dist[b] + dist[n] - dist[a];
    }

int main() {

    scanf( "%d", &t );
    while ( t-- ) {

        value = l = r = 0;
        middle = -1;

        scanf( "%d", &n );
        for ( i = 0; i < n; i++ ) {
            scanf( "%d %d", &beer[i], &dist[i + 1] );
            dist[i + 1] += dist[i];
        }

        /* First city */
        for ( i = 0; i < n; i++ ) {
            value += ( last( 0, i ) <? next( 0, i ) ) * beer[i];
            if ( last( 0, i ) < next( 0, i ) ) {
                l += beer[i];
                if ( middle == -1 )
                    middle = i;
            } else
                r += beer[i];
        }

        sol = value;

        l += beer[0];
        r -= beer[0];

        /* "Sweep" cities */
        for ( i = 1; i < n; i++ ) {
            value += l * ( dist[i] - dist[i - 1] );
            value -= r * ( dist[i] - dist[i - 1] );
            while ( next( i, middle ) < last( i, middle ) ) {
                l -= beer[middle];
                r += beer[middle];
                value = value - beer[middle] *
                        ( last( i, middle ) - next( i, middle ) );
                middle = ( middle + 1 ) % n;
            }
            l += beer[i];
            r -= beer[i];
            sol <?= value;
        }

        printf( "%Ld\n", sol );
    }

    return 0;
}
