/*
Alfonso2 Peterssen
22 - 7 - 2008
APIO 2007 "Mobiles"
*/
#include <cstdio>

const int MAXN = 200000;

int N, sol;
int L[MAXN];
int R[MAXN];
int lo[MAXN], hi[MAXN];

int main() {

    scanf( "%d", &N );
    for ( int i = 1; i <= N; i++ ) {
        scanf( "%d %d", &L[i], &R[i] );
        if ( L[i] == -1 ) L[i] = 0;
        if ( R[i] == -1 ) R[i] = 0;
    }

    for ( int i = N; i >= 1; i-- ) {
        int l = L[i];
        int r = R[i];
        if ( hi[r] > lo[l] ) sol++; // swap L[i], R[i]
        lo[i] = ( lo[l] <? lo[r] ) + 1;
        hi[i] = ( hi[l] >? hi[r] ) + 1;
        if ( ( lo[l] != hi[l] &&
               lo[r] != hi[r] ) ||
             ( hi[i] - lo[i] > 1 ) ) {
            printf( "-1\n" );
            return 0;
        }
    }

    printf( "%d\n", sol );

    return 0;
}
