/*
Alfonso Alfonso Peterssen
8 - 12 - 2007
SPOJ #338 "Roads"
*/
#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

const int
    MAXV = 101,
    MAXE = 10001,
    oo = 1000000000;

int T, M, V, E, i, j, k;
int min_dist[MAXV];

int P[MAXV];
struct edge {
    int node, cost, dist, next;
} ls[MAXE];

struct state {
    int node, cost, dist;
};

struct myqueue {

    list< state > ls;
    list< state >::iterator it;

    void clear() { ls.clear(); }
    void pop() { ls.pop_front(); }
    bool empty() { return ls.empty(); }
    state front() { return *( ls.begin() ); }

    void push( state x ) {

        for ( it = ls.begin(); it != ls.end(); it++ ) {

            if ( ( *it ).cost > x.cost ) break;

            if ( ( *it ).node == x.node  ) {

                if ( ( *it ).dist <= x.dist )
                    return;

                if ( ( *it ).cost == x.cost && ( *it ).dist > x.dist ) {
                    ( *it ).dist = x.dist;
                    return;
                }
            }
        }

        ls.insert( it, x );
    }

} Q;

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        scanf( "%d %d %d", &M, &V, &E );
        
        /* Init */
        Q.clear();
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
        Q.push( ( state ) { 1, 0, 0 } );
        while ( !Q.empty() ) {

            state x = Q.front();
            Q.pop();
            
            if ( x.dist > min_dist[ x.node ] ) continue;
            min_dist[ x.node ] = x.dist;

            for ( i = P[ x.node ]; i; i = ls[i].next )
                if ( x.cost + ls[i].cost <= M )
                    Q.push( ( state ) { ls[i].node,
                                        x.cost + ls[i].cost,
                                        x.dist + ls[i].dist } );
        }

        printf( "%d\n", min_dist[V] );
    }

    return 0;
}
