/*
Alfonso Alfonso Peterssen
29 - 2 - 2008
POI 2002 Stage I "Railways"
*/
#include <cstdio>

const int
    MAXN = 70000,
    MAXSQR = 250;

int n, cap, q, i, j;
int lo, hi, cant;
int sq;
int value[MAXN];
int piece[MAXN];
int delta[MAXSQR];
int upper[MAXSQR];
int start[MAXSQR];
int end[MAXSQR];

int query( int lo, int hi ) {
    int last = piece[lo];
    int next = piece[hi];
    int res = 0;
    if ( last == next ) {
        for ( i = lo; i <= hi; i++ )
            res >?= value[i] + delta[next];
        return res;
    }
    for ( i = last + 1; i < next; i++ )
        res >?= upper[i] + delta[i];
    for ( i = lo; i <= end[last]; i++ )
        res >?= value[i] + delta[last];
    for ( i = start[next]; i <= hi; i++ )
        res >?= value[i] + delta[next];
    return res;
}

void update( int lo, int hi, int amount ) {
    int last = piece[lo];
    int next = piece[hi];
    if ( last == next ) {
        for ( i = lo; i <= hi; i++ ) {
            value[i] += amount;
            upper[next] >?= value[i];
        }
        return ;
    }
    for ( i = last + 1; i < next; i++ )
        delta[i] += amount;
    for ( i = lo; i <= end[last]; i++ )
        upper[last] >?= ( value[i] += amount );
    for ( i = start[next]; i <= hi; i++ )
        upper[next] >?= ( value[i] += amount );
}

int main() {

    scanf( "%d %d", &n, &cap );

    /* Preprocess */
    for ( sq = 0; sq * sq < n; sq++ );
    for ( i = 0; i < sq; i++ ) {
        start[i] = i * sq;
        end[i] = start[i] + sq - 1;
        for ( j = 0; j < sq; j++ )
            piece[i * sq + j] = i;
    }

    scanf( "%d", &q );
    while ( q-- ) {
        scanf( "%d %d %d", &lo, &hi, &cant );
        lo--; hi--;
        if ( query( lo, hi - 1 ) + cant <= cap ) {
            update( lo, hi - 1, cant );
            printf( "T\n" );
        } else
            printf( "N\n" );
    }

    return 0;
}
