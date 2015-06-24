/*
Alfonso Alfonso Peterssen
6 - 12 - 2007
SPOJ #51 "Fake Tournament"
*/
#include <cstdio>
#include <stack>
using namespace std;

const int MAXN = 1000;

int T, N, i, j, k;
int SCC, discover_time;
int dfsnum[MAXN], low[MAXN];
bool in_stack[MAXN];

bool has_parent[MAXN];
int cant[MAXN], comp[MAXN];
int sz[MAXN];
int ls[MAXN][MAXN];
stack< int > S;

    void dfs( int x ) {

        int i, y;
        S.push( x );
        in_stack[x] = true;
        dfsnum[x] = low[x] = ++discover_time;

        for ( i = 0; i < sz[x]; i++ )
            if ( !dfsnum[ y = ls[x][i] ] ) {
                dfs( y );
                low[x] <?= low[y];
            } else
                if ( in_stack[y] )
                    low[x] <?= dfsnum[y];

        if ( dfsnum[x] == low[x] ) {
            do {
                i = S.top(); S.pop();
                in_stack[i] = false;
                cant[SCC]++;
                comp[i] = SCC;
            } while ( i != x );
            SCC++;
        }
    }

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        /* Init */
        SCC = discover_time = 0;
        memset( cant, 0, sizeof( cant ) );
        memset( sz, 0, sizeof( sz ) );
        memset( dfsnum, 0, sizeof( dfsnum ) );
        memset( has_parent, 0, sizeof( has_parent ) );

        scanf( "%d", &N );

        for ( i = 0; i < N; i++ ) {
            int x;
            scanf( "%d", &x );
            for ( j = 0; j < x; j++ ) {
                scanf( "%d", &k ); k--;
                ls[k][ sz[k]++ ] = i;
            }
        }

        for ( i = 0; i < N; i++ )
            if ( !dfsnum[i] ) dfs( i );

        for ( i = 0; i < N; i++ )
            for ( j = 0; j < sz[i]; j++ )
                if ( comp[i] != comp[ ls[i][j] ] )
                    has_parent[ comp[ ls[i][j] ] ] = true;

        for ( i = 0; i < SCC; i++ )
            if ( !has_parent[i] ) break;
            
        int sol = cant[i];
            
        for ( i++ ;i < SCC; i++ )
            if ( !has_parent[i] ) break;

        if ( i < SCC ) sol = 0;
        
        printf( "%d\n", sol );
    }

    return 0;
}
