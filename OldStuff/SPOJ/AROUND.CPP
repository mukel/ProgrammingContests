/*
Alfonso Alfonso Peterssen
2 - 12 - 2007
SPOJ #349 "Around the world"
*/
#include <cstdio>
#include <queue>
#include <set>
using namespace std;

const int
    MAXV = 5000,
    MAXE = 50000;

int T, V, E, i, j, k, sol;
int diff, new_angle;
int angle[MAXV];
set< int > S[MAXV];
bool found;
int P[MAXV];
struct edge {
    int v, next;
} ls[MAXE];

struct state {
    int id, angle, cost;
};

int main() {

    for ( scanf( "%d", &T ); T; T-- ) {

        /* Init */
        found = false;
        memset( P, 0, sizeof( P ) );
        for ( i = 0; i < MAXV; i++ )
            S[i].clear();

        scanf( "%d %d", &V, &E );

        for ( i = 0; i < V; i++ )
            scanf(  "%d", &angle[i] );

        for ( i = 1; i <= E; i++ ) {
            scanf( "%d %d", &j, &k );
            j--; k--;
            ls[i] = ( edge ) { k, P[j] };
            P[j] = i;
            ls[E + i] = ( edge ) { j, P[k] };
            P[k] = E + i;
        }

        /* Solve -> BFS */
        queue< state > Q;
        Q.push( ( state ) { 0, angle[0], 0 } );
        S[0].insert( angle[0] );

        while ( !Q.empty() && !found ) {

            state x = Q.front();
            Q.pop();

            for ( i = P[ x.id ]; i; i = ls[i].next ) {

                j = ls[i].v;

                diff = angle[j] - angle[ x.id ];
                new_angle = x.angle + diff;

                if ( diff > 180 )  new_angle -= 360;
                if ( diff < -180 ) new_angle += 360;

                if ( S[j].find( new_angle ) == S[j].end() ) {

                    if ( !j ) {
                        found = true;
                        sol = x.cost + 1;
                        break;
                    }

                    S[j].insert( new_angle );
                    Q.push( ( state ) { j, new_angle, x.cost + 1 } );
                }
            }
        }

        if ( found )
             printf( "%d\n", sol );
        else printf( "-1\n" );
    }

    return 0;
}
