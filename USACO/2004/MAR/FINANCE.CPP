/*
Alfonso Alfonso Peterssen
8 - 4 - 2008
USACO MAR04 Gold "Moo University -- Financial Aid"
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int
    MAXN = 100000,
    oo = 666666666;

typedef pair< int, int > par;

int N, C, money;
int i, sum, sol;
int next[MAXN];
int last[MAXN];
par cows[MAXN];
priority_queue< int > Q;

int main() {

    scanf( "%d %d %d", &N, &C, &money );

    for ( i = 0; i < C; i++ )
        scanf( "%d %d", &cows[i].first, &cows[i].second );

    sort( cows, cows + C );

    /* From left */
    sum = 0;
    for ( i = 0; i < C; i++ ) {
        sum += cows[i].second;
        Q.push( cows[i].second );
        if ( Q.size() > N / 2 ) {
            sum -= Q.top();
            Q.pop();
        }
        last[i] = ( Q.size() == N / 2 ? sum : oo );
    }

    /* Clear */
    while ( !Q.empty() )
        Q.pop();

    /* From right */
    sum = 0;
    for ( i = C - 1; i >= 0; i-- ) {
        sum += cows[i].second;
        Q.push( cows[i].second );
        if ( Q.size() > N / 2 ) {
            sum -= Q.top();
            Q.pop();
        }
        next[i] = ( Q.size() == N / 2 ? sum : oo );
    }

    sol = -1;
    for ( i = 1; i < C - 1; i++ )
        if ( last[i - 1] +
             next[i + 1] +
             cows[i].second <= money  )
            sol >?= cows[i].first;

    printf( "%d\n", sol );
    fflush( stdout );

    return 0;
}
