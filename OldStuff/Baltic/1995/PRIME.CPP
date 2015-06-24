/*
Alfonso2 Peterssen
8 - 5 - 2008
Baltic 1995 TASK: PRIME
*/
#include <cstdio>

const int MAXP = 60000;

typedef long long int64;

int N, P, i, j;
bool mark[MAXP];
int prime[MAXP];

bool is_prime( int64 x ) {
    for ( int64 i = 2; i * i <= x; i++ )
        if ( x % i == 0 )
            return false;
    return true;
}

int64 join( int64 a, int64 b ) {
    for ( int64 x = b; x; x /= 10, a *= 10 );
    return a + b;
}

int main() {

    for ( i = 2; i * i < MAXP; i++ )
        if ( !mark[i] )
            for ( j = i * i; j < MAXP; j += i )
                mark[j] = true;

    for ( i = 2; i < MAXP; i++ )
        if ( !mark[i] )
            prime[P++] = i;

    scanf( "%d", &N );
    for ( i = 0; i < P - 1; i += 2  ) {
        int64 x = join( prime[i], prime[i + 1] );
        if ( is_prime( x ) )
            if ( --N == 0 ) {
                printf( "%I64d\n", x );
                return 0;
            }
    }

    return 0;
}
