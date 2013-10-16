/*
Alfonso Alfonso Peterssen
TASK: TOOTH
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int
    oo = 1000000000,
    MAXN = 700;

typedef pair< int, int > par;

int n, m, money, i, j, k;
int _dp0[MAXN], _dp1[MAXN];
int *last = _dp0;
int *next = _dp1;
par from[MAXN][MAXN];
int dp[MAXN][MAXN];
int cost[MAXN];
vector< par > vec[MAXN];
int back[MAXN];

    void print( int muela, int kk ) {
                int back = from[muela][kk].first;
        int cant = from[muela][kk].second;
        //printf ( "%d %d -> %d\n", muela , kk, back );
        if ( muela <= 0 ) return ;

        for ( int i = 0; i <= cant; i++ )
            printf( "%d ", vec[kk][i].second + 1 );

        print( muela - cant - 1, back );
    }

int main() {

    scanf( "%d %d %d", &n, &m, &money );
    for ( i = 0; i < m; i++ )
        scanf( "%d", &cost[i] );

    for ( i = 0; i < n; i++ ) {
        int val, id;
        scanf( "%d %d", &val, &id );
        vec[id - 1].push_back( make_pair( val, i ) );
    }

    /* ... */
    fill( next, next + n + 1, oo );
    next[0] = 0;
    for ( i = 0; i < m; i++ ) {
        swap( last, next );
        for ( j = 0; j <= n; j++ )
            next[j] = last[j];
        sort( vec[i].begin(), vec[i].end() );

        for ( k = n; k > 0; k-- ) {
        int val = 0;
        for ( j = 0; j < vec[i].size(); j++ ) {
            val += vec[i][j].first;
                if ( k - j - 1 < 0 ) continue;
                if ( last[k - j - 1] + val + cost[i] < next[k] ) {
                    next[k] = last[k - j - 1] + val + cost[i];
                    from[k][i] = make_pair( back[k - j - 1], j );
                    back[k] = i;
                    dp[k][i] = next[k];
                }
            }
        }
    }

    for ( i = n; i >= 0; i-- )
        if ( next[i] <= money )
            break;
            
    printf( "%d\n", i );
    
    for ( j = 0; j < m; j++ )
        if ( dp[i][j] == next[i] )
            break;
    
    print( i, j );
    printf( "\n" );

    fflush( stdout );

    return 0;
}
