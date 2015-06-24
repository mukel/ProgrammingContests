/*
Alfonso Alfonso Peterssen
28 - 2 - 2008
POI 2002 Stage II "Ski Resort"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int
    MAXV = 5000,
    MAXMONEY = 2000;

typedef pair< int, int > par;

int V, S, E, B, i, j;
int u, v, w;
int next, newcost;
int start, money, sol;
queue< par > Q;
bool mark[MAXV][MAXMONEY + 1];
vector< par > G[MAXV];

int main() {

    scanf( "%d %d", &V, &B );
    scanf( "%d", &S );
    for ( i = 0; i < S; i++ ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( make_pair( v, 0 ) );
    }
    
    scanf( "%d", &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d %d", &u, &v, &w );
        u--; v--;
        G[u].push_back( make_pair( v, w ) );
    }

    scanf( "%d %d", &start, &money );
    start--;

    Q.push( make_pair( start, 0 ) );
    mark[start][0] = true;
    
    while ( !Q.empty() ) {
        int node = Q.front().first;
        int cost = Q.front().second;
        Q.pop();
        for ( i = 0; i < G[node].size(); i++ ) {
            next = G[node][i].first;
            newcost = G[node][i].second + cost;
            if ( newcost > money ) continue;
            if ( next < B )
                sol >?= newcost;
            if ( !mark[next][newcost] ) {
                mark[next][newcost] = true;
                Q.push( make_pair( next, newcost ) );
            }
        }
    }

    printf( "%d\n", money - sol );

    return 0;
}
