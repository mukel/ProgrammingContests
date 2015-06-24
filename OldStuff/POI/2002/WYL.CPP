/*
Alfonso Alfonso Peterssen
*/
#include <cstdio>

const int MAXN = 20;

int n, i, j, sol;
int limit;
bool mark[MAXN];
int order[MAXN], mod[MAXN];

int gcd( int a, int b ) {
    while ( a && b ) if ( a %= b ) b %= a;
    return a + b;
}

int main() {

    scanf( "%d", &n );
    for ( i = 0; i < n; i++ ) {
        scanf( "%d", &j );
        order[j - 1] = i;
    }

    for ( i = j = 0; i < n; i++ ) {
        while ( mark[j] )
            j = ( j + 1 ) % n;
        while ( j != order[i] ) {
            do j = ( j + 1 ) % n;
                while ( mark[j] );
            mod[i]++;
        }
        mark[ order[i] ] = true;
    }

    limit = 1;
    for ( i = 1; i <= n; i++ )
        limit = limit / gcd( limit, i ) * i;

    for ( i = mod[0]; i < limit; i += n ) {
        for ( j = 1; j < n; j++ )
            if ( i % ( n - j ) != mod[j] )
                break;
        if ( j == n ) {
            printf( "%d\n", i + 1 );
            break;
        }
    }

    if ( i >= limit )
        printf( "NIE\n" );

    return 0;
}
