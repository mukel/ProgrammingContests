/*
Alfonso Alfonso Peterssen
1 - 5 - 2008
TASK: NUMB
Very easy!!!
*/
#include <cstdio>
#include <queue>

using std::queue;

const int
    MAXN = 10,
    LIMIT = 1 << 15;

int digits( int x ) {
    if ( x == 0 )
        return 0;
    int res = 1;
    while ( x ) {
        res *= x % 10;
        x /= 10;
    }
    return res;
}

int value;
bool __mark[LIMIT * 2];
bool *mark = __mark + LIMIT;

int main() {

    for ( int i = 0; i < MAXN; i++ ) {

        scanf( "%d", &value );
        memset( __mark, 0, sizeof( __mark ) );

        queue< int > Q;
        for ( Q.push( value ); !Q.empty(); Q.pop() ) {

            int top = Q.front();
            int d = digits( top );
            int x = top + d;
            int y = top - d;

            if ( x == value || y == value )
                break;
            if ( x < LIMIT && !mark[x] ) {
                mark[x] = true;
                Q.push( x );
            }
            if ( y > -LIMIT && !mark[y] ) {
                mark[y] = true;
                Q.push( y );
            }
        }

        printf( "%d", ( int )!Q.empty() );
    }

    printf( "\n" );

    return 0;
}

