/*
Alfonso2 Peterssen
3 - 5 - 2008
TASK: JPOL
*/
#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair< int, int > par;

const int
    MAXN = 60,
    LIMIT = 1000000;

int N, i;
int sum, prob;
int x, y, d, diff;
par seq[3 * MAXN];

int main() {

    scanf( "%d", &N );
    for ( i = 0; i < 3 * N; i++ ) {
        scanf( "%d", &x );
        seq[i] = par( x, i );
    }

    sort( seq, seq + 3 * N, greater< par >() );

    for ( i = 0; i < N; i++ ) {
        diff += seq[i].first - seq[i + N].first;
        sum  += seq[i].first + seq[i + N].first;
    }

    for ( i = 0; i < LIMIT; i++ ) {

        if ( abs( diff ) < sum - 1000 * N )
            break;

        x = rand() % N;
        y = rand() % N + N;
        d = diff + 2 * ( seq[y].first - seq[x].first );

        if ( abs( d ) < abs( diff ) )
             prob = 90;
        else prob = 10;

        if ( rand() % 100 < prob ) {
            swap( seq[x], seq[y] );
            diff = d;
        }
    }

    for ( i = 0; i < 3 * N; i++ )
        printf( "%d\n", seq[i].second + 1 );

    return 0;
}
