/*
Alfonso Alfonso Peterssen
4 - 4 - 2008
IOI 2003 Task "Trail Maintenance"
O( E * V )
*/
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXV = 200;

int V, E, MST, edges;
int u, v, w;
int a, b, max_cost;
int mark[MAXV];
struct edge{ int u, w; };
vector< edge > G[MAXV];

bool find( int u, int v ) {
    mark[u] = true;
    if ( u == v ) return 1;
    for ( int i = 0; i < G[u].size(); i++ )
        if ( !mark[ G[u][i].u ] &&
             find( G[u][i].u, v ) ) {
            if ( G[u][i].w > max_cost ) {
                max_cost = G[u][i].w;
                a = u;
                b = G[u][i].u;
            }
            return 1;
        }
    return 0;
}

void delete_edge( int u, int v ) {
    for ( int i = 0; i < G[u].size(); i++ )
        if ( G[u][i].u == v ) {
            swap( G[u][i], G[u].back() );
            G[u].pop_back();
            break;
        }
}

int main() {

    scanf( "%d %d", &V, &E );

    while ( E-- )  {
        scanf( "%d %d %d", &u, &v, &w );
        u--; v--;

        max_cost = 0;
        fill( mark, mark + V, false );
        if ( find( u, v ) ) {
            if ( max_cost > w ) {
                MST -= max_cost - w;
                delete_edge( a, b );
                delete_edge( b, a );
                G[u].push_back( (edge){ v, w } );
                G[v].push_back( (edge){ u, w } );
            }
        } else {
            edges++;
            MST += w;
            G[u].push_back( (edge){ v, w } );
            G[v].push_back( (edge){ u, w } );
        }

        printf( "%d\n", edges == V - 1 ? MST : -1 );
    }

    return 0;
}
