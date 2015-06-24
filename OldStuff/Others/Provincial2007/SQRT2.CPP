/*
Alfonso Alfonso Peterssen
SQRT2
*/
#include <cstdio>
using namespace std;

const int
    MAXLEN = 130000,
    LIMIT = 60000;

struct big_num {
    int size;
    int digit[MAXLEN];
};

    void sum( const big_num &x, const big_num &y, big_num &z ) {

        int i, r = 0, t;
        
        int len = ( x.size <? y.size );
        for ( i = 0; i < len; i++ ) {
            t = x.digit[i] + y.digit[i] + r;
            z.digit[i] = t % 10;
            r = t / 10;
        }

        if ( x.size >= y.size ) {
            len = x.size;
            for ( ; i < len; i++ ) {
                t = x.digit[i] + r;
                z.digit[i] = t % 10;
                r = t / 10;
            }
        }
        else {
            len = y.size;
            for ( ; i < len; i++ ) {
                t = y.digit[i] + r;
                z.digit[i] = t % 10;
                r = t / 10;
            }
        }
        
        z.size = len;
        if ( r > 0 )
            z.digit[ z.size++ ] = r;
    }

    void sum( const big_num &x, const int y, big_num &z ) {

        int i, r = 0, t;

        z.size = x.size;
        for ( i = 0; i < z.size; i++ ) {
            t = x.digit[i] + r;
            if ( i == 0 ) t += y;
            z.digit[i] = t % 10;
            r = t / 10;
            if ( r == 0 ) return;
        }
        if ( r > 0 )
            z.digit[ z.size++ ] = r;
    }

    void mul( const big_num &x, const int y, big_num &z ) {

        int i, r = 0, t;

        z.size = x.size;
        for ( i = 0; i < z.size; i++ ) {
            t = ( x.digit[i] * y ) + r;
            z.digit[i] = t % 10;
            r = t / 10;
        }

        for ( ; r > 0; r /= 10 )
            z.digit[ z.size++ ] = r % 10;
    }

    void set( big_num &x, int y ) {
        x.size = 0;
        for ( ; y; y /= 10 )
            x.digit[ x.size++ ] = y % 10;
    }

    void set( big_num &x, const big_num &y ) {
        x.size = y.size;
        for ( int i = 0; i < x.size; i++ )
            x.digit[i] = y.digit[i];
    }

    void shift( big_num &x, const int y ) {
        int i;
        x.size += y;
        for ( i = x.size - 1; i >= y; i-- )
            x.digit[i] = x.digit[i - y];
        for ( ; i >= 0; i-- )
            x.digit[i] = 0;
    }

    void print( const big_num &x ) {
        for ( int i = x.size - 1; i >= 0; i-- )
            printf( "%d", x.digit[i] );
        printf( "\n" );
    }

int i, j, k, dig;
int lo, hi, mid;
big_num root, sqr, tmp;

    bool ok( int dig ) {
        mul( root, 2 * dig, tmp );
        sum( tmp, dig * dig, tmp );
        sum( sqr, tmp, tmp );
        return tmp.digit[ tmp.size - 1 ] < 2;
    }

int main() {

    /* Init */
    set( root, 1 );
    set( sqr, 1 );
    
    printf( "1." );

    for ( i = 0; i < LIMIT; i++ ) {

        shift( root, 1 );
        shift( sqr, 2 );

        lo = 0; hi = 9;
        while ( lo <= hi ) {
            mid = ( lo + hi ) / 2;
            if ( ok( mid ) )
                 lo = mid + 1;
            else hi = mid - 1;
        }

        dig = lo - 1;

        mul( root, 2 * dig, tmp );
        sum( tmp, dig * dig, tmp );
        sum( tmp, sqr, sqr );
        
        root.digit[0] = dig;
        
        printf( "%d", dig );
    }
    
    printf( "\n" );

    return 0;
}
