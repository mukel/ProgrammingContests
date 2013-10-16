/*
Alfonso Alfonso Peterssen
30 - 4 - 2008
TASK: XOR
*/
#include <cstdio>

const int
    MAXN = 100000,
    MAXBITS = 64;

typedef long long int64;

int N, S, i;
int64 value, last, sol;
char st[MAXBITS];
int next[MAXN * MAXBITS][2];

void to_string( int64 value ) {
    for ( int i = 0; i < MAXBITS; i++ ) {
        st[i] = value % 2;
        value /= 2;
    }
}

void insert( int64 value ) {
    int root = 0;
    to_string( value );
    for ( int i = MAXBITS - 1; i >= 0; i-- ) {
        int &nxt = next[root][ st[i] ];
        if ( !nxt )
            nxt = ++S;
        root = nxt;
    }
}

int64 query( int64 value ) {
    int root = 0;
    int64 res = 0;
    to_string( value );
    for ( int i = MAXBITS - 1; i >= 0; i-- ) {
        int *nxt = next[root];
        st[i] ^= 1; // reverse
        if ( !nxt[ st[i] ] ) st[i] ^= 1;
        root = nxt[ st[i] ];
        res = res * 2 + st[i];
    }
    return res;
}

int main() {

    scanf( "%d", &N );

    insert( 0 );
    for ( i = 0; i < N; i++ ) {
        scanf( "%I64d", &value );
        value ^= last;
        sol >?= value ^ query( value );
        insert( value );
        last = value;
    }

    printf( "%I64d\n", sol );

    return 0;
}
