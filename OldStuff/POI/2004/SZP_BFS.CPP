/*
Alfonso Alfonso Peterssen
3 - 3 - 2008
POI 2004 Stage I "Spies"
Using BFS
*/
#include <cstdio>
#include <queue>

using std::queue;

const int MAXN = 1000000;

int n, i, sol;
int sh[MAXN];
int in_degree[MAXN];
bool mark[MAXN];
queue< int > Q;

int main() {

    scanf( "%d", &n );
    for ( i = 0; i < n; i++ ) {
        scanf( "%d", &sh[i] );
        in_degree[ --sh[i] ]++;
    }

    for ( i = 0; i < n; i++ )
        if ( !in_degree[i] )
            Q.push( i );

    for ( ; !Q.empty(); Q.pop() ) {
        int u = Q.front();
        if ( !mark[u] && !mark[ sh[u] ] ) {
            sol++;
            mark[u] = mark[ sh[u] ] = true;
            int v = sh[ sh[u] ];
            if ( !mark[v] && --in_degree[v] == 0 )
                Q.push( v );
        }
    }

    for ( i = 0; i < n; i++ ) {
        int u = i;
        while ( !mark[u] && !mark[ sh[u] ] ) {
            sol++;
            mark[u] = mark[ sh[u] ] = true;
            u = sh[ sh[u] ];
        }
    }

    printf( "%d\n", sol  );

    return 0;
}
