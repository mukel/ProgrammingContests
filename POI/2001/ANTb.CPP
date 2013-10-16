/*
Alfonso Alfonso Peterssen
4 - 3 - 2008
POI 2001 Stage I "Antiprime Numbers"
BFS-like search using STL::queue
*/
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;;

const int MAXP = 8;
const int prime[MAXP] = { 2, 3, 5, 7, 11, 13, 17, 19 };

typedef long long int64;
typedef pair< int, int > par;

int n, i, j, sol, max_div;
queue< par > next, last;

int main() {

    scanf( "%d", &n );

    next.push( make_pair( 1, 1 ) );
    for ( i = 0; i < MAXP; i++ ) {
        swap( last, next );
        for ( ; !last.empty(); last.pop() ) {
            int64 val = last.front().first;
            int64 div = last.front().second;
            for ( j = 1; val <= n; val *= prime[i], j++ )
                next.push( make_pair( val, div * j ) );
        }
    }

    for ( ; !next.empty(); next.pop() ) {
        int val = next.front().first;
        int div = next.front().second;
        if ( div > max_div || ( div == max_div && val < sol ) ) {
            max_div = div;
            sol = val;
        }
    }

    printf( "%d\n", sol );

    return 0;
}
