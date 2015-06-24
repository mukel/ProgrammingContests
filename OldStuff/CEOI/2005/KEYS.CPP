/*
Alfonso Alfonso Peterssen
6 - 3 - 2008
CEOI 2005 "Keys"
*/
#include <cstdio>
#include <algorithm>

using std::sort;

const int MAXC = 1000000 + 1;

int n, c, x, len;
int last[MAXC];
int sol[MAXC];

bool comp( const int &i, const int &j ) {
    return last[i] < last[j];
}

int main() {

    scanf( "%d %d", &c, &n );
    while ( n-- ) {
        scanf( "%d", &x );
        if ( !last[x] ) sol[len++] = x;
        last[x] = n + 1;
    }
    
    sort( sol, sol + len, comp );

    printf( "%d\n", len );
    while ( len-- )
        printf( len ? "%d " : "%d\n", sol[len] );

    return 0;
}
