/*
Alfonso Alfonso Peterssen
17 - 3 - 2008
USACO MAR08 Gold "ppairing"
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair< int, int > par;

int n, c, i, x;
priority_queue< par > Q;

int main() {

    scanf( "%d %d", &n, &c );
    for ( i = 0; i < c; i++ ) {
        scanf( "%d", &x );
        if ( x > 0 )
            Q.push( make_pair( x, i + 1 ) );
    }

    while ( !Q.empty() ) {
        par one = Q.top(); Q.pop();
        par two = Q.top(); Q.pop();
        printf( "%d %d\n", one.second, two.second );
        if ( --one.first > 0 ) Q.push( one );
        if ( --two.first > 0 ) Q.push( two );
    }

    fflush( stdout );

    return 0;
}
