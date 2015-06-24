/*
Alfonso2 Peterssen
15 - 4 - 2008
TASK: NUMBERS
O( 32 * n )
*/
#include <cstdio>
#include <algorithm>
#include <numeric>

using namespace std;

const int MAXN = 250000;

typedef pair< int, int > par;

#define REP( i, n ) \
    for ( i = 0; i < (n); i++ )

int N, i, j, k;
int unions;
int sol[MAXN];
par a[MAXN];
par b[MAXN];
bool useda[MAXN];
bool usedb[MAXN];

int main() {

    scanf( "%d", &N );
    REP( i, N ) scanf( "%d", &a[i].first ), a[i].second = i;
    REP( i, N ) scanf( "%d", &b[i].first ), b[i].second = i;
    
    sort( a, a + N, greater< par >() );
    sort( b, b + N, greater< par >() );
    
    REP( i, 32 ) {
        k = 0;
        REP( j, N ) {
            if ( usedb[j] ) continue;
            while ( k < N && ( useda[k] || a[k].first > b[j].first ) )
                k++;
            if ( k < N && a[k].first == b[j].first ) {
                /* join */
                unions++;
                sol[ a[k].second ] = b[j].second + 1;
                useda[k] = true;
                usedb[j] = true;
            }
        }
        /* Divide by 2 */
        REP( j, N )
            b[j].first /= 2;
    }
    
    if ( unions == N ) {
        REP( i, N ) printf( i == N - 1 ? "%d\n" : "%d ", sol[i] );
    } else
        printf( "-1\n" );
        
    fflush( stdout );
    
    return 0;
}
