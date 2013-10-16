/*
Alfonso Alfonso Peterssen
TASK: NEVENKA
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int
    MAXV = 1000,
    oo = 1000000000;

int V, E, C, B;
int i, j, k;
int min_dist;
int solA, solB;
int house, u, v;
int church[MAXV];
int brewery[MAXV];
int dist[MAXV][MAXV];
bool mark[MAXV];
vector< int > G[MAXV];

void bfs( int src ) {
    queue< int > Q;
    fill( mark, mark + V, false );

    dist[src][src] = 0;
    mark[src] = true;
    for ( Q.push( src ); !Q.empty(); Q.pop() ) {
        int x = Q.front();
        for ( int i = 0; i < G[x].size(); i++ ) {
            int y = G[x][i];
            if ( mark[y] ) continue;
            mark[y] = true;
            dist[src][y] = dist[src][x] + 1;
            Q.push( y );
        }
    }
}

int main() {

    #warning READ FROM FILES!!!!!!


//    freopen( "nevenka.in", "r", stdin );
//    freopen( "nevenka.out", "w", stdout );

    scanf( "%d", &V );
    scanf( "%d", &house ); house--;
    scanf( "%d", &C );
    for ( i = 0; i < C; i++ ) {
        scanf( "%d", &church[i] );
        church[i]--;
    }
    scanf( "%d", &B );
    for ( i = 0; i < B; i++ ) {
        scanf( "%d", &brewery[i] );
        brewery[i]--;
    }

    memset( dist, 63, sizeof( dist ) );
    scanf( "%d", &E );
    for ( i = 0; i < E; i++ ) {
        scanf( "%d %d", &u, &v );
        u--; v--;
        G[u].push_back( v );
        G[v].push_back( u );
    }

    for ( i = 0; i < C; i++ )
        bfs( church[i] );

    min_dist = oo;
    for ( i = 0; i < B; i++ )
        for ( j = i + 1; j < B; j++ ) {
            int my_dist = -oo;
            for ( k = 0; k < C; k++ )
                my_dist >?= min( dist[ church[k] ][ brewery[i] ],
                                 dist[ church[k] ][ brewery[j] ] ) -
                                 dist[ church[k] ][ house ];

            if ( my_dist <= min_dist ) {
                min_dist = my_dist;
                solA = brewery[i];
                solB = brewery[j];
            }
        }

    printf( "%d %d\n", solA + 1, solB + 1 );
    fflush( stdout );

    return 0;
}
