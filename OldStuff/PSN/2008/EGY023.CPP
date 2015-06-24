/*
Alfonso Alfonso Peterssen
TASK: GAP
*/
#include <cstdio>

int n, lo, hi;

bool prime( int x ) {
    for ( int i = 2; i * i <= x; i++ )
        if ( x % i == 0 )
            return 0;
    return 1;
}

int main() {

    scanf( "%d", &n );
    for ( lo = n; !prime( lo ); lo-- );
    for ( hi = n; !prime( hi ); hi++ );
    printf( "%d\n", hi - lo );
    fflush( stdout );

    return 0;
}
