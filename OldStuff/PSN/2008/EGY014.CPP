/*
Alfonso Alfonso Peterssen
23 - 2 - 2008
IOI 2007 Day 0 Task "Fish"
*/
#include <cstdio>

const int MAXN = 100000;

int N, i, lo, hi, mid;
int dist[MAXN], fish[MAXN];

    bool check( int value ) {

        int carry = 0;
        bool debt = false;

        for ( int i = 0; i < N; i++ ) {
            if ( i != 0 )
                carry -= dist[i] - dist[i - 1];
            if ( !debt && carry < 0 )
                carry = 0;
            carry += fish[i] - value;
            debt = ( carry < 0 );
        }

        return !debt;
    }

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < N; i++ ) {
        scanf( "%d %d", &dist[i], &fish[i] );
        hi >?= fish[i];
    }

    while ( lo <= hi ) {
        mid = ( lo + hi ) / 2;
        if ( check( mid ) )
             lo = mid + 1;
        else hi = mid - 1;
    }

    printf( "%d\n", lo - 1 );

    return 0;
}
