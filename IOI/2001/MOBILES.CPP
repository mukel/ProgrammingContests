/*
Alfonso Alfonso Peterssen
25 - 2 - 2008
IOI 2001 Day 1 Task "Mobiles"
*/
#include <cstdio>

const int MAXC = 1200;

int query, limit;
int x1, y1, x2, y2, value;
int T[MAXC][MAXC];

int lobit( int x ) { return x & -x; }

int update( int x, int y, int amount ) {
    for ( ; x <= limit; x += lobit( x ) )
        for ( int i = y; i <= limit; i += lobit( i ) )
        T[x][i] += amount;
}

int sum( int x, int y ) {
    int sum = 0;
    for ( ; x > 0; x -= lobit( x ) )
        for ( int i = y; i > 0; i -= lobit( i ) )
        sum += T[x][i];
    return sum;
}

int sum( int x1, int y1, int x2, int y2 ) {
    return sum( x2, y2 ) -
           sum( x1 - 1, y2 ) - sum( x2, y1 - 1 ) +
           sum( x1 - 1, y1 - 1 );
}

int main() {

    while ( query != 3 ) {

        scanf( "%d", &query );

        if ( query == 0 )
            scanf( "%d", &limit );

        if ( query == 1 ) {
            scanf( "%d %d %d", &x1, &y1, &value );
            x1++; y1++;
            update( x1, y1, value );
        }

        if ( query == 2 ) {
            scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
            x1++; y1++;
            x2++; y2++;
            printf( "%d\n", sum( x1, y1, x2, y2 ) );
        }
    }

    fflush( stdout );

    return 0;
}
