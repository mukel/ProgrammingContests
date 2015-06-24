/*
Alfonso Alfonso Peterssen
28 - 2 - 2008
POI 2002 Stage I "Castle"
*/
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int
    MAXV = 100,
    MAXMONEY = 1000 + 1;

typedef pair< int, int > par;

int V, E, start, end, money;
int i, j, u, v, len;
int chamber[MAXV];
int sol[MAXMONEY];
bool mark[MAXV][MAXMONEY];
int from[MAXV][MAXMONEY];
vector< int > G[MAXV];
queue< par > Q;

int main() {

    scanf( "%d %d", &V, &E );
    scanf( "%d %d", &start, &end );
    start--; end--;
    scanf( "%d", &money );

    for ( i = 0; i < V; i++ )
        scanf( "%d", &chamber[i] );

    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( v );
        G[v].push_back( u );
    }

    /* BFS */
    mark[start][ chamber[start] ] = true;
    Q.push( make_pair( start, chamber[start] ) );
    
    while ( !Q.empty() ) {

        int node = Q.front().first;
        int cost = Q.front().second;
        Q.pop();
        
        for ( i = 0; i < G[node].size(); i++ ) {
            int next = G[node][i];
            int newcost = cost + chamber[next];
            
            if ( newcost > money )
                continue;
                
            if ( !mark[next][newcost] ) {
                mark[next][newcost] = true;
                from[next][newcost] = node;
                Q.push( make_pair( next, newcost ) );
            }
        }
    }
    
    i = end;
    j = money;
    while ( i != start || j != chamber[i]  ) {
        sol[len++] = i + 1;
        int t = i;
        i = from[i][j];
        j -= chamber[t];
    }
    
    sol[len++] = start + 1;

    while ( len-- )
        printf( len ? "%d " : "%d\n", sol[len] );

    return 0;
}
