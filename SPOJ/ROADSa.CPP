/*
Alfonso Alfonso Peterssen
8 - 12 - 2007
SPOJ #338 "Roads"
*/
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int
    MAXV = 101,
    MAXE = 10001,
    oo = 1000000000;

int T, M, V, E, i, j, k, dist;
int min_dist[MAXV];
int P[MAXV];
struct edge {
    int node, cost, dist, next;
} ls[MAXE];

typedef pair< int, int > state;
map< state, int > S;
map< state, int >::iterator it;

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        scanf( "%d %d %d", &M, &V, &E );
        
        /* Init */
        S.clear();
        memset( P, 0, sizeof( P ) );
        for ( i = 1; i <= V; i++ )
            min_dist[i] = oo;

        for ( i = 1; i <= E; i++ ) {
            int dist, cost;
            scanf( "%d %d %d %d", &j, &k, &dist, &cost );
            ls[i] = ( edge ) { k, cost, dist, P[j] };
            P[j] = i;
        }

        /* Solve */
        S.insert( make_pair( state( 0, 1 ), 0 ) );
        min_dist[1] = 0;
        while ( !S.empty() ) {

            state x = (*( S.begin() )).first;
            dist = (*( S.begin() )).second;
            S.erase( S.begin() );
            
            if ( dist > min_dist[ x.second ] ) continue;
            min_dist[ x.second ] = dist;

            for ( i = P[ x.second ]; i; i = ls[i].next )
                if ( x.first + ls[i].cost <= M ) {
                    it = S.find( state( x.first + ls[i].cost, ls[i].node ) );
                    if ( it != S.end() )
                        (*it).second <?= dist + ls[i].dist;
                    else S.insert( make_pair( state( x.first + ls[i].cost, ls[i].node ), dist + ls[i].dist ) );
                }
        }

        printf( "%d\n", min_dist[V] );
    }

    return 0;
}
