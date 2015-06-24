/*
Alfonso2 Peterssen
28 - 5 - 2008
COPA UCI 2008 "La casa misteriosa"
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

/* fors++  */
#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )

const int
    MAXR = 10,
    oo = 1000000000;

int R, D, S;
int u, v;
int mask[MAXR];
int dist[MAXR][1 << MAXR];
struct state {
    int room, conf, dist;
    state( int r = 0, int c = 0, int d = 0 )
    : room( r ), conf( c ), dist( d ) {}
    bool operator < ( const state &s ) const {
        if ( dist != s.dist ) return dist < s.dist;
        if ( room != s.room ) return room < s.room;
        return conf < s.conf;
    }
};
set< state > Q;

void update( int room, int conf, int steps ) {
    if ( steps >= dist[room][conf] )
        return ;
    if ( dist[room][conf] != oo )
        Q.erase( Q.find( state( room, conf, dist[room][conf] ) ) );
    dist[room][conf] = steps;
    Q.insert( state( room, conf, steps ) );
}

int main() {

	for (;;)  {

        scanf( "%d %d %d", &R, &D, &S );
        if ( R == 0 && D == 0 && S == 0 )
            break;

        vector< int > G[MAXR];

        REP( i, D ) {
            scanf( "%d %d", &u, &v );
            u--; v--;
            G[u].push_back( v );
            G[v].push_back( u );
        }

        memset( mask, 0, sizeof( mask ) );
        REP( i, S ) {
            scanf( "%d %d", &u, &v );
            u--; v--;
            mask[u] |= ( 1 << v );
        }

        REP( i, R )
        REP( j, 1 << R )
            dist[i][j] = oo;

        Q.clear();

        dist[0][1] = 0;
        Q.insert( state( 0, 1, 0 ) );        
        while ( !Q.empty() ) {
              
            state top = *Q.begin();
            Q.erase( Q.begin() );
            
            if ( top.room == R - 1 && top.conf == ( 1 << (R - 1)))
               break;

            REP( i, 1 << R ) {                 
                if ( ( i | mask[top.room] ) != mask[top.room] )
                    continue;                    
                int nconf = top.conf ^ i;                
                if ( ( nconf >> top.room ) & 1 )
                    update( top.room, nconf, dist[top.room][top.conf] + __builtin_popcount( i ) );
            }
            
            REP( i, G[top.room].size() ) {
                int next = G[top.room][i];
                if ( ( top.conf >> next ) & 1 )
                    update( next, top.conf, dist[top.room][top.conf] + 1 );
            }
        }

        if ( dist[R - 1][1 << (R - 1)] == oo )
             printf( "Pepito no puede dormir.\n" );
        else printf( "Pepito necesita %d pasos.\n", dist[R - 1][1 << (R - 1)] );
    }

	return 0;
}
