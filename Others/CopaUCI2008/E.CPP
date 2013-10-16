/*
Alfonso2 Peterssen
29 - 5 - 2008
Copa UCI 2008 "Copiando Libros"
*/
#include <cstdio>
#include <cstring>
#include <cassert>

#define FOR( i, s, e ) \
    for ( int i = s; i <= (e); i++ )

const int MAXN = 1000;

int T, N, K;
int lo, hi, mid;
int S[MAXN];
bool slash[MAXN];

bool check( int value ) {

    int i, j, cant = 0;

    memset( slash, 0, sizeof( slash ) );
    for ( i = N; i > 0; i = j + 1 ) {
        for ( j = i - 1; j >= 0 && S[i] - S[j] <= value; j-- );
        if ( j == i - 1 )
           return 0;
        slash[j + 1] = true;
        cant++;
    }

    for ( i = 1; i <= N && cant < K; i++ )
        if ( !slash[i] ) {
            slash[i] = true;
            cant++;
        }

    return cant <= K;
}

int main() {

    scanf( "%d", &T );
    while ( T-- )  {

        scanf( "%d %d", &N, &K );
        FOR( i, 1, N ) {
            scanf( "%d", &S[i] );
            S[i] += S[i - 1];
        }

        lo = 0;
        hi = 1000000000;
        while ( lo <= hi ) {
            long long mid = ( lo + hi ) / 2;
            if ( check( mid ) )
                 hi = mid - 1;
            else lo = mid + 1;
        }

        assert( check( hi + 1 ) );
        FOR( i, 1, N ) {
            printf( "%d", S[i] - S[i - 1] );
            if ( slash[i] ) printf( " /" );
            printf( i < N ? " " : "\n" );
        }
    }

    return 0;
}
