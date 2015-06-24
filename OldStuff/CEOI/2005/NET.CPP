/*
Alfonso Alfonso Peterssen
12 - 3 - 2008
CEOI 2005 "Nets"
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV = 100000;

int V, E, A, B, x, i;
int u, v;
int cantA, cantB;
bool isA[MAXV];
bool isB[MAXV];
int low[MAXV];
int dfsnum[MAXV];
int discover_time;
vector< int > G[MAXV];
vector< pair< int, int > > sol;

    void dfs( int node, int father = -1 ) {

        cantA += isA[node];
        cantB += isB[node];
        dfsnum[node] = low[node] = ++discover_time;

        for ( int i = 0; i < G[node].size(); i++ ) {
            int next = G[node][i];
            if ( next == father ) continue;

            if ( !dfsnum[next] ) {
                int tmpA = cantA;
                int tmpB = cantB;

                dfs( next, node );
                low[node] <?= low[next];

                if ( low[next] > dfsnum[node] ) {
                    tmpA = cantA - tmpA;
                    tmpB = cantB - tmpB;
                    if ( tmpA == 0 || tmpA == A ||
                         tmpB == 0 || tmpB == B )
                    sol.push_back( make_pair( node, next ) );
                }
            } else
                low[node] <?= dfsnum[next];
        }
    }

int main() {

    scanf( "%d %d %d %d", &V, &E, &A, &B );
    for ( i = 0; i < A; i++ )
        scanf( "%d", &x ), isA[--x] = true;
    for ( i = 0; i < B; i++ )
        scanf( "%d", &x ), isB[--x] = true;
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( v );
        G[v].push_back( u );
    }

    dfs( 0 );

    printf( "%d\n", sol.size() );
    for ( i = 0; i < sol.size(); i++ ) {
        u = sol[i].first;
        v = sol[i].second;
        u++; v++;
        printf( "%d %d\n", u, v );
    }

    return 0;
}
