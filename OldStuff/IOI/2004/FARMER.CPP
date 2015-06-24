/*
Alfonso2 Peterssen
6 - 10 - 2007
IOI 2004 "Farmer"
*/
#include <cstdio>
#include <algorithm>

using std::sort;

const int
    MAXQ = 160000,
    MAXFS = 2000;

int T, Q, S, F;
int sum, sol;
int i, j, k;
int field[MAXFS];
int strip[MAXFS];
bool mark[MAXQ];

int main() {

    scanf( "%d %d %d", &Q, &F, &S );

    for ( i = 0; i < F; i++ ) {
        scanf( "%d", &field[i] );
        sum += field[i];
    }

    for ( i = 0; i < S; i++ )
        scanf( "%d", &strip[i] );

    if ( sum < Q ) {
        sort( strip, strip + S );
        for ( i = 0; i < S && sum < Q; i++ )
            sum += strip[S - i - 1];
        sol = Q - i;
    }
    else if ( sum > Q ) {
        mark[0] = true;
        sort( field, field + F );
        for ( i = k = 0; i < F && !mark[Q]; i++ ) {
            for ( j = k; j >= 0; j-- )
                if ( mark[j] )
                    mark[ j + field[i] ] = true;
            if ( k < Q )
                k += field[i];
        }
        sol = Q - !mark[Q];
    }
    else sol = Q;

    printf( "%d\n", sol );

    return 0;
}
