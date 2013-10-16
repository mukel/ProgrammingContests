/*
Alfonso Alfonso Peterssen
24 - 3 - 2008
USACO MAR06 Silver "Water Slides"
*/
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 100000;

int V, E, i, j, sol;
int u, v;
int pos[MAXN];
int degree[MAXN];
priority_queue< int > P, Q;

int main() {

    scanf( "%d %d", &V, &E );
    for ( i = 0; i < V; i++ )
        scanf( "%d", &pos[i] );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        degree[u]++;
        degree[v]--;
    }

    for ( i = 0; i < V; i++ ) {
        for ( j = 0; j < degree[i]; j++ ) P.push( pos[i] );
        for ( j = 0; j > degree[i]; j-- ) Q.push( pos[i] );
    }

    while ( !Q.empty() && !P.empty() ) {
        sol += abs( P.top() - Q.top() );
        P.pop();
        Q.pop();
    }

    printf( "%d\n", sol );

    return 0;
}
