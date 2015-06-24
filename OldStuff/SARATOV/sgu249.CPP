/*
Alfonso2 Peterssen
16 - 5 - 2008
Saratov #249 "Matrix"
*/
#include <cstdio>

const int MAXC = 20;

#define REP( i, n ) \
    for ( int i = 0; i < (n); i++ )

int F, C, sz;
int seq[1 << MAXC];

int main() {

    scanf( "%d %d", &F, &C );

    seq[sz++] = 0;    
    REP( i, F >? C ) {
        REP( j, sz )
            seq[sz + j] = ( 1 << i ) + seq[sz - j - 1];
        sz *= 2;
    }

    REP( i, 1 << F )
    REP( j, 1 << C )
        printf( j < ( 1 << C ) - 1 ? "%d " : "%d\n",
                ( seq[i] << C ) + seq[j] );

    return 0;
}
